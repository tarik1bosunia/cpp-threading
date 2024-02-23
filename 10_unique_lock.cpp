/* 
    std::unique_lock<mutex> lock(m1)

    1.  The class unique_lock is a mutex ownership wrapper.
    2.  It allows:
        a. Can have different strateties
        b. time-contrainedattempts at locking(try_lock_for,try_lock_until)
        c. recursive locking
        d. transfer of lock ownership
        e. condition variables
    //Locking Strateties 
        TYPE            EFFECT
    1.defer_lock    do not acquire wonership of the mutex.
    2.try_to_lock   try to acquire ownership of the mutex without blocking.
    3.adopt_lock    assume the calling thread already has the ownership of the mutex.

 */

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m1;
int buffer = 0;

// //Example 1
// void task(const char* threadNumber, int loopFor){
//     std::unique_lock<mutex> lock(m1);//autometiclly calls on the mutex m1
//     for(int i = 0;i < loopFor;++i){
//         buffer++;
//         cout << threadNumber << buffer << endl;
//     }
// }

//Example 2
void task(const char* threadNumber, int loopFor){
    std::unique_lock<mutex> lock(m1, std::defer_lock);//does not call on the mutex m1, because use defer_lock
    lock.lock();
    for(int i = 0;i < loopFor;++i){
        buffer++;
        cout << threadNumber << buffer << endl;
    }
    //lock.unlock() it is not needed as it will be unlocked in destructor of unique_lock.
}

int main()
{
    thread t1(task, "T0 ",10);
    thread t2(task, "T1 ",10);

    t1.join();
    t2.join();
    
    
    
    return 0;
}

