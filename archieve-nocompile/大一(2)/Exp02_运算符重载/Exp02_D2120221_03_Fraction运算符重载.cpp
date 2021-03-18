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
�ο��� ʵ��12����1��P130��4.8��P137��4.8_1 �������������
���ݸ����ķ�����Ķ��壬����һ�������ࡣ
-  ����������ݳ�Ա���������Ӻͷ�ĸ��
-  ����������Լ�֡�ͨ�֡��Ƚϡ��ӡ������ˡ�������������ʾ�����롣
-  ����������ء�
��̣�
-  ��Ӻ��ʵ�ͷ�ļ�
-  ����ת��������ֻ���ǳ�Ա������
-  ���ϸ�ֵ�����+=��-=��*=��/=������
-  ǰ��/���ã�++��--����������ء�
-  һԪ������������ŵ����ء�
-  ����ͨ�������������������
-  ����Ԫ�������ع�ϵ�������
-  �����ӻ��ĸ����һ��Ϊ��ֵʱ��Ҫ����������ڷ����ϡ�
   (�����漰���캯�������ӷ�ĸ�����ú������Լ�Լ��ͨ�ֺ�����)
-  ��main()�м������в��������������ʱע����Ե��걸�ԡ�
��ע����ᡰ��Ԫ������������Ա�������͡���ͨ��������ʹ���ϵĲ�ͬ����
*/

#include <string>
#include <iostream>

using namespace std;

//������Ķ���
class Fraction
{
    int Above;         //����
    int Below;         //��ĸ
    void reduction();           //Լ��
    void makeCommon(const Fraction &); //ͨ��

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

    //��д����
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

    //�������
    void input()
    {
        cin >> Above >> Below;
    }

    //��ʾ����
    void display() const
    {
        cout << Above << '/' << Below << endl;
    }

    //����ת����ֻ���ǳ�Ա�������˴�Ϊ�������÷�ʽ��ͬʵ��1����������ϵ���㺯������
    //����ǰ����Ҳ�ɲο�Renminbi�࣬�Զ���ǿ������ת��������
    int intValue() const;

    double doubleValue() const;

    string toString() const;

    Fraction(int);   //���캯������չ��˼��Ϊ�δ˴�����������ת��



    //���ϸ�ֵ�����
    Fraction &operator+=(const Fraction &f2);

    Fraction &operator-=(const Fraction &f2);

    Fraction &operator*=(const Fraction &f2);

    Fraction &operator/=(const Fraction &f2);

    //ǰ��++��--
    Fraction &operator++();

    Fraction &operator--();

    //����++��--
    Fraction operator++(int dummy);

    Fraction operator--(int dummy);

    //һԪ�������������
    Fraction operator+();

    Fraction operator-();

    //�±�0���ʷ��ӣ��±�1���ʷ�ĸ
    int &operator[](int index);

    //����Ԫ�������ع�ϵ�����
    friend bool operator<(const Fraction &f1, const Fraction &f2);

    friend bool operator<=(const Fraction &f1, const Fraction &f2);

    friend bool operator>(const Fraction &f1, const Fraction &f2);

    friend bool operator>=(const Fraction &f1, const Fraction &f2);

    friend bool operator==(const Fraction &f1, const Fraction &f2);

    friend bool operator!=(const Fraction &f1, const Fraction &f2);
};

//����ͨ�����������������
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
    //Լ���㷨
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

void makeCommon(const Fraction &); //ͨ��
///////////////////////////////

//����� in class
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

//ǰ��++��--
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

//����++��--
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

//һԪ�������������
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