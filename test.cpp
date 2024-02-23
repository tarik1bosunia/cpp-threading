#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int counter = 0;
std::mutex m;

void addMoney(){
    for (int i = 0; i < 100000; i++)
    {
        if(m.try_lock()){
            ++counter;
            m.unlock();
        }
    } 
    
}


int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();
    
    cout<< counter << endl;
    
    return 0;
}
