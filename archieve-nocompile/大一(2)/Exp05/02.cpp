/* �����Ѹ������Ա���ģ�壬ʹ֮˳���
 -	������һ����ģ�壬���������ڲ�ͬ���б�Ԫ�����͡���ˣ�����ģ�嶨�壬����ͨ���ԡ�
ע�⣺
 -  ����ģ���ڶ������Աʱ�����Ͳ���T����ͬ�κ���ͨ����һ��ʹ��
 -  ����ģ���ⲿ�������ģ��ĳ�Ա�����������Ǻ���ģ�� 
�Ѹ��������Ա�Ĳ���������
-	�����
-	���Ҷ��󣨱������ڱ��е�λ�ã��±�ֵ��
-	�ж�x�Ƿ��ڱ���
-	ɾ��x
-	��x������е�i��λ��
-	����x��ǰ������
-	�жϱ��Ƿ�ջ���
-	��ȡ��i��Ԫ�ص�ֵ
****�����Ѹ�������ʵ�ַ�ʽ�����Ķ�����⣬Ҫ��ɸ��֡�

���Ҫ��
-    1 ���ӣ������±������[] P194��E6.3
-    2 ���ӣ����ַ����ҵ����㷨��P200��E6.5(ֻ��˳�����е��б���Ч)
-    3 ���ӣ�����ֱ�Ӳ������� P202��E6.6
-    4 ���ӣ�����԰�������� P203��E6.7
-    5 ���ӣ�ð��(�³�)���� P204��E6.8  (Ҳ��������������Ϊ��ǰmԪ����������㷨�������ϸ��㷨)
-    6 ���ӣ�ֱ��ѡ������ P207��E6.9
-    7*���ӣ�ϰ��6.6���鲢����(Ҳ����������������ͨ������������һ�����ź�������飬�鲢�뱾����)
-    8*���ӣ�ϰ��6.7��ϣ������
-    9 ���ԣ�Ԫ�����ͷֱ�����Ϊ��int, double��char, string��, MyString�࣬
    ��Student��(��seqlist�ඨ����Ѹ���)ʱ�������ӵĸ���Ա����ģ��Ĳ��ԡ�
    ������ɼ򵥵�int���͵ĳ������������ͣ��Լ��޸ļ�����ɡ�
    Ϊstudent������<<��>>�󣬲��Գ�����ú���ģ����ɡ�
    
-   10 ���ӣ�������Ա�(�Ӳ����������о����Ƿ���Ҫ)
-   11 ���ӣ�ʹ���������Ա�����(�Ӳ����������о����Ƿ���Ҫ����ϴ�Ƴ���)

ע��
-   ���Ҫ��1~6�������ڿα����ҵ�ֱ�ӵķ������Լ��޸ļ���ʹ�á�
-   ���˲��Խ���Ա�ʱ�����Զ�����������в��������ϵͳ�Դ�sort()������
-   Ϊ�˳����ϰ������Ŀ��ƣ�������ʹ�ö�̬�ڴ����롣
-   Ҫ������һ��Ԫ�����ͣ���int��Ҳ����սһ��student�ࣩ�Ĳ���ʹ�ýϴ��ģ�Ĳ��Է���������1000��Ԫ�صĲ��ԡ�
-   ����ԴС��ģ��ʱ������ڲ��Ժ���ֱ���ó������������Ǵ��ģ����������ó�������/���
    Ҫ�����ò���������ĳ���ÿ�����ɣ�Ԥ�����ļ������ļ����룬Ȼ�������Ա�
    Ȼ��ͬ�����㷨����������ͬ�ļ���
    ����������time��ͳ�ƴ��ģ�����������ĵ�ʱ�䣬һ��������ļ���
ע���ִ�����������ٶȿ죬���1000������Ȼ�޷��Ƚϳ�ʱ����죬
    ����ջ�������з�Χ�ڼ�������������ݹ�ģ��
    �������������������������������ĳ��������GOD.
*/

#include <iostream>
using namespace std;


template <typename T,int size>
class seqlist
{
    //����ģ���ڶ������Աʱ�����Ͳ���T����ͬ�κ���ͨ����һ��ʹ�á�
    T slist[size];   //���˳��������
    int Maxsize;     //������������ 
    int last;        //�Ѵ��������λ��
public:
	//����ģ���ڶ������Աʱ�����Ͳ���T����ͬ�κ���ͨ����һ��ʹ�á�
    seqlist() { last=-1; Maxsize=size; }          //��ʼ��Ϊ�ձ�
                                                  
    int  Length() const{return last+1;}           //�������
    int  Find(T & x)const;                        // Ѱ��x�ڱ���λ�ã��±꣩
    bool IsIn(T & x)const;                        //�ж�x�Ƿ��ڱ���
    bool Insert(const T & x,int i);               //x���뵽�б��е�i��λ�ô����±꣩
    bool Remove(const T & x);                     //ɾ��x
    int  Next(const T & x)const;                  //Ѱ��x�ĺ��λ��
    int  Prior(const T & x)const;                 //Ѱ��x��ǰ��λ��
    bool IsEmpty()const{return last==-1;}         //�жϱ��Ƿ��
    bool IsFull()const{return last==Maxsize -1;}  //�жϱ��Ƿ���
    T Get(int i)const{return i<0||i>last?NULL:slist[i];} //ȡ��i��Ԫ��ֵ֮
    
    //=========�����Ӳ���	
    T& operator[](int i);                         //�����±������[]
    //����㷨
    void EmptyList();
    //�����㷨
    int BinarySearch(const T &x, int low, int high);    //����Ŀ����������У��������ٴ���������
    //�����㷨
    void InsertSort();       //����ֱ�Ӳ��������㷨
    void BinaryInsertSort(); //����԰��������
    void BubbleSort();       //ð�������㷨
	void BubbleSort(int sortedSize, int waitSortSize);
	void BubbleSort(int dummy);

    void SelectSort();       //ֱ��ѡ������
    void MergeSort();        //�鲢���� 
    //��ʾ�������ض���鲢���������ɵ��ù鲢AB����ΪC�����صĺ�����ʵ��this����Ĺ鲢����
    void ShellSort();        //ϣ������


    
};     


//1 ���ӣ������±������[]����Ҫget(��ֵ�����)��Ҫset(��ֵ����)��P194��E6.3
template <typename T,int size>
T seqlist<T,size>::&operator[](int num){
	return slist[num];
}

//2 ���ӣ����ֲ����㷨��P200��E6.5��ֻ��˳�����е��б���Ч��
template <typename T,int size>
int seqlist<T,size>::BinarySearch(const T &x, int low, int high){
	int mid;
	while(low<=high){
		////�˲������ڷ�ֹ����ѭ��
		if(slist[high]==x){
			return high;
		}
		if(slist[low]==x){
			return low;
		}
		////���ֽ���
		mid=(low+high)/2;
		if(x==slist[mid]){
			return mid;
		}
		else if(x>slist[mid]){
			low=mid;
		}
		else{
			high=mid;
		}
	}
	return
}



//3 ���ӣ�����ֱ�Ӳ��������㷨����Ϊ seqlist<T,size>��ĳ�Ա������ P202��E6.6 
template <typename T,int size>
void seqlist<T,size>::InsertSort(){
	int before;
	//before is a selector for choosing the before elements and compare with the nowElem
	T nowElem;
	for(int i=1;i<last+1;i++){
		before=i-1;
		nowElem=slist[i];
		while(before>=0&&slist[before]>nowElem){
			slist[before+1]=slist[before];
			before--;
		}
		slist[before+1]=nowElem;
	}
}

 
//4 ���ӣ�����԰���������㷨����Ϊ seqlist<T,size>��ĳ�Ա������  P203��E6.7
template <typename T,int size>
void seqlist<T,size>::BinaryInsertSort(){
	int high,low;
	T temp;
	for(int i=1;i<n;i++){
		temp=slist[];

	}
}




//5 ���ӣ�ð��(�³�)�����㷨����Ϊ seqlist<T,size>��ĳ�Ա������ P204��E6.8
template <typename T,int size>
void seqlist<T,size>::BubbleSort(){
	T temp;
	bool noSwap;
	for(int i=0;i<last;i++){
		noSwap=true;
		for(int j=i;j<last;j++){
			if(slist[j]>slist[j+1]){
				slist[j+1]=temp;
				slist[j+1]=slist[j];
				slist[j]=temp;
				noSwap=false;
			}
		}
		if(noSwap){
			break;
		}
	}
}

//5*   �������ض����ͨ�õ�void BubbleSort(int sortedSize, int waitSortSize);
template <typename T,int size>
void seqlist<T,size>::BubbleSort(int sortedSize, int waitSortSize){
	T temp;
	bool noSwap;
	for(int i=sortedSize;i<sortedSize+waitSortSize-1;i++){
		noSwap=true;
		for(int j=i;j<sortedSize+waitSortSize-1;j++){
			if(slist[j]>slist[j+1]){
				slist[j+1]=temp;
				slist[j+1]=slist[j];
				slist[j]=temp;
				noSwap=false;
			}
		}
		if(noSwap){
			break;
		}
	}
}

//5*   �������ض���ð��(�ϸ�)�����㷨��void BubbleSort(int dummy);
template <typename T,int size>
void seqlist<T,size>::BubbleSort(int dummy){
	T temp;
	bool noSwap;
	for(int i=last;i>0;i--){
		noSwap=true;
		for(int j=i;j>0;j--){
			if(slist[j]<slist[j-1]){
				slist[j+1]=temp;
				slist[j+1]=slist[j];
				slist[j]=temp;
				noSwap=false;
			}
		}
		if(noSwap){
			break;
		}
	}
}


	
//6 ���ӣ�ֱ��ѡ��������Ϊ seqlist<T,size>��ĳ�Ա������ P207��E6.9 





//7 ���ӣ�ϰ��6.6���鲢����
//7* ����������Ϊͨ������������һ�����ź��������鲢��this���Ա������

//8 ���ӣ�ϰ��6.7��ϣ������


	
//���ⶨ��ģ����ĳ�Ա�����������ģ��ǰ׺
template <typename T,int size> 
int seqlist<T,size>::Find(T & x) const
//ע���ʽ��const��ʾ�ú�����thisָ��Ϊ����ָ�룬�������ʶ�������ݲ��ܱ��޸ġ�   
//�类�޸ģ��������ᾯ�棬��ֹ���ʱʧ�� 
{
    int i=0;
    while(i<=last && slist[i]!=x) i++;  //˳������Ƿ���x 
    if(i>last) return -1;               //δ�ҵ�������-1
    else       return i;                //�ҵ��������±�
}

template <typename T,int size> 
bool seqlist<T,size>::IsIn(T &x) const 
{
    int i=0;  
    bool found=0;  
    while(i<=last && !found)            //����һ�ַ���������   
    {
        if (slist[i]!=x) i++;   
        else found=1;                   //�ҵ�  
    }
    return found; 
} 

template <typename T,int size>
bool seqlist<T,size>::Insert(T & x, int i)
{
    int j;  
    if (i<0||i>last+1||last==Maxsize-1) return false;  //����λ�ò��������ܲ��루�Ƚ��ԣ�  
    else
    {
        last++;   
        for(j=last;j>i;j--) slist[j]=slist[j-1];        //�ӱ����λ����ǰ���κ��ƣ��ճ�ָ��λ��  
        slist[i]=x;   
        return true;  
    } 
} 

template <typename T,int size> 
bool seqlist<T,size>::Remove(T & x)
{
    int i=Find(x),j;                                      //��ȥ��x���ĸ�λ�� 
    if(i>=0)
    {
        last--;   
        for(j=i;j<=last;j++) slist[j]=slist[j+1];         //����ǰ�ƣ���֤������ 
        return true;  
    }  
    return false;                                         //���в�����x 
}

 template <typename T,int size> 
int seqlist<T,size>::Next(T & x) const
{ 
     int i=Find(x);  
     if(i>=0 && i<last) return i+1;                      //x���λ��  
     else return -1;                                     //x���ڱ��У����ڱ�ĩβ 
} 

template <typename T,int size> 
int seqlist<T,size>::Prior(T & x) const
{
    int i=Find(x);  
    if(i>0 && i<=last)  return i-1;                      //xǰ����λ��  
	else return -1; 
} 

/*========================��ģ�嶨�����========================*/
    
    






class Student    
{
public:
	int   id;   //ѧ��
	float gpa;  //ƽ����   
    Student(int i=0, float g=0):id(i), gpa(g){}
	
	//���ز���/��������ʹ�õĹ�ϵ�������ֻ�ܽ���Student����ıȽϣ����ó�Ա��������
	bool operator< (Student s2){return id<s2.id;}        
	bool operator<=(Student s2){return id<=s2.id;}    
	bool operator!=(Student s2){return id!=s2.id;}      
	void show(){cout<<"Sutdent id is:"<<id<<endl;}
}; 	


// 9 ���ԣ�Ԫ�����ͷֱ�����Ϊ��int, double��char, string��, MyString�࣬
//   ��Student��(��seqlist�ඨ����Ѹ���)ʱ�������ӵĸ���Ա����ģ��Ĳ��ԡ�
//   ������ɼ򵥵�int���͵ĳ������������ͣ��Լ��޸ļ�����ɡ�
//   Ϊstudent������<<��>>�󣬲��Գ�����ú���ģ����ɡ�
	
// Start of your testing program








void main()
{
    return;         //Return to the OS 
}

