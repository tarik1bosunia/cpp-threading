/*
TOPIC: Thread or Process Syncronization

NOTE: we will use only thread example to explain this topic

POINTS:
    1. Thread or Process syncronize to access critical section.
    2. Critical section is one or collection of program statements which should be executed by only one thread or process at a time
*/


#include<iostream>
#include<thread>
#include<mutex>

typedef long long ll;
ll bankBalance = 0;
std::mutex m1;

void addMoney(ll value){
    if(value <= 0) return;
    m1.lock();
    bankBalance += value;
    m1.unlock();

}


using namespace std;

int main(){
    std::thread t1(addMoney, 100);
    std::thread t2(addMoney, 200);

    t1.join();
    t2.join();

    cout << "Final Balance : " << bankBalance << endl;

    return 0;
}