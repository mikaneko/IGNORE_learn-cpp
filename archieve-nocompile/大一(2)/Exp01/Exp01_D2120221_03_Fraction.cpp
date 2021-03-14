//utf-8 (should compile with ansi-gbk)
//LF 4space
//D2120221 Haixin ZHANG

/*
实验10，二、2，实验11，二、4， 有理数类 Fraction。

参考实验11范例3，完善已给分数类的定义。
根据给出的分数类的定义，建立一个分数类。
-  分数类的数据成员包括：分子和分母，
-  操作包括：约分、通分、比较、加、减、乘、除、求倒数、显示和输入。
编程：
-  添加合适的头文件，
-  添加复制构造函数的定义，
-  编写程序完成所有给出声明的成员函数的定义（类外定义），
   成员函数形参类型目前均声明为引用。(需要清楚，形参为引用时，传值也可以)
-  如有需要可自行增加新的成员函数。
-  在main()中检验所有操作，思考两个私有成员函数，如何设计测试函数。
*/

#include <iostream>

using namespace std;

//copy from my work


class Fraction
{
private:
    int Above;         //分子
    int Below;         //分母
    void reduction();                 //约分
    void makeCommon(const Fraction);  //通分

public:
    Fraction(int a = 0, int b = 1) : Above(a), Below(b)
    {} //构造函数
    Fraction(Fraction &);               //复制构造函数

    //my
    int gcd(int a, int b)
    {
        int min;
        if (a >= b)
        { min = b; }
        else
        { min = a; }
        int testnum = min;

        while (true)
        {
            if (a % testnum == 0 && b % testnum == 0)
            {
                return testnum;
            }
            testnum--;
        }
    }

    //访问和设置
    int getAbove() const;

    int getBelow() const;

    void setAbove(int a);

    void setBelow(int b);

    void input();                       //输入分数
    void display() const;               //显示分数

    //算术运算
    Fraction add(const Fraction &) const;     //两分数相加
    Fraction sub(const Fraction &) const;     //本分数减去实参分数
    Fraction mul(const Fraction &) const;     //两分数相乘
    Fraction div(const Fraction &) const;     //本分数除以实参分数
    Fraction reciprocal() const;        //求倒数

    //比较
    bool equal(const Fraction &) const;       //等于运算
    bool greaterThan(const Fraction &) const; //大于运算
    bool lessThan(const Fraction &) const;    //小于运算

};

int Fraction::getAbove() const
{
    return Above;
}

int Fraction::getBelow() const
{
    return Below;
}

void Fraction::setAbove(int _a)
{
    Above = _a;
}

void Fraction::setBelow(int _b)
{
    Below = _b;
}

Fraction::Fraction(Fraction &_f)
{
    Above = _f.Above;
    Below = _f.Below;
}

void Fraction::input()
{
    cin >> Above >> Below;
}

void Fraction::display() const
{
    cout << Above << '/' << Below << endl;
}

void Fraction::reduction()
{
    int i = Below;
    //约分算法
    while (true)
    {
        if (i == 1)
        {
            break;
        }
        if (Above % i == 0 && Below % i == 0)
        {
            Below /= i;
            Above /= i;
            i--;
            continue;
        }
        i--;
    }
}

Fraction Fraction::add(const Fraction &_f) const
{
    int new_above = Above * _f.Below + Below * _f.Above;
    int new_below = Below * _f.Below;
    Fraction ret_fraction(new_above, new_below);
    ret_fraction.reduction();
    return ret_fraction;
}

Fraction Fraction::sub(const Fraction &_f) const
{
    int new_above = Above * _f.Below - Below * _f.Above;
    int new_below = Below * _f.Below;
    Fraction ret_fraction(new_above, new_below);
    ret_fraction.reduction();
    return ret_fraction;
}

Fraction Fraction::mul(const Fraction &_f) const
{
    int new_above = Above * _f.Above;
    int new_below = Below * _f.Below;
    Fraction ret_fraction(new_above, new_below);
    ret_fraction.reduction();
    return ret_fraction;
}

Fraction Fraction::div(const Fraction &_f) const
{
    int new_above = Above * _f.Below;
    int new_below = Below * _f.Above;
    Fraction ret_fraction(new_above, new_below);
    ret_fraction.reduction();
    return ret_fraction;
}


Fraction Fraction::reciprocal() const
{
    int new_above = Below;
    int new_below = Above;
    Fraction ret_fraction(new_above, new_below);
    return ret_fraction;
}

bool Fraction::equal(const Fraction &_f) const
{
    int above_a = Above * _f.Below;
    int above_b = Below * _f.Above;
    return above_a == above_b;

}

bool Fraction::greaterThan(const Fraction &_f) const
{
    int above_a = Above * _f.Below;
    int above_b = Below * _f.Above;
    return above_a > above_b;

}

bool Fraction::lessThan(const Fraction &_f) const
{
    int above_a = Above * _f.Below;
    int above_b = Below * _f.Above;
    return above_a < above_b;

}

void Fraction::makeCommon(const Fraction _f)
{
    int aim = gcd(Below, _f.Below);
    Above *= aim / _f.Below;
    Below *= aim / _f.Below;
}

int main()
{
    Fraction f1(5, 4);
    Fraction f2 = f1;
    Fraction f3;
    f3.setAbove(7);
    f3.setBelow(6);

    f1.display();
    f2.display();
    f3.display();

    Fraction f4;
    f4 = f1.add(f3);
    f4.display();

    Fraction f5;
    f5 = f4.reciprocal();
    f5.sub(f1);
    f5.display();
    cout << f5.getAbove() << "/**/" << f5.getBelow() << endl;

    Fraction f6;
    cout << "input(2 value): ";
    f6.input();
    f6.display();

    return 0;
}