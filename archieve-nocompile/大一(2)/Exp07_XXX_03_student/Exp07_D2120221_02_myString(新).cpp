//build encoding: gbk
/*
参考P226，例7.4对c字符串的处理，
完备你自定义的MyString类。使之能自动适应不同的串长度。

主要是三个成员函数的处理，即所谓三规则(rule of three)，大三元(the big three)：
-  拷贝构造函数（深复制）
-  赋值运算符“=”（深复制）
-  析构函数（资源释放）
除上述三个函数，所有改变对象内容的运算符均需多考虑考虑内存的管理
-  如 +=  >> [] 运算符 以及 + 运算符返回的对象

进一步理解类的封装性(encapsulation)
-  数据(成员变量)，对数据的操作(成员函数)
-  运算符重载，提高类的使用体验。
-  安全的内存资源动态申请和释放。
*/

//下列成员函数在你自定义的myString类中，
//若有，改造为动态内存申请的。
//若无，新增这些成员函数，且使用动态内存申请适应串长变化。
#define DebugMode 0

#define _POSSIBLE_MAX_INPUT_STRING_LENGTH_ 100

#include <iostream>
#include <cstring>
using namespace std;

class mystring
{
private:
    char *str;
    int last;

public:
    mystring();
    mystring(const char *);     //C风格字符串强制转换为mystring类，要考虑串长
    mystring(const mystring &); //深复制，要考虑串长
    ~mystring();
    void show() const;

    char &operator[](int i);                //返回引用，可读可写，注意越界处理，测试时，注意用英文字符串测试
    mystring &operator=(const mystring &);  //深复制，要考虑串长
    mystring &operator=(const char *);      //C风格字符串强制转换为mystring类，要考虑串长
    mystring &operator+=(const mystring &); //要考虑串长

    //仅支持与本类型对象的运算，故使用成员函数。【不支持与C风格字符串的运算】
    bool operator<(const mystring &) const;
    bool operator==(const mystring &) const;
    mystring operator+(const mystring &) const; //要考虑返回对象的串长

    friend istream &operator>>(istream &, mystring &); //要考虑串长
    friend ostream &operator<<(ostream &, const mystring &);

    void CorrectCinBug(); //额，没有办法的办法
};

mystring::mystring()
{
    str = NULL;
    last = -1;
}

mystring::mystring(const char *s)
{
    str = new char[strlen(s) + 1];
    last = strlen(s);
    for (int i = 0; i <= last; i++)
    {
        str[i] = s[i];
    }
}

mystring::mystring(const mystring &strs)
{
    last = strs.last;
    str = new char[last + 1];
    for (int i = 0; i <= last; i++)
    {
        str[i] = strs.str[i];
    }
}

mystring::~mystring()
{
    if (str)
    {
        delete[] str;
    }
}

void mystring::show() const
{
    if (str)
    {
        cout << str << endl;
    }
    else
    {
        cout << "<NoString>" << endl;
    }
}

char &mystring::operator[](int i)
{
    return str[i];
}

mystring &mystring::operator=(const mystring &strs)
{
    if (str)
    {
        delete[] str;
    }
    last = strs.last;
    str = new char[last + 1];
    for (int i = 0; i <= last; i++)
    {
        str[i] = strs.str[i];
    }
    return *this;
}

mystring &mystring::operator=(const char *s)
{
    if (str)
    {
        delete[] str;
    }
    str = new char[strlen(s) + 1];
    last = strlen(s);
    for (int i = 0; i <= last; i++)
    {
        str[i] = s[i];
    }
    return *this;
}

mystring &mystring::operator+=(const mystring &strs)
{
    mystring temp(*this);
    if (str)
    {
        delete[] str;
    }
    str = new char[strs.last + last + 1];

    for (int i = 0; i < last; i++)
    {
        str[i] = temp.str[i];
    }
    for (int i = last; i <= last + strs.last; i++)
    {
        str[i] = strs.str[i - last];
    }
    last += strs.last;
    return *this;
}

bool mystring::operator<(const mystring &strs) const
{
    return strcmp(str, strs.str) < 0;
}
bool mystring::operator==(const mystring &strs) const
{
    return strcmp(str, strs.str) == 0;
}

mystring mystring::operator+(const mystring &strs) const
{
    mystring temp(*this);
    temp += strs;
    return temp;
}

ostream &operator<<(ostream &os, const mystring &stro)
{
    if (stro.str)
    {
        os << stro.str;
    }
    else
    {
        cout << "<NoString>";
    }
    return os;
}

//重写了
istream &operator>>(istream &is, mystring &stro)
{
    if (stro.str)
    {
        delete[] stro.str;
    }
    char tmp[_POSSIBLE_MAX_INPUT_STRING_LENGTH_+1];
    is>>tmp;
    stro.str = new char[strlen(tmp) + 1];
    strcpy(stro.str,tmp);
    stro.last = strlen(tmp);
    return is;
}

#if DebugMode
int main()
{

    mystring name;
    name = "haha";
    name.show();

    mystring xuehao("121");
    xuehao.show();

    name += xuehao;
    name.show();

    cout << name[1] << endl;

    mystring dizhi;
    dizhi = xuehao + name;
    dizhi.show();

    cout << (xuehao < name) << endl;
    cout << (xuehao == name) << endl;

    mystring gongzuo;
    printf("INPUT: ");
    cin >> gongzuo;
    gongzuo.show();
    cout << gongzuo << endl;
    return 0;
}
#endif