#include <iostream>
#include <string>

using namespace std;

/*
定义一个 Tracer 类，构造和析构时打印名字。
定义一个 Owner 类，包含至少 3 个 Tracer 成员。
故意让初始化列表顺序和成员声明顺序不同，观察编译警告。
再调整为一致顺序。
在注释中写清楚成员初始化顺序和析构顺序。
*/

class Treacer{
public:
    Treacer():name("T老师")
    {
        cout<<"Treacer默认构造"<<endl;
    }
    Treacer(string _name):name(_name)
    {
        cout<<"Treacer带参构造:"<<name<<endl;
    }

    ~Treacer()
    {
        cout<<"Treacer析构  : " <<name <<endl;
    }

private:
    string name;
};

class Owner{
public:
    Owner(string _s1,string _s2,string _s3,int _age = 10)
    :s2(_s2)
    ,s1(_s1)
    ,s3(_s3)
    ,age(_age)
    {
        cout<<"Owner带参构造"<<endl;
    }
    ~Owner()
    {
        cout<<"Owner析构"<<endl;
    }
 private:
    Treacer s1;
    Treacer s2;
    Treacer s3;
    int age;   
};

int main()
{
    //调用顺序 是先从 Owner的成员变量开始   然后走自定义类型的构造函数
    // s1 s2 s3   
    //然后再说  Owner的构造  输出  Owner带参构造
    //最后析构 先从 成员变量开始析构   顺序大概率就是栈先进后出
    // s3 s2 s1 最后Owner
    //然后初始列表的初始化顺序是按照 成员变量声明顺序来初始化 就算调换初始化列表的顺序依然如此
    Owner s("王","文","杰",18);
    return 0;
}