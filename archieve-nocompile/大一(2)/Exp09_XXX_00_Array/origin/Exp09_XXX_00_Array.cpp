/* 
  本题为前期掌握程度欠佳的同学设计。
  建议但不局限于期中考试80分以下同学完成（一班二班各7位同学）。  
  
  已较好掌握深复制的同学约可以用20~30分钟完成本题，视自己的程度自选完成。
  本次作业第4题矩阵的一种测试方案可参考本题。
   
编程要求：
-    1 Array类中已给部分成员函数的声明，包括构造，析构，打印数据等。 
-    2 完成给出声明的成员函数的类外定义：注意，是类外定义。
-    3 完成友元函数的类内定义。
-    4 测试：完成各成员函数或友元函数的测试。

已给整型测例一，策略对构造函数的测试仅使用到二参构造函数，
更多更丰富的函数测试以及其他类型测试自行设计完成。

测例的运行结果为：
v1向量是：6 2 7
v2向量是：3 8 4
v3向量是：9 5 1
级联v1、v2、v3得到的向量是：6 2 7 3 8 4 9 5 1
*/

#include <iostream>
using namespace std;


//======== 动态数组模板类定义 ========//
template <typename T> class Array
{
    T*  pArr;       //动态数组
    int len;        //存放的数据个数
public:
    ~Array();       //析构
    
    Array();        //无参构造，仅初始化类成员数据值，不动态分配空间
    Array(int len); //一参构造，动态分配elem数组空间，参数len为数组长度，动态数组内容不初始化。
    Array(int len, const T* pT); //两参构造，动态分配elem数组空间，参数len为数组长度，参数pT为长度为len的数组，用于初始化elem数组。
    //或自行修改函数声明，将上述三个函数合并为一个函数实现，合并后更要注意分支的完整性。
    
    Array(const Array& pArr);                 //深复制
    Array& operator=(const Array& arr);       //深赋值
    Array  operator+(const Array& arr) const; //重载+
    
    void print(); //打印，若不会重载<<，>>，先用打印函数测试 
    
    //模板类的友元函数，必须类内完成定义 
    friend istream& operator>>(istream& is, Array& arr) {} 
    friend ostream& operator<<(ostream& os, const Array& arr) {}
};

int main()
{
    int matrix[3][3]={
          6, 2, 7,
          3, 8, 4,
          9, 5, 1    };
    
    Array<int> v1(3,matrix[0]);
    Array<int> v2(3,matrix[1]);
    Array<int> v3(3,matrix[2]);
    Array<int> concat;
    
    cout<<"v1向量是：";     v1.print();
    cout<<"v2向量是：";     v2.print();
    cout<<"v3向量是：";     v3.print();
    concat=v1+v2+v3;
    cout<<"级联v1、v2、v3得到的向量是：";
    concat.print();
    
    return 0;
}
