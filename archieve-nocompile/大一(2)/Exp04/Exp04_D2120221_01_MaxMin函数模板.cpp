/*
实验15，二-1，建立求数组元素最小值和最大值的函数模板。
编程要求：
- 完成函数模板的定义。
- 分别使用char, int, double, C++标准string类 和 自定义的MyString，
  五种数据类型定义数组类型，并完成测试。
- 通过MyString类的定义以及在模板中的应用，进一步体会运算符重载的好处。
*/

#include <string>
#include <iostream>
#include "MyString_D2120221.h"


//函数模板原型
template<typename T>
T maxOfArray(const T *pA, int size);

template<typename T>
T minOfArray(const T *pA, int size);
//注意形参为指针类型与形参为数组，本质上是相同的

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