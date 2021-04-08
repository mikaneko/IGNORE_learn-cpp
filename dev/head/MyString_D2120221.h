/*
参考P177，5.6.3自定义字符串类，完善给出的MyString类。

   习题5.11，完善自定义字符串类 MyString，
   函数包括：构造函数、复制构造函数、析构函数，
并重载运算符：
    [ ] (具备读写访问功能);
    = (分别用 MyString 和 C 字符串复制);
    + 、+=(对应strcat);
    <、 >、==(对应strcmp)

   习题5.12， 将习题 5.8 中的字符串处理函数移植到 MyString 类中，请将它们转为成员函数。
   注意对比成员函数与独立函数在参数传递上有何不同？
   字符串函数包括：
   （1）char *strcat (char *s, const char *ct); 将串 ct 接到串 s 的后面，形成一个长串。
   （2）int strlen(const char * s); 求字符串长度的函数，返回串长（不包括串结束符）。
   （3）char * reverse (char *); 反置字符串 s，即可将“break”成为“kaerb”。
   （4）char * strchr( const char *cs,char c); 查找字符 c 在串 cs 中第一次出现的位置，返回指向该字符的指针，若没有出现则返回 NULL。
   （5）char *strstr (const char *cs1,const char *cs2); 返回串 cs2 作为子串在 cs1 中第一次出现的位置，若没有出现则返回 NULL。


编程要求：
-  添加合适的头文件
-  重载赋值构造函数
-  重载关系运算符
-  重载下标运算符[]
-  重载赋值运算符=
-  重载字符串串连接运算符+和+=
-  重载流插入运算符<<和流提取运算符>>，参见9.3.3节例9.5
-  添加字符串处理函数的声明和定义
-  在main()中检验所有操作

*/


#include <iostream>
#include <cstring>


const int n = 21;        //串长限制在 20 个字符或 10 个汉字

class MyString
{
    char str[n];   //存放字符串的数组容器
    int maxsize;   //最大可用元素数，可防止数组出界，提高稳健性
    int last;      //已用元素最大下标
public:
    //mytest
    int getLast()
    {
        return last;
    }

    MyString()     //无参构造函数
    {
        last = -1;
        maxsize = n;
        str[0] = '\0';
    }

    MyString(const char *s)     //当C字符串过长，初始化时采用截尾处理
    {
        last = -1;
        maxsize = n;
        do
        {
            last++;
            str[last] = s[last];
        } while (s[last] != '\0' && last < maxsize - 1);
        str[last] = '\0'; //截尾处理时，必须加串结束符
    }

    ~MyString()
    {}

    void show() const
    { std::cout << str << '\t'; }


    //==============需增加定义的操作============//
    //复制构造函数
    MyString(const MyString &ms);


    //重载关系运算符
    bool operator<(const MyString &) const;     //定义已给
    bool operator>(const MyString &) const;

    bool operator==(const MyString &) const;     //定义已给
    bool operator!=(const MyString &) const;

    //下标运算符，既作访问器(右值运算符)，又作设置器(左值运算符)，故返回引用。
    char &operator[](int);                //测试时，注意用英文字符串测试

    //以下函数返回值不为引用，需调用复制构造函数
    MyString &operator=(const char *ms);      //定义已给 这里重载的=是把C风格字符串赋给MyString
    MyString operator=(const MyString &);      //这里重载的=是把MyString类的对象赋给MyString
    MyString operator+(const MyString &);

    MyString &operator+=(const MyString &);

    //重载流运算符,请参见9.3.3节例9.5
    friend std::istream &operator>>(std::istream &, MyString &);

    friend std::ostream &operator<<(std::ostream &, const MyString &);

    //习题5.12要求的成员函数声明请自行完成，对比成员函数与独立函数构造上有何不同？
    MyString &strcat_my(const MyString &ms); //将串 ct 接到串 s 的后面，形成一个长串。
    int strlen_my(); //求字符串长度的函数，返回串长（不包括串结束符）。
    MyString &reverse_my(); //反置字符串 s，即可将“break”成为“kaerb”。
    char *strchr_my(char c); //查找字符 c 在串 cs 中第一次出现的位置，返回指向该字符的指针，若没有出现则返回 NULL。
    char *strstr_my(const char *cs2); //返回串 cs2 作为子串在 cs1 中第一次出现的位置，若没有出现则返回 NULL。


};

//重载<运算符
bool MyString::operator<(const MyString &ms) const
{
    int i = 0, k;
    do
    {
        k = str[i] - ms.str[i];
        i++;
    } while (k == 0 && i < last && i < ms.last);

    if (k < 0) return true;
    if (i == last && i != ms.last) return true;
    return false;
}

//重载>运算符
bool MyString::operator>(const MyString &ms) const
{
    int i = 0, k;
    do
    {
        k = str[i] - ms.str[i];
        i++;
    } while (k == 0 && i < last && i < ms.last);

    if (k > 0) return true;
    if (i == last && i != ms.last) return true;
    return false;
}


//重载==运算符
bool MyString::operator==(const MyString &ms) const
{
    int i = 0, k;
    if (last != ms.last) return false;
    do
    {
        k = str[i] - ms.str[i];
        i++;
    } while (k == 0 && i < last);

    if (k != 0) return false;
    else return true;
}

//重载!=运算符
bool MyString::operator!=(const MyString &ms) const
{
    int i = 0, k;
    if (last != ms.last) return true;
    do
    {
        k = str[i] - ms.str[i];
        i++;
    } while (k == 0 && i < last);

    if (k != 0) return true;
    else return false;
}

//这里重载的=是把C风格字符串赋给MyString
//这里返回值为引用，不调用复制构造函数
MyString &MyString::operator=(const char *ms)
{
    last = -1;
    do
    {
        last++;
        str[last] = ms[last];
    } while (ms[last] != '\0' && last < maxsize - 1);
    str[last] = '\0';    //截尾处理时，必须加串结束符
    return *this;
}

MyString MyString::operator=(const MyString &ms)
{
    last = 0;
    int ms_pointer = 0;
    while (ms.str[ms_pointer] != '\0')
    {
        str[last] = ms.str[ms_pointer];
        last++;
        ms_pointer++;
    }
    str[last] = '\0';
    //用于副本
    return MyString(*this);
}

// 复制构造函数
MyString::MyString(const MyString &ms)
{
    last = 0;
    int ms_pointer = 0;
    while (ms.str[ms_pointer] != '\0')
    {
        str[last] = ms.str[ms_pointer];
        last++;
        ms_pointer++;
    }
    str[last] = '\0';

}


MyString &MyString::operator+=(const MyString &ms)
{
    int ms_pointer = 0;
    while (ms.str[ms_pointer] != '\0')
    {
        str[last] = ms.str[ms_pointer];
        last++;
        ms_pointer++;
    }
    str[last] = '\0';
    return *this;
}

std::ostream &operator<<(std::ostream &out, const MyString &ms)
{
    out << ms.str;
    return out;
}

std::istream &operator>>(std::istream &in, MyString &ms)
{
    in >> ms.str;
    ms.last = strlen(ms.str);
    return in;
}

char &MyString::operator[](int n)
{
    return str[n];
}

MyString MyString::operator+(const MyString &ms)
{
    MyString tmp(*this);
    int ms_pointer = 0;
    while (ms.str[ms_pointer] != '\0')
    {
        tmp.str[tmp.last] = ms.str[ms_pointer];
        tmp.last++;
        ms_pointer++;
    }
    tmp.str[tmp.last] = '\0';
    return tmp;
}

MyString &MyString::strcat_my(const MyString &ms)
{
    *this += ms;
    return *this;
}

int MyString::strlen_my()
{
    return last;
}

MyString &MyString::reverse_my()
{
    char tmp[n];
    strcpy(tmp, str);
    int theleft = 0;
    int theright = strlen(tmp) - 1;
    while (theleft <= theright)
    {
        char uu = tmp[theleft];
        tmp[theleft] = tmp[theright];
        tmp[theright] = uu;
        theleft++;
        theright--;
    }
    MyString ttmmpp(tmp);
    *this = ttmmpp;
    return *this;
}

char *MyString::strchr_my(char c)
{
    char tmp[n];
    strcpy(tmp, str);
    return strchr(tmp, c);
}

char *MyString::strstr_my(const char *cs2)
{
    char tmp[n];
    strcpy(tmp, str);
    return strstr(tmp, cs2);
}

// 不管了，只要能用就行