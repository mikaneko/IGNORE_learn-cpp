/* 
   ������ʹ��MFC����ģ��������ģ�����Ӧ��ʵ�顣
   
   ��������ConsoleӦ�ó��򹤳��޷����У���Ҫʹ��MFC��̬�⡣
   ����ʹ��MFC��ģ��ķ����ǣ�
1. �½�һ��ConsoleӦ�ó��򹤳�
2. ѡ����Ŀ(Project) |���һ���Ӳ˵� ����(Settings��)�˵�
3. ������ҳѡ�� �������� | ����Generalѡ���
4. ��MFC��ʹ�ã�Microsoft Foundation Classes������ѡ���ھ�̬����ʹ��MFC�� Use MFC in a Static Library��
5. ������ҳѡ�� �������� | C/C++ | �������ɣ�Code Generation�� | ���п⣨Use run-time library��
   ѡ��"���̵߳���(/MTd)" Debug Multithreaded����multithreaded

	�Ķ�ʵ��ʮ����3������MFC��CRect��ĳ�Ա�����Ĺ��ܣ�
	�������һЩ���Է�������ϰʹ��CRect��CPoint���ࡣ
	
    �Ķ�ʵ��ʮ�ţ�CArray��ģ��ĳ�Ա����������Ȼ����ɱ���ʵ�顣
    ������ʹ����MFC��CPoint
*/
#include <iostream>    
using namespace std;

#include <afxwin.h>     //MFC���
#include <afxtempl.h>   //MFCģ�����

void main()
{
	CPoint cp(10,10);     //���ã������Ա�����μ�https://docs.microsoft.com/zh-cn/previous-versions/visualstudio/visual-studio-2010/a5sc01d3(v=vs.100)
    CRect  rt(0,0,10,10); //���ã������Ա�����μ�https://docs.microsoft.com/zh-cn/previous-versions/visualstudio/visual-studio-2010/0kk0fzx6(v=vs.100)
	cout<<rt.Width();
	//����MFC�࣬�����˽Ⲣ��Ӧ����ϰ��

//2010��ģ�����ò�������⣬�����г����޷�ִ�У������ϰafxwin.h�����Ӧ��
#if 0  
    CArray<int,int> iArray; 
	CArray<int, const int&> arr;
	CArray<CPoint,CPoint> m_Array; //�����������CArray��������
    m_Array.SetSize(10,10); //��������Ĵ�С������
    CPoint pt1(10,10); //������󲢴����������
    m_Array.Add(pt1);
    CPoint pt2(20,20);
    m_Array.Add(pt2);
    CPoint pt3(30,30);
    m_Array.Add(pt3);
    int size = m_Array.GetSize();
    CPoint pt;
    for(int i = 0; i < size; i++) { //�������Ԫ��
        pt = m_Array.GetAt(i);
        cout<<pt.x<<' '<<pt.y<<'\n';
    }
#endif
}