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

#define _INSERT_SORT_ 0
#define _BUBBLE_SORT_ 1
#define _SELECT_SORT_ 0


#include <iostream>
#include <ctime>
#include <cstdlib>
#include "MyString_D2120221.h"


//����ģ��ԭ��
template<typename T>
void InsertSort(T *pA, int size);

template<typename T>
void BubbleSort(T *pA, int sortedSize, int waitSortSize);

template<typename T>
void SelectSort(T *pA, int size);
//�������β�����ʵ�����壬���ǿ��������ڶ���ʱ���Լ�ϲ��Ϊ�β�����


//���Ժ���ģ��
template<typename T>
void RandomArray(T array[], int len);

template<typename T>
void PrintArray(T array[], int len);

template<typename T>
void SortTest(T array[], int len);


// ���� definition part
template<typename T>
void RandomArray(T array[], int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        array[i] == rand();
    }
}

template<typename T>
void PrintArray(T array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << array[i];
    }
    std::cout << std::endl;
}

////    �����׵�ַ������sortedSize������waitSortSize��
////    ���У�sortedSize��ʾ�������ǰsortedSize��Ԫ���Ѿ�����
////    waitSortSize��ʾ�����黹��waitSortSize��Ԫ��δ����
////    ��sortedSize=0��waitSortSize=sizeʱ����ȫ��Ԫ������
template<typename T>
void BubbleSort(T *pA, int sortedSize, int waitSortSize)
{
    for (int i = sortedSize; i < sortedSize + waitSortSize; i++)
    {
        bool noSwap = true; //�������ڱ���һ��֮ǰ�����ʱ��������ǰ��ֹ

        for (int j = sortedSize + waitSortSize - 1; j > i; j--) //�Ӻ���ǰ�ϸ�
        {
            if (pA[j] < pA[j - 1])
            {
                T temp = pA[j];
                pA[j] = pA[j - 1];
                pA[j - 1] = temp;
                noSwap = false;
            }
        }
        if (noSwap) break;  //�޽���ʱ����������ǰ���
    }
}

template<typename T>
void SelectSort(T *pA, int size)
{
    int pos;  //��ǰѡ�е�λ�ã��ڸ�λ�÷���δ��������е���Сֵ
    for (pos = 0; pos < size; pos++)
    {
        T temp = pA[pos];

        int min = pos;   //ÿ��������Сֵλ��
        for (int i = pos; i < size; i++)
        {
            if (pA[i] < temp)
            {
                min = i;
                temp = pA[i];
            }
        }
        pA[min] = pA[pos];
        pA[pos] = temp;
    }
}

template<typename T>
void InsertSort(T *pA, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j;
        T temp = pA[i];  //���桰��ǰ���в������������
        for (j = i; j > 0;)
        {
            //ֻҪǰһ�������ڡ���ǰ����������ͺ���һλ
            if (temp < pA[j - 1])
            {
                pA[j] = pA[j - 1];
                j--;
            }
            else break;
        }
        pA[j] = temp; //����ǰ����������������λ��
    }
}

int main()
{
    char Arr[11] = {"eacdbeacdb"};
    std::cout << Arr << "==>";

#if _BUBBLE_SORT_
    BubbleSort(Arr, 0, 10);
#endif

#if _SELECT_SORT_
    SelectSort(Arr,10);
#endif

#if _INSERT_SORT_
    InsertSort(Arr,10);
#endif

    std::cout << Arr << std::endl;

////////////////


    MyString str[4] = {"cccc", "abcd", "bbaa", "dede"};
    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
    {
        std::cout << str[i] << std::endl;
    }
    std::cout << "==>" << std::endl;
#if _BUBBLE_SORT_
    BubbleSort(str, 0, 4);
#endif

#if _SELECT_SORT_
    SelectSort(str,4);
#endif

#if _INSERT_SORT_
    InsertSort(str,4);
#endif

    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
    {
        std::cout << str[i] << std::endl;
    }

    return 0;
}