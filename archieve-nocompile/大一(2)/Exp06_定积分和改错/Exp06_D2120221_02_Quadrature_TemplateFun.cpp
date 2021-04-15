// encoding: ansi-gbk

/*
��Ŀ��ʵ��17������2��������ֽ��Ʒ������������ָ������Ķ����֡�
���Ҫ��
-  ģ��P211,��6.12�����������ָ�����䶨���ֵĺ���ģ�壬
   �󶨻��ֺ���ģ����Ϊ��ͨ�ǳ�Ա���������������������Ϊ�ࡣ
   ����ģ��Ϊ������ʵ��ͨ���㷨��
-  ��Ӻ��ʵ�ͷ�ļ���
-  Ϊ���������ý��Ʒ������б����������ж����ּ��㡣

   sin(x)��      ����Ϊ 0.0 ������Ϊ��/2��      [-cosx]=0-(-1)=1                              
   exp(x)��      ����Ϊ 0.0 ������Ϊ 1.0��     [exp(x)]=2.718281828459045-1=1.718281828459045 
   4.0/(1+x*x)�� ����Ϊ 0.0 ������Ϊ 1.0��     [4.0arctan(x)]=pi=3.141592653589794            
   
-  ������������������Ĳ��Ժ󣬿������й��캯��������������䣬�����������㡣
-  ���η�rectangleΪ�α��������Ǳ�����ҵ�Ļ���Ҫ��
-  ѧ��������ͬѧ�ֱ��ã����η�rectangle�����η�ladder������ɭ��Simpson���ж����ּ��㣬
   ���Ƚϻ��־��ȡ�
*/

#include <iostream>
// #include <string>
#include <cmath>
// #include "useful_tool.h"

//���Ժ���
namespace fun_test
{
    class F1
    {
    public:
        double fun(double x)
        {
            return std::sin(x);
        }
    };

    class F2
    {
    public:
        double fun(double x)
        {
            return std::exp(x);
        }
    };

    class F3
    {
    public:
        double fun(double x)
        {
            return 4.0 / (1 + x * x);
            ;
        }
    };
}

template <typename T> //���η�����(�������������ޣ��������ޣ��ָ���������)
double inge_by_reac(T funclass, double start, double end, int intervals)
{
    bool positive = (end - start) ? true : false;
    double length = positive ? end - start : start - end;
    double step = length / intervals;
    double sum = 0.0;
    for (double i = start; i < end; i += step)
    {
        sum += step * funclass.fun(i);
    }
    return sum;
}

template <typename T> //ladder������
double inge_by_ladder(T funclass, double start, double end, int intervals)
{
    bool positive = (end - start) ? true : false;
    double length = positive ? end - start : start - end;
    double step = length / intervals;
    double sum = 0.0;
    sum += step * funclass.fun(0.0) / 2.0;
    sum += step * funclass.fun(end - step) / 2.0;
    for (double i = step; i < end - step; i += step)
    {
        sum += step * funclass.fun(i);
    }
    return sum;
}

template <typename T> //sim������
double inge_by_sim(T funclass, double start, double end, int intervals)
{
    bool positive = (end - start) ? true : false;
    double length = positive ? end - start : start - end;
    double step = length / intervals;
    double sum = 0.0;
    sum += step * funclass.fun(0.0) / 3.0;
    sum += step * funclass.fun(end - step) / 3.0;
    for (double i = step; i < end - step; i += step * 2)
    {
        sum += 2.0 * step * funclass.fun(i) / 3.0;
    }
    for (double i = 2 * step; i < end - step; i += step * 2)
    {
        sum += 4.0 * step * funclass.fun(i) / 3.0;
    }
    return sum;
}

//entrance
int main()
{
    fun_test::F1 f1;
    fun_test::F2 f2;
    fun_test::F3 f3;

    std::cout << inge_by_reac<fun_test::F1>(f1, 0, 1, 10000) << std::endl;
    std::cout << inge_by_ladder<fun_test::F1>(f1, 0, 1, 10000) << std::endl;
    std::cout << inge_by_sim<fun_test::F1>(f1, 0, 1, 10000) << std::endl;
    std::cout << std::endl;

    std::cout << inge_by_reac<fun_test::F2>(f2, 0, 1, 10000) << std::endl;
    std::cout << inge_by_ladder<fun_test::F2>(f2, 0, 1, 10000) << std::endl;
    std::cout << inge_by_sim<fun_test::F2>(f2, 0, 1, 10000) << std::endl;
    std::cout << std::endl;

    std::cout << inge_by_reac<fun_test::F3>(f3, 0, 1, 10000) << std::endl;
    std::cout << inge_by_ladder<fun_test::F3>(f3, 0, 1, 10000) << std::endl;
    std::cout << inge_by_sim<fun_test::F3>(f3, 0, 1, 10000) << std::endl;
    std::cout << std::endl;

    return 0;
}