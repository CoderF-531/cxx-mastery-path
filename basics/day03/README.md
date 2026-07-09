# Day 03 - 类与对象、初始化列表、拷贝控制

今天主题：构造、初始化列表、拷贝构造、拷贝赋值、析构、`explicit`。

先阅读：

```text
C:\Users\fly\Desktop\学习规划\01-科目\C++\10-每日学习\day03-2026-07-09-类与对象拷贝控制\知识文档.md
C:\Users\fly\Desktop\学习规划\01-科目\C++\10-每日学习\day03-2026-07-09-类与对象拷贝控制\面试八股.md
```

## 示例

编译运行：

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic basics/day03/examples/lifecycle_demo.cpp -o basics/day03/examples/lifecycle_demo.exe
g++ -std=c++17 -Wall -Wextra -pedantic basics/day03/examples/explicit_demo.cpp -o basics/day03/examples/explicit_demo.exe
```

观察：

- 构造、拷贝构造、赋值、析构分别何时发生。
- 初始化列表顺序警告是否出现。
- `explicit` 打开或关闭时调用是否能通过编译。

## 练习 1：初始化顺序

文件：

```text
basics/day03/practice_init_order.cpp
```

要求：

- 定义一个 `Tracer` 类，构造和析构时打印名字。
- 定义一个 `Owner` 类，包含至少 3 个 `Tracer` 成员。
- 故意让初始化列表顺序和成员声明顺序不同，观察编译警告。
- 再调整为一致顺序。
- 在注释中写清楚成员初始化顺序和析构顺序。

## 练习 2：StringLite

文件：

```text
basics/day03/practice_string_lite.cpp
```

要求实现一个最小字符串类：

- 成员：`char* data_`、`size_t size_`。
- 默认构造：空字符串。
- 从 `const char*` 构造。
- 析构函数。
- 拷贝构造。
- 拷贝赋值，推荐 copy-and-swap。
- `size() const`。
- `c_str() const`。
- `operator[](size_t)` 和 const 版本。
- 越界抛 `std::out_of_range`。

测试：

- 默认构造。
- 字符串构造。
- 拷贝构造。
- 拷贝赋值。
- 自赋值。
- 修改副本不影响原对象。

## 练习 3：explicit

文件：

```text
basics/day03/practice_explicit.cpp
```

要求：

- 写一个 `Score` 类，单参数构造函数接收 `int`。
- 先不加 `explicit`，观察 `print_score(90)` 是否能编译。
- 再加 `explicit`，把不能编译的代码注释掉。
- 用注释说明为什么推荐单参数构造函数加 `explicit`。

## 问题回答

文件：

```text
basics/day03/Day 03 问题回答.md
```

回答：

1. 初始化列表和构造函数体赋值有什么区别？
2. 成员初始化顺序由什么决定？
3. 拷贝构造和拷贝赋值的区别是什么？
4. Rule of Three 是什么？
5. copy-and-swap 中临时副本什么时候析构？释放谁的资源？
6. `explicit` 解决什么问题？
7. 裸指针成员默认浅拷贝有什么风险？
8. 析构函数调用顺序和构造顺序是什么关系？

## 提交

通过验收后使用中文提交：

```powershell
git add basics/day03
git commit -m "基础：完成第 3 天类与对象拷贝控制练习"
git push
```
