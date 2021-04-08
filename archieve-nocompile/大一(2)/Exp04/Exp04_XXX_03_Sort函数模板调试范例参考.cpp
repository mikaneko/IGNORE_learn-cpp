/*
ʵ��ʮ��.3��
    ��д���롢ð�ݡ�ѡ�����������㷨�ĺ���ģ�塣
    
���Ҫ��
-   ����ð�������㷨��Ľ�PPT�ķ��������ݸ������Ĳ�����������
    �����׵�ַ������sortedSize������waitSortSize��
    ���У�sortedSize��ʾ�������ǰsortedSize��Ԫ���Ѿ�����
    waitSortSize��ʾ�����黹��waitSortSize��Ԫ��δ����
    ��sortedSize=0��waitSortSize=sizeʱ����ȫ��Ԫ������
    
-   ��main()�зֱ�ʹ��char, int, double, C++��׼string�� �� �Զ����MyString��
    �����������Ͷ����������ͣ�����ɲ��ԡ�
-   Ϊ��߿ɸ����ԣ������ú���ģ�嶨����Ժ����������Ĺ���Ч�ʡ�

��1��(����)�����㷨˵��
-   �������i(i>=1)��Ԫ��ʱ,ǰ���Ԫ��0,1,��, i-1��Ԫ���Ѿ��ź���,
-   ����i��Ԫ�صĹؼ�����i-1, i-2,��,�Ĺؼ���˳����бȽ�,
-   �ҵ���һ������С��,���i��Ԫ�ز嵽��Ԫ��֮��
   
��2��ð�������㷨˵��
-	�ظ��ر�����Ҫ��������У�һ�αȽ�����Ԫ�أ�������ǵ�˳�����Ͱ����ǽ���������
-	�������еĹ����ظ��ؽ��У�ֱ��û������Ҫ������Ҳ����˵�������Ѿ�������ɡ�
-	����㷨��������������ΪԽС��Ԫ�ػᾭ�ɽ������������������еĶ��ˡ�
-   ��ǰ��������������³�
-	�Ӻ���ǰ������С���ϸ�
�����³��㷨��
-   ������ĵ�һ����a[0]��ʼ����������ÿ�αȽ�a[i]��a[i+1]��ֵ
-   ��a[i]����a[i+1]���ͽ�������λ�õ�����ֵ��
-   �ظ�����1��2�Ĳ��������ٳ���ֵ�Ľ�����

��3����(��)��ѡ�������㷨˵��
-   ������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�ã�
-   Ȼ���ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ��ŵ����������е�ĩβ��
-   �Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//����ģ��ԭ��
template <typename T>void InsertSort(T *pA, int size);
template <typename T>void BubbleSort(T *pA, int sortedSize, int waitSortSize);  
template <typename T>void SelectSort(T *pA, int size);
//�������β�����ʵ�����壬���ǿ��������ڶ���ʱ���Լ�ϲ��Ϊ�β�����

//���Ժ���ģ��
template <typename T>void RandomArray(T array[], int len);
template <typename T>void PrintArray( T array[], int len);
template <typename T>void SortTest(   T array[], int len);




//��char���Ժú������ܺ󣬼�ǰ׺����char�������Ϊ��������
void InsertSort(char *pA, int size)
{
	for(int i=1; i<size; i++)
	{
		int j;
		char temp=pA[i];  //���桰��ǰ���в������������
		for(j=i; j>0; )
		{
			//ֻҪǰһ�������ڡ���ǰ����������ͺ���һλ
			if(temp<pA[j-1]) 
			{
			    pA[j]=pA[j-1];
				j--;
			}
			else break;
		}		 
        pA[j]=temp; //����ǰ����������������λ��
	}
}


void BubbleSort(char *pA, int size)
{
    for(int i=0; i<size; i++)
	{
        bool noSwap=true; //�������ڱ���һ��֮ǰ�����ʱ��������ǰ��ֹ 

        for(int j=size-1; j>i; j--) //�Ӻ���ǰ�ϸ�
		{
			if(pA[j]<pA[j-1])
			{
				char temp=pA[j];
                pA[j]=pA[j-1];
				pA[j-1]=temp;
                noSwap=false;
			}
		}
		if(noSwap) break;  //�޽���ʱ����������ǰ��� 
	}	 
}

void SelectSort(char *pA, int size)
{
    int	pos;  //��ǰѡ�е�λ�ã��ڸ�λ�÷���δ��������е���Сֵ
    for(pos=0; pos<size; pos++)
	{
        char temp=pA[pos];

		int  min=pos;   //ÿ��������Сֵλ��
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




/*������Ժ���*/
void RandomArray(char array[], int len)
{
    int i;
    int sub;
    char temp;
    
    srand(time(0));
#if 0	//���Ƚ϶�ʱ���Ч����
    for(i=0; i<len; i++)
    {
        sub=rand()%len;
        temp = array[i];
        array[i] = array[sub];
        array[sub] = temp;
    }
#else   //�����Ч�����ȶ�
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
