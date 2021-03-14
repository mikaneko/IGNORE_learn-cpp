//我吐了
#include <iostream>
using namespace std;

int main() {
	const int xuehao = 21;
	char banji[] = "D21202";

	//表头部分
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << endl;


	cout << "* 学号:" << banji << xuehao << "\t\t*" << endl;
	cout << "* 习题:" << "2." << (xuehao - 1) % 3 + 5 << "\t\t*" << endl;
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << "\n\n\n";

	//计算部分
	while (1) {
		int n = 0;
		int temp_jiecheng = 1;
		int sum = 0;
		cout << "求1!+2!+3!+...+n!\t(n>=1)" << endl;
		cout << "请输入n:";
		cin >> n;
		cout << "\n\n\n\n你输入   n = " << n << endl;

		for (int a1 = 1; a1 <= n; a1 += 1) {
			for (int i = a1; i > 0; i -= 1) {
				temp_jiecheng = temp_jiecheng * i;
			}
			sum += temp_jiecheng;
			temp_jiecheng = 1;
		}

		cout << "计算出 sum = " << sum << endl;
		cout << "\n\n";
		for (int a = 0; a < 40; a += 1) {
			cout << '=';
		}
		cout << "\n\n";
	}



	return 0;
}

/*
BAIDU下面举例说明for语句的使用方法：
int i;
for(i=0; i<3; i++)   
i=0是初始化部分；i<3是循环判断条件部分（当满足此条件时才进入执行for循环中的语句）；i++是执行完循环体语句后的操作
*/