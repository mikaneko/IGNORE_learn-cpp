// encoding: ansi-gbk

/*
题目：实验17，二、2，用求积分近似法，编程求函数在指定区间的定积分。
编程要求：
-  模仿P211,例6.12，设计求函数在指定区间定积分的函数模板，
   求定积分函数模板作为普通非成员函数，将待求积函数定义为类。
   以类模板为参数，实现通用算法。
-  添加合适的头文件。
-  为检验结果，用近似法对下列被积函数进行定积分计算。

   sin(x)，      下限为 0.0 ，上限为π/2；      [-cosx]=0-(-1)=1                              
   exp(x)，      下限为 0.0 ，上限为 1.0；     [exp(x)]=2.718281828459045-1=1.718281828459045 
   4.0/(1+x*x)， 下限为 0.0 ，上限为 1.0。     [4.0arctan(x)]=pi=3.141592653589794            
   
-  完成了上面三个函数的测试后，可以自行构造函数，设置求积区间，并完成求积计算。
-  矩形法rectangle为课本范例，是本次作业的基本要求。
-  学有余力的同学分别用：矩形法rectangle，梯形法ladder，辛普森法Simpson进行定积分计算，
   并比较积分精度。
*/

#include <iostream>
// #include <string>
#include <cmath>
// #include "useful_tool.h"

//测试函数
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

template <typename T> //矩形法积分(函数，积分下限，积分上限，分割区间数量)
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

template <typename T> //ladder法积分
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

template <typename T> //sim法积分
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