//D2120221

//friend函数重载
/*
D:\GitCode\IGNORE_learn-cpp\cmake-build-debug\IGNORE_learn_cpp.exe
Real=1	Image=1
Real=1.2333	Image=1
Real=6	Image=6
Real=7	Image=7
Real=1.5	Image=1
Real=1.5	Image=1
Real=0	Image=16
Real=4	Image=0
c3的模为：5.65685
Real=1	Image=1
Real=4	Image=4

Process finished with exit code 0
*/

//member函数重载
/*
Invalid operands to binary expression ('double' and 'Complex')
Invalid operands to binary expression ('double' and 'Complex')
*/

//common函数重载
/*
Real=1	Image=1
Real=1.2333	Image=1
Real=6	Image=6
Real=7	Image=7
Real=1.5	Image=1
Real=1.5	Image=1
Real=0	Image=16
Real=4	Image=0
c3的模为：5.65685
Real=1	Image=1
Real=4	Image=4

Process finished with exit code 0
*/


/*
参考" 实验12范例1，P130例4.8，P137例4.8_1"，改造复数类
在例4.8.构造的 Complex 类的基础上，添加完善类的声明和定义
-  复数类的数据成员包括：实部和虚部，
-  操作包括：显示，输入和运算符的重载。
编程：
-  添加合适的头文件。
-  静态成员的定义和使用。
-  赋值运算符=的重载
-  复合赋值运算符+=，-=，*=，/=的重载
-  前置/后置，++，--运算符的重载。
-  通过预编译选项分别用成员函数和友元函数重载算术运算符。
-  在main()中调用检验操作的函数。
【注：体会“友元函数”、“成员函数”和“普通函数”在使用上的不同。】
*/


/*****************************************************
设置编译选项“MATH_OPERATOR”为
-  _MEMBER_FUN_  为1时，使用成员函数重载算术运算符，代码已给
-  _FRIEND_FUN_  为1时，使用友元函数重载算术运算符
-  _COMMON_FUN_  为1时，使用普通函数重载算术运算符
体会三者者在函数实现以及测试main函数中要求的算式时的差异。

若实无法理解预编译命令，则无需修改下面三行命令行的现有设置，
然后，仅使用友元函数重载算术运算符
即，仅在#if  _FRIEND_FUN_ 和其后的#endif之间完成代码。
*****************************************************/
#define _MEMBER_FUN_  0
#define _FRIEND_FUN_  0
#define _COMMON_FUN_  1

#include <iostream>
#include <cmath>

using namespace std;

//Complex类的声明和定义
class Complex
{
    //静态成员
    static int num;                                         //对象数量;
    static void ShowNum()
    { cout << "Show Num: " << num << endl; }    //显示对象数
    //Tips:静态成员不属于特定的对象，故静态函数不可以声明为const成员函数。
    //     且只可访问静态成员变量。

    double Real;
    double Image;
public:
    //补充完善构造函数和析构函数，可在构造和析构函数中添加观察语句，观察对象的创建和撤销
    //注意构造时对象数量，静态成员num要加一
    //注意析构时对象数量，静态成员num要减一
    Complex(double _v1 = 0, double _v2 = 0)
    {
        Real = _v1;
        Image = _v2;
        num++;
    }

    Complex(const Complex &_c)
    {
        Real = _c.Real;
        Image = _c.Image;
        num++;
    }
    ~Complex()
    {
        num--;
    }

    void Print()
    { cout << "Real=" << Real << '\t' << "Image=" << Image << '\n'; }

    //访问和设置函数
    double getReal() const;

    double getImage() const;

    void setReal(double);

    void setImage(double);

    //赋值运算符
    Complex &operator=(const Complex &c2);

    //复合赋值运算符
    Complex &operator+=(const Complex &c2);

    Complex &operator-=(const Complex &c2);

    Complex &operator*=(const Complex &c2);

    Complex &operator/=(const Complex &c2);

    //前置++，--  仅为理解两类运算符的重载，对实部进行+1或-1运算。
    Complex &operator++();

    Complex &operator--();

    //后置++，--  仅为理解两类运算符的重载，对实部进行+1或-1运算。
    Complex operator++(int dummy);

    Complex operator--(int dummy);

    double abs(void) const; //求模

    //使用成员函数重载运算符
#if  _MEMBER_FUN_
    //算术运算
    Complex operator+(const Complex& c2) const;
    Complex operator-(const Complex& c2) const;
    Complex operator*(const Complex& c2) const;
    Complex operator/(const Complex& c2) const;
#endif

#if  _FRIEND_FUN_

    //友元函数重载算术运算符
    friend Complex operator+(const Complex &c1, const Complex &c2);

    friend Complex operator-(const Complex &c1, const Complex &c2);

    friend Complex operator*(const Complex &c1, const Complex &c2);

    friend Complex operator/(const Complex &c1, const Complex &c2);

#endif
};





int Complex::num=0;





#if _COMMON_FUN_

//普通函数重载算术运算符的声明，
Complex operator+(const Complex &c1, const Complex &c2);

Complex operator-(const Complex &c1, const Complex &c2);

Complex operator*(const Complex &c1, const Complex &c2);

Complex operator/(const Complex &c1, const Complex &c2);

#endif


//访问和设置函数
double Complex::getReal() const
{
    return Real;
}

double Complex::getImage() const
{
    return Image;
}

void Complex::setReal(double _real)
{
    Real = _real;
}

void Complex::setImage(double _image)
{
    Image = _image;
}


//赋值运算符，
Complex &Complex::operator=(const Complex &c2)
{
    Real = c2.Real;
    Image = c2.Image;
    return *this;   //必须是成员函数才有this指针
}

//复合赋值运算符+=
Complex &Complex::operator+=(const Complex &c2)
{
    (*this).Real = Real + c2.Real;
    (*this).Image = Image + c2.Image;
    return *this;
}


Complex &Complex::operator-=(const Complex &c2)
{
    Real -= c2.Real;
    Image -= c2.Image;
    return *this;
}

Complex &Complex::operator*=(const Complex &c2)
{
    Real *= c2.Real;
    Image *= c2.Image;
    return *this;
}

Complex &Complex::operator/=(const Complex &c2)
{
    Real /= c2.Real;
    Image /= c2.Image;
    return *this;
}

Complex &Complex::operator++()
{
    Real++;
    return *this;
}

Complex &Complex::operator--()
{
    Real--;
    return *this;
}

Complex Complex::operator++(int dummy)
{
    Complex tmp(*this);
    Real++;
    return tmp;
}

Complex Complex::operator--(int dummy)
{
    Complex tmp(*this);
    Real--;
    return tmp;
}


double Complex::abs() const
{
    return sqrt(Real * Real + Image * Image);
}

#if _MEMBER_FUN_
//成员函数重载的算术运算+
Complex  Complex::operator+(const Complex &c2) const
{
    return  Complex(Real+c2.Real, Image+c2.Image) ;  //隐式说明局部对象，只使用一次的无名/匿名对象。
    //可在析构函数中将对象数减一时，观察静态成员变量num的值
}

//算术运算-
Complex  Complex::operator-(const Complex &c2) const
{
    return  Complex(Real-c2.Real, Image-c2.Image);
}

//算术运算*
Complex Complex::operator*(const Complex &c2) const
{
    return Complex(Real*c2.Real-Image*c2.Image , Real*c2.Image+c2.Real*Image);
}

//算术运算/
Complex Complex::operator/(const Complex &c2) const
{
    double d=c2.Real*c2.Real+c2.Image*c2.Image;
    return Complex((Real*c2.Real+Image*c2.Image)/d , (Image*c2.Real-Real*c2.Image)/d);
}
#endif


#if  _FRIEND_FUN_

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.Real + c2.Real, c1.Image + c2.Image);
}

Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.Real - c2.Real, c1.Image - c2.Image);
}

Complex operator*(const Complex &c1, const Complex &c2)
{
    return Complex(c1.Real * c2.Real - c1.Image * c2.Image, c1.Real * c2.Image + c2.Real * c1.Image);
}

Complex operator/(const Complex &c1, const Complex &c2)
{
    double d = c2.Real * c2.Real + c2.Image * c2.Image;
    return Complex((c1.Real * c2.Real + c1.Image * c2.Image) / d, (c1.Image * c2.Real - c1.Real * c2.Image) / d);
}

#endif



//请在 #if _COMMON_FUN_与 #endif 之间自行完成普通函数重载算术运算符的定义
#if _COMMON_FUN_

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.getReal() + c2.getReal(), c1.getImage() + c2.getImage());
}

Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.getReal() - c2.getReal(), c1.getImage() - c2.getImage());
}

Complex operator*(const Complex &c1, const Complex &c2)
{
    return Complex(c1.getReal() * c2.getReal() - c1.getImage() * c2.getImage(),
                   c1.getReal() * c2.getImage() + c2.getReal() * c1.getImage());
}

Complex operator/(const Complex &c1, const Complex &c2)
{
    double d = c2.getReal() * c2.getReal() + c2.getImage() * c2.getImage();
    return Complex((c1.getReal() * c2.getReal() + c1.getImage() * c2.getImage()) / d,
                   (c1.getImage() * c2.getReal() - c1.getReal() * c2.getImage()) / d);
}

#endif







//注意对静态数据成员的定义性说明




//注意使用静态成员函数观察对象数量
int main(void)
{
    Complex c1(1.0, 1.0), c2(2.0, 2.0), c3(4.0, 4.0), c;
    double d = 0.2333;

    c1.Print();

    c = d + c1;
    c.Print();

    c = c2 + c3;
    c.Print();

    c += c1;
    c.Print();

    c = 0.5 + c1;
    c.Print();                    //复数加实数

    c = c1 + 0.5;
    c.Print();                    //复数加实数

    c = c3 * c2;  //自行添加常量参与*运算的测试
    c.Print();

    c = c3 / c1;  //自行添加常量参与/运算的测试
    c.Print();

    cout << "c3的模为：" << c3.abs() << endl;

    c = c3 = c2 = c1;
    c.Print();               //连续赋值

    c += c3 += c2 += c1;
    c.Print();              //连续加赋值

    return 0;
}