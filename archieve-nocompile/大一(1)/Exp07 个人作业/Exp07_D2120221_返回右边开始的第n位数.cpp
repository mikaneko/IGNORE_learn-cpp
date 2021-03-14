//*************************
//* 学号:D2120221 *
//*习题 : 3.5 *
//*************************
//
//
//返回num右边开始的第k位数
//请输入num : 1234567
//请输入k : 3
#include <iostream>
using namespace std;

void TableH();
int digit(int a, int b);

int main() {
	int num = 0, k = 0;;
	TableH();
	cout << "返回num右边开始的第k位数" << endl;
	cout << "请输入num:";
	cin >> num;
	cout << "请输入k:";
	cin >> k;

	cout << digit(num, k) << endl;

	return 0;
}


void TableH() {
	const int xuehao = 21;
	char banji[] = "D21202";
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << endl;
	cout << "* 学号:" << banji << xuehao << "\t\t*" << endl;
	cout << "* 习题:" << "3." << (xuehao - 1) % 4 + 5 << "\t\t*" << endl;
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << "\n\n\n";
	return;
}

int digit(int num, int k) {
	int factor = 1;
	for (int i = 0; i < k; i++) {
		factor *= 10;
	}
	int outcome = (num % factor) / (factor / 10);
	return outcome;
}