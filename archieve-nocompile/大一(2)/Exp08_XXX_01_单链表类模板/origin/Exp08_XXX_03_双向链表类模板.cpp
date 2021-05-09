/*
7.2.3*˫������Ϊ������ݡ�
����ϰ��7.7��Ҫ�������Ѹ���˫������ʵ�ֵ����Ա���ģ�壬

    ������һ����ģ�壬���������ڲ�ͬ���б�Ԫ�����͡�
    ��ˣ�����ģ�嶨�壬����ͨ���ԡ�
    
�Ѹ��α�P240 ��7.7��˫��������ģ�塣
˫������Ľ������࣬�����йصĻ�����������Ϊ�����ĳ�Ա������
��˫����������Ĳ�������Ϊ������ĳ�Ա����������:
��������������ݡ����������ȡ���ӡ�������ݡ��Ƴ�ָ�����
�����������ȵȡ�
ע��
    ������ɾ��ָ�����Ĳ���û����ȫ��װ�����ڣ��������޸�Ϊ�����ڽ�ɾ��������ȫ��װ��

���Ҫ��
-    1 ϰ��7.7 �����������˫������ϲ�Ϊһ�������˫������
       ������Ϊ�Ƿ�ȥ����������ͬ�Ľ����������������� 
-    2 ���ԣ������ӵĳ�Ա����ģ��Ĳ��ԡ�
*/
#include<iostream>
#include<string>
using namespace std;


template<typename T> class DblList;   //ǰ����������  


//======== ͷ�����ģ�嶨�忪ʼ ========//
//���ȿ������֯�����ý���࣬���������ݺ�ָ������йغ�����Ϊ��Ա���� 
template<typename T> class DblNode
{
    T info;                    //������  
    DblNode<T> *llink,*rlink;  //ǰ��������������̣�������ָ�� 
public:
    DblNode(T data);  
    DblNode();  
    T Getinfo(){return info;}  
    friend class DblList<T>; 
    //��ListΪ��Ԫ�࣬List��ֱ�ӷ���Node��˽�г�Ա����ṹһ�����㣬������ȫ 
}; 

template<typename T> DblNode<T>::DblNode()
{   llink=rlink=NULL; } 
	
template<typename T> DblNode<T>::DblNode(T data)
{   info=data;  llink=NULL;  rlink=NULL; } 

//======== ͷ�����ģ�嶨����� ========//

	

//======== ������ģ�嶨�忪ʼ ========//
//�ٶ��������࣬ѡ���ò����������������������������������롢ɾ����ȡ���ݵ� 
template<typename T>class DblList
{
    DblNode<T> *head,*current; 
public:
    DblList();  
    ~DblList();  
    
    void InsertRear(const T & data);  
    DblNode<T>* Remove(DblNode<T>* p);  
    void Print();  
    int Length();                            //����������  
    DblNode<T> *Find(T data);                //���������붨ֵ��ͬ�Ľ��  
    void MakeEmpty();                        //�������  
    //�������� 
}; 

template<typename T> DblList<T>::DblList()
{
    //������ͷ���  
    head=new DblNode<T>();  
    head->rlink=head->llink=head;  
    current=NULL; 
} 

template<typename T> DblList<T>::~DblList()
{
    MakeEmpty();                             //�������  
    delete head; 
} 

template<typename T> void DblList<T>::MakeEmpty()
{
    DblNode<T> *tempP;  
    
    while(head->rlink!=head)
    {
    	
        tempP=head->rlink;   
        head->rlink=tempP->rlink;          //��ͷ����ĵ�һ���ڵ����������   
        tempP->rlink->llink=head;          //������ָ��   
        delete tempP;                      //ɾ��(�ͷ�)���������Ľ��  
    }  
    current=NULL;                          //currentָ��ָ� 
} 

template<typename T> void DblList<T>::InsertRear(const T & data)
{
    //�½ڵ�����β  
    current=new DblNode<T>;  
    current->info=data;  
    current->rlink=head;                   //ע�����  
    current->llink=head->llink;  
    head->llink->rlink=current;  
    head->llink=current;                   //����� 
} 

template<typename T> DblNode<T>* DblList<T>::Remove(DblNode<T>* p)
{
    current=head->rlink;  
    while(current!=head&&current!=p) current=current->rlink;  
    if(current==head) current=NULL;  
    else                                   //ժ�½�� 
    {
    	p->llink->rlink=p->rlink;   
    	p->rlink->llink=p->llink;   
    	p->rlink=p->llink=NULL;  
    }  
    return current; 
    //������ָ����ɾ���Ľ�㣬����δ�����Ա���������ɾ�������� 
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
      
    cout<<"˫�������ȣ�"<<Dbl1.Length()<<endl;  
    Dbl1.Print();  
    
    tp=Dbl1.Find(7);  
    if(tp) cout<<"�鵽�Ľ������Ϊ��"<<tp->Getinfo()<<" ���"<<endl;  
    delete Dbl1.Remove(tp);          //��Ҫ����Խ��ռ����ɾ����
      
    cout<<"˫�������ȣ�"<<Dbl1.Length()<<endl;  
    Dbl1.Print();  
    cout<<"�������"<<endl;  
    
    Dbl1.MakeEmpty();  
    cout<<"˫�������ȣ�"<<Dbl1.Length()<<endl;  
    return 0; 
} 
	    	 