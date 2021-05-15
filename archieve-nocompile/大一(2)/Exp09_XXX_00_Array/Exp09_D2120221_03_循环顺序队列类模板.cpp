/* 
本题结合课本范例、实践教程范例，略加改造即可完成，难度不大。

   模仿实验二十，范例1.2，改造课本例7.10循环队列类模板。
   注意，循环队列中浪费一个位置，用作队空队满判断。
   front指向那个空位置，下标从(front+1)%maxSize开始是有效数据。
   队空时，rear也指向该空位置，否则，rear指向最后一个有效数据。
   
编程要求：
-    1 为例7.10的循环顺序队列类模板增加打印队列中元素的函数 PrintQueue()。

-    2 为例7.10的循环顺序队列类模板增加扩容函数 QueueFull()。
   当队列满时，执行QueueFull()操作：动态创建一个是原来的队列容量的两倍的队列空间，
   把原来队列中的内容放入新队列，再删除原队列空间。
   
-    4 测试：完成添加的各成员函数模板的测试，按下列要求完成基本测试：
       初始创建一个容量为 5 的队列， 【注意是容量，队列长度为：容量+1】
       将26个字母，首先入队20个字母，【此过程中，会产生两次扩容操作，得到容量为20的队列】
       出队10个字母后，再完成剩余6个字母的入队。【此过程中，不产生扩容操作，队列容量仍为20，此时队列中有16个元素】
       最后完成剩余16个字母的出队。  【此时队列容量为20，队列空】
       
       完成基本测试后，可以自行设计自己的测试程序。
注意：

     增加的两个函数都要注意当循环队列 front>rear 时的处理。
*/

#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    int rear, front;
    T *elements;
    int maxSize;

public:
    Queue(int ms = 18);
    ~Queue() { delete[] elements; }
    bool IsEmpty() const { return front == rear; }
    bool IsFull() const { return (rear + 1) % maxSize == front; }
    int Length() const { return (rear - front + maxSize) % maxSize; }
    void en(const T &data);
    T de();
    T get();
    void MakeEmpty() { front = rear = 0; }
    //my
    void printRaw();
    void print();
    void QueueFull();
};

template <typename T>
Queue<T>::Queue(int ms)
{
    maxSize = ms;
    elements = new T[maxSize];
    front = rear = 0;
    assert(elements);
}

template <typename T>
void Queue<T>::en(const T &data)
{
    if (IsFull())
    {
        QueueFull();
        rear = (rear + 1) % maxSize;
        elements[rear] = data;
    }
    else
    {
        rear = (rear + 1) % maxSize;
        elements[rear] = data;
    }
}

template <typename T>
T Queue<T>::de()
{
    assert(!IsEmpty());
    front = (front + 1) % maxSize;
    return elements[front];
}

template <typename T>
T Queue<T>::get()
{
    assert(!IsEmpty());
    return elements[(front + 1) % maxSize];
}

template <typename T>
void Queue<T>::printRaw()
{
    for (int i = 0; i < maxSize; i++)
    {

        cout << elements[i] << '\t';
        if (i == front)
            cout << " { ";
        if (i == rear)
            cout << " } ";
    }
    cout << endl
         << endl;
}

template <typename T>
void Queue<T>::print()
{
    if (front == rear)
    {
        cout << "NoQueue";
    }
    else
    {
        for (int i = (front + 1) % maxSize; i != rear; i = (i + 1) % maxSize)
        {
            cout << elements[i] << '\t';
        }
        cout << elements[rear];
    }

    cout << endl
         << endl;
}
template <typename T>
void Queue<T>::QueueFull()
{
    assert(elements);
    T *old_ele = elements;
    int newMaxsize = maxSize * 2;
    elements = new T[newMaxsize];
    assert(elements);
    for (int i = 1; i < maxSize; i++)
    {
        elements[i] = old_ele[(i + front) % maxSize];
    }

    front = 0;
    rear = maxSize - 1;
    maxSize = newMaxsize;
    if (old_ele)
        delete[] old_ele;
}

int main()
{
    int arr[10] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    Queue<int> que(12);
    for (int i = 0; i < 10; i++)
    {
        que.en(arr[i]);
    }
    que.printRaw();
    que.print();

    cout << endl
         << endl
         << endl;
    que.en(233);
    que.printRaw();
    que.print();

    cout << endl
         << endl
         << endl;

    que.en(556);
    que.printRaw();
    que.print();

    cout << endl
         << endl
         << endl;

    que.en(111);
    que.printRaw();
    que.print();
    cout << endl
         << endl
         << endl;

    que.en(666);
    que.printRaw();
    que.print();

    cout << endl
         << endl
         << endl;
    //system("pause");
    return 0;
}