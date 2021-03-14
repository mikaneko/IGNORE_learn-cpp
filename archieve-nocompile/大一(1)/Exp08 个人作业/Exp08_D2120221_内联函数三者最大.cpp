#include<iostream>
using namespace std;

void Table() {
	//editable
	const int xuehao = 21;
	char banji[] = "D21202";
	//表头部分
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << endl;

	cout << "* 学号:" << banji << xuehao << "\t\t*" << endl;
	cout << "* 习题:" << "3." << (xuehao - 1) % 2 + 11 << "\t\t*" << endl;
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << "\n\n\n";
	return;
}

inline double max3(double a, double b, double c) {
	if (b > a) { a = b; }
	if (c > a) { a = c; }
	return a;
}
int main() {
	Table();
	cout << max3(7.5, 9.4, 3.4) << endl;
	cout << max3(7.6, 7.7, 7.8) << endl;
	cout << max3(6.3, 6.2, 6.1) << endl;
	cout << max3(7.5, 9.4, 3.9) << endl;
}