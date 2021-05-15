/* 
本题结合课本范例、实践教程范例，略加改造即可完成，难度不大。
根据习题7.9的要求，将单链表类模板改造为一个双端队列，（即实验P73范例2.2)

编程要求：
-    1 习题7.9 用单链表类模板来表示一个双端队列，要求可在表的两端插入
     （链表头和尾，即可用向前和也可用向后生成），但只能在表的一端删除（链表头）
-    2 给出基于此结构队列的两个入队（链头入队，链尾入队）算法的成员函数。
-    3 给出基于此结构队列的一个出队（链头出队）算法的成员函数。 
-    4 测试：完成添加的各成员函数模板的测试。
*/

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class DeQueue;

template <typename T>
class Node
{
    T info;
    Node<T> *link;

public:
    Node(T data = 0, Node *l = NULL);
    friend class DeQueue<T>;
};

template <typename T>
Node<T>::Node(T data, Node<T> *l)
{
    info = data;
    link = l;
}

template <typename T>
class DeQueue
{
    Node<T> *front, *rear;

public:
    DeQueue() { rear = front = NULL; }
    ~DeQueue() { MakeEmpty(); }
    bool IsEmpty()
    {
        return front == NULL;
    }
    void enf(const T &data);
    void en(const T &data);
    T de();
    T get();
    void MakeEmpty();
};

template <typename T>
void DeQueue<T>::en(const T &data)
{
    if (front == NULL)
        front = rear = new Node<T>(data, NULL);
    else
        rear = rear->link = new Node<T>(data, NULL);
}

template <typename T>
void DeQueue<T>::enf(const T &data)
{
    if (front == NULL)
        front = rear = new Node<T>(data, NULL);
    else
        front = new Node<T>(data, front);
}

template <typename T>
T DeQueue<T>::de()
{
    assert(!IsEmpty());
    Node<T> *temp = front;
    T data = temp->info;
    front = front->link;
    delete temp;
    return data;
}

template <typename T>
void DeQueue<T>::MakeEmpty(){
    

}

int main(int argc, char *argv[])
{
    DeQueue<int> d1;
    ;
    d1.en(1);
    d1.en(2);
    d1.en(3);
    d1.enf(4);
    d1.enf(5);
    for (int i = 0; i < 5; i++)
        cout << d1.de() << "   ";

    //std::system("pause");
    return 0;
}