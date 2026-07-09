#include <iostream>
using namespace std;


/*
写一个 Score 类，单参数构造函数接收 int。
先不加 explicit，观察 print_score(90) 是否能编译。
再加 explicit，把不能编译的代码注释掉。
用注释说明为什么推荐单参数构造函数加 explicit。
*/

// explicit  防止单参数构造 的类型转换   如果不加的话编译器会帮你走类型转化 这对于一些对象不太安全

class Score{
public:
   explicit Score(int val):_val(val){}
    int _val;
};

void print_val(const Score& s)
{
    cout<<"val = "<<s._val<<endl;
}

int main()
{
    Score s1(10);
    print_val(s1);
 //   print_val(100);
  print_val(Score(100));
}

