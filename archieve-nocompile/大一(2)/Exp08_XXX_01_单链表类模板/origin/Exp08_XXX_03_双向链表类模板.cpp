/*
7.2.3*双向链表为提高内容。
根据习题7.7的要求，完善已给出双向链表实现的线性表类模板，

    定义了一个类模板，可以适用于不同的列表元素类型。
    因此，用类模板定义，更具通用性。
    
已给课本P240 例7.7，双向链表类模板。
双向链表的结点采用类，与结点有关的基本操作都作为结点类的成员函数。
对双向链表整体的操作则作为链表类的成员函数，包括:
清空链表、查找数据、计算链表长度、打印链表数据、移除指定结点
向后生成链表等等。
注：
    范例中删除指定结点的操作没有完全封装在类内，可自行修改为在类内将删除操作完全封装。

编程要求：
-    1 习题7.7 将两个有序的双向链表合并为一个有序的双向链表。
       可重载为是否去除数据域相同的结点的两个操作函数。 
-    2 测试：完成添加的成员函数模板的测试。
*/
#include<iostream>
#include<string>
using namespace std;


template<typename T> class DblList;   //前向引用声明  


//======== 头结点类模板定义开始 ========//
//首先看结点组织，采用结点类，凡与结点数据和指针操作有关函数作为成员函数 
template<typename T> class DblNode
{
    T info;                    //数据域  
    DblNode<T> *llink,*rlink;  //前驱（左链）、后继（右链）指针 
public:
    DblNode(T data);  
    DblNode();  
    T Getinfo(){return info;}  
    friend class DblList<T>; 
    //以List为友元类，List可直接访问Node的私有成员，与结构一样方便，但更安全 
}; 

template<typename T> DblNode<T>::DblNode()
{   llink=rlink=NULL; } 
	
template<typename T> DblNode<T>::DblNode(T data)
{   info=data;  llink=NULL;  rlink=NULL; } 

//======== 头结点类模板定义完成 ========//

	

//======== 链表类模板定义开始 ========//
//再定义链表类，选择常用操作：包括建立有序链表、搜索遍历、插入、删除、取数据等 
template<typename T>class DblList
{
    DblNode<T> *head,*current; 
public:
    DblList();  
    ~DblList();  
    
    void InsertRear(const T & data);  
    DblNode<T>* Remove(DblNode<T>* p);  
    void Print();  
    int Length();                            //计算链表长度  
    DblNode<T> *Find(T data);                //搜索数据与定值相同的结点  
    void MakeEmpty();                        //清空链表  
    //其它操作 
}; 

template<typename T> DblList<T>::DblList()
{
    //建立表头结点  
    head=new DblNode<T>();  
    head->rlink=head->llink=head;  
    current=NULL; 
} 

template<typename T> DblList<T>::~DblList()
{
    MakeEmpty();                             //清空链表  
    delete head; 
} 

template<typename T> void DblList<T>::MakeEmpty()
{
    DblNode<T> *tempP;  
    
    while(head->rlink!=head)
    {
    	
        tempP=head->rlink;   
        head->rlink=tempP->rlink;          //把头结点后的第一个节点从链中脱离   
        tempP->rlink->llink=head;          //处理左指针   
        delete tempP;                      //删除(释放)脱离下来的结点  
    }  
    current=NULL;                          //current指针恢复 
} 

template<typename T> void DblList<T>::InsertRear(const T & data)
{
    //新节点在链尾  
    current=new DblNode<T>;  
    current->info=data;  
    current->rlink=head;                   //注意次序  
    current->llink=head->llink;  
    head->llink->rlink=current;  
    head->llink=current;                   //最后做 
} 

template<typename T> DblNode<T>* DblList<T>::Remove(DblNode<T>* p)
{
    current=head->rlink;  
    while(current!=head&&current!=p) current=current->rlink;  
    if(current==head) current=NULL;  
    else                                   //摘下结点 
    {
    	p->llink->rlink=p->rlink;   
    	p->rlink->llink=p->llink;   
    	p->rlink=p->llink=NULL;  
    }  
    return current; 
    //返回了指定待删除的结点，而并未在类成员函数中完成删除操作。 
} 
 
template<typename T> DblNode<T>* DblList<T>::Find(T data)
{
    current=head->rlink;  
    while(current!=head&&current->info!=data) current=current->rlink;  
    if(current==head) current=NULL;  
    return current; 
} 

template<typename T> void DblList<T>::Print()
{
    current=head->rlink;  
    while(current!=head)
    {
        cout<<current->info<<'\t';   
        current=current->rlink;  
    }  
    cout<<endl; 
} 

template<typename T> int DblList<T>::Length()
{
    int count=0;  
    current=head->rlink; 
    while(current!=head)
    {
         count++;   
         current=current->rlink;  
    }  
    return count; 
} 

int main()
{
    DblList<int> Dbl1,Dbl2;  
    DblNode<int> *tp=NULL;  
    
    int i,a[11]={19,11,17,13,7,2,3,5,23,31,29};  
    for(i=0;i<11;i++) Dbl1.InsertRear(a[i]);
      
    cout<<"双向链表长度："<<Dbl1.Length()<<endl;  
    Dbl1.Print();  
    
    tp=Dbl1.Find(7);  
    if(tp) cout<<"查到的结点数据为："<<tp->Getinfo()<<" 清除"<<endl;  
    delete Dbl1.Remove(tp);          //需要类外对结点空间进行删除！
      
    cout<<"双向链表长度："<<Dbl1.Length()<<endl;  
    Dbl1.Print();  
    cout<<"清空链表"<<endl;  
    
    Dbl1.MakeEmpty();  
    cout<<"双向链表长度："<<Dbl1.Length()<<endl;  
    return 0; 
} 
	    	 