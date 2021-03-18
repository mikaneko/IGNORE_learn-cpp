/*
D:\GitCode\IGNORE_learn-cpp\cmake-build-debug\IGNORE_learn_cpp.exe
7/1
7/1
51/28
67/28
67
28
0
1

Process finished with exit code 0
*/

/*
参考“ 实验12范例1，P130例4.8，P137例4.8_1 ”，改造分数类
根据给出的分数类的定义，建立一个分数类。
-  分数类的数据成员包括：分子和分母，
-  操作包括：约分、通分、比较、加、减、乘、除、求倒数、显示和输入。
-  运算符的重载。
编程：
-  添加合适的头文件
-  类型转换函数，只能是成员函数。
-  复合赋值运算符+=，-=，*=，/=的重载
-  前置/后置，++，--运算符的重载。
-  一元运算符，正负号的重载。
-  用普通函数重载算术运算符。
-  用友元函数重载关系运算符。
-  当分子或分母其中一项为负值时，要求符号体现在分子上。
   (可能涉及构造函数，分子分母的设置函数，以及约分通分函数等)
-  在main()中检验所有操作，测试运算符时注意测试的完备性。
【注：体会“友元函数”、“成员函数”和“普通函数”在使用上的不同。】
*/

#include <string>
#include <iostream>

using namespace std;

//分数类的定义
class Fraction
{
    int Above;         //分子
    int Below;         //分母
    void reduction();           //约分
    void makeCommon(const Fraction &); //通分

public:

    Fraction(int a, int b)
    {
        Above = a;
        Below = b;
    }

    Fraction(const Fraction &a)
    {
        Above = a.Above;
        Below = a.Below;
    }

    //读写操作
    int getAbove() const
    {
        return Above;
    }

    int getBelow() const
    {
        return Below;
    }

    void setAbove(int a)
    {
        Above = a;
    }

    void setBelow(int b)
    {
        Below = b;
    }

    //输入分数
    void input()
    {
        cin >> Above >> Below;
    }

    //显示分数
    void display() const
    {
        cout << Above << '/' << Below << endl;
    }

    //类型转换，只能是成员函数。此处为函数调用方式，同实验1中算术，关系运算函数类似
    //其中前两个也可参考Renminbi类，自定义强制类型转换函数。
    int intValue() const;

    double doubleValue() const;

    string toString() const;

    Fraction(int);   //构造函数的扩展，思考为何此处归类入类型转换



    //复合赋值运算符
    Fraction &operator+=(const Fraction &f2);

    Fraction &operator-=(const Fraction &f2);

    Fraction &operator*=(const Fraction &f2);

    Fraction &operator/=(const Fraction &f2);

    //前置++，--
    Fraction &operator++();

    Fraction &operator--();

    //后置++，--
    Fraction operator++(int dummy);

    Fraction operator--(int dummy);

    //一元运算符，正负号
    Fraction operator+();

    Fraction operator-();

    //下标0访问分子，下标1访问分母
    int &operator[](int index);

    //用友元函数重载关系运算符
    friend bool operator<(const Fraction &f1, const Fraction &f2);

    friend bool operator<=(const Fraction &f1, const Fraction &f2);

    friend bool operator>(const Fraction &f1, const Fraction &f2);

    friend bool operator>=(const Fraction &f1, const Fraction &f2);

    friend bool operator==(const Fraction &f1, const Fraction &f2);

    friend bool operator!=(const Fraction &f1, const Fraction &f2);
};

//用普通函数重载算术运算符
Fraction operator+(const Fraction &f1, const Fraction &f2);

Fraction operator-(const Fraction &f1, const Fraction &f2);

Fraction operator*(const Fraction &f1, const Fraction &f2);

Fraction operator/(const Fraction &f1, const Fraction &f2);


//////////////////////////////

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
///////////////////////////////

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
    if (Below < 0)
    {
        Below *= -1;
        Above *= -1;
    }
}

void makeCommon(const Fraction &); //通分
///////////////////////////////

//运算符 in class
Fraction &Fraction::operator+=(const Fraction &_f)
{
    Above = Above * _f.Below + Below * _f.Above;
    Below = Below * _f.Below;
    reduction();
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &_f)
{
    Above = Above * _f.Below - Below * _f.Above;
    Below = Below * _f.Below;
    reduction();
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &_f)
{
    Above = Above * _f.Below + Below * _f.Above;
    Below = Below * _f.Below;
    reduction();
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &_f)
{
    Above = Above * _f.Below - Below * _f.Above;
    Below = Below * _f.Below;
    reduction();
    return *this;
}

//前置++，--
Fraction &Fraction::operator++()
{
    Above = +Below;
    reduction();
    return *this;
}

Fraction &Fraction::operator--()
{
    Above -= Below;
    reduction();
    return *this;
}

//后置++，--
Fraction Fraction::operator++(int dummy)
{
    Fraction tmp(*this);
    ++Above;
    ++Below;
    return tmp;
}

Fraction Fraction::operator--(int dummy)
{
    Fraction tmp(*this);
    --Above;
    --Below;
    return tmp;
}

//一元运算符，正负号
Fraction Fraction::operator+()
{
    return Fraction(Above, Below);
}

Fraction Fraction::operator-()
{
    return Fraction(-Above, Below);
}

int &Fraction::operator[](int index)
{
    if (index == 0)
    {
        return Above;
    }
    else if (index == 1)
    {
        return Below;
    }
    else
    {
        return Below;
    }
}

int Fraction::intValue() const
{
    return Above / Below;
}

double Fraction::doubleValue() const
{
    return Above * 1.0 / Below;
}

string Fraction::toString() const
{
    return string(to_string(Above) + '/' + to_string(Below));
}
//easy part

bool operator<(const Fraction &f1, const Fraction &f2)
{
    int b_f1 = f1.Below, a_f1 = f1.Above, a_f2 = f2.Above, b_f2 = f2.Below;
    if (f1.Below < 0)
    {
        b_f1 = -f1.Below;
        a_f1 = -f1.Above;
    }
    if (f2.Below < 0)
    {
        b_f2 = -f2.Below;
        a_f2 = -f2.Above;
    }
    int above_a = a_f1 * b_f2;
    int above_b = b_f1 * a_f2;
    return above_a < above_b;
}

bool operator<=(const Fraction &f1, const Fraction &f2)
{
    int b_f1 = f1.Below, a_f1 = f1.Above, a_f2 = f2.Above, b_f2 = f2.Below;
    if (f1.Below < 0)
    {
        b_f1 = -f1.Below;
        a_f1 = -f1.Above;
    }
    if (f2.Below < 0)
    {
        b_f2 = -f2.Below;
        a_f2 = -f2.Above;
    }
    int above_a = a_f1 * b_f2;
    int above_b = b_f1 * a_f2;
    return above_a <= above_b;
}

bool operator>(const Fraction &f1, const Fraction &f2)
{
    int b_f1 = f1.Below, a_f1 = f1.Above, a_f2 = f2.Above, b_f2 = f2.Below;
    if (f1.Below < 0)
    {
        b_f1 = -f1.Below;
        a_f1 = -f1.Above;
    }
    if (f2.Below < 0)
    {
        b_f2 = -f2.Below;
        a_f2 = -f2.Above;
    }
    int above_a = a_f1 * b_f2;
    int above_b = b_f1 * a_f2;
    return above_a > above_b;
}

bool operator>=(const Fraction &f1, const Fraction &f2)
{
    int b_f1 = f1.Below, a_f1 = f1.Above, a_f2 = f2.Above, b_f2 = f2.Below;
    if (f1.Below < 0)
    {
        b_f1 = -f1.Below;
        a_f1 = -f1.Above;
    }
    if (f2.Below < 0)
    {
        b_f2 = -f2.Below;
        a_f2 = -f2.Above;
    }
    int above_a = a_f1 * b_f2;
    int above_b = b_f1 * a_f2;
    return above_a >= above_b;
}

bool operator==(const Fraction &f1, const Fraction &f2)
{
    int b_f1 = f1.Below, a_f1 = f1.Above, a_f2 = f2.Above, b_f2 = f2.Below;
    if (f1.Below < 0)
    {
        b_f1 = -f1.Below;
        a_f1 = -f1.Above;
    }
    if (f2.Below < 0)
    {
        b_f2 = -f2.Below;
        a_f2 = -f2.Above;
    }
    int above_a = a_f1 * b_f2;
    int above_b = b_f1 * a_f2;
    return above_a == above_b;
}

bool operator!=(const Fraction &f1, const Fraction &f2)
{
    int b_f1 = f1.Below, a_f1 = f1.Above, a_f2 = f2.Above, b_f2 = f2.Below;
    if (f1.Below < 0)
    {
        b_f1 = -f1.Below;
        a_f1 = -f1.Above;
    }
    if (f2.Below < 0)
    {
        b_f2 = -f2.Below;
        a_f2 = -f2.Above;
    }
    int above_a = a_f1 * b_f2;
    int above_b = b_f1 * a_f2;
    return above_a != above_b;
}

Fraction::Fraction(int a)
{
    Above = a;
    Below = 1;
}

void Fraction::makeCommon(const Fraction &a)
{
    int tmp = gcd(Below, a.Below) / Below;
    Above *= tmp;
    Below *= tmp;
}

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.getAbove() * f2.getBelow() + f1.getBelow() * f2.getAbove(), f1.getBelow() * f2.getBelow());
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.getAbove() * f2.getBelow() - f1.getBelow() * f2.getAbove(), f1.getBelow() * f2.getBelow());
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.getAbove() * f2.getBelow(), f1.getBelow() * f2.getAbove());
}

Fraction operator/(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.getAbove() * f2.getAbove(), f1.getBelow() * f2.getBelow());
}


int main()
{
    Fraction a(5, 4);
    Fraction b(4, 7);
    Fraction c(7);

    c.display();
    cout << c.toString() << endl;

    c = a + b;
    c.display();

    c += b;
    c.display();

    cout << c[0] << endl;
    cout << c[1] << endl;

    Fraction d(-5, 7);
    Fraction e(5, 6);
    cout << (d > e) << endl;
    cout << (d <= e) << endl;
    return 0;

}