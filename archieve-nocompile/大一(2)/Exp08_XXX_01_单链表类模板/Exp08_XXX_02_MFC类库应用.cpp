/* 
   本程序使用MFC类库和模板类库进行模板类的应用实验。
   
   单纯创建Console应用程序工程无法运行，需要使用MFC静态库。
   设置使用MFC类模板的方法是：
1. 新建一个Console应用程序工程
2. 选择项目(Project) |最后一个子菜单 属性(Settings…)菜单
3. 在属性页选择 配置属性 | 常规General选项卡，
4. 在MFC的使用（Microsoft Foundation Classes）框中选择“在静态库中使用MFC” Use MFC in a Static Library。
5. 在属性页选择 配置属性 | C/C++ | 代码生成（Code Generation） | 运行库（Use run-time library）
   选择"多线程调试(/MTd)" Debug Multithreaded或者multithreaded

	阅读实验十二，3，关于MFC的CRect类的成员函数的功能，
	自行设计一些测试方案，练习使用CRect、CPoint等类。
	
    阅读实验十九，CArray类模板的成员函数声明，然后完成本次实验。
    范例，使用了MFC的CPoint
*/
#include <iostream>    
using namespace std;

#include <afxwin.h>     //MFC类库
#include <afxtempl.h>   //MFC模板类库

void main()
{
	CPoint cp(10,10);     //可用，更多成员函数参见https://docs.microsoft.com/zh-cn/previous-versions/visualstudio/visual-studio-2010/a5sc01d3(v=vs.100)
    CRect  rt(0,0,10,10); //可用，更多成员函数参见https://docs.microsoft.com/zh-cn/previous-versions/visualstudio/visual-studio-2010/0kk0fzx6(v=vs.100)
	cout<<rt.Width();
	//更多MFC类，自行了解并作应用练习。

//2010的模板类库貌似有问题，若下列程序无法执行，则仅练习afxwin.h库类的应用
#if 0  
    CArray<int,int> iArray; 
	CArray<int, const int&> arr;
	CArray<CPoint,CPoint> m_Array; //定义数组对象，CArray类有问题
    m_Array.SetSize(10,10); //设置数组的大小及增量
    CPoint pt1(10,10); //定义对象并存放在数组中
    m_Array.Add(pt1);
    CPoint pt2(20,20);
    m_Array.Add(pt2);
    CPoint pt3(30,30);
    m_Array.Add(pt3);
    int size = m_Array.GetSize();
    CPoint pt;
    for(int i = 0; i < size; i++) { //输出数组元素
        pt = m_Array.GetAt(i);
        cout<<pt.x<<' '<<pt.y<<'\n';
    }
#endif
}