/* 
������Ϊ�α�����7.5��ԭ������ִ�С�
��ѧϰ����Ļ������������� - ���֣����֣������֣���
Ȼ����ҵҪ�����������ܡ�
����Ʋ��Գ�������������ܡ�

    ������һ����ģ�壬���������ڲ�ͬ���б�Ԫ�����͡�
    ��ˣ�����ģ�嶨�壬����ͨ���ԡ�
    �Ѹ��α�P233 ��7.5����������ģ�塣

    Ϊ������Ľ�㶨�����࣬�����йصĻ�����������Ϊ�����ĳ�Ա������������
 -  ����ͷ�����޲ι��캯��������һ������вι��캯��
 -  �ڵ�ǰ�������һ����㣬ɾ����ǰ���ĺ�̽��

    ����������Ĳ�������Ϊ������ĳ�Ա����������:
 -  ��������������ݡ����㵥�����ȡ���ӡ�������ݡ��Ƴ�ָ�����
 -  ��ǰ���������������������������������ȵ� 
 
ע��
    ������ɾ��ָ�����Ĳ���û����ȫ��װ�����ڣ�
    �������޸�Ϊ�����ڽ�ɾ��������ȫ��װ��
    
���Ҫ��
-    1 ϰ��7.3 ����������ģ������������Ա������
               1.ɾ������������������Ϊָ��ֵ�Ľ�㣻    *********  ok  ********
               2.ȡ�������е�K��Ԫ��(��1��ʼ����)��     *********  ok  ********

-    2 ϰ��7.4 Ϊ��������ģ������:
               ������ƹ��캯��                     *********  ok  ********
               �����ֵ�������=��                  *********  ok  ********

-    3 ϰ��7.5*��Ϊ��������ģ�����һ����������ת�ĳ�Ա������Ҫ��   *********  ok  ********
               ��ɾ��ԭ��㣬                           
               Ҳ����һ��������ȡ����
               ����ͨ���ı�ָ��������ӷ�������ת���� 
       �㷨��ʾ��������Ϊ��ͷ����������Ȼ���յ�ͷ��㣬
               Ȼ�����δӵ�һ����㿪ʼ����ͷ��β����ժ�½�㣬
               ͨ��ָ����Ľ�����������ÿ������ָ����ָ��ԭǰһ�����
               �����ת�������ӵ������ͷ���� 
       ע����ɸ��㷨�����ѵ�ͬѧ����ʵ���½�һ����ת����ȡ��ԭ������㷨��

-    4 ϰ��7.6*Ϊ���������ء�+���������ʵ�������������������ӡ�  *********  ok  ********
               ����Ҫ���ǵ���������������ǰ��ƴ�ӳ�һ���µĴ�����
               �����Ҫ��������ȥ����������ͬ�Ľ���+���㡣  
               ע���ڴ�ռ������

-    5 ���ԣ������ӵĸ���Ա����ģ��Ĳ��ԡ�

ע��
-   ���Ҫ��1�ϼ򵥣������˶�����������ɡ�
-   ���Ҫ��2��ʵ��̳�ʵ��ʮ�ŷ���2��P62.Exp_19_2��һ����Ҫ��ע�ⷶ��7.5��Exp_19_2����ͬ��
    ģ�²����޸ļ�����ɡ�
    
-   *��־Ϊѧ��������ͬѧ׼����
-   ���Ҫ��3ͬ�Զ���string��һ�����Ǹ��󳧾��������⣬�����ϸ��ַ�������ǵأ�
    ģ���޸����ʺϱ���ʵ��Ҫ�󡪡�����ѧΪ���á�
-   ���Ҫ��4��ʾ����Ϊȥ�ع���ʵ�ּ�㣬�ɷֱ�����������������򣬺�鲢��
    ���������ȥ���㷨ʵ��Ҳ�����ӣ���ִ��ʱ���㸴�ӶȽϸߡ�
-   �����Ĳ��ֹ��ܣ����ڲ��Խ׶ν����������ȶ���һ���պ��������������ƹ��ܡ�    
*/

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class List; //ǰ����������

//======== ͷ�����ģ�嶨�忪ʼ ========//
//���ȿ������֯�����ý���࣬���������ݺ�ָ������йغ�����Ϊ��Ա����
template <typename T>
class Node
{
    T info;        //������Ϊ�Ӷ���ʵ���̳�P62.Exp_19_2������ָ�룬����������һ�㡿
    Node<T> *link; //ָ����ע�������ʽ�����������ǲ���������ģ��ʵ����Ϊ��
public:
    Node();                       //����ͷ���Ĺ��캯��
    Node(const T &data);          //����һ����Ĺ��캯��
    void InsertAfter(Node<T> *P); //�ڵ�ǰ�������һ�����
    Node<T> *RemoveAfter();       //ɾ����ǰ���ĺ�̽�㣬���ظý�㱸��
    friend class List<T>;
    //��ListΪ��Ԫ�࣬List��ֱ�ӷ���Node��˽�г�Ա����ṹһ�����㣬������ȫ
};

template <typename T>
Node<T>::Node()
{
    link = NULL;
}

template <typename T>
Node<T>::Node(const T &data)
{
    info = data;
    link = NULL;
}

template <typename T>
void Node<T>::InsertAfter(Node<T> *p)
{
    p->link = link;
    link = p;
}

template <typename T>
Node<T> *Node<T>::RemoveAfter()
{
    Node<T> *tempP = link;
    if (link == NULL)
        tempP = NULL; //������β,�����޽��
    else
        link = tempP->link;
    return tempP;
}
//======== ͷ�����ģ�嶨����� ========//

//======== ������ģ�嶨�忪ʼ ========//
//�ٶ��������࣬ѡ���ò����������������������������������롢ɾ����ȡ���ݵ�
template <typename T>
class List
{
private:
    Node<T> *head, *tail; //����ͷָ���βָ��
public:
    List();  //���캯��������ͷ���(������)
    ~List(); //��������

    void MakeEmpty();                //���һ������ֻ���ͷ���
    Node<T> *Find(T data);           //������������data��ͬ�Ľ�㣬���ظý��ĵ�ַ
    int Length();                    //���㵥������
    void PrintList();                //��ӡ�����������
    void InsertFront(Node<T> *p);    //��������ǰ���������ڱ�ͷ����һ�����
    void InsertRear(Node<T> *p);     //������������������ڱ�β���һ�����
    void InsertOrder(Node<T> *p);    //��������������
    Node<T> *CreatNode(T data);      //����һ�����(�������)
    Node<T> *DeleteNode(Node<T> *p); //ɾ��ָ����㣬

    //��������
    bool DeleteNode(T data); //ϰ��7.3 ɾ������������������Ϊָ��ֵ�Ľ�㣬���㸴�Ӷ������ڲ��ҡ�aaa

    Node<T> *FindK(int K) const; //ϰ��7.3 ȡ�������е�K��Ԫ��(��1��ʼ����),T����Ϊint���ʲ�������

    //һ�������Ḵ�ƹ������ɻ�ʹ�õ�ʽ������Ҫʵ��+���أ��������������������ݡ�
    List(const List<T> &);               //ϰ��7.4*���� ���ƹ��캯������ʵ��̳�ʵ��ʮ�ŷ���2��P62.Exp_19_2��һ����Ҫ��
    List<T> &operator=(const List<T> &); //ϰ��7.4*���� ��ֵ�����(=)��ע��ԭ������Ҫɾ���������ڴ�й©��

    void Reverse(); //ϰ��7.5*�����㷨�⣬ͨ��ָ�������ӵĸı䣬��������ת��
                    //ʵ���޷�ʵ�ֵ�ͬѧ����������һ������������ע��ԭ������Ҫɾ����

    List<T> operator+(const List<T> &L2); //ϰ��7.6 ���ء�+����������򻯲�����ֱ����ǰ��ƴ��
    List<T> Merge(const List<T> &L2);     //ȥ�غϲ��������鲢�ɷ���ȥ�ز���
    void Sort();                          //������������Ȼ��鲢����Ҫ����������
    void inforUnique();                   //ȥ�أ�����δ����ʱ��ȥ�ز��������㸴�Ӷ������ڲ��ҡ�
};

template <typename T>
List<T>::List()
{
    head = tail = new Node<T>();
}

template <typename T>
List<T>::~List()
{
    MakeEmpty();
    delete head;
}

template <typename T>
void List<T>::MakeEmpty()
{
    Node<T> *tempP;
    while (head->link != NULL)
    {
        tempP = head->link;
        head->link = tempP->link; //��ͷ����ĵ�һ���ڵ����������
        delete tempP;             //ɾ��(�ͷ�)���������Ľ��
    }
    tail = head; //��ͷָ�����βָ���ָ���ͷ��㣬��ʾ����
}

template <typename T>
Node<T> *List<T>::Find(T data)
{
    Node<T> *tempP = head->link;
    while (tempP != NULL && tempP->info != data)
        tempP = tempP->link;
    return tempP; //�����ɹ����ظý���ַ�����ɹ�����NULL
}

template <typename T>
int List<T>::Length()
{
    Node<T> *tempP = head->link;
    int count = 0;
    while (tempP != NULL)
    {
        tempP = tempP->link;
        count++;
    }
    return count;
}

template <typename T>
void List<T>::PrintList()
{
    Node<T> *tempP = head->link;
    while (tempP != NULL)
    {
        cout << tempP->info << '\t';
        tempP = tempP->link;
    }
    cout << endl;
}

template <typename T>
void List<T>::InsertFront(Node<T> *p)
{
    //��ͷ����
    p->link = head->link;
    head->link = p;
    if (tail == head)
        tail = p;
}

template <typename T>
void List<T>::InsertRear(Node<T> *p)
{
    //��β����
    p->link = tail->link;
    tail->link = p;
    tail = p;
}

template <typename T>
void List<T>::InsertOrder(Node<T> *p)
{
    //�������
    Node<T> *tempP = head->link, *tempQ = head; //tempQָ��tempPǰ���һ���ڵ�

    //˳����ң�����ɾ�����߲�����ĸ��Ӷ������ڲ���
    while (tempP != NULL)
    {
        if (p->info < tempP->info)
            break; //�ҵ�һ���Ȳ������Ľ�㣬��tempPָ��
        tempQ = tempP;
        tempP = tempP->link;
    }

    tempQ->InsertAfter(p); //����tempPָ����֮ǰ��tempQ֮��
    if (tail == tempQ)
        tail = tempQ->link; //��ֹ��һ
}

template <typename T>
Node<T> *List<T>::CreatNode(T data)
{
    //�����½ڵ�
    Node<T> *tempP = new Node<T>(data);
    return tempP;
}

template <typename T>
Node<T> *List<T>::DeleteNode(Node<T> *p)
{
    Node<T> *tempP = head;

    //˳����ң�ȷ��P�������У�����ɾ�����߲�����ĸ��Ӷ������ڲ���
    while (tempP->link != NULL && tempP->link != p)
        tempP = tempP->link;

    if (tempP->link == tail)
        tail = tempP; //��δ�ҵ���tempP->link=NULL

    return tempP->RemoveAfter(); //���������÷�����ʡһ������ָ�룬��InsertOrder�Ƚ�
    //��p������β������Ĵ�����RemoveAfter()������ˡ�
    //������ָ����ɾ���Ľ�㣬����δ�����Ա���������ɾ��������
}

// My Method
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

// ԭ��head�ǲ������ݵİ�������
template <typename T>
bool List<T>::DeleteNode(T data)
{
    bool del_flag = false;

    Node<T> *now_node_p = head;
    while (now_node_p->link)
    {
        if ((now_node_p->link)->info == data)
        {
            Node<T> *to_del = now_node_p->link;
            Node<T> *link_to = now_node_p->link->link;
            now_node_p->RemoveAfter();
            delete to_del;
            now_node_p->link = link_to;
            del_flag = true;
        }
        else
            now_node_p = now_node_p->link;

        if (now_node_p == NULL)
            break;
    }

    return del_flag;
}

template <typename T>
Node<T> *List<T>::FindK(int K) const
{
    Node<T> *now_node_link = head;
    for (int i = 1; i <= K; i++)
    {
        now_node_link = now_node_link->link;
    }
    return now_node_link;
}

template <typename T>
List<T>::List(const List<T> &tmpL)
{
    Node<T> *new_head = new Node<T>(tmpL.head->info);
    head = new_head;
    head->link = NULL;
    tail = head;

    Node<T> *now_old_node_p = tmpL.head->link;
    Node<T> *now_new_node_p = head;
    while (true)
    {
        Node<T> *tp = new Node<T>(now_old_node_p->info);
        InsertRear(tp);

        now_new_node_p->link = tp;
        now_new_node_p = now_new_node_p->link;
        now_old_node_p = now_old_node_p->link;
        if (now_old_node_p == NULL)
            break;
    }
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &tmpL)
{
    //delete all node
    Node<T> *node_now_p = head;
    while (true)
    {
        Node<T> *link_to = node_now_p->link;
        if (node_now_p)
            delete node_now_p;
        if (link_to == NULL)
            break;
        node_now_p = link_to;
    }

    //Copy from copy-construct-method
    Node<T> *new_head = new Node<T>(tmpL.head->info);
    head = new_head;
    head->link = NULL;
    tail = head;

    Node<T> *now_old_node_p = tmpL.head->link;
    Node<T> *now_new_node_p = head;
    while (true)
    {
        Node<T> *tp = new Node<T>(now_old_node_p->info);
        InsertRear(tp);

        now_new_node_p->link = tp;
        now_new_node_p = now_new_node_p->link;
        now_old_node_p = now_old_node_p->link;
        if (now_old_node_p == NULL)
            break;
    }
    return *this;
}
//////////////////////

template <typename T>
void List<T>::Reverse()
{
    if (head->link == NULL)
        return;
    if (head->link->link == NULL)
        return;

    Node<T> *front_node_p = head->link;
    Node<T> *after_node_p = head->link->link;

    tail = head->link;

    Node<T> *next_front = NULL;
    Node<T> *next_after = NULL;

    while (true)
    {
        Node<T> *next_front = after_node_p;
        Node<T> *next_after = after_node_p->link;
        after_node_p->link = front_node_p;
        front_node_p = next_front;
        after_node_p = next_after;
        if (after_node_p == NULL)
            break;
    }
    head->link = front_node_p;
    tail->link = NULL;
}

//////////////////////
template <typename T>
List<T> List<T>::operator+(const List<T> &tmpL)
{
    List<T> lsdis(*this);
    Node<T> *now_old_node_p = tmpL.head->link;
    Node<T> *now_new_node_p = lsdis.tail;
    while (true)
    {
        Node<T> *tp = new Node<T>(now_old_node_p->info);
        lsdis.InsertRear(tp);

        now_new_node_p->link = tp;
        now_new_node_p = now_new_node_p->link;
        now_old_node_p = now_old_node_p->link;
        if (now_old_node_p == NULL)
            break;
    }
    return lsdis;
}

//======== ������ģ�嶨����� ========//









#if 1

// ���Լ��Ĳ��Դ���
int main()
{
    Node<int> *P1, *P3;
    List<int> list1;
    int a[16] = {34, 12, 35, 17, 54, 12, 53, 63, 46, 23, 53, 63, 13, 52, 62, 73};
    for (int i = 0; i < 16; i++)
    {
        P1 = list1.CreatNode(a[i]);
        list1.InsertRear(P1);
    }
    list1.PrintList();
    cout << "list1 len: " << list1.Length() << endl;

    //TEST copy-construct-method
    List<int> list2(list1);
    list2.PrintList();
    cout << "list2 len: " << list2.Length() << endl;

    //TEST operator+
    List<int> list3;
    int b[16] = {999, 888, 777, 666, 777, 99999, 66666, 63, 46, 23, 53, 63, 13, 52, 62, 73};
    for (int i = 0; i < 16; i++)
    {
        P3 = list3.CreatNode(b[i]);
        list3.InsertRear(P3);
    }
    list3.PrintList();
    cout << "list3 len: " << list3.Length() << endl;
    list3 = list2;
    list3.PrintList();
    cout << "list3 len: " << list3.Length() << endl;

    //TEST delete-number
    list1.PrintList();
    cout << "list1 len: " << list1.Length() << endl;
    int num = 12;
    list1.DeleteNode(num);
    list1.PrintList();
    cout << "list1 len: " << list1.Length() << endl;

    //TEST reverse
    list2.Reverse();
    list2.PrintList();
    cout << "list2 len: " << list2.Length() << endl;

    //TEST +
    List<int> list4;
    list4=list1+list2;
    list4.PrintList();
    cout << "list4 len: " << list4.Length() << endl;


    //system("pause");
    return 0;
}
#endif






//���Դ���
#if 0

int main()
{
    Node<int> *P1;
    List<int> list1, list2;
    int a[16], i, j;
    cout << "������16������" << endl;
    for (i = 0; i < 16; i++)
        cin >> a[i]; //�������16������
    for (i = 0; i < 16; i++)
    {
        P1 = list1.CreatNode(a[i]);
        list1.InsertFront(P1); //��ǰ����list1

        P1 = list2.CreatNode(a[i]);
        list2.InsertRear(P1); //�������list2
    }

    list1.PrintList();
    cout << "list1���ȣ�" << list1.Length() << endl;

    list2.PrintList();

    cout << "������һ��Ҫ��ɾ��������" << endl;
    cin >> j;
    P1 = list1.Find(j);
    if (P1 != NULL)
    {
        P1 = list1.DeleteNode(P1);
        delete P1; //����7.5��Ҫ����Խ��ռ����ɾ���������غ�ʹ�øýڵ㣬�ɸ���Ϊ���Ƴ�����ֱ��ɾ����

        list1.PrintList();
        cout << "list1���ȣ�" << list1.Length() << endl;
    }
    else
        cout << "δ�ҵ�" << endl;
    list1.MakeEmpty(); //���list1

    for (i = 0; i < 16; i++)
    {
        P1 = list1.CreatNode(a[i]);
        list1.InsertOrder(P1); //���򴴽�list1
    }
    list1.PrintList();
    //system("pause");
    return 0;
}
#endif