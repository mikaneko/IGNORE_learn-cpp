//D2120221

//friend��������
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
c3��ģΪ��5.65685
Real=1	Image=1
Real=4	Image=4

Process finished with exit code 0
*/

//member��������
/*
Invalid operands to binary expression ('double' and 'Complex')
Invalid operands to binary expression ('double' and 'Complex')
*/

//common��������
/*
Real=1	Image=1
Real=1.2333	Image=1
Real=6	Image=6
Real=7	Image=7
Real=1.5	Image=1
Real=1.5	Image=1
Real=0	Image=16
Real=4	Image=0
c3��ģΪ��5.65685
Real=1	Image=1
Real=4	Image=4

Process finished with exit code 0
*/


/*
�ο�" ʵ��12����1��P130��4.8��P137��4.8_1"�����츴����
����4.8.����� Complex ��Ļ����ϣ����������������Ͷ���
-  ����������ݳ�Ա������ʵ�����鲿��
-  ������������ʾ�����������������ء�
��̣�
-  ��Ӻ��ʵ�ͷ�ļ���
-  ��̬��Ա�Ķ����ʹ�á�
-  ��ֵ�����=������
-  ���ϸ�ֵ�����+=��-=��*=��/=������
-  ǰ��/���ã�++��--����������ء�
-  ͨ��Ԥ����ѡ��ֱ��ó�Ա��������Ԫ�������������������
-  ��main()�е��ü�������ĺ�����
��ע����ᡰ��Ԫ������������Ա�������͡���ͨ��������ʹ���ϵĲ�ͬ����
*/


/*****************************************************
���ñ���ѡ�MATH_OPERATOR��Ϊ
-  _MEMBER_FUN_  Ϊ1ʱ��ʹ�ó�Ա������������������������Ѹ�
-  _FRIEND_FUN_  Ϊ1ʱ��ʹ����Ԫ�����������������
-  _COMMON_FUN_  Ϊ1ʱ��ʹ����ͨ�����������������
����������ں���ʵ���Լ�����main������Ҫ�����ʽʱ�Ĳ��졣

��ʵ�޷����Ԥ��������������޸��������������е��������ã�
Ȼ�󣬽�ʹ����Ԫ�����������������
��������#if  _FRIEND_FUN_ ������#endif֮����ɴ��롣
*****************************************************/
#define _MEMBER_FUN_  0
#define _FRIEND_FUN_  0
#define _COMMON_FUN_  1

#include <iostream>
#include <cmath>

using namespace std;

//Complex��������Ͷ���
class Complex
{
    //��̬��Ա
    static int num;                                         //��������;
    static void ShowNum()
    { cout << "Show Num: " << num << endl; }    //��ʾ������
    //Tips:��̬��Ա�������ض��Ķ��󣬹ʾ�̬��������������Ϊconst��Ա������
    //     ��ֻ�ɷ��ʾ�̬��Ա������

    double Real;
    double Image;
public:
    //�������ƹ��캯�����������������ڹ����������������ӹ۲���䣬�۲����Ĵ����ͳ���
    //ע�⹹��ʱ������������̬��ԱnumҪ��һ
    //ע������ʱ������������̬��ԱnumҪ��һ
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

    //���ʺ����ú���
    double getReal() const;

    double getImage() const;

    void setReal(double);

    void setImage(double);

    //��ֵ�����
    Complex &operator=(const Complex &c2);

    //���ϸ�ֵ�����
    Complex &operator+=(const Complex &c2);

    Complex &operator-=(const Complex &c2);

    Complex &operator*=(const Complex &c2);

    Complex &operator/=(const Complex &c2);

    //ǰ��++��--  ��Ϊ�����������������أ���ʵ������+1��-1���㡣
    Complex &operator++();

    Complex &operator--();

    //����++��--  ��Ϊ�����������������أ���ʵ������+1��-1���㡣
    Complex operator++(int dummy);

    Complex operator--(int dummy);

    double abs(void) const; //��ģ

    //ʹ�ó�Ա�������������
#if  _MEMBER_FUN_
    //��������
    Complex operator+(const Complex& c2) const;
    Complex operator-(const Complex& c2) const;
    Complex operator*(const Complex& c2) const;
    Complex operator/(const Complex& c2) const;
#endif

#if  _FRIEND_FUN_

    //��Ԫ�����������������
    friend Complex operator+(const Complex &c1, const Complex &c2);

    friend Complex operator-(const Complex &c1, const Complex &c2);

    friend Complex operator*(const Complex &c1, const Complex &c2);

    friend Complex operator/(const Complex &c1, const Complex &c2);

#endif
};





int Complex::num=0;





#if _COMMON_FUN_

//��ͨ�������������������������
Complex operator+(const Complex &c1, const Complex &c2);

Complex operator-(const Complex &c1, const Complex &c2);

Complex operator*(const Complex &c1, const Complex &c2);

Complex operator/(const Complex &c1, const Complex &c2);

#endif


//���ʺ����ú���
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


//��ֵ�������
Complex &Complex::operator=(const Complex &c2)
{
    Real = c2.Real;
    Image = c2.Image;
    return *this;   //�����ǳ�Ա��������thisָ��
}

//���ϸ�ֵ�����+=
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
//��Ա�������ص���������+
Complex  Complex::operator+(const Complex &c2) const
{
    return  Complex(Real+c2.Real, Image+c2.Image) ;  //��ʽ˵���ֲ�����ֻʹ��һ�ε�����/��������
    //�������������н���������һʱ���۲쾲̬��Ա����num��ֵ
}

//��������-
Complex  Complex::operator-(const Complex &c2) const
{
    return  Complex(Real-c2.Real, Image-c2.Image);
}

//��������*
Complex Complex::operator*(const Complex &c2) const
{
    return Complex(Real*c2.Real-Image*c2.Image , Real*c2.Image+c2.Real*Image);
}

//��������/
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



//���� #if _COMMON_FUN_�� #endif ֮�����������ͨ������������������Ķ���
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







//ע��Ծ�̬���ݳ�Ա�Ķ�����˵��




//ע��ʹ�þ�̬��Ա�����۲��������
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
    c.Print();                    //������ʵ��

    c = c1 + 0.5;
    c.Print();                    //������ʵ��

    c = c3 * c2;  //������ӳ�������*����Ĳ���
    c.Print();

    c = c3 / c1;  //������ӳ�������/����Ĳ���
    c.Print();

    cout << "c3��ģΪ��" << c3.abs() << endl;

    c = c3 = c2 = c1;
    c.Print();               //������ֵ

    c += c3 += c2 += c1;
    c.Print();              //�����Ӹ�ֵ

    return 0;
}