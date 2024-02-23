#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

std::mutex m1, m2;

void thread1(){
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m2.lock();

    cout << "Critical Section of Thread 1" << endl;

    m1.unlock();
    m2.unlock();
}

void thread2(){
    m2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    m1.lock();
    cout << "Critical Section of Thread 2" << endl;
    m2.unlock();
    m1.unlock();
}

int main(){
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}