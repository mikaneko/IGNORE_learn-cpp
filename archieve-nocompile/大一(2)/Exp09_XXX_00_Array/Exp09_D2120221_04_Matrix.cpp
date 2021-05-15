/* 
  P160.【例5.5】以二维数组作为函数参数，仅可实现固定维数int型的矩阵运算。
  P183.【题5.4】以一维数组和行数，列数作为函数参数，实现int型的矩阵运算通用算法。
  P188.【例6.2】以一维数组作为模板的数据类型，用函数模板实现int型的矩阵运算通用算法。
  本次实验采用链表类的思想，节点为“一维动态数组”的形式，实现矩阵管理，
  是链表数据结构的一个应用实例。

  链表的结点采用Array类定义的动态数组，
- 将数据存储到由指针pArr指向的动态开辟的数组空间
 （空间的大小在判断出字节数len后，动态开辟的长度为len的数组pArr）。
- 将与结点有关的基本操作都作为结点类的成员函数。
- pArr域，目前设定存放len个int型数据，若想写得更通用，还可以自行改用模板定义。
  
  链表采用Matrix类定义，对链表整体的操作则作为链表类的成员函数，包括:
 -	清空链表、查找数据、计算链表长度、打印链表数据、移除指定结点
 -	生成链表等等。 
    
编程要求：
-    1 Array类中声明和定义的成员函数，包括构造，析构，打印数据，以及结点操作等。 
-    2 Matrix类中声明和定义的链表的基本操作成员函数。
-    3 测试：完成各成员函数的测试。
*/

/*
思考题：(请在本注释区域回答)
顺序表元素类型必须一致，而链表元素类型可以不一致。
若需要链表结点的数据指针域指向不同类型数据，思考该如何定义？
答：
用两个typename的模板，data和link用不同的模板类型
当然也可以结构体中一部分做数据段，一部分做指针段。

*/

#include <cstring>
#include <assert.h>
#include <iostream>
using namespace std;

class Matrix; //前向引用声明

//======== 结点类定义 ========//
class Array
{
    int len;     //存放的数据个数
    int *pArr;   //目前设定存放len个int型数据
    Array *link; //也可自行定义为双链表，丰俭由人
public:
    Array();
    ~Array();
    //自行添加有参，复制构造函数等
    Array(int from[], int len);
    Array(const Array &arr);
    //自行添加如读取元素，设置元素，打印元素等函数，丰俭由人
    void show();
    //自行添加结点相关操作函数
    friend class Matrix;
};

//======== 链表类定义 ========//
//常用操作：包括建立链表、搜索遍历、插入、删除、取数据等
class Matrix
{
private:
    Array *head; //链表头指针
public:
    Matrix(); //构造函数，生成头结点(空链表)，
              //也可定义不带头结点的链表完成矩阵运算的封装
    Matrix(int arr[]);
    ~Matrix(); //析构函数
    //自行添加矩阵运算相关操作函数，丰俭由人
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