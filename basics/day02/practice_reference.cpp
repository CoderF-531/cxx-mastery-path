/*
写 swap_by_pointer(int* a, int* b)。
写 swap_by_reference(int& a, int& b)。
写 try_reset_pointer(int* p)，观察它能否改变外部指针。
写 reset_pointer_by_reference(int*& p)，让外部指针变成 nullptr。
在 main 中输出每一步结果。
*/

#include <iostream>
using namespace std;

void swap_by_pointer(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_by_reference(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void try_reset_pointer(int* p)
{
    *p = 666;
}
void reset_pointer_by_reference(int*& p)
{
    p = nullptr;
}

int main()
{
    int x = 1,y = 2;
    swap_by_pointer(&x,&y);
    cout<<"x = "<<x<<" "<<"y = "<<y<<endl;
    int a = 10,b = 20;
    swap_by_reference(a,b);
    cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
    
    int z = 10;
    int* tmp = &z;
    try_reset_pointer(tmp);
    cout<<"*tmp = "<<*tmp<<endl;

    reset_pointer_by_reference(tmp);
    if(tmp!=nullptr)
    {
        cout<<"tmp != nullptr"<<endl;
    }else
    {
        cout<<"tmp == nullptr"<<endl;

    }

    return 0;
}
