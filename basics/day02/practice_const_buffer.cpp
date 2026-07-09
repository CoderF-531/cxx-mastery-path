#include <iostream>
using namespace std;


/*
使用 size_t 表示下标、大小、容量。
实现 size() const、capacity() const、empty() const。
实现两个 operator[]：
int& operator[](size_t index)
const int& operator[](size_t index) const
越界时抛出 std::out_of_range。
在 main 中测试普通对象修改元素、const 引用读取元素、越界异常。
*/


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

    size_t size() const{
        return _size;
    }
    size_t capacity() const{
        return _capacity;
    }

    bool empty() const{
        return _size==0;
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

    int& operator[] (size_t i)
    {
         if (i >= _size) {
            throw std::out_of_range("Buffer index out of range");
        }
        return _data[i];
    }
    const int& operator[] (size_t i) const
    {
     if (i >= _size) {
            throw std::out_of_range("Buffer index out of range");
        }
        return _data[i];
    }

    //扩容
    void reserve(int N)
    {
        int* temp = new int[N];
        for(size_t i = 0;i<_size;i++)
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
            size_t N = _capacity==0?4:2*_capacity;
            reserve(N);
        }
        _data[_size++] = val;
    }

    private:
        
        size_t _size;
        size_t _capacity;
        int* _data;
};


void print_buffer(const Buffer& buffer) {
    for (std::size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << ' ';
    }
    std::cout << '\n';
}


int main() {
    Buffer buffer;
    buffer.push_back(10);
    buffer.push_back(20);
    buffer.push_back(30);

    buffer[1] = 200;
    print_buffer(buffer);

    const Buffer& const_buffer = buffer;
    std::cout << "size: " << const_buffer.size() << '\n';
    std::cout << "first: " << const_buffer[0] << '\n';

    try {
        std::cout << const_buffer[100] << '\n';
    } catch (const std::out_of_range& e) {
        std::cout << "caught: " << e.what() << '\n';
    }

    return 0;
}