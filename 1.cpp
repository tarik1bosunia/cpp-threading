//=====Interdution to thread in C++(c++11)======

//what do you mean by thread and give one example in  c++?

//Answer
//  0. In evry application there is a default thread which is main(),inside this we create other threads.
//  1. A thread is also known as lightweight process. Idea is achive parallesm by dividing a process into mutiple threeads.
//  For Example:
        // a. the browser has mutiple tabs that can be different threads.
        // b. MS word must be using multiple threads , one thread to formaat the text , anoother thread to process inputs(spell checker)
        // c. visual studio editor would be using threading for auto completing the code.(intelligence)

// ways to create threads in c++ 11
//  1. function pointers
//  2. lamda functions 
//  3. functions
//  4. Member functions 
//  5. Static member functions

//Requirement
//Find the addition off all odd number from 1 to 1900000000 and all even numbers from q to 1900000000

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long  ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull start,ull end){
    for(ull i = start;i <= end; i++){
        if((i&1) == 0){
            evenSum += i;
        }
    }
}

void findOdd(ull start,ull end){
    for(ull i = start;i <= end; i++){
        if((i&1) == 1){
            oddSum += i;
        }
    }
}

// int main()
// {
//     ull start = 0,end = 1900000000;

//     auto startTime = high_resolution_clock::now();
//     findOdd(start,end);
//     findEven(start,end);
//     auto endTime = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(endTime - startTime);


//     cout << "OddSum = " << oddSum <<endl;
//     cout << "EvenSum = " << evenSum <<endl;

//     cout <<"Seconds: " << duration.count()/1000000 <<endl;
    
//     return 0;
// }



int main()
{
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();
    
    std::thread t1(findEven,start,end);
    std::thread t2(findOdd,start,end);

    t1.join();
    t2.join();
   
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);


    cout << "OddSum = " << oddSum <<endl;
    cout << "EvenSum = " << evenSum <<endl;

    cout <<"Seconds: " << duration.count()/1000000 <<endl;
    
    return 0;
}
