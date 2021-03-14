/*
输入	输出
0		0
1200	10
3200	205
6200	665
21200	3675
41200	8685
*/
#include <iostream>
using namespace std;

int main() {

	while (1) {
		double money = 0, tax = 0;
		cout << "输入money\n";
		cin >> money;
		cout << "\n\nmoney = " << money << endl;

		money = money - 1000;

		if (money >= 100000) { tax += (money - 100000) * 0.45; money = 100000; }
		if (money >= 80000) { tax += (money - 80000) * 0.40; money = 80000; }
		if (money >= 60000) { tax += (money - 60000) * 0.35; money = 60000; }
		if (money >= 40000) { tax += (money - 40000) * 0.30; money = 40000; }
		if (money >= 20000) { tax += (money - 20000) * 0.25; money = 20000; }
		if (money >= 5000) { tax += (money - 5000) * 0.20; money = 5000; }
		if (money >= 2000) { tax += (money - 2000) * 0.15; money = 2000; }
		if (money >= 500) { tax += (money - 500) * 0.10; money = 500; }
		if (money >= 0) { tax += money * 0.05; money = 0; }

		cout << "tax = " << tax << endl;
		cout << "\n\n\n\n\n\n\n========================\n\n\n";
	}


	return 0;

}