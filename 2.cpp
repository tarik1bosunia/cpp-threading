//========types of threads creation in c++ 11===

//there are 5 different types we can create threads in c++11 using callable objects.

//NOTE:
//  if we create multiple threads at the same time it does not gurantee which one will start first.

//1. Function pointer 
//   this is the very basic form of thread creation.

// #include<iostream>
// #include<thread>

// using namespace std;

// void fun(int x){
//     while(x-- > 0){
//         cout << x << endl;
//     }
// }
// //  -->  : the value of i will be decremented, immediately after the condition is checked.
// int main(){
//     std::thread t(fun,10);
//     t.join();
// } 







// #include<iostream>
// #include<thread>
// using namespace std;

// int main()
// {
//     //we can directly inject lamda at thread creation time.
//     auto fun = [](int x){
//         while(x-->0){
//             cout << x << endl;
//         }
//     };
//     std::thread t1(fun,6);
//     t1.join();
    

//     return 0;
// } 


/* #include<iostream>
#include<thread>
using namespace std;
int main()
{
    //we can directly inject lamda at thread creation time.

    std::thread t1([](int x){
        while(x-->0){
            cout << x << endl;
        }
    },5);
    t1.join();

    return 0;
}
 */




/* //3.functor(function object)

#include<iostream>
#include<thread>
using namespace std;
class Base{
public:
    void operator ()(int x){
        while(x-->0){
            cout << x << endl;
        }
    }
};

int main()
{
    std::thread t1((Base()),5);
    t1.join();

    return 0;
} */




/* ///4. Non-static member functions
#include<iostream>
#include<thread>
using namespace std;
class Base{
public:
    void run(int x){
        while(x-->0){
            cout << x << endl;
        }
    }
};

int main()
{
    Base b;
    std::thread t1(&Base::run,&b,5);
    t1.join();

    return 0;
}  */




/* //5. Static Member Function
#include<iostream>
#include<thread>
using namespace std;
class Base{
public:
    static void run(int x){
        while(x-->0){
            cout << x << endl;
        }
    }
};

int main()
{
    Base b;
    std::thread t1(&Base::run,5);
    t1.join();

    return 0;
} */