//使用for语句循环，使用if语句进行制表
#include <iostream>
using namespace std;

int main() {
	
	
	//下三角计算部分
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << "×" << i << '=' << i * j;
			if (i != j) { cout << '\t'; }
		}
		cout << endl;
	}
	
	//空行
	cout<<"\n\n\n\n";
	
	//上三角计算部分
	for (int i = 1; i <= 9; i++) {
		for (int j = i; j <= 9; j++) {
			cout << i << "×" << j << '=' << i * j;
			if (j != 9) { cout << '\t'; }
		}
		cout << endl;
	}

	return 0;
}






/*
BAIDU下面举例说明for语句的使用方法：
int i;
for(i=0; i<3; i++)   
i=0是初始化部分；i<3是循环判断条件部分（当满足此条件时才进入执行for循环中的语句）；i++是执行完循环体语句后的操作
*/