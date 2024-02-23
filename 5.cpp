/* 
    Mutex:: tryLock

    //0. try_lock() Tries to lock the Mutex. Returns immidiately. On successful lock acquisition 
         returns true otherwise returns false.
    //1. if try lock is not able to lock mutex then it does not get blocked thats why it is called non bloking.
    //
    //2.if try lock is called aganin by the sme thread which wonsthe mutex , the behaviour is undefined.
    It is a dead lock cisuation with undefined behaviour. (if you want to able to lock the same mutex by same thread
    more than one time the go for recursive_mutex)
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int counter = 0;
std::mutex mtx;

void incraseTheCounterFor100000Time(){
    for(int i = 0; i<100000 ; ++i){
        if(mtx.try_lock()){
            ++counter;
            mtx.unlock();
        }
    }
}

int main()
{
    std::thread t1(incraseTheCounterFor100000Time);
    std::thread t2(incraseTheCounterFor100000Time);
    
    t1.join();
    t2.join();

    cout << "counter could increases upto : " << counter <<endl;

    return 0;
}