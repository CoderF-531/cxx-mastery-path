# Day 02 - References, const, Overload, and Class Interfaces

今天目标：补 Day 01 暴露出的类型、返回值和接口设计问题。

你需要先阅读学习规划中的知识文档：

```text
C:\Users\fly\Desktop\学习规划\01-科目\C++\02-知识文档\2026-07-09-引用const函数重载与类接口.md
C:\Users\fly\Desktop\学习规划\01-科目\C++\03-面试八股\2026-07-09-面试八股重点.md
```

## 示例代码

先编译运行：

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic basics/day02/examples/reference_const_demo.cpp -o basics/day02/examples/reference_const_demo.exe
g++ -std=c++17 -Wall -Wextra -pedantic basics/day02/examples/buffer_interface_demo.cpp -o basics/day02/examples/buffer_interface_demo.exe
```

运行后回答：

- 哪些函数用了引用传参？
- 哪些函数承诺不会修改对象？
- 为什么 `operator[]` 要写两个版本？

## 练习 1：引用与指针

文件：

```text
basics/day02/practice_reference.cpp
```

要求：

- 写 `swap_by_pointer(int* a, int* b)`。
- 写 `swap_by_reference(int& a, int& b)`。
- 写 `try_reset_pointer(int* p)`，观察它能否改变外部指针。
- 写 `reset_pointer_by_reference(int*& p)`，让外部指针变成 `nullptr`。
- 在 `main` 中输出每一步结果。

验收重点：

- 能解释指针传参和引用传参的差异。
- 能解释 `int*&` 的含义。

## 练习 2：const Buffer

文件：

```text
basics/day02/practice_const_buffer.cpp
```

要求：

- 基于 Day 01 的 `Buffer` 写一个更规范版本。
- 使用 `size_t` 表示下标、大小、容量。
- 实现 `size() const`、`capacity() const`、`empty() const`。
- 实现两个 `operator[]`：
  - `int& operator[](size_t index)`
  - `const int& operator[](size_t index) const`
- 越界时抛出 `std::out_of_range`。
- 在 `main` 中测试普通对象修改元素、const 引用读取元素、越界异常。

验收重点：

- const 对象只能调用 const 成员函数。
- 非 const `operator[]` 可以修改元素。
- const `operator[]` 只能读取元素。

## 练习 3：函数重载

文件：

```text
basics/day02/practice_overload.cpp
```

要求：

- 实现三个 `print_value` 重载：
  - `int`
  - `double`
  - `const std::string&`
- 实现两个 `max_value` 重载：
  - `int max_value(int a, int b)`
  - `double max_value(double a, double b)`
- 写一个故意容易二义性的例子，用注释说明为什么不建议这样写。

验收重点：

- 能说明重载由参数列表决定。
- 能说明返回值不能单独构成重载。
- 能说明默认参数和重载混用的风险。

## 今日验收提交

提交时给 Codex：

```text
今日学习内容：
完成文件：
编译命令：
运行结果：
遇到的错误：
我能解释的概念：
我还不懂的问题：
希望 Codex 验收的重点：
```

## Git 提交

通过验收后再提交：

```powershell
git add basics/day02
git commit -m "basics: complete day 02 references and const"
git push
```
