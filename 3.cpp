/*
    Topic:: Use of join(),detach() and joinable Thread in C++11

    JOIN NOTES::
    <<0>> once a thread is started we wait for this thread to finish by calling join() function on thread object .
    <<1>> Double join will result into termination.
    <<2>> if needed we needed check thread is joinable before joining.(using joinable() function)

    DETACH NOTES::
    <<0>> This is used to detach newly created thread from the parent thread .
    <<1>> Always check before detaching a thread that it is joinable otherwise we may end up  double detaching and
          double detach() will result into program  termination.
    <<2>> If  we had detached thread and main function  is returning then the detached thread execution is suspended.

    NOTES::
    Either join() or detach() should be called on thread object, otherwise  during thread object's destuctor it will terminate the program.Because insie destuctor if thred is still joinable? if yes then it termintes the program.
*/


// #include<iostream>
// #include<thread>
// #include<chrono>
// using namespace std;
// void run(int count){
//     while (count -->0)
//     {
//         cout << "tata" <<endl;
//     }
//     std::this_thread::sleep_for(chrono::seconds(3));  
// }
// int main()
// {
//     std::thread t1(run,10);
//     cout << "main()" << endl;
//     t1.join();
//    // t1.join(); //double join invalid

//    if(t1.joinable()){
//        t1.join();
//     }

//     cout << "man() after" << endl;
    
//     return 0;
// }


/* #include<iostream>
#include<thread>
#include<chrono>
using namespace std;
void run(int count){
    while (count -->0)
    {
        cout << count << " tata" <<endl;
    }
    std::this_thread::sleep_for(chrono::seconds(5));  
    cout << "thread finished" << endl;
}
int main()
{
    std::thread t1(run,10);
    cout << "main()" << endl;
    t1.detach();
    cout << "main() after" << endl;
   
    
    return 0;
} */


