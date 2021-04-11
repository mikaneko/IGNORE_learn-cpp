/* ��ģ�������⣺
  ʵ��ʮ�壬����2��ʵ��̲�P46. 
  ��ʵ��ʮ��1�ļ����࣬����Ϊģ���ࡣ
  
���Ҫ��
1. �ο��������Լ��ֶ����ģ������޸ġ�
2. ��main()�����У�Ԫ�����ͷֱ�����Ϊ��
   int, double��char, 
   �Զ���һ��ö�����ͣ��Զ����MyString�࣬
   ��5��Ԫ�����ͣ���ɸ���Ա����ģ��Ĳ��ԡ�
3. ����ģ����ʱ��ע���
   ע��1����ģ����ǰ׺Ϊtemplate <typename eleT, int maxnum>
          ��ģ����ʵ�������൱�� set<eleT, maxnum> Ϊ����������
   ע��2��ģ��������<<ʱ��ֻ�������ڶ��庯���塣
          �������ԣ�������������Ԫ������Ȼ�������ⶨ�庯���塣
4. Ϊ��߿ɸ����ԣ������ú���ģ�嶨����Ժ����������Ĺ���Ч�ʡ�

����ʵ��ʮ���ϡ���Set������������μ�ʵ��̲�P27��

*/
#include<iostream> 
using namespace std; 

const int maxnum=20; 
enum ErrCode{noErr,overflow}; 

template <typename eleT,int maxnum>
class set
{  
	eleT elements[maxnum];  
	int num; 
public:  
	set(){num=0;}  
	bool Member(eleT);        //�ж�Ԫ��elem�Ƿ�Ϊ�����ϵĳ�Ա  
	ErrCode AddElem(eleT);    //����Ԫ��elem���뱾����  
	void RmvElem(eleT);       //��Ԫ��elem�Ӹü�����ɾȥ  
	void Copy(set);           //��ʵ������ʶ�ļ����е�����Ԫ�ظ��Ƶ���������ȥ  
	bool Equal(set);          //�ж������ϸ��԰�����Ԫ���Ƿ���ȫ��ͬ  
	void print();             //��ʾ�����ϵ�����Ԫ��  
	set Intersect(set);       //�󱾼������һ������ָ���ļ��ϵĽ���������Ϊ����ֵ  
	set Union(set);           //�󱾼������һ������ָ���ļ��ϵĲ���������Ϊ����ֵ  
	bool Contain(set);        //�жϱ������Ƿ����ʵ������ʶ�ļ��������е�Ԫ�� 
}; 


template <typename eleT,int maxnum>
bool set<eleT,maxnum>::Member(eleT elem)
{  
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem) 
	    	return true;  
	return false; 
} 

template <typename eleT,int maxnum>
ErrCode set<eleT,maxnum>::AddElem(eleT elem)
{  
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem) 
	    	return noErr;      //����������elem�����ظ�����  
	if(num<maxnum)
	{  
		elements[num++]=elem;   
		return noErr;  
	}  
	else return overflow;      //�������� 
} 

template <typename eleT,int maxnum>
void set<eleT,maxnum>::RmvElem(eleT elem)
{ 
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem)
	    {
	        for(;i<num-1;i++)  elements[i]=elements[i+1]; //��ɾ��һ��Ԫ�غ����к��Ԫ��ǰ��һλ    
	        num--;   
	    } 
} 

template <typename eleT,int maxnum>
void set<eleT,maxnum>::Copy(set s)
{
    int i;  
    for(i=0;i<s.num;i++) 
        elements[i]= s.elements[i];  
    num= s.num; 
} 

template <typename eleT,int maxnum>
bool set<eleT,maxnum>::Equal(set s)
{  
	int i;  
	if(num!=s.num) return false;       //Ԫ�ظ�����ͬ  
	for(i=0;i<num;i++)   
	    if(!s.Member(elements[i])) 
	    	return false;       //�в�ͬԪ��  
	return true; 
} 

template <typename eleT,int maxnum>
void set<eleT,maxnum>::print()
{
    cout<<"���ϵ�Ԫ�ذ�����"<<endl;  
    int i;  
    for(i=0;i<num;i++) 
        cout<<elements[i]<<"  ";  
    cout<<endl; 
} 

template <typename eleT,int maxnum>
set<eleT,maxnum> set<eleT,maxnum>::Intersect(set s1)
{  
	int i,j; 
	set s;   
	for(i=0;i<num;i++)   
	    for(j=0;j<s1.num;j++)    
	        if(elements[i]==s1.elements[j])
	        {
	            s.elements[s.num++]=elements[i];     
	            break;    
	        }  
	return s; 
} 

template <typename eleT,int maxnum>
set<eleT,maxnum> set<eleT,maxnum>::Union(set s1)
{
    int i; 
    set s;   
    s.Copy(s1);  
    for(i=0;i<num;i++)   
        s.AddElem(elements[i]);  //��������˼��Ͽ������  
    return s; 
} 

template <typename eleT,int maxnum>
bool set<eleT,maxnum>::Contain(set s)
{ 
	int i;  
	for(i=0;i<s.num;i++)   
	    if(!Member(s.elements[i])) 
	    	return false;  
	return true; 
} 
 
int main()  
{
	int i;
	
	//ԭ�����Ĳ��Գ������������ɾ������ɱ�����ҵ  
	char ch[30]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d'};  
	set<char,maxnum> s,s1,s2,s3,s4;  
	ErrCode b;  
	for(i=0;i<10;i++)
	{
	    b=s.AddElem(ch[i]);   
	    b=s1.AddElem(ch[2*i]);   
	    b=s2.AddElem(ch[3*i]);  
	}  
    cout<<"s"; 
    s.print();  
    cout<<"s1"; 
    s1.print();  
    cout<<"s2"; 
    s2.print();  
    s3=s.Intersect(s1);  
    s4=s.Union(s1);  
    cout<<"s3"; 
    s3.print();  
    cout<<"s4"; 
    s4.print(); 
    if(s3.Contain(s4)) cout<<"Set s3 contains s4"<<endl;  
    else cout<<"Set s3 do not contains s4"<<endl;  
    
    if(s4.Contain(s3)) cout<<"Set s4 contains s3"<<endl;  
    else cout<<"Set s4 do not contains s3"<<endl;  
    	
    if(s3.Equal(s4)) cout<<"Set s3=s4"<<endl;  
    else cout<<"Set s3!=s4"<<endl;  
    	
    for(i=6;i<10;i++)
    {
    	s.RmvElem(ch[i]);   
    	s1.RmvElem(ch[i]);   
    	s2.RmvElem(ch[i]);  
    }  
    cout<<"ɾ������Ԫ�غ�"<<endl;  
    cout<<"s"; s.print();  
    cout<<"s1"; 
    s1.print();  
    cout<<"s2"; 
    s2.print(); 
    
    return 0; 
} 	