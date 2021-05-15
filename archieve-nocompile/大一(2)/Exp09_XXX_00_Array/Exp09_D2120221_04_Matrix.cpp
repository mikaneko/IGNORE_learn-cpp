/* 
  P160.����5.5���Զ�ά������Ϊ��������������ʵ�̶ֹ�ά��int�͵ľ������㡣
  P183.����5.4����һά�����������������Ϊ����������ʵ��int�͵ľ�������ͨ���㷨��
  P188.����6.2����һά������Ϊģ����������ͣ��ú���ģ��ʵ��int�͵ľ�������ͨ���㷨��
  ����ʵ������������˼�룬�ڵ�Ϊ��һά��̬���顱����ʽ��ʵ�־������
  ���������ݽṹ��һ��Ӧ��ʵ����

  ����Ľ�����Array�ඨ��Ķ�̬���飬
- �����ݴ洢����ָ��pArrָ��Ķ�̬���ٵ�����ռ�
 ���ռ�Ĵ�С���жϳ��ֽ���len�󣬶�̬���ٵĳ���Ϊlen������pArr����
- �������йصĻ�����������Ϊ�����ĳ�Ա������
- pArr��Ŀǰ�趨���len��int�����ݣ�����д�ø�ͨ�ã����������и���ģ�嶨�塣
  
  �������Matrix�ඨ�壬����������Ĳ�������Ϊ������ĳ�Ա����������:
 -	��������������ݡ����������ȡ���ӡ�������ݡ��Ƴ�ָ�����
 -	��������ȵȡ� 
    
���Ҫ��
-    1 Array���������Ͷ���ĳ�Ա�������������죬��������ӡ���ݣ��Լ��������ȡ� 
-    2 Matrix���������Ͷ��������Ļ���������Ա������
-    3 ���ԣ���ɸ���Ա�����Ĳ��ԡ�
*/

/*
˼���⣺(���ڱ�ע������ش�)
˳���Ԫ�����ͱ���һ�£�������Ԫ�����Ϳ��Բ�һ�¡�
����Ҫ�����������ָ����ָ��ͬ�������ݣ�˼������ζ��壿
��
������typename��ģ�壬data��link�ò�ͬ��ģ������
��ȻҲ���Խṹ����һ���������ݶΣ�һ������ָ��Ρ�

*/

#include <cstring>
#include <assert.h>
#include <iostream>
using namespace std;

class Matrix; //ǰ����������

//======== ����ඨ�� ========//
class Array
{
    int len;     //��ŵ����ݸ���
    int *pArr;   //Ŀǰ�趨���len��int������
    Array *link; //Ҳ�����ж���Ϊ˫�����������
public:
    Array();
    ~Array();
    //��������вΣ����ƹ��캯����
    Array(int from[], int len);
    Array(const Array &arr);
    //����������ȡԪ�أ�����Ԫ�أ���ӡԪ�صȺ������������
    void show();
    //������ӽ����ز�������
    friend class Matrix;
};

//======== �����ඨ�� ========//
//���ò������������������������������롢ɾ����ȡ���ݵ�
class Matrix
{
private:
    Array *head; //����ͷָ��
public:
    Matrix(); //���캯��������ͷ���(������)��
              //Ҳ�ɶ��岻��ͷ����������ɾ�������ķ�װ
    Matrix(int arr[]);
    ~Matrix(); //��������
    //������Ӿ���������ز����������������
    int len();
    void push(const Array &arr);
    void push_head(const Array &arr);
    void del();
    void del_head();
    void show();
};

Array::Array()
{
    len = 0;
    pArr = NULL;
    link = NULL;
}

Array::Array(int from[], int _len)
{
    len = _len;
    assert(pArr = new int[_len]);
    for (int i = 0; i < _len; i++)
    {
        pArr[i] = from[i];
    }
    link = NULL;
}
Array::Array(const Array &arr)
{
    len = arr.len;
    assert(pArr = new int[len]);
    for (int i = 0; i < len; i++)
    {
        pArr[i] = arr.pArr[i];
    }
    link = NULL;
}

void Array::show()
{
    for (int i = 0; i < len; i++)
    {
        cout << pArr[i] << '\t';
    }
    cout << endl;
}
Array::~Array()
{
    if (pArr)
        delete pArr;
}

Matrix::Matrix()
{
    assert(head = new Array);
}

Matrix::~Matrix()
{
    if (head)
        delete head;
}

int Matrix::len()
{
    Array *p = head;
    int counter = 0;
    while (p->link != NULL)
    {
        counter++;
    }
    return counter;
}

void Matrix::push(const Array &arr)
{
    Array *p = head;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = new Array(arr);
    p = p->link;
}

void Matrix::push_head(const Array &arr)
{
    Array *pt = head->link;
    head->link = new Array(arr);
    head->link->link = pt;
}

void Matrix::del()
{
    Array *p = head;
    while (p->link->link != NULL)
    {
        p = p->link;
    }
    delete p->link;
    p->link = NULL;
}
void Matrix::show()
{
    Array *p = head->link;
    while (p != NULL)
    {
        for (int i = 0; i < p->len; i++)
        {
            cout << p->pArr[i] << ' ';
        }
        cout << endl;
        p = p->link;
    }
}
void Matrix::del_head()
{
    Array *pt = head->link->link;
    delete head->link;
    head->link = pt;
}

int main()
{
    Matrix m1;
    int arr1[3] = {3, 2, 1};
    int arr2[3] = {33, 44, 55};
    int arr3[3] = {66, 66, 66};
    int arr4[3] = {6126, 1212, 342};
    Array ar1(arr1, 3);
    Array ar2(arr2, 3);
    Array ar3(arr3, 3);
    Array ar4(arr4, 3);
    m1.push(ar1);
    m1.push(ar2);
    m1.push(ar3);
    m1.show();
    cout << endl
         << endl;
    m1.del_head();
    m1.show();
    cout << endl
         << endl;
    m1.push_head(ar4);
    m1.show();
    cout << endl
         << endl;
    //system("pause");

    return 0;
}