/*
Topic:: Condition variable in C++ Threading
IMPORTANT POINT:: CV are used for two purposes
    A. Notify ohther threads 
    B. Waiting for other conditions

1. Condition Variable allows running threads on some conditions and once those conditions are met
   the waiting thread is notified using:
   a. notify_one();
   b. notify_all();
2. you need mutex to use condition variable
3. If some thread want to wait on some condition then it has to do these things:
    a. aqure the mutex lock using std::unique_lock<std::mutex>lock(m);
    b. execute wait, wait_for, wait_until. The wait operation autometically release the mutex
       and suspense the execution of the thread.
    c. when the condition variable is notified, the thread is awakened and the mutex is autometically reaqueared.
       the thread shoud then check the condition and resume waiting if the wake up was spurious.

NOTE::
1. condition variable are used to syncronize two or more threads.
2. best use of the condition variable is Producer/Consumer problem.        

*/


#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money){
    std::lock_guard<mutex> lg(m);
    balance += money;
    cout << "Ammount Added Current Balance: " << balance << endl;
    cv.notify_one();
}

void withdrowMoney(int money){
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, []{return (balance != 0) ? true : false;});
    if(balance >= money){
        balance -= money;
        cout << "Amount Deducted: " << money << endl;
    }else{
        cout << "Ammount can not be Deducted. Current balance is less then money " << money << endl;
    }
    cout << "Current Balance is: " << balance << endl;
}

int main(){
    std::thread t1(withdrowMoney, 600);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();
    
    return 0;
}
