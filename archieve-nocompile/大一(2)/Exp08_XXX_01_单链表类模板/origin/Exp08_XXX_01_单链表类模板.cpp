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
               ɾ������������������Ϊָ��ֵ�Ľ�㣻
               ȡ�������е�K��Ԫ��(��1��ʼ����)�� 

-    2 ϰ��7.4 Ϊ��������ģ������:
               ������ƹ��캯��
               �����ֵ�������=�� 

-    3 ϰ��7.5*��Ϊ��������ģ�����һ����������ת�ĳ�Ա������Ҫ��
               ��ɾ��ԭ��㣬
               Ҳ����һ��������ȡ����
               ����ͨ���ı�ָ��������ӷ�������ת���� 
       �㷨��ʾ��������Ϊ��ͷ����������Ȼ���յ�ͷ��㣬
               Ȼ�����δӵ�һ����㿪ʼ����ͷ��β����ժ�½�㣬
               ͨ��ָ����Ľ�����������ÿ������ָ����ָ��ԭǰһ�����
               �����ת�������ӵ������ͷ���� 
       ע����ɸ��㷨�����ѵ�ͬѧ����ʵ���½�һ����ת����ȡ��ԭ������㷨��

-    4 ϰ��7.6*Ϊ���������ء�+���������ʵ�������������������ӡ�
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

#include<iostream>
#include<iomanip>
using namespace std;


template<typename T>class List;   //ǰ���������� 

//======== ͷ�����ģ�嶨�忪ʼ ========//
//���ȿ������֯�����ý���࣬���������ݺ�ָ������йغ�����Ϊ��Ա���� 
template<typename T>class Node
{
    T info;           //������Ϊ�Ӷ���ʵ���̳�P62.Exp_19_2������ָ�룬����������һ�㡿  
    Node<T> *link;    //ָ����ע�������ʽ�����������ǲ���������ģ��ʵ����Ϊ�� 
public:
    Node();                           //����ͷ���Ĺ��캯��  
    Node(const T & data);             //����һ����Ĺ��캯��  
    void InsertAfter(Node<T>* P);     //�ڵ�ǰ�������һ�����  
    Node<T>* RemoveAfter();           //ɾ����ǰ���ĺ�̽�㣬���ظý�㱸��  
    friend class List<T>;             
    //��ListΪ��Ԫ�࣬List��ֱ�ӷ���Node��˽�г�Ա����ṹһ�����㣬������ȫ 
};

template <typename T> Node<T>::Node()
{   link=NULL;} 
    
template <typename T> Node<T>::Node(const T & data)
{   info=data;  link=NULL; } 

template<typename T>void Node<T>::InsertAfter(Node<T>* p)
{   p->link=link;  link=p; } 

template<typename T>Node<T>* Node<T>::RemoveAfter()
{
    Node<T>* tempP=link;  
    if(link==NULL) tempP=NULL;                 //������β,�����޽��  
    else link=tempP->link;  
    return tempP; 
} 
//======== ͷ�����ģ�嶨����� ========//



//======== ������ģ�嶨�忪ʼ ========//
//�ٶ��������࣬ѡ���ò����������������������������������롢ɾ����ȡ���ݵ� 
template<typename T>class List
{
private:      
    Node<T> *head,*tail;       //����ͷָ���βָ�� 
public: 
    List();                    //���캯��������ͷ���(������)  
    ~List();                   //��������  
    
    void MakeEmpty();          //���һ������ֻ���ͷ���  
    Node<T>* Find(T data);     //������������data��ͬ�Ľ�㣬���ظý��ĵ�ַ  
    int Length();              //���㵥������  
    void PrintList();          //��ӡ�����������     
    void InsertFront(Node<T>* p);        //��������ǰ���������ڱ�ͷ����һ�����  
    void InsertRear(Node<T>* p);         //������������������ڱ�β���һ�����  
    void InsertOrder(Node<T> *p);        //��������������  
    Node<T>*CreatNode(T data);           //����һ�����(�������)  
    Node<T>*DeleteNode(Node<T>* p);      //ɾ��ָ����㣬 
    
    
    //��������
    bool DeleteNode( T data);           //ϰ��7.3 ɾ������������������Ϊָ��ֵ�Ľ�㣬���㸴�Ӷ������ڲ��ҡ�
    Node<T>* FindK(int K) const;        //ϰ��7.3 ȡ�������е�K��Ԫ��(��1��ʼ����),T����Ϊint���ʲ�������
    
    //һ�������Ḵ�ƹ������ɻ�ʹ�õ�ʽ������Ҫʵ��+���أ��������������������ݡ�
    List(const List<T> &);              //ϰ��7.4*���� ���ƹ��캯������ʵ��̳�ʵ��ʮ�ŷ���2��P62.Exp_19_2��һ����Ҫ��
    List<T>& operator=(const List<T> &);//ϰ��7.4*���� ��ֵ�����(=)��ע��ԭ������Ҫɾ���������ڴ�й©��
    
    void Reverse();                     //ϰ��7.5*�����㷨�⣬ͨ��ָ�������ӵĸı䣬��������ת��
                                        //ʵ���޷�ʵ�ֵ�ͬѧ����������һ������������ע��ԭ������Ҫɾ����
                                        
    List<T> operator+(const List<T> &L2);//ϰ��7.6 ���ء�+����������򻯲�����ֱ����ǰ��ƴ��
    List<T> Merge(const List<T> &L2);    //ȥ�غϲ��������鲢�ɷ���ȥ�ز��� 
    void Sort();                         //������������Ȼ��鲢����Ҫ����������
    void inforUnique();                  //ȥ�أ�����δ����ʱ��ȥ�ز��������㸴�Ӷ������ڲ��ҡ�
}; 


template<typename T>List<T>::List()
{   head=tail=new Node<T>(); } 

template<typename T>List<T>::~List()
{   MakeEmpty();  delete head; } 

template<typename T>void List<T>::MakeEmpty()
{
    Node<T> *tempP;  
    while(head->link!=NULL)
    {
        tempP=head->link;   
        head->link=tempP->link;  //��ͷ����ĵ�һ���ڵ����������   
        delete tempP;            //ɾ��(�ͷ�)���������Ľ�� 
    }
    tail=head;                   //��ͷָ�����βָ���ָ���ͷ��㣬��ʾ���� 
} 

template<typename T> Node<T>* List<T>::Find(T data)
{
    Node<T> *tempP=head->link;  
    while(tempP!=NULL&&tempP->info!=data) 
        tempP=tempP->link;  
    return tempP;        //�����ɹ����ظý���ַ�����ɹ�����NULL 
} 

template<typename T>int List<T>::Length()
{
    Node<T>* tempP=head->link;  
    int count=0;  
    while(tempP!=NULL)
    {
        tempP=tempP->link;   
        count++;  
    }  
    return count; 
}

template<typename T>void List<T>::PrintList()
{
    Node<T>* tempP=head->link;  
    while(tempP!=NULL)
    {
        cout<<tempP->info<<'\t';   
        tempP=tempP->link;  
    }  
    cout<<endl; 
} 

template<typename T>void List<T>::InsertFront(Node<T> *p)
{
    //��ͷ����  
    p->link=head->link;  
    head->link=p;  
    if(tail==head) tail=p; 
} 

template<typename T>void List<T>::InsertRear(Node<T> *p)
{
    //��β����  
    p->link=tail->link;  
    tail->link=p;  
    tail=p; 
} 

template<typename T>void List<T>::InsertOrder(Node<T> *p)
{
    //�������  
    Node<T> *tempP=head->link,*tempQ=head;   //tempQָ��tempPǰ���һ���ڵ�
    
    //˳����ң�����ɾ�����߲�����ĸ��Ӷ������ڲ���  
    while(tempP!=NULL)
    {
        if(p->info<tempP->info) break;       //�ҵ�һ���Ȳ������Ľ�㣬��tempPָ��   
        tempQ=tempP;   
        tempP=tempP->link;  
    }
    
    tempQ->InsertAfter(p);                   //����tempPָ����֮ǰ��tempQ֮��  
    if(tail==tempQ) tail=tempQ->link;        //��ֹ��һ
} 

template<typename T>Node<T>* List<T>::CreatNode(T data)
{
    //�����½ڵ�  
    Node<T>*tempP=new Node<T>(data);  
    return tempP; 
} 

template<typename T>Node<T>* List<T>::DeleteNode(Node<T>* p)
{
    Node<T>* tempP=head;  
    
    //˳����ң�ȷ��P�������У�����ɾ�����߲�����ĸ��Ӷ������ڲ���
    while(tempP->link!=NULL&&tempP->link!=p) tempP=tempP->link;  
    
    if(tempP->link==tail) tail=tempP;   //��δ�ҵ���tempP->link=NULL
    
    return tempP->RemoveAfter();      //���������÷�����ʡһ������ָ�룬��InsertOrder�Ƚ� 
    //��p������β������Ĵ�����RemoveAfter()������ˡ�
    //������ָ����ɾ���Ľ�㣬����δ�����Ա���������ɾ�������� 
} 



//======== ������ģ�嶨����� ========//
//���Դ���
int main()
{
    Node<int> * P1;  
    List<int> list1,list2;  
    int a[16],i,j;  
    cout<<"������16������"<<endl;  
    for(i=0;i<16;i++)  cin>>a[i];     //�������16������  
    for(i=0;i<16;i++)
    {
        P1=list1.CreatNode(a[i]);   
        list1.InsertFront(P1);        //��ǰ����list1   
         
        P1=list2.CreatNode(a[i]);   
        list2.InsertRear(P1);         //�������list2  
    }  
    
    list1.PrintList();  
    cout<<"list1���ȣ�"<<list1.Length()<<endl;  
    
    list2.PrintList(); 
    
    cout<<"������һ��Ҫ��ɾ��������"<<endl;     
    cin>>j;  
    P1=list1.Find(j);  
    if(P1!=NULL)
    {
        P1=list1.DeleteNode(P1);   
        delete P1;                    //����7.5��Ҫ����Խ��ռ����ɾ���������غ�ʹ�øýڵ㣬�ɸ���Ϊ���Ƴ�����ֱ��ɾ����
        
        list1.PrintList();   
        cout<<"list1���ȣ�"<<list1.Length()<<endl;   
    }  
    else cout<<"δ�ҵ�"<<endl;  
    list1.MakeEmpty();                //���list1   
    
    for(i=0;i<16;i++)
    {
        P1=list1.CreatNode(a[i]);   
        list1.InsertOrder(P1);        //���򴴽�list1  
    }  
    list1.PrintList();  
    return 0; 
}     
