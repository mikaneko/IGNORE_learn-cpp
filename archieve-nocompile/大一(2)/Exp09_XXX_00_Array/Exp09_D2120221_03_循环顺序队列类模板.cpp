/* 
�����Ͽα�������ʵ���̷̳������ԼӸ��켴����ɣ��ѶȲ���

   ģ��ʵ���ʮ������1.2������α���7.10ѭ��������ģ�塣
   ע�⣬ѭ���������˷�һ��λ�ã������ӿն����жϡ�
   frontָ���Ǹ���λ�ã��±��(front+1)%maxSize��ʼ����Ч���ݡ�
   �ӿ�ʱ��rearҲָ��ÿ�λ�ã�����rearָ�����һ����Ч���ݡ�
   
���Ҫ��
-    1 Ϊ��7.10��ѭ��˳�������ģ�����Ӵ�ӡ������Ԫ�صĺ��� PrintQueue()��

-    2 Ϊ��7.10��ѭ��˳�������ģ���������ݺ��� QueueFull()��
   ��������ʱ��ִ��QueueFull()��������̬����һ����ԭ���Ķ��������������Ķ��пռ䣬
   ��ԭ�������е����ݷ����¶��У���ɾ��ԭ���пռ䡣
   
-    4 ���ԣ������ӵĸ���Ա����ģ��Ĳ��ԣ�������Ҫ����ɻ������ԣ�
       ��ʼ����һ������Ϊ 5 �Ķ��У� ��ע�������������г���Ϊ������+1��
       ��26����ĸ���������20����ĸ�����˹����У�������������ݲ������õ�����Ϊ20�Ķ��С�
       ����10����ĸ�������ʣ��6����ĸ����ӡ����˹����У����������ݲ���������������Ϊ20����ʱ��������16��Ԫ�ء�
       ������ʣ��16����ĸ�ĳ��ӡ�  ����ʱ��������Ϊ20�����пա�
       
       ��ɻ������Ժ󣬿�����������Լ��Ĳ��Գ���
ע�⣺

     ���ӵ�����������Ҫע�⵱ѭ������ front>rear ʱ�Ĵ���
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