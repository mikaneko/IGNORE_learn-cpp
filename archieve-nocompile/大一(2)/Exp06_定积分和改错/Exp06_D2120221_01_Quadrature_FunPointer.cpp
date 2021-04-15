// encoding: ansi-gbk


/*
��Ŀ��ʵ��17������2��������ֽ��Ʒ������������ָ������Ķ����֡�
���Ҫ��
-  ģ��P213,��6.13��������̵ķ�ʽʵ��ͨ���Դ��롣
-  ������ָ����Ϊ���߷������Ĳ���������ʱָ��ͬ������ʵ��ͨ���ԡ�
-  ��Ӻ��ʵ�ͷ�ļ���
-  Ϊ���������ý��Ʒ������б����������ж����ּ��㡣

   sin(x)��      ����Ϊ 0.0 ������Ϊ��/2��    [-cosx]=0-(-1)=1                              
   exp(x)��      ����Ϊ 0.0 ������Ϊ 1.0��   [exp(x)]=2.718281828459045-1=1.718281828459045 
   4.0/(1+x*x)�� ����Ϊ 0.0 ������Ϊ 1.0��   [4.0arctan(x)]=pi=3.141592653589794            
   
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
namespace test_function
{
    double function_01(double x)
    {
        return std::sin(x);
    }

    double function_02(double x)
    {
        return std::exp(x);
    }

    double function_03(double x)
    {
        return 4.0 / (1 + x * x);
    }
    double ret1(double x)
    {
        return 1;
    }
}


//���η�����(�������������ޣ��������ޣ��ָ���������)
double inge_by_reac(double (*fti)(double x), double start, double end, int intervals)
{
    bool positive = (end - start) ? true : false;
    double length = positive ? end - start : start - end;
    double step = length / intervals;
    double sum = 0.0;
    for (double i = start; i < end; i += step)
    {
        sum += step * fti(i);
    }
    return sum;
}

//ladder������
double inge_by_ladder(double (*fti)(double x), double start, double end, int intervals)
{
    bool positive = (end - start) ? true : false;
    double length = positive ? end - start : start - end;
    double step = length / intervals;
    double sum = 0.0;
    sum += step * fti(0.0) / 2.0;
    sum += step * fti(end - step) / 2.0;
    for (double i = step; i < end - step; i += step)
    {
        sum += step * fti(i);
    }
    return sum;
}

//sim������
double inge_by_sim(double (*fti)(double x), double start, double end, int intervals)
{
    bool positive = (end - start) ? true : false;
    double length = positive ? end - start : start - end;
    double step = length / intervals;
    double sum = 0.0;
    sum += step * fti(0.0) / 3.0;
    sum += step * fti(end - step) / 3.0;
    for (double i = step; i < end - step; i += step * 2)
    {
        sum += 2.0 * step * fti(i) / 3.0;
    }
    for (double i = 2 * step; i < end - step; i += step * 2)
    {
        sum += 4.0 * step * fti(i) / 3.0;
    }
    return sum;
}

//entrance
int main()
{
    double (*fun_to_be_inte)(double x);          //����ָ��

    fun_to_be_inte = test_function::function_01; //ָ������
    std::cout << inge_by_reac(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << inge_by_ladder(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << inge_by_sim(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << std::endl;

    fun_to_be_inte = test_function::function_02;
    std::cout << inge_by_reac(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << inge_by_ladder(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << inge_by_sim(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << std::endl;

    fun_to_be_inte = test_function::function_03;
    std::cout << inge_by_reac(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << inge_by_ladder(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << inge_by_sim(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << std::endl;

    fun_to_be_inte = test_function::ret1;
    std::cout << inge_by_reac(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << inge_by_ladder(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << inge_by_sim(fun_to_be_inte, 0, 1, 10000) << std::endl;
    std::cout << std::endl;

    //std::system("pause");
    return 0;
}
