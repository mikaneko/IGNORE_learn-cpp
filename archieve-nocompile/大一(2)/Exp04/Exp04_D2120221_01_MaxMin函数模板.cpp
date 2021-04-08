/*
ʵ��15����-1������������Ԫ����Сֵ�����ֵ�ĺ���ģ�塣
���Ҫ��
- ��ɺ���ģ��Ķ��塣
- �ֱ�ʹ��char, int, double, C++��׼string�� �� �Զ����MyString��
  �����������Ͷ����������ͣ�����ɲ��ԡ�
- ͨ��MyString��Ķ����Լ���ģ���е�Ӧ�ã���һ�������������صĺô���
*/

#include <string>
#include <iostream>
#include "MyString_D2120221.h"


//����ģ��ԭ��
template<typename T>
T maxOfArray(const T *pA, int size);

template<typename T>
T minOfArray(const T *pA, int size);
//ע���β�Ϊָ���������β�Ϊ���飬����������ͬ��

template<typename T>
T maxOfArray(const T *pA, int size)
{
    T now_max = pA[0];
    for (int i = 0; i < size; i++)
    {
        if (pA[i] > now_max)
        {
            now_max = pA[i];
        }
    }
    return now_max;
}

template<typename T>
T minOfArray(const T *pA, int size)
{
    T now_min = pA[0];
    for (int i = 0; i < size; i++)
    {
        if (pA[i] < now_min)
        {
            now_min = pA[i];
        }
    }
    return now_min;
}


void test();

int main()
{
    test();
    return 0;
}

void test()
{
    char str1[10] = {'1', 'a', '8', '1', 'u', 'a', 'd', '9', 't', '\0'};
    int arr1[10] = {1, 4, 6, 2, 4, 5, 8, 3, 7, 3};
    double arr2[10] = {1.2, 0.6, 8.4, 0.4, 8.3, 9.5, 10.8, 9.9, 1.1, 7.4};
    std::string str2[5] = {"abccc", "tagsh", "hahahd", "seulala", "aa"};
    MyString str3[5] = {"abccc", "tagsh", "hahahd", "seulala", "aa"};

    std::cout << maxOfArray<char>(str1, 10) << std::endl;
    std::cout << maxOfArray<int>(arr1, 10) << std::endl;
    std::cout << maxOfArray<double>(arr2, 10) << std::endl;
    std::cout << maxOfArray<std::string>(str2, 5) << std::endl;
    std::cout << maxOfArray<MyString>(str3, 5) << std::endl;
}