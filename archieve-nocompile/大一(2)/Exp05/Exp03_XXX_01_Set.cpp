/*
�Ѹ������ϡ���Set���Ķ�����������������μ�ʵ��̲�P27��
������ҵ��ɹ��ܣ����ø�Set�����������ϵĽ�����
��������ҵΪSet��Ŀͻ���������Set��������й��ܡ�

��Ҫ��
1. �������������ϵĽ�����������ָ��ͬ�����������ϵ�Ԫ�������ɵ��¼��ϡ�
   �Դ���������ı��ļ���d1.txt��d2.txt���е������������������ǵĽ�����
   ��������Ľ���д����һ���ı��ļ� Exp03_ѧ��_03_set.txt��
   ��ÿ��4�������ĸ�ʽ����ԭʼ�����ļ�d1.txt��d2.txt�е����ݱ��ֲ��䡣
2. ���裺ԭʼ�����ļ�d1.txt��d2.txt�Ѵ��ڣ��������ݼ����ģ��Գ�����ԣ�
   �ļ��е�������Ŀ���꣬����������20��������������֮�������ɿո񡢻��߻س����м����
   ѡ����ʵĶ��뷽ʽ������ѭ���ķ�ʽ��
   ��ʾ�����˿�����Ҫ�ĳԿջس��Ĳ�������ʹ��getline()������Ϊ���ļ��������ݵĺ�����
3. ���ύ������ݵ�txt�ļ���txt�ļ�Ӧ���ɳ����Զ��ڵ�ǰ�ļ��������ɡ� 
4. ���⹦�ܲ����ӣ���set�ඨ���Ѹ������������30��������ɡ�

������
1. ��Ԫ�����͸�Ϊint����set�ඨ��Ϊͨ�õ�ģ���ࡣ
2. ����Ϊset�����������������<<����������ݡ�
3. ��main�����У���ofstream�����ı��ļ�d1.txt��d2.txt��д��ԭʼ���ݡ�
4. ��main�����У���ifstream�����ı��ļ�d1.txt��d2.txt����ȡ�������в�ͳ��Ԫ�ظ������ֱ���봴����Set�����С�
4. ��main�����У��ر����д��ļ�����
5. ��main�����У�����set�ĳ�Ա����Intersect()��������ݽ�����������������´�����Set�����С�
6. ��main�����У������������е���������д�뵽�ı��ļ� Exp03_ѧ��_03_set.txt�У���ÿ��4�������ĸ�ʽд�룬Ȼ��رո��ļ���

�� ��������ǰ��׼��������
����ofstream��������ԭʼ�����ļ�d1.txt��d2.txt��������һЩ������
����֮�������ɿո񡢻��߻س����м�������������ļ�������Ϊ��
d1.txt��
23   17   56   67   88   
33   94   45   13   22   
18   25   66   86   99   
35   

d2.txt��
32   21   33   56   66   
85   99   20   11   45   
98   22   67   81   91   
69   65   76   89

�� �������к�ĺ˶Թ�����ʹ�ü��±��������ɵ��ļ� Exp03_ѧ��_03_set.txt��
�˶������Ƿ���ȷ��
��d1.txt��d2.txt�������ϣ���Exp03_ѧ��_03_set.txt����ӦΪ�� 
56   67   33   45   
22   66   99

���Թ�����Ҳ�������趨����������ɲ��ԡ�
��ע�����/ѧϰ������Set�ඨ���ʵ�֣��ο����ж�����Ԫ�ؿ��Ƶķ�ʽʵ�ֵڶ����MyString�ࡣ
�������и���Set�ࡣ
*/

//������Ķ�������
#include<iostream> 
using namespace std; 
 
const int maxnum=20; 
enum ErrCode{noErr,overflow}; 
 
class set
{  
	char elements[maxnum];  
	int num; 
public:  
	set(){num=0;}  
	bool Member(char);        //�ж�Ԫ��elem�Ƿ�Ϊ�����ϵĳ�Ա  
	ErrCode AddElem(char);    //����Ԫ��elem���뱾����  
	void RmvElem(char);       //��Ԫ��elem�Ӹü�����ɾȥ  
	void Copy(set);           //��ʵ������ʶ�ļ����е�����Ԫ�ظ��Ƶ���������ȥ  
	bool Equal(set);          //�ж������ϸ��԰�����Ԫ���Ƿ���ȫ��ͬ  
	void print();             //��ʾ�����ϵ�����Ԫ��  
	set Intersect(set);       //�󱾼������һ������ָ���ļ��ϵĽ���������Ϊ����ֵ  
	set Union(set);           //�󱾼������һ������ָ���ļ��ϵĲ���������Ϊ����ֵ  
	bool Contain(set);        //�жϱ������Ƿ����ʵ������ʶ�ļ��������е�Ԫ�� 
}; 

bool set::Member(char elem)
{  
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem) 
	    	return true;  
	return false; 
} 

ErrCode set::AddElem(char elem)
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

void set::RmvElem(char elem)
{ 
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem)
	    {
	        for(;i<num-1;i++)  elements[i]=elements[i+1]; //��ɾ��һ��Ԫ�غ����к��Ԫ��ǰ��һλ    
	        num--;   
	    } 
} 

void set::Copy(set s)
{
    int i;  
    for(i=0;i<s.num;i++) 
        elements[i]= s.elements[i];  
    num= s.num; 
} 

bool set::Equal(set s)
{  
	int i;  
	if(num!=s.num) return false;       //Ԫ�ظ�����ͬ  
	for(i=0;i<num;i++)   
	    if(!s.Member(elements[i])) 
	    	return false;       //�в�ͬԪ��  
	return true; 
} 

void set::print()
{
    cout<<"���ϵ�Ԫ�ذ�����"<<endl;  
    int i;  
    for(i=0;i<num;i++) 
        cout<<elements[i]<<"  ";  
    cout<<endl; 
} 

set set::Intersect(set s1)
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

set set::Union(set s1)
{
    int i; 
    set s;   
    s.Copy(s1);  
    for(i=0;i<num;i++)   
        s.AddElem(elements[i]);  //��������˼��Ͽ������  
    return s; 
} 

bool set::Contain(set s)
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
	set s,s1,s2,s3,s4;  
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
	