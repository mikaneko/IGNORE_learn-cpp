//utf-8 (should compile with ansi-gbk)
//LF 4space
//D2120221 Haixin ZHANG

/*
习题4.4，
实验11，二-3，Rectangle类

在例4.2. 构造的 Rectangle 类的基础上，根据实验11范例3，添加完善类的声明和定义
- 属性为矩形的左下与右上角的坐标，矩形水平放置
- 操作为计算矩形的宽度，高度，周长与面积。
注意：
-  模仿标准库的CRect类，设计标准化矩形的成员函数，
   使得：left小于right, top小于bottom
-  注意原点(电脑屏幕的左上角顶点)象限与数学上的差别：
   原点在左上角，y轴正向向下，x轴正向向右
-  左右间距为宽与上下间距为高，也与数学意义有区别。
编程：
-  添加合适的头文件，
-  添加复制构造函数，
-  编写程序添加4项计算的成员函数的声明和定义。
-  分别用成员函数和普通函数完成对添加的操作的测试。
-  在main()中检验添加的操作。
*/



#include <iostream>

using namespace std;


//例4.2. Rectangle类的声明和定义
class Rectangle
{
    int left, top;     //左上角
    int right, bottom; //右下角
public:
    Rectangle(int l = 0, int t = 0, int r = 0, int b = 0);   //构造函数，带默认参数，默认值为全0
    Rectangle(const Rectangle &_r) //复制构造函数
    {
        left = _r.left;
        top = _r.top;
        right = _r.right;
        bottom = _r.bottom;
    }

    ~Rectangle()
    {};  //析构函数，在此函数体为空
    void Assign(int l, int t, int r, int b);

    int calculate_width() const;

    int calculate_height() const;

    int calculate_lenth() const;

    int calculate_square() const;

    void SetLeft(int t)
    { left = t; }  // 以下4个函数皆为内联成员函数
    void SetRight(int t)
    { right = t; }

    void SetTop(int t)
    { top = t; }

    void SetBottom(int t)
    { bottom = t; }

    void Show();
};

int Rectangle::calculate_width() const
{
    return right - left;
}

int Rectangle::calculate_height() const
{
    return bottom - top;
}

int Rectangle::calculate_lenth() const
{
    return calculate_height() * 2 + calculate_width() * 2;
}

int Rectangle::calculate_square() const
{
    return calculate_width() * calculate_height();
}

// 构造函数，带默认参数，默认值为全0，在声明中指定
Rectangle::Rectangle(int l, int t, int r, int b)
{
    left = l;
    top = t;
    right = r;
    bottom = b;
}

void Rectangle::Assign(int l, int t, int r, int b)
{
    left = l;
    top = t;
    right = r;
    bottom = b;
}

void Rectangle::Show()
{
    cout << "left-top point is (" << left << "," << top << ")" << '\n';
    cout << "right-bottom point is (" << right << "," << bottom << ")" << '\n';
}

int main()
{
    Rectangle rect;
    cout << "由默认的构造函数生成的rect：" << endl;
    rect.Show();
    rect.Assign(100, 200, 300, 400);
    cout << "由赋值函数处理后的rect：" << endl;
    rect.Show();

    Rectangle rect1(0, 0, 200, 200);
    cout << "由构造函数生成的rect1：" << endl;
    rect1.Show();
    return 0;
}
