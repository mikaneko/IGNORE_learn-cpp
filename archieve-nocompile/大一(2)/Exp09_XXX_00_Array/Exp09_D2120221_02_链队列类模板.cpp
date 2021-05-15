/* 
�����Ͽα�������ʵ���̷̳������ԼӸ��켴����ɣ��ѶȲ���
����ϰ��7.9��Ҫ�󣬽���������ģ�����Ϊһ��˫�˶��У�����ʵ��P73����2.2)

���Ҫ��
-    1 ϰ��7.9 �õ�������ģ������ʾһ��˫�˶��У�Ҫ����ڱ�����˲���
     ������ͷ��β����������ǰ��Ҳ����������ɣ�����ֻ���ڱ��һ��ɾ��������ͷ��
-    2 �������ڴ˽ṹ���е�������ӣ���ͷ��ӣ���β��ӣ��㷨�ĳ�Ա������
-    3 �������ڴ˽ṹ���е�һ�����ӣ���ͷ���ӣ��㷨�ĳ�Ա������ 
-    4 ���ԣ������ӵĸ���Ա����ģ��Ĳ��ԡ�
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