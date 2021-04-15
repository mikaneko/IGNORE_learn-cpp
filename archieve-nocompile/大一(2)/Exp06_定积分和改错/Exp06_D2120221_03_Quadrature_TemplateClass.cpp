// encoding: ansi-gbk

/*
题目：实验17，二、2，用求积分近似法，编程求函数在指定区间的定积分。
编程要求：
-  模仿P210,例6.11，设计求函数在指定区间定积分的类模板，
   求定积分函数模板作为类模板的成员函数，
   待求积函数，通过类型参数的静态联编，引入为类模板的私有成员。
   求定积分函数模板，访问类模板的待求积函数成员，编译器静态联编，识别出待求积函数，实现通用性。
-  添加合适的头文件。
-  为检验结果，用近似法对下列被积函数进行定积分计算。

   sin(x)，      下限为 0.0 ，上限为π/2；   [-cosx]=0-(-1)=1                              
   exp(x)，      下限为 0.0 ，上限为 1.0；  [exp(x)]=2.718281828459045-1=1.718281828459045 
   4.0/(1+x*x)， 下限为 0.0 ，上限为 1.0。  [4.0arctan(x)]=pi=3.141592653589794            
   
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

template <typename T>
class inte
{
    double start, end, length;
    bool positive;
    int intervals;
    double results;
    double step;
    T functions_inte;

public:
    //CONSTRACTOR
    inte(T _func, double _start = 0, double _end = 0, int _intervals = 1000)
    {
        start = _start;
        end = _end;
        functions_inte = _func;
        intervals = _intervals;
        positive = (end - start) ? true : false;
        length = positive ? end - start : start - end;
        step = length / intervals;
    }
    //重新赋值
    void assign(T _func, double _start = 0, double _end = 0, int _intervals = 1000)
    {
        start = _start;
        end = _end;
        functions_inte = _func;
        intervals = _intervals;
        positive = (end - start) ? true : false;
        length = positive ? end - start : start - end;
        step = length / intervals;
    }

    //矩形法积分(函数，积分下限，积分上限，分割区间数量)
    double inge_by_reac()
    {
        double sum = 0.0;
        for (double i = start; i < end; i += step)
        {
            sum += step * functions_inte.fun(i);
        }
        results = sum;
        return sum;
    }

    //ladder法积分
    double inge_by_ladder()
    {
        double sum = 0.0;
        sum += step * functions_inte.fun(0.0) / 2.0;
        sum += step * functions_inte.fun(end - step) / 2.0;
        for (double i = step; i < end - step; i += step)
        {
            sum += step * functions_inte.fun(i);
        }
        results = sum;
        return sum;
    }

    //sim法积分
    double inge_by_sim()
    {
        double sum = 0.0;
        sum += step * functions_inte.fun(0.0) / 3.0;
        sum += step * functions_inte.fun(end - step) / 3.0;
        for (double i = step; i < end - step; i += step * 2)
        {
            sum += 2.0 * step * functions_inte.fun(i) / 3.0;
        }
        for (double i = 2 * step; i < end - step; i += step * 2)
        {
            sum += 4.0 * step * functions_inte.fun(i) / 3.0;
        }
        results = sum;
        return sum;
    }

    void show_results()
    {
        std::cout << results << std::endl;
    }
};

int main()
{
    fun_test::F1 f1;
    inte<fun_test::F1> test1(f1, 0, 1, 1000);
    test1.inge_by_reac();
    test1.show_results();
    test1.inge_by_sim();
    test1.show_results();

    fun_test::F2 f2;
    inte<fun_test::F2> test2(f2, 0, 1, 1000);
    test2.inge_by_reac();
    test2.show_results();
    test2.inge_by_ladder();
    test2.show_results();
    test2.inge_by_sim();
    test2.show_results();

    return 0;
}
