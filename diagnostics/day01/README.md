# Day 01 - C++ Baseline Diagnostic

今天目标：确认你当前 C++ 基础、对象生命周期、STL 和基础数据结构的真实水平。

不要先看答案，不要追求写得花哨。目标是暴露问题。

## 任务 1：基础语法与 STL

文件名：

```text
diagnostics/day01/diagnostic_basic.cpp
```

要求：

1. 从标准输入读取一整行英文文本。
2. 统计每个单词出现次数，忽略大小写。
3. 输出出现次数最高的前 3 个单词。
4. 如果次数相同，按字典序从小到大输出。
5. 必须使用 `string`、`vector` 或 `map/unordered_map`。

示例输入：

```text
C++ is hard but c++ is powerful and hard
```

示例输出格式：

```text
hard 2
is 2
c 1
```

说明：标点处理不要求完美，但你需要在复盘里说明你如何处理了 `C++` 这种输入。

## 任务 2：类与对象生命周期

文件名：

```text
diagnostics/day01/diagnostic_class.cpp
```

要求：

实现一个 `Buffer` 类：

- 内部维护一段动态数组，例如 `int* data_` 和 `size_t size_`。
- 实现构造函数、析构函数、拷贝构造、拷贝赋值。
- 每个特殊成员函数都打印自己的调用信息。
- 在 `main` 中设计至少 4 个场景触发这些函数。

必须回答：

- 哪些地方发生了深拷贝？
- 如果没有自定义拷贝构造和拷贝赋值，会出什么问题？
- 析构函数什么时候被调用？

## 任务 3：基础数据结构

文件名：

```text
diagnostics/day01/diagnostic_ds.cpp
```

二选一完成：

1. 单链表反转。
2. 二叉树前序、中序、后序遍历。

要求：

- 自己定义节点结构。
- 至少准备 1 组正常用例和 1 组边界用例。
- 输出运行结果。
- 复盘里说明时间复杂度和空间复杂度。

## 今日提交要求

完成后提交这些内容：

```text
今日学习内容：
代码文件：
运行结果：
遇到的错误：
我能解释的概念：
我还不懂的问题：
希望 Codex 验收的重点：
```

## Git 提交

写完并运行后，在仓库根目录执行：

```powershell
git status
git add diagnostics/day01
git commit -m "diagnostics: complete day 01 baseline exercises"
git push
```

如果某一步报错，先不要强行处理，把完整错误发给 Codex。
