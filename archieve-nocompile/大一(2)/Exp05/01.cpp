/* 类模板练手题：
  实验十五，范例2，实验教材P46. 
  将实验十题1的集合类，改造为模板类。
  
编程要求
1. 参考范例，自己手动完成模板类的修改。
2. 在main()函数中，元素类型分别设置为：
   int, double，char, 
   自定义一个枚举类型，自定义的MyString类，
   共5种元素类型，完成各成员函数模板的测试。
3. 定义模板类时的注意点
   注意1：若模板类前缀为template <typename eleT, int maxnum>
          则模板类实例化后，相当于 set<eleT, maxnum> 为完整的类名
   注意2：模板类重载<<时，只能在类内定义函数体。
          即不可以：在类内声明友元函数，然后在类外定义函数体。
4. 为提高可复用性，建议用函数模板定义测试函数，提高你的工作效率。

附：实验十集合“类Set”的属性详情参见实验教材P27，

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
	bool Member(eleT);        //判断元素elem是否为本集合的成员  
	ErrCode AddElem(eleT);    //将新元素elem加入本集合  
	void RmvElem(eleT);       //将元素elem从该集合中删去  
	void Copy(set);           //将实参所标识的集合中的所有元素复制到本集合中去  
	bool Equal(set);          //判断两集合各自包涵的元素是否完全相同  
	void print();             //显示本集合的所有元素  
	set Intersect(set);       //求本集合与第一参数所指出的集合的交，并且作为返回值  
	set Union(set);           //求本集合与第一参数所指出的集合的并，并且作为返回值  
	bool Contain(set);        //判断本集合是否包含实参所标识的集合中所有的元素 
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
	    	return noErr;      //集合中已有elem，不重复加入  
	if(num<maxnum)
	{  
		elements[num++]=elem;   
		return noErr;  
	}  
	else return overflow;      //数组已满 
} 

template <typename eleT,int maxnum>
void set<eleT,maxnum>::RmvElem(eleT elem)
{ 
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem)
	    {
	        for(;i<num-1;i++)  elements[i]=elements[i+1]; //当删除一个元素后，所有后继元素前移一位    
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
	if(num!=s.num) return false;       //元素个数不同  
	for(i=0;i<num;i++)   
	    if(!s.Member(elements[i])) 
	    	return false;       //有不同元素  
	return true; 
} 

template <typename eleT,int maxnum>
void set<eleT,maxnum>::print()
{
    cout<<"集合的元素包括："<<endl;  
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
        s.AddElem(elements[i]);  //这里忽略了集合可能溢出  
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
	
	//原范例的测试程序，运行体会后可删除，完成本次作业  
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
    cout<<"删除部分元素后："<<endl;  
    cout<<"s"; s.print();  
    cout<<"s1"; 
    s1.print();  
    cout<<"s2"; 
    s2.print(); 
    
    return 0; 
} 	