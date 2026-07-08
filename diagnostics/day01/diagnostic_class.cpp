#include <iostream>
using namespace std;

class Buffer{

    public:
    typedef int* iterator;
    typedef const int* const_iterator;
    iterator begin(){
        return _data;
    }
    iterator end(){
        return _data+_size;
    }


    //初始化给4个int空间
    Buffer()
    :_size(0)
    ,_capacity(0)
    ,_data(nullptr)
    {
        cout<<"调用 Buffer()"<<endl;
    }
    ~Buffer()
    {
        delete[] _data;
        _data = nullptr;
        _size = _capacity = 0;
        cout<<"调用 ~Buffer()"<<endl;

    }

    Buffer(const Buffer& BF)
    {
       
        _size = BF._size;
        _capacity = BF._capacity;
        _data = _capacity == 0 ? nullptr : new int[_capacity];

        for (size_t i = 0; i < _size; ++i) {
            _data[i] = BF._data[i];
        }
        cout<<"调用 Buffer(const Bufeer& BF)"<<endl;
    }

    void swap(Buffer& Bf)
    {
        std::swap(_size,Bf._size);
        std::swap(_capacity,Bf._capacity);
        std::swap(_data,Bf._data);
    }

   Buffer& operator= (Buffer BF)
    {
      
           swap(BF);
            cout<<"调用 operator="<<endl;
            return *this;
      
    }

    int operator[] (int i)
    {
        if(_data!=nullptr && (i>=0 && i<_size) )
        {
            return this->_data[i];
        }else
        {
            cout<<"数组为空或者输入下标错误"<<endl;
            return ;
        }
    }

    //扩容
    void reserve(int N)
    {
        int* temp = new int[N];
        for(int i = 0;i<_size;i++)
        {
            temp[i] = _data[i];
        }
        delete[] _data;
        _data = temp;
        _capacity = N;
    }
    //插入
    void push_back(int val)
    {
        //判断空间 是否够
        if(_size==_capacity)
        {
            int N = _capacity==0?4:2*_capacity;
            reserve(N);
        }
        _data[_size++] = val;
    }

    private:
        
        size_t _size;
        size_t _capacity;
        int* _data;
};


int main()
{
    Buffer B;
    B.push_back(1);
    B.push_back(2);
    B.push_back(3);
    B.push_back(4);

    for(auto e:B)
    {
        cout<<e<<endl;
    }

    Buffer B1 = B;
    Buffer B2;
    B1.push_back(666);
    B2 = B1;

}

