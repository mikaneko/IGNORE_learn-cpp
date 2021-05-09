/*
ϰ��6.4��
  ����������Ԫ�ؽ���˳��Ͷ԰���ҵĺ���ģ�壬
  ���ҵ�Ԫ���򷵻������±꣬�Ҳ����򷵻�-1��

���Ҫ��
- ��ɺ���ģ��Ķ��塣
- �԰���Ҳ����Ƶݹ�����ʵ�֣�Ҳ�������ַ�ʽ��ʵ��
- ��main()�зֱ�ʹ�ã�char, int, double, C++��׼string��
  �� �Զ����MyString�࣬�����������Ͷ����������ͣ�����ɲ��ԡ�
- Ϊ��߿ɸ����ԣ������ú���ģ�嶨����Ժ����������Ĺ���Ч�ʡ�
- ע���ֹ���ַ�������ѭ����
*/


#include <iostream>


//����ģ��ԭ�ͣ�����low��highΪ���ҷ�Χ���±�����
template<typename T>
int SequenceSearch(const T *pA, T x, int low, int high);

template<typename T>
int BinarySearch(const T *pA, T x, int low, int high);
//ע���β�Ϊָ���������β�Ϊ���飬����������ͬ��

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

//���㷨ֻ������ �����ظ��� ������ ������
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
//ע���β�Ϊָ���������β�Ϊ���飬����������ͬ��

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