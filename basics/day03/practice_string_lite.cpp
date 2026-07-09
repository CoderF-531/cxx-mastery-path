#include <iostream>
#include <cstring>
using namespace std;

/*
成员：char* data_、size_t size_。
默认构造：空字符串。
从 const char* 构造。
析构函数。
拷贝构造。
拷贝赋值，推荐 copy-and-swap。
size() const。
c_str() const。
operator[](size_t) 和 const 版本。
越界抛 std::out_of_range
*/
namespace fjy{
    class string{
public:

    string(const char* s = "")
    {
        _size = strlen(s);
        _data = new char[_size+1]; //预留一个\0
        memcpy(_data,s,_size+1);
    }
    string(const string& s)
    {
        _size = s._size;
        _data = new char[_size+1]; 
        memcpy(_data,s.c_str(),_size+1);
    }
    ~string()
    {
        delete[] _data;
        _data = nullptr;
        _size = 0;
    }
    void swap(string& s)
    {
        std::swap(_size,s._size);
        std::swap(_data,s._data);
    }
    string& operator=(string s)
    {
        swap(s);
        return *this;
    }
   const char* c_str() const{
        return _data;
    }
    size_t size() const{
        return _size;
    }

 
    char& operator[](size_t index)
    {
         if (index >= _size) {
            throw std::out_of_range("string index out of range");
        }
        return _data[index];

    }
    const char& operator[](size_t index) const
    {
       if (index >= _size) {
            throw std::out_of_range("string index out of range");
        }
        return _data[index];
    }

private:
    char* _data;
    size_t _size;
};
}



/*
默认构造。
字符串构造。
拷贝构造。
拷贝赋值。
自赋值。
修改副本不影响原对象。
*/
void test111(fjy::string bb)
{
    bb = "string";
    cout<<bb.c_str()<<endl;
}

void test01()
{
    fjy::string s1;
    cout<<s1.c_str()<<endl;
    fjy::string s2("abcde");
    cout<<s2.c_str()<<endl;

    fjy::string s3(s2);
    cout<<s3.c_str()<<endl;

    s1 = s2;
    cout<<s1.c_str()<<endl;
    s2 = s2;
    cout<<s2.c_str()<<endl;

    test111(s1);
    cout<<s1.c_str()<<endl;

    s3[0] = 'A';
cout << s3.c_str() << endl;
cout << s2.c_str() << endl;

    cout<<s1[2]<<endl;

}

int main()
{
    test01();
    return 0;
}