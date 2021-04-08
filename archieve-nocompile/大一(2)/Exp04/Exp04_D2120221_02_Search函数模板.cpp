/*
习题6.4，
  建立对数组元素进行顺序和对半查找的函数模板，
  若找到元素则返回数组下标，找不到则返回-1。

编程要求：
- 完成函数模板的定义。
- 对半查找不限制递归或迭代实现，也可以两种方式都实现
- 在main()中分别使用：char, int, double, C++标准string类
  和 自定义的MyString类，五种数据类型定义数组类型，并完成测试。
- 为提高可复用性，建议用函数模板定义测试函数，提高你的工作效率。
- 注意防止二分法陷入死循环。
*/


#include <iostream>


//函数模板原型，其中low和high为查找范围，下标区间
template<typename T>
int SequenceSearch(const T *pA, T x, int low, int high);

template<typename T>
int BinarySearch(const T *pA, T x, int low, int high);
//注意形参为指针类型与形参为数组，本质上是相同的

template<typename T>
int SequenceSearch(const T *pA, T x, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        if (pA[i] == x)
        {
            return i;
        }
    }
    return -1;
}

//本算法只能用于 “非重复” “升序” 的数列
template<typename T>
int BinarySearch(const T *pA, T x, int low, int high)
{
    int left = low;
    int right = high;
    int middle = (high + low) / 2;
    while (left < right)
    {

        //// partly debug
        if (middle == left || middle == right)
        {
            if (pA[right] == x)
            {
                return right;
            }
            else if (pA[left] == x)
            {
                return left;
            }
            else break;
        }
        //// partly debug end

        if (pA[middle] == x)
        {
            return middle;
        }
        else if (pA[middle] < x)
        {
            left = middle;
            middle = (right + left) / 2;
        }
        else
        {
            right = middle;
            middle = (right + left) / 2;
        }


    }
    return -1;

}
//注意形参为指针类型与形参为数组，本质上是相同的

void test()
{
    int array[10] = {1, 2, 4, 5, 6, 8, 11, 22, 24, 27};
    std::cout << SequenceSearch<int>(array, 4, 0, 9) << std::endl;
    std::cout << SequenceSearch<int>(array, 7, 0, 9) << std::endl;
    std::cout << SequenceSearch<int>(array, 11, 0, 9) << std::endl;
    std::cout << SequenceSearch<int>(array, 27, 0, 9) << std::endl;
    std::cout << SequenceSearch<int>(array, 1, 0, 9) << std::endl;

    std::cout << std::endl;

    std::cout << BinarySearch<int>(array, 4, 0, 9) << std::endl;
    std::cout << BinarySearch<int>(array, 7, 0, 9) << std::endl;
    std::cout << BinarySearch<int>(array, 11, 0, 9) << std::endl;
    std::cout << BinarySearch<int>(array, 27, 0, 9) << std::endl;
    std::cout << BinarySearch<int>(array, 1, 0, 9) << std::endl;
}

int main()
{
    test();
    return 0;

}