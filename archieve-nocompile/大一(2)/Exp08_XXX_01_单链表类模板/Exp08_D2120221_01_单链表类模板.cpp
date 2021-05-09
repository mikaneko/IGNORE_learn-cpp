/* 
本程序为课本范例7.5，原本即可执行。
请学习链表的基本操作后，自行 - 复现！复现！！复现！！
然后按作业要求增加链表功能。
并设计测试程序测试新增功能。

    定义了一个类模板，可以适用于不同的列表元素类型。
    因此，用类模板定义，更具通用性。
    已给课本P233 例7.5，单链表类模板。

    为单链表的结点定义结点类，与结点有关的基本操作都作为结点类的成员函数。包括：
 -  生成头结点的无参构造函数，生成一般结点的有参构造函数
 -  在当前结点后插入一个结点，删除当前结点的后继结点

    对链表整体的操作则作为链表类的成员函数，包括:
 -  清空链表、查找数据、计算单链表长度、打印链表数据、移除指定结点
 -  向前生成链表、向后生成链表、按升序生成链表等等 
 
注：
    范例中删除指定结点的操作没有完全封装在类内，
    可自行修改为在类内将删除操作完全封装。
    
编程要求：
-    1 习题7.3 给单链表类模板增加两个成员函数：
               1.删除链表中所有数据域为指定值的结点；    *********  ok  ********
               2.取出链表中第K个元素(从1开始计数)。     *********  ok  ********

-    2 习题7.4 为单链表类模板增加:
               （深）复制构造函数                     *********  ok  ********
               （深）赋值运算符（=）                  *********  ok  ********

-    3 习题7.5*试为单链表类模板设计一个将链表逆转的成员函数。要求：   *********  ok  ********
               不删除原结点，                           
               也不另建一个链表来取代，
               而是通过改变指针域的链接方向来逆转链表 
       算法提示：本链表为有头结点链表，首先缓存空的头结点，
               然后依次从第一个结点开始，从头向尾依次摘下结点，
               通过指针域的交换操作，将每个结点的指针域指向原前一个结点
               最后将逆转后的链表接到缓存的头结点后。 
       注：完成该算法有困难的同学，可实现新建一个逆转链表取代原链表的算法。

-    4 习题7.6*为单链表重载“+”运算符，实现两个单链表对象的连接。  *********  ok  ********
               基本要求，是单纯完成两个链表的前后拼接成一个新的大链表。
               若提高要求，则可完成去除数据域相同的结点的+运算。  
               注意内存空间的需求。

-    5 测试：完成添加的各成员函数模板的测试。

注：
-   编程要求1较简单，所有人都可以自行完成。
-   编程要求2是实验教程实验十九范例2，P62.Exp_19_2的一个简化要求。注意范例7.5与Exp_19_2的异同。
    模仿并简单修改即可完成。
    
-   *标志为学有余力的同学准备。
-   编程要求3同自定义string类一样，是各大厂经典面试题，网络上各种范例铺天盖地，
    模仿修改以适合本次实验要求————学为己用。
-   编程要求4提示，若为去重功能实现简便，可分别对两个单链表：先排序，后归并。
    无序链表的去重算法实现也不复杂，但执行时计算复杂度较高。
-   新增的部分功能，可在测试阶段仅声明，或先定义一个空函数，逐步增加完善功能。    
*/

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class List; //前向引用声明

//======== 头结点类模板定义开始 ========//
//首先看结点组织，采用结点类，凡与结点数据和指针操作有关函数作为成员函数
template <typename T>
class Node
{
    T info;        //数据域为子对象【实践教程P62.Exp_19_2采用了指针，操作更复杂一层】
    Node<T> *link; //指针域，注意结点类格式，尖括号中是参数名表，类模板实例化为类
public:
    Node();                       //生成头结点的构造函数
    Node(const T &data);          //生成一般结点的构造函数
    void InsertAfter(Node<T> *P); //在当前结点后插入一个结点
    Node<T> *RemoveAfter();       //删除当前结点的后继结点，返回该结点备用
    friend class List<T>;
    //以List为友元类，List可直接访问Node的私有成员，与结构一样方便，但更安全
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
        tempP = NULL; //已在链尾,后面无结点
    else
        link = tempP->link;
    return tempP;
}
//======== 头结点类模板定义完成 ========//

//======== 链表类模板定义开始 ========//
//再定义链表类，选择常用操作：包括建立有序链表、搜索遍历、插入、删除、取数据等
template <typename T>
class List
{
private:
    Node<T> *head, *tail; //链表头指针和尾指针
public:
    List();  //构造函数，生成头结点(空链表)
    ~List(); //析构函数

    void MakeEmpty();                //清空一个链表，只余表头结点
    Node<T> *Find(T data);           //搜索数据域与data相同的结点，返回该结点的地址
    int Length();                    //计算单链表长度
    void PrintList();                //打印链表的数据域
    void InsertFront(Node<T> *p);    //可用来向前生成链表，在表头插入一个结点
    void InsertRear(Node<T> *p);     //可用来向后生成链表，在表尾添加一个结点
    void InsertOrder(Node<T> *p);    //按升序生成链表
    Node<T> *CreatNode(T data);      //创建一个结点(孤立结点)
    Node<T> *DeleteNode(Node<T> *p); //删除指定结点，

    //新增函数
    bool DeleteNode(T data); //习题7.3 删除链表中所有数据域为指定值的结点，运算复杂度体现在查找。aaa

    Node<T> *FindK(int K) const; //习题7.3 取出链表中第K个元素(从1开始计数),T可能为int，故不可重载

    //一般链表不会复制构造生成或使用等式，但若要实现+重载，则定义这两个操作后更便捷。
    List(const List<T> &);               //习题7.4*增加 复制构造函数，是实验教程实验十九范例2，P62.Exp_19_2的一个简化要求。
    List<T> &operator=(const List<T> &); //习题7.4*增加 赋值运算符(=)，注意原链表需要删除，否则内存泄漏。

    void Reverse(); //习题7.5*经典算法题，通过指针域连接的改变，将链表逆转。
                    //实在无法实现的同学，可新生成一个逆序链表，但注意原链表需要删除。

    List<T> operator+(const List<T> &L2); //习题7.6 重载“+”运算符，简化操作，直接做前后拼接
    List<T> Merge(const List<T> &L2);     //去重合并，排序后归并可方便去重操作
    void Sort();                          //排序，若先排序，然后归并，需要排序函数辅助
    void inforUnique();                   //去重，假设未排序时的去重操作，运算复杂度体现在查找。
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
        head->link = tempP->link; //把头结点后的第一个节点从链中脱离
        delete tempP;             //删除(释放)脱离下来的结点
    }
    tail = head; //表头指针与表尾指针均指向表头结点，表示空链
}

template <typename T>
Node<T> *List<T>::Find(T data)
{
    Node<T> *tempP = head->link;
    while (tempP != NULL && tempP->info != data)
        tempP = tempP->link;
    return tempP; //搜索成功返回该结点地址，不成功返回NULL
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
    //链头插入
    p->link = head->link;
    head->link = p;
    if (tail == head)
        tail = p;
}

template <typename T>
void List<T>::InsertRear(Node<T> *p)
{
    //链尾插入
    p->link = tail->link;
    tail->link = p;
    tail = p;
}

template <typename T>
void List<T>::InsertOrder(Node<T> *p)
{
    //升序插入
    Node<T> *tempP = head->link, *tempQ = head; //tempQ指向tempP前面的一个节点

    //顺序查找，链表删除或者插入结点的复杂度体现在查找
    while (tempP != NULL)
    {
        if (p->info < tempP->info)
            break; //找第一个比插入结点大的结点，由tempP指向
        tempQ = tempP;
        tempP = tempP->link;
    }

    tempQ->InsertAfter(p); //插在tempP指向结点之前，tempQ之后
    if (tail == tempQ)
        tail = tempQ->link; //防止差一
}

template <typename T>
Node<T> *List<T>::CreatNode(T data)
{
    //建立新节点
    Node<T> *tempP = new Node<T>(data);
    return tempP;
}

template <typename T>
Node<T> *List<T>::DeleteNode(Node<T> *p)
{
    Node<T> *tempP = head;

    //顺序查找，确认P在链表中，链表删除或者插入结点的复杂度体现在查找
    while (tempP->link != NULL && tempP->link != p)
        tempP = tempP->link;

    if (tempP->link == tail)
        tail = tempP; //若未找到则tempP->link=NULL

    return tempP->RemoveAfter(); //本函数所用方法可省一个工作指针，与InsertOrder比较
    //对p处于链尾的情况的处理在RemoveAfter()内完成了。
    //返回了指定待删除的结点，而并未在类成员函数中完成删除操作。
}

// My Method
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

// 原来head是不存数据的啊，我晕
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

//======== 链表类模板定义完成 ========//









#if 1

// 我自己的测试代码
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






//测试代码
#if 0

int main()
{
    Node<int> *P1;
    List<int> list1, list2;
    int a[16], i, j;
    cout << "请输入16个整数" << endl;
    for (i = 0; i < 16; i++)
        cin >> a[i]; //随机输入16个整数
    for (i = 0; i < 16; i++)
    {
        P1 = list1.CreatNode(a[i]);
        list1.InsertFront(P1); //向前生成list1

        P1 = list2.CreatNode(a[i]);
        list2.InsertRear(P1); //向后生成list2
    }

    list1.PrintList();
    cout << "list1长度：" << list1.Length() << endl;

    list2.PrintList();

    cout << "请输入一个要求删除的整数" << endl;
    cin >> j;
    P1 = list1.Find(j);
    if (P1 != NULL)
    {
        P1 = list1.DeleteNode(P1);
        delete P1; //范例7.5需要类外对结点空间进行删除！若返回后不使用该节点，可改造为由移除函数直接删除。

        list1.PrintList();
        cout << "list1长度：" << list1.Length() << endl;
    }
    else
        cout << "未找到" << endl;
    list1.MakeEmpty(); //清空list1

    for (i = 0; i < 16; i++)
    {
        P1 = list1.CreatNode(a[i]);
        list1.InsertOrder(P1); //升序创建list1
    }
    list1.PrintList();
    //system("pause");
    return 0;
}
#endif