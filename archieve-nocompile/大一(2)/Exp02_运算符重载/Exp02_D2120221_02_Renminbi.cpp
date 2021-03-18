/*
D:\GitCode\IGNORE_learn-cpp\cmake-build-debug\IGNORE_learn_cpp.exe
1yuan2jiao3fen
1.23
yuan=1 jiao=2 fen=3
yuan=3 jiao=2 fen=3

Process finished with exit code 0
*/

/*ϰ��4.9
 ����������࣬����̽��м��顣
-  ���ݳ�Ա������Բ���ǡ��֣���Ϊ���͡�
-  ����ת���������������ǿ��ת��Ϊ����������ԲΪ��λ��
��̣�
-  ��Ӻ��ʵ�ͷ�ļ�
-  ���Renminbi��Ķ���
-  ��main()�м�������ת������
*/
/*
���������ת����˵����
�����������Ϳ��Խ�������ǿ��ת������Ҳ���Խ���ͬ����ת��������ͨ����������ת������ʵ�ֵġ�
��ֻ������ĳ�Ա��������������Ԫ��������ʽΪ��
     ����::operator  ת�������������( ) {��}
�磺operator float()��ת��Ϊ�������ĳ�Ա������
ʹ��ʱ�ĸ�ʽΪ�� float(������);  ��   (float) ������;
ע�⣺������һ���������ʱ��
     float (������);    �൱������һ���Զ�����Ϊ��ʶ����float�ͱ���
     (float) ������;    �������ǿ��ת���˶�����Ϊfloat,�����������壬���ı�ö������͡�
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
    cout << (float) r1 << endl;  //ǿ������ת��
    cout << r1 << endl;         //��ʽ����ת��

    Renminbi r;
    r = r1 + 2;          //�Ƚ�����+�Ͳ�����+ʱ������ı����ִ�н����˼��Ϊʲô��
    cout << r << endl;   //�����Ϊ�㶨�����Ĳ�ͬ�����ֲ�ͬ�����˼��Ϊʲô��
    return 0;
}