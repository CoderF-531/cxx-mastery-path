## 1、示例代码运行
运行后回答：

- 哪些函数用了引用传参？
- void add_one_by_reference(int& x) 
- void print_name(const std::string& name) 
- void reset_pointer_ref(int*& p)
- Buffer(const Buffer& other)
- void print_buffer(const Buffer& buffer)
- 这几个函数都用到引用传值
- 
- 
- 哪些函数承诺不会修改对象？
- 当我们再类对象成员函数后 +const 就保证了不会修改对象
-  std::size_t size() const {
        return size_;
    }

    std::size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }
- 
- 为什么 `operator[]` 要写两个版本？
- 我的理解是 用非const修饰的对象 他的权限可以缩小但是不能放大 因此普通对象可以调用非const版本也能调用const版本
- 而const修饰的对象 他的访问权限不能够放大  要是只要非const版本他就无法调用该版本 因此要满足这两种只能写两个版本的 