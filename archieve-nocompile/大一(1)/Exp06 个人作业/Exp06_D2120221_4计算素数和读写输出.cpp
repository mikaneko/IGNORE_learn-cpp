/*
文件输出至".\D2120221_output.txt"下
请输入起始数字(>=2)：2
请输入结束数字：50

文件以保存
读取文件在Console输出
Press ENTER to continue

2       3       5       7       11
13      17      19      23      29
31      37      41      43      47
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int start = 0, end = 0;
	bool basic_validate = 0;
	int a1 = 0, a2 = 0;
	bool sushu = 1;
	int coutflag = 1;
	cout << "文件输出至\".\\D2120221_output.txt\"下" << endl;
	//基本数据验证
	while (basic_validate == 0) {
		cout << "请输入起始数字(>=2)：";
		cin >> start;
		cout << "请输入结束数字：";
		cin >> end;
		if (start >= 2 && end >= 2 && start <= end) {
			basic_validate = 1;
		}
		else { cout << "输入错误，请重新输入" << endl; }
	}
	//open file
	ofstream outp;
	outp.open("D2120221_output.txt");

	//定义法（二分）求素数
	for (int i = start; i <= end; i++) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				sushu = 0;
			}
		}
		if (sushu == 1) {
			//cout << i << '\t';
			outp << i << '\t';
			if (coutflag % 5 == 0) {
				//cout << endl;
				outp << endl;
			}
			coutflag++;
		}
		sushu = 1;
	}
	outp.close();

	cout << "\n文件以保存\n读取文件在Console输出\nPress ENTER to continue" << endl;
	cin.get();//absorb enter above
	cin.get();//pause

	//读取文件
	int readme = 0;
	int coutflag1 = 1;
	ifstream inp;
	inp.open("D2120221_output.txt");
	while (1) {
		if (inp.eof() != 0)break;
		inp >> readme;
		cout << readme << '\t';
		if (coutflag1 % 5 == 0) {
			cout << endl;
			outp << endl;
		}
		coutflag1++;
	}
	inp.close();
	return 0;
}