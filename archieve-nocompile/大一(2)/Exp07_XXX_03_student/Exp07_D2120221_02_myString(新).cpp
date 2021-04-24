//build encoding: gbk
/*
�ο�P226����7.4��c�ַ����Ĵ���
�걸���Զ����MyString�ࡣʹ֮���Զ���Ӧ��ͬ�Ĵ����ȡ�

��Ҫ��������Ա�����Ĵ�������ν������(rule of three)������Ԫ(the big three)��
-  �������캯������ƣ�
-  ��ֵ�������=������ƣ�
-  ������������Դ�ͷţ�
�������������������иı�������ݵ����������࿼�ǿ����ڴ�Ĺ���
-  �� +=  >> [] ����� �Լ� + ��������صĶ���

��һ�������ķ�װ��(encapsulation)
-  ����(��Ա����)�������ݵĲ���(��Ա����)
-  ��������أ�������ʹ�����顣
-  ��ȫ���ڴ���Դ��̬������ͷš�
*/

//���г�Ա���������Զ����myString���У�
//���У�����Ϊ��̬�ڴ�����ġ�
//���ޣ�������Щ��Ա��������ʹ�ö�̬�ڴ�������Ӧ�����仯��
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
    mystring(const char *);     //C����ַ���ǿ��ת��Ϊmystring�࣬Ҫ���Ǵ���
    mystring(const mystring &); //��ƣ�Ҫ���Ǵ���
    ~mystring();
    void show() const;

    char &operator[](int i);                //�������ã��ɶ���д��ע��Խ�紦������ʱ��ע����Ӣ���ַ�������
    mystring &operator=(const mystring &);  //��ƣ�Ҫ���Ǵ���
    mystring &operator=(const char *);      //C����ַ���ǿ��ת��Ϊmystring�࣬Ҫ���Ǵ���
    mystring &operator+=(const mystring &); //Ҫ���Ǵ���

    //��֧���뱾���Ͷ�������㣬��ʹ�ó�Ա����������֧����C����ַ��������㡿
    bool operator<(const mystring &) const;
    bool operator==(const mystring &) const;
    mystring operator+(const mystring &) const; //Ҫ���Ƿ��ض���Ĵ���

    friend istream &operator>>(istream &, mystring &); //Ҫ���Ǵ���
    friend ostream &operator<<(ostream &, const mystring &);

    void CorrectCinBug(); //�û�а취�İ취
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

//��д��
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