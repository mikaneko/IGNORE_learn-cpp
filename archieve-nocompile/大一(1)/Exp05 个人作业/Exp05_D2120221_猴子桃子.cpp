/*
*************************
* 学号:D2120221         *
* 习题:2.8              *
*************************


第9天后，桃子还剩1个。
第8天后，桃子还剩4个。
第7天后，桃子还剩10个。
第6天后，桃子还剩22个。
第5天后，桃子还剩46个。
第4天后，桃子还剩94个。
第3天后，桃子还剩190个。
第2天后，桃子还剩382个。
第1天后，桃子还剩766个。
原桃子数为：1534
*/
#include <iostream>
using namespace std;

int main() {
	//个人信息
	const int xuehao = 21;
	char banji[] = "D21202";
	//表头部分
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << endl;

	cout << "* 学号:" << banji << xuehao << "\t\t*" << endl;
	cout << "* 习题:" << "2." << (xuehao - 1) % 5 + 8 << "\t\t*" << endl;
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << "\n\n\n";

	//主体部分
	int remain = 1;
	int cycle = 8;
	cout << "第9天后，桃子还剩" << remain << "个。"<<endl;
	for (int i = cycle; i >= 1; i--) {
		remain = (remain + 1) * 2;
		cout << "第" << i << "天后，桃子还剩" << remain << "个。" << endl;
	}
	remain = (remain + 1) * 2;
	cout << "原桃子数为：" << remain << endl;
	//没了
	return 0;
}