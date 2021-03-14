//utf-8 (should compile with ansi-gbk)
//LF 4space
//D2120221 Haixin ZHANG


/*
为2*2线性方程组：
   ax + by = e
   cx + dy = f
设计类 LinearEquation ,这个类包括
-  私有数据域：a,b,c,d,e,f
-  一个构造函数，参数分别对应：a,b,c,d,e,f
-  一个复制构造函数。
-  六个访问函数，分别get：a,b,c,d,e,f
-  是否可解判断函数，isSolvable(),当ad-bc不为0时，返回真
-  用克莱姆法则求解函数，getX()和getY()
-  编写测试程序，提示用户输入a,b,c,d,e,f的值，打印输出结果，如果不可解，提示用户方程不可解。
-  编写相交点求解程序，提示用户输入两条线段的四个端点(x1,y1)、(x2,y2)、(x3,y3)、(x4,y4)，
   利用 LinearEquation 类来计算相交点,详见PPT

 运行样例二则：

   请输入两线段端点(x1,y1)(x2,y2)(x3,y3)(x4,y4):    2 2 5 -1.0 4.0 2.0 -1.0 -2.0
   两线相交点为: (2.88889, 1.1111)

   请输入两线段端点(x1,y1)(x2,y2)(x3,y3)(x4,y4):    2 2 7 6.0 4.0 2.0 -1.0 -2.0
   两线平行
*/
#include<iostream>

using namespace std;

class LinearEquation
{
    double a, b, c, d, e, f;    //默认是私有的

public:
    LinearEquation();

    LinearEquation(double, double, double, double, double, double);

    LinearEquation(LinearEquation &);

    ~LinearEquation()
    {}

    //myfunction!!!!!!
    void setAll(double, double, double, double, double, double);

    bool isSolvable();

    double determinant();

    double getX();

    double getY();

    //设置器
    void setA(double);

    void setB(double);

    void setC(double);

    void setD(double);

    void setE(double);

    void setF(double);


    //访问器
    double getA() const;

    double getB() const;

    double getC() const;

    double getD() const;

    double getE() const;

    double getF() const;


    void show() const;
};


LinearEquation::LinearEquation()
{
}

LinearEquation::LinearEquation(double _a, double _b, double _c, double _d, double _e, double _f) : a(_a), b(_b), c(_c),
                                                                                                   d(_d), e(_e), f(_f)
{
}

void LinearEquation::setA(double _value)
{
    a = _value;
}

void LinearEquation::setB(double _value)
{
    b = _value;
}

void LinearEquation::setC(double _value)
{
    c = _value;
}

void LinearEquation::setD(double _value)
{
    d = _value;
}

void LinearEquation::setE(double _value)
{
    e = _value;
}

void LinearEquation::setF(double _value)
{
    f = _value;
}

double LinearEquation::getA() const
{
    return a;
}

double LinearEquation::getB() const
{
    return b;
}

double LinearEquation::getC() const
{
    return c;
}

double LinearEquation::getD() const
{
    return d;
}

double LinearEquation::getE() const
{
    return e;
}

double LinearEquation::getF() const
{
    return f;
}

void LinearEquation::show() const
{
    cout << a << ' ' << b << ' ' << c << endl;
    cout << d << ' ' << e << ' ' << f << endl;
}

LinearEquation::LinearEquation(LinearEquation &_l)
{
    a = _l.a;
    b = _l.b;
    c = _l.c;
    d = _l.d;
    e = _l.e;
    f = _l.f;
}

bool LinearEquation::isSolvable()
{
    return bool(a * d - b * c);
}

double LinearEquation::determinant()
{
    return (a * d - b * c);
}

double LinearEquation::getX()                         //a b e
//c d f
{
    double X_determinant = e * d - b * f;
    return X_determinant / determinant();

}


double LinearEquation::getY()
{
    double Y_determinant = a * f - e * c;
    return Y_determinant / determinant();
}

void LinearEquation::setAll(double _a, double _b, double _c, double _d, double _e, double _f)
{
    cout << "Input 6 value: ";
    cin >> _a >> _b >> _c >> _d >> _e >> _f;
}







// caution!
// if __name__ == __main__:

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cout << "1 and 2 dot(type four value)";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "3 and 4 dot(type four value)";
    cin >> x3 >> y3 >> x4 >> y4;
    LinearEquation obj_le(y1 - y2, -(x1 - x2), y3 - y4, -(x3 - x4), x1 * (y1 - y2) - y1 * (x1 - x2),
                          x3 * (y3 - y4) - (x3 - x4) * y3);
    cout << "isSolvable: " << obj_le.isSolvable() << endl;
    cout << "det: " << obj_le.determinant() << endl;
    if (obj_le.isSolvable())
    {
        cout << obj_le.getX() << ' ' << obj_le.getY() << endl;
    }

    return 0;
}

