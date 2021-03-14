/*
*************************
* 学号:D2120221         *
* 习题:3.9              *
*************************


1---1
1---2
2---2
6---4
14---5
44---9
541---29
2432---61
10307---125
*/
#include <iostream>
using namespace std;


void Table();
int Ackman(int, int);

int count=0;

int main() {
	Table();
	cout << count<<"---"<< Ackman(0, 0) << endl;
	count = 0;
	cout << count<<"---"<< Ackman(0, 1) << endl;
	count = 0;
	cout << count<<"---"<< Ackman(1, 0) << endl;
	count = 0;
	cout << count<<"---"<< Ackman(1, 2) << endl;
	count = 0;
	cout << count<<"---"<< Ackman(2, 1) << endl;
	count = 0;
	cout << count<<"---"<< Ackman(2, 3) << endl;
	count = 0;
	cout << count<<"---"<< Ackman(3, 2) << endl;
	count = 0;
	cout << count<<"---"<< Ackman(3, 3) << endl;
	count = 0;
	cout << count<<"---"<< Ackman(3, 4) << endl;
	count = 0;

	//cout << Ackman(4, 3) << endl;
	return 0;
}

int Ackman(int m, int n) {
	count++;
	if (m == 0) { return n + 1; }
	if (n == 0) { return Ackman(m - 1, 1); }
	if (n > 0 && m > 0) { return Ackman(m - 1, Ackman(m, n - 1)); }
}


void Table() {
	//editable
	const int xuehao = 21;
	char banji[] = "D21202";
	//表头部分
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << endl;

	cout << "* 学号:" << banji << xuehao << "\t\t*" << endl;
	cout << "* 习题:" << "3." << (xuehao - 1) % 2 + 9 << "\t\t*" << endl;
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << "\n\n\n";
	return;
}