/*
实验十六.3，
    编写插入、冒泡、选择，三种排序算法的函数模板。
    
编程要求：
-   其中冒泡排序算法需改进PPT的范例，传递给函数的参数有三个：
    数组首地址，整数sortedSize，整数waitSortSize。
    其中，sortedSize表示该数组的前sortedSize个元素已经有序。
    waitSortSize表示该数组还有waitSortSize个元素未排序。
    当sortedSize=0，waitSortSize=size时，即全部元素排序。
    
-   在main()中分别使用char, int, double, C++标准string类 和 自定义的MyString，
    五种数据类型定义数组类型，并完成测试。
-   为提高可复用性，建议用函数模板定义测试函数，提高你的工作效率。

附1：(升序)插入算法说明
-   当插入第i(i>=1)个元素时,前面的元素0,1,…, i-1个元素已经排好序,
-   将第i个元素的关键字与i-1, i-2,…,的关键字顺序进行比较,
-   找到第一个比它小的,则第i个元素插到该元素之后。
   
附2：冒泡排序算法说明
-	重复地遍历过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。
-	遍历数列的工作重复地进行，直到没有再需要交换，也就是说该数列已经排序完成。
-	这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。
-   从前往后遍历，大数下沉
-	从后往前遍历，小数上浮
大数下沉算法：
-   从数组的第一个数a[0]开始，向后遍历，每次比较a[i]和a[i+1]的值
-   若a[i]大于a[i+1]，就交换两个位置的数的值。
-   重复上述1和2的操作至不再出现值的交换。

附3：升(降)序选择排序算法说明
-   首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
-   然后，再从剩余未排序元素中继续寻找最小（大）元素，放到已排序序列的末尾。
-   以此类推，直到所有元素均排序完毕。

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//函数模板原型
template <typename T>void InsertSort(T *pA, int size);
template <typename T>void BubbleSort(T *pA, int sortedSize, int waitSortSize);  
template <typename T>void SelectSort(T *pA, int size);
//声明中形参名无实际意义，你们可以自行在定义时按自己喜好为形参起名

//测试函数模板
template <typename T>void RandomArray(T array[], int len);
template <typename T>void PrintArray( T array[], int len);
template <typename T>void SortTest(   T array[], int len);




//用char测试好函数功能后，加前缀，将char类型体会为类型名。
void InsertSort(char *pA, int size)
{
	for(int i=1; i<size; i++)
	{
		int j;
		char temp=pA[i];  //缓存“当前进行插入排序的数”
		for(j=i; j>0; )
		{
			//只要前一个数大于“当前排序的数”就后移一位
			if(temp<pA[j-1]) 
			{
			    pA[j]=pA[j-1];
				j--;
			}
			else break;
		}		 
        pA[j]=temp; //“当前排序的数”插入合适位置
	}
}


void BubbleSort(char *pA, int size)
{
    for(int i=0; i<size; i++)
	{
        bool noSwap=true; //当排序在遍历一遍之前就完成时，辅助提前终止 

        for(int j=size-1; j>i; j--) //从后向前上浮
		{
			if(pA[j]<pA[j-1])
			{
				char temp=pA[j];
                pA[j]=pA[j-1];
				pA[j-1]=temp;
                noSwap=false;
			}
		}
		if(noSwap) break;  //无交换时表明排序提前完成 
	}	 
}

void SelectSort(char *pA, int size)
{
    int	pos;  //当前选中的位置，在该位置放入未排序的数中的最小值
    for(pos=0; pos<size; pos++)
	{
        char temp=pA[pos];

		int  min=pos;   //每轮搜索最小值位置
		for(int i=pos; i<size; i++)
        {
			if(pA[i]<temp) 
			{
				min=i;
				temp=pA[i];
			}
		}
        pA[min]=pA[pos];
		pA[pos]=temp;        
	}
}




/*定义测试函数*/
void RandomArray(char array[], int len)
{
    int i;
    int sub;
    char temp;
    
    srand(time(0));
#if 0	//长度较短时随机效果差
    for(i=0; i<len; i++)
    {
        sub=rand()%len;
        temp = array[i];
        array[i] = array[sub];
        array[sub] = temp;
    }
#else   //随机性效果较稳定
	for(i=0; i<200; i++)
    {
        sub=rand()%len;
        temp = array[0];
        array[0] = array[sub];
        array[sub] = temp;
    }
#endif
}



int main()
{
	char Arr[11]={"eacdbeacdb"};

    cout<<Arr<<"==>";
	InsertSort(Arr,10);
	cout<<Arr<<endl;
	
	cout<<"======AGAIN\n";
	RandomArray(Arr,10);   
	cout<<Arr<<"==>";
	InsertSort(Arr,10);
	cout<<Arr<<endl;
    
	cout<<"======AGAIN\n";
	RandomArray(Arr,10);
	cout<<Arr<<"==>";
	BubbleSort(Arr,10);
	cout<<Arr<<endl;
	
	cout<<"======AGAIN\n";
	RandomArray(Arr,10);
	cout<<Arr<<"==>";
	SelectSort(Arr,10);
	cout<<Arr<<endl;
	return 0;
}
