/* 
本题有范例，简单，所有人都能完成。
根据习题7.8的要求，改造完善P244例7.8顺序栈类模板（即实验P71范例1.2)。

编程要求：
-    1 习题7.3 	改造例7.8的顺序栈类，当栈满时，执行StackFull()操作：
	动态创建一个是原来的栈空间的两倍的空间，把原来栈中的内容放入新栈，再删除原栈空间。
-    2 测试：完成添加的成员函数模板的测试。
*/

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Stack
{
    int top;
    T *elements;
    int maxSize;

public:
    Stack(int _maxsize = 20);
    ~Stack() { delete[] elements; }
    void push(const T &data);
    T pop();
    T get(int i);
    void clear();
    bool isEmpty() { return top == -1; };
    bool isFull() { return top == maxSize - 1; }
    void print();
    //
    void StackFull();
};

template <typename T>
Stack<T>::Stack(int _max)
{
    maxSize = _max;
    top = -1;
    elements = new T[maxSize];
    assert(elements);
}

template <typename T>
void Stack<T>::print()
{
    for (int i = 0; i <= top; i++)
    {
        cout << elements[i] << '\t';
    }
    cout << endl;
}

template <typename T>
void Stack<T>::push(const T &data)
{
    if (isFull())
    {
        StackFull();
    }
    elements[++top] = data;
}

template <typename T>
T Stack<T>::pop()
{
    assert(!isEmpty());
    return elements[top--];
}

template <typename T>
T Stack<T>::get(int i)
{
    assert(i <= top && i >= 0);
    return elements[top];
}

template <typename T>
void Stack<T>::StackFull()
{
    assert(elements);
    T *old_elements = elements;
    elements = new T[maxSize * 2];
    maxSize *= 2;
    for (int i = 0; i <= top; i++)
    {
        elements[i] = old_elements[i];
    }
    delete[] old_elements;
}

int main()
{
    Stack<int> s1(6);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.print();

    //system("pause");
    return 0;
}