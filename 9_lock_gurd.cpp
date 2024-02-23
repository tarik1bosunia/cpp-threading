/* 
    std::lock_guard<mutex>lock(m1)

    Notes:
    1.  it is very light weight wrapper for owning mutex on scoed basis.
    2.  It aquires mutex lock the moment you create the object of lock_guard.
    3.  it autometically removes the lock while goes out of scope.
    4.  You can not explicitly unlock the lock guard.
    5.  You can not copy lockguard.

 */
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m1;
int buffer = 0;

void task(const char* threadNumber,int loopFor){
    std::lock_guard<mutex> lock(m1);
    for(int i = 0; i< loopFor;i++){
        buffer++;
        cout << threadNumber << buffer << endl;
    }
}

int main()
{
    
    thread t1(task, "T1 ",10);
    thread t2(task, "T2 ",10);

    t1.join();
    t2.join();
    
    
    return 0;
}
