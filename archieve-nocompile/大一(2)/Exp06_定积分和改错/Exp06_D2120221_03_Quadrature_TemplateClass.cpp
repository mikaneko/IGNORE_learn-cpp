// encoding: ansi-gbk

/*
��Ŀ��ʵ��17������2��������ֽ��Ʒ������������ָ������Ķ����֡�
���Ҫ��
-  ģ��P210,��6.11�����������ָ�����䶨���ֵ���ģ�壬
   �󶨻��ֺ���ģ����Ϊ��ģ��ĳ�Ա������
   �����������ͨ�����Ͳ����ľ�̬���࣬����Ϊ��ģ���˽�г�Ա��
   �󶨻��ֺ���ģ�壬������ģ��Ĵ����������Ա����������̬���࣬ʶ��������������ʵ��ͨ���ԡ�
-  ��Ӻ��ʵ�ͷ�ļ���
-  Ϊ���������ý��Ʒ������б����������ж����ּ��㡣

   sin(x)��      ����Ϊ 0.0 ������Ϊ��/2��   [-cosx]=0-(-1)=1                              
   exp(x)��      ����Ϊ 0.0 ������Ϊ 1.0��  [exp(x)]=2.718281828459045-1=1.718281828459045 
   4.0/(1+x*x)�� ����Ϊ 0.0 ������Ϊ 1.0��  [4.0arctan(x)]=pi=3.141592653589794            
   
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
    //���¸�ֵ
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

    //���η�����(�������������ޣ��������ޣ��ָ���������)
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

    //ladder������
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

    //sim������
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
