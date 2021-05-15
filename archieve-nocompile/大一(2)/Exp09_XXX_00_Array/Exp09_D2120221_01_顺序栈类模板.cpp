/* 
�����з������򵥣������˶�����ɡ�
����ϰ��7.8��Ҫ�󣬸�������P244��7.8˳��ջ��ģ�壨��ʵ��P71����1.2)��

���Ҫ��
-    1 ϰ��7.3 	������7.8��˳��ջ�࣬��ջ��ʱ��ִ��StackFull()������
	��̬����һ����ԭ����ջ�ռ�������Ŀռ䣬��ԭ��ջ�е����ݷ�����ջ����ɾ��ԭջ�ռ䡣
-    2 ���ԣ������ӵĳ�Ա����ģ��Ĳ��ԡ�
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