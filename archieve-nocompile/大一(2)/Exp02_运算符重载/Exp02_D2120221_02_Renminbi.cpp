/*
D:\GitCode\IGNORE_learn-cpp\cmake-build-debug\IGNORE_learn_cpp.exe
1yuan2jiao3fen
1.23
yuan=1 jiao=2 fen=3
yuan=3 jiao=2 fen=3

Process finished with exit code 0
*/

/*习题4.9
 定义人民币类，并编程进行检验。
-  数据成员包括：圆、角、分，均为整型。
-  类型转换函数将人民币类强制转换为浮点数，以圆为单位。
编程：
-  添加合适的头文件
-  完成Renminbi类的定义
-  在main()中检验类型转换操作
*/
/*
对类的类型转换的说明：
内置数据类型可以进行类型强制转换，类也可以进行同样的转换，这是通过定义类型转换函数实现的。
它只能是类的成员函数，不能是友元函数。格式为：
     类名::operator  转换后的数据类型( ) {…}
如：operator float()是转换为浮点数的成员函数。
使用时的格式为： float(对象名);  或   (float) 对象名;
注意：若单独一个如下语句时：
     float (对象名);    相当于声明一个以对象名为标识符的float型变量
     (float) 对象名;    在语句内强制转换了对象名为float,但无其他意义，不改变该对象类型。
*/
#include <iostream>

using namespace std;

class Renminbi
{
private:
    int yuan, jiao, fen;
public:
    Renminbi(int _v1 = 0, int _v2 = 0, int _v3 = 0)
    {
        yuan = _v1;
        jiao = _v2;
        fen = _v3;
    }

    Renminbi(const Renminbi &_v)
    {
        yuan = _v.yuan;
        jiao = _v.jiao;
        fen = _v.fen;
    }

    ~Renminbi()
    {
    }

    operator float()
    {
        return yuan + jiao / 10.0 + fen / 100.0;
    }

    void Show()
    {
        cout << yuan << "yuan" << jiao << "jiao" << fen << "fen" << endl;
    }

    Renminbi operator+(int a)
    {
        return Renminbi(yuan + a, jiao, fen);
    }

    Renminbi &operator=(const Renminbi &a)
    {
        yuan = a.yuan;
        jiao = a.jiao;
        fen = a.fen;
        return *this;
    }

    friend ostream &operator<<(ostream &a, const Renminbi &b);
};

ostream &operator<<(ostream &a, const Renminbi &b)
{
    a << "yuan=" << b.yuan << " jiao=" << b.jiao << " fen=" << b.fen;
    return a;
}


int main()
{
    Renminbi r1(1, 2, 3);
    r1.Show();
    cout << (float) r1 << endl;  //强制类型转换
    cout << r1 << endl;         //隐式类型转换

    Renminbi r;
    r = r1 + 2;          //比较重载+和不重载+时，本句的编译和执行结果，思考为什么？
    cout << r << endl;   //输出因为你定义的类的不同而呈现不同结果，思考为什么？
    return 0;
}