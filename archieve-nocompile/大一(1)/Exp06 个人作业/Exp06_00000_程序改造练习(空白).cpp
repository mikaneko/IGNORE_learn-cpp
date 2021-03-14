/*
例2.23，实现输入8位二进制数，将其转换为十进制数输出。
        本程序定义了一个权值变量，改变权值，可支持多种进制(如2进制，8进制)转换为十进制。
 
算法：
直接法：y=a[n]*x^n + ... + a[1] * x + a[0]  直接法反复做乘法 n*(n+1)/2 次，执行效率低。
递推法：y=(...((a[n]*x+a[n-1])*x + a[n-2])*x) + a[n-3]...)*x+a[0]

程序中共用注释列出6个问题，在30分钟内选择自己能实现或者回答的，尽可能多地回答。
*/
#include <iostream>
using namespace std;

int main()
{
    const int LENGTH=8;   //输入数据位数
    const int WEIGHT=2;   //输入数据进制
    
    char  before[LENGTH];   
    /*
    题1：在注释区域内回答，为何使用char来定义输入数据，若改为int会出现什么问题？
    答：。。。
    */
    
    int   decByDirect=0;      //存储直接法转换后结果     
 	int   decByRecursion=0;   //存储递推法转换后结果
 	
 	int   x=WEIGHT;           //转换前X进制的权值
    int   a,i;
    int   MultiplyCounter=0;
    
    /*
    题2：改造下面两行输入数据的代码，要求
    在输入后可循环检查输入是否正确，直至输入正确为止，
    如2进制输入时，若输入123则为错误，需提示重新输入
    */ 
	cout << "输入" << LENGTH << "个" << x << "进制数字：" <<endl; 
	for(i=0;i<LENGTH;i++)  cin>>before[i];     //注意，与例题2.23对比，本程序改变了数字串的存储顺序
	
	
	
	/*
	题3：在下面区域实现直接法转换的代码
	题4：其中，用变量MultiplyCounter统计直接法的乘法次数。
	*/
	cout << x <<"进制序列(" << before << ")的值为:" << decByDirect << "直接法乘次数为：" << MultiplyCounter << endl;
	
	
	
	//P.58，例2.23，递推法
	//注意，与例题2.23对比，本程序改变了数字串的存储顺序
	MultiplyCounter=0;
	decByRecursion=0;
	x=WEIGHT;
	for(i=0;i<LENGTH;i++) {
		a=before[i]-'0';
		decByRecursion = decByRecursion*x+a;
		MultiplyCounter++;
	}
	
	/*
	题5.在注释区域内回答问题，
	由于本程序改变了数字串的存储顺序，故可以用字符数组名直接输出整列数字串，
	但是，课本例2.23所用的输出方式更好，为什么？
	（提示：本程序的输出法可能产生错误，请尝试解释出错的原因）
	答：。。。
    */
    
	/*
	题6.若一定想用字符数组名直接输出整列数字，可以怎么改造程序，保证输出的正确性。
	*/
	cout << x <<"进制序列(" << before << ")的值为:" << decByRecursion << "递推法乘的次数为：" << MultiplyCounter << endl;
	return 0;
}