#include <iostream>
#include <string>
using namespace std;


/*
实现三个 print_value 重载：
int
double
const std::string&
实现两个 max_value 重载：
int max_value(int a, int b)
double max_value(double a, double b)
写一个故意容易二义性的例子，用注释说明为什么不建议这样写。
*/


void print_value(int val)
{
    cout<<"int value = "<<val<<endl;
}

void print_value(double val)
{
    cout<<"double value = "<<val<<endl;
}

void print_value(string val)
{
    cout<<"string value = "<<val<<endl;
}


int max_value(int a, int b)
{
    return a>b?a:b;
}
double max_value(double a, double b)
{
    return a>b?a:b;
}

//重载函数如果使用默认参数的话 就可能一下情况 二义性
void f()
{
        cout << "f ()" << endl;
}

void f(int  a = 10)
{
        cout << "f (int a)" << endl;
}


int main()
{
    print_value(1);
    print_value(1.0);
    print_value("111");
    cout<<"max num = "<<max_value(1,5)<<endl;
    cout<<"max num = "<<max_value(1.0,5.0)<<endl;

    //f();

    return 0;
}
