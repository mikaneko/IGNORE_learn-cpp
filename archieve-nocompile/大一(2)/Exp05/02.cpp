/* 完善已给出线性表类模板，使之顺序表
 -	定义了一个类模板，可以适用于不同的列表元素类型。因此，用类模板定义，更具通用性。
注意：
 -  在类模板内定义类成员时，类型参数T可以同任何普通类型一样使用
 -  在类模板外部定义的类模板的成员函数，必须是函数模板 
已给出的线性表的操作包括：
-	计算表长
-	查找对象（变量）在表中的位置（下标值）
-	判断x是否在表中
-	删除x
-	将x插入表中第i个位置
-	查找x的前驱或后继
-	判断表是否空或满
-	获取第i个元素的值
****上述已给操作的实现方式自行阅读，理解，要求可复现。

编程要求：
-    1 增加：重载下标运算符[] P194，E6.3
-    2 增加：二分法查找迭代算法。P200，E6.5(只对顺序排列的列表有效)
-    3 增加：升序直接插入排序法 P202，E6.6
-    4 增加：升序对半插入排序法 P203，E6.7
-    5 增加：冒泡(下沉)排序法 P204，E6.8  (也可自行增加重载为，前m元素已排序的算法，或者上浮算法)
-    6 增加：直接选择排序法 P207，E6.9
-    7*增加：习题6.6，归并排序，(也可以自行重载增加通过参数引入另一组已排好序的数组，归并入本序列)
-    8*增加：习题6.7，希尔排序。
-    9 测试：元素类型分别设置为：int, double，char, string类, MyString类，
    和Student类(在seqlist类定义后已给出)时，完成添加的各成员函数模板的测试。
    首先完成简单的int类型的程序，其他的类型，稍加修改即可完成。
    为student类重载<<和>>后，测试程序可用函数模板完成。
    
-   10 增加：清空线性表(视测试需求自行决定是否需要)
-   11 增加：使已排序线性表乱序(视测试需求自行决定是否需要，即洗牌程序)

注：
-   编程要求1~6都可以在课本中找到直接的范例，稍加修改即可使用。
-   除了测试结果对比时候，在自定义的排序函数中不允许调用系统自带sort()函数。
-   为了充分练习对数组的控制，不允许使用动态内存申请。
-   要求至少一种元素类型（如int，也可挑战一下student类）的测试使用较大规模的测试范例，例如1000个元素的测试。
-   数据源小规模的时候可以在测试函数直接用常量给出。但是大规模的数据最好用程序输入/输出
    要不就用产生随机数的程序每次生成，预存入文件，由文件读入，然后建立线性表，
    然后不同排序算法结果输出到不同文件。
    还可以利用time类统计大规模数据排序消耗的时间，一并输出到文件。
注：现代计算机运算速度快，如果1000个数仍然无法比较出时间差异，
    可在栈容量运行范围内继续增大测试数据规模。
    ————————————你就是你的程序世界的GOD.
*/

#include <iostream>
using namespace std;


template <typename T,int size>
class seqlist
{
    //在类模板内定义类成员时，类型参数T可以同任何普通类型一样使用。
    T slist[size];   //存放顺序表的数组
    int Maxsize;     //最大可容纳项数 
    int last;        //已存表项的最后位置
public:
	//在类模板内定义类成员时，类型参数T可以同任何普通类型一样使用。
    seqlist() { last=-1; Maxsize=size; }          //初始化为空表
                                                  
    int  Length() const{return last+1;}           //计算表长度
    int  Find(T & x)const;                        // 寻找x在表中位置（下标）
    bool IsIn(T & x)const;                        //判断x是否在表中
    bool Insert(const T & x,int i);               //x插入到列表中第i个位置处（下标）
    bool Remove(const T & x);                     //删除x
    int  Next(const T & x)const;                  //寻找x的后继位置
    int  Prior(const T & x)const;                 //寻找x的前驱位置
    bool IsEmpty()const{return last==-1;}         //判断表是否空
    bool IsFull()const{return last==Maxsize -1;}  //判断表是否满
    T Get(int i)const{return i<0||i>last?NULL:slist[i];} //取第i个元素之值
    
    //=========待增加部分	
    T& operator[](int i);                         //重载下标运算符[]
    //清空算法
    void EmptyList();
    //查找算法
    int BinarySearch(const T &x, int low, int high);    //搜索目标在类对象中，函数不再传递数组名
    //排序算法
    void InsertSort();       //升序直接插入排序算法
    void BinaryInsertSort(); //升序对半插入排序法
    void BubbleSort();       //冒泡排序算法
	void BubbleSort(int sortedSize, int waitSortSize);
	void BubbleSort(int dummy);

    void SelectSort();       //直接选择排序
    void MergeSort();        //归并排序 
    //提示：可重载多个归并排序函数，可调用归并AB数组为C的重载的函数来实现this数组的归并排序。
    void ShellSort();        //希尔排序


    
};     


//1 增加：重载下标运算符[]，即要get(右值运算符)又要set(左值运算)，P194，E6.3
template <typename T,int size>
T seqlist<T,size>::&operator[](int num){
	return slist[num];
}

//2 增加：二分查找算法，P200，E6.5（只对顺序排列的列表有效）
template <typename T,int size>
int seqlist<T,size>::BinarySearch(const T &x, int low, int high){
	int mid;
	while(low<=high){
		////此部分用于防止无限循环
		if(slist[high]==x){
			return high;
		}
		if(slist[low]==x){
			return low;
		}
		////部分结束
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



//3 增加：升序直接插入排序算法，作为 seqlist<T,size>类的成员函数。 P202，E6.6 
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

 
//4 增加：升序对半插入排序算法，作为 seqlist<T,size>类的成员函数。  P203，E6.7
template <typename T,int size>
void seqlist<T,size>::BinaryInsertSort(){
	int high,low;
	T temp;
	for(int i=1;i<n;i++){
		temp=slist[];

	}
}




//5 增加：冒泡(下沉)排序算法，作为 seqlist<T,size>类的成员函数。 P204，E6.8
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

//5*   可以重载定义更通用的void BubbleSort(int sortedSize, int waitSortSize);
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

//5*   可以重载定义冒泡(上浮)排序算法，void BubbleSort(int dummy);
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


	
//6 增加：直接选择排序，作为 seqlist<T,size>类的成员函数。 P207，E6.9 





//7 增加：习题6.6，归并排序，
//7* 还可以重载为通过参数引入另一组已排好序的数组归并入this线性表的数组

//8 增加：习题6.7，希尔排序。


	
//类外定义模板类的成员函数，必须加模板前缀
template <typename T,int size> 
int seqlist<T,size>::Find(T & x) const
//注意格式，const表示该函数的this指针为常量指针，即被访问对象的数据不能被修改。   
//如被修改，编译器会警告，防止编程时失误。 
{
    int i=0;
    while(i<=last && slist[i]!=x) i++;  //顺序查找是否有x 
    if(i>last) return -1;               //未找到，返回-1
    else       return i;                //找到，返回下标
}

template <typename T,int size> 
bool seqlist<T,size>::IsIn(T &x) const 
{
    int i=0;  
    bool found=0;  
    while(i<=last && !found)            //换了一种方法来查找   
    {
        if (slist[i]!=x) i++;   
        else found=1;                   //找到  
    }
    return found; 
} 

template <typename T,int size>
bool seqlist<T,size>::Insert(T & x, int i)
{
    int j;  
    if (i<0||i>last+1||last==Maxsize-1) return false;  //插入位置不合理，不能插入（稳健性）  
    else
    {
        last++;   
        for(j=last;j>i;j--) slist[j]=slist[j-1];        //从表最后位置向前依次后移，空出指定位置  
        slist[i]=x;   
        return true;  
    } 
} 

template <typename T,int size> 
bool seqlist<T,size>::Remove(T & x)
{
    int i=Find(x),j;                                      //先去找x在哪个位置 
    if(i>=0)
    {
        last--;   
        for(j=i;j<=last;j++) slist[j]=slist[j+1];         //依次前移，保证表连续 
        return true;  
    }  
    return false;                                         //表中不存在x 
}

 template <typename T,int size> 
int seqlist<T,size>::Next(T & x) const
{ 
     int i=Find(x);  
     if(i>=0 && i<last) return i+1;                      //x后继位置  
     else return -1;                                     //x不在表中，或在表末尾 
} 

template <typename T,int size> 
int seqlist<T,size>::Prior(T & x) const
{
    int i=Find(x);  
    if(i>0 && i<=last)  return i-1;                      //x前驱的位置  
	else return -1; 
} 

/*========================类模板定义完成========================*/
    
    






class Student    
{
public:
	int   id;   //学号
	float gpa;  //平均分   
    Student(int i=0, float g=0):id(i), gpa(g){}
	
	//重载查找/排序函数中使用的关系运算符，只能进行Student对象的比较，故用成员函数定义
	bool operator< (Student s2){return id<s2.id;}        
	bool operator<=(Student s2){return id<=s2.id;}    
	bool operator!=(Student s2){return id!=s2.id;}      
	void show(){cout<<"Sutdent id is:"<<id<<endl;}
}; 	


// 9 测试：元素类型分别设置为：int, double，char, string类, MyString类，
//   和Student类(在seqlist类定义后已给出)时，完成添加的各成员函数模板的测试。
//   首先完成简单的int类型的程序，其他的类型，稍加修改即可完成。
//   为student类重载<<和>>后，测试程序可用函数模板完成。
	
// Start of your testing program








void main()
{
    return;         //Return to the OS 
}

