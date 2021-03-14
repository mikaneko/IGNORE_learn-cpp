/*
*************************
* 学号:D2120221         *
* 习题:2.15             *
*************************


Press Enter to continue

A vs K
B vs J
C vs M
D vs L
E vs N
================================
A vs K
B vs J
C vs M
D vs N
E vs L
================================
A vs K
B vs L
C vs M
D vs J
E vs N
================================
A vs K
B vs L
C vs M
D vs N
E vs J
================================
A vs K
B vs M
C vs J
D vs L
E vs N
================================
A vs K
B vs M
C vs J
D vs N
E vs L
================================
A vs K
B vs M
C vs L
D vs J
E vs N
================================
A vs K
B vs M
C vs L
D vs N
E vs J
================================
A vs K
B vs M
C vs N
D vs J
E vs L
================================
A vs K
B vs M
C vs N
D vs L
E vs J
================================
A vs K
B vs N
C vs M
D vs J
E vs L
================================
A vs K
B vs N
C vs M
D vs L
E vs J
================================
A vs L
B vs J
C vs M
D vs K
E vs N
================================
A vs L
B vs J
C vs M
D vs N
E vs K
================================
A vs L
B vs K
C vs M
D vs J
E vs N
================================
A vs L
B vs K
C vs M
D vs N
E vs J
================================
A vs L
B vs M
C vs J
D vs K
E vs N
================================
A vs L
B vs M
C vs J
D vs N
E vs K
================================
A vs L
B vs M
C vs K
D vs J
E vs N
================================
A vs L
B vs M
C vs K
D vs N
E vs J
================================
A vs L
B vs M
C vs N
D vs J
E vs K
================================
A vs L
B vs M
C vs N
D vs K
E vs J
================================
A vs L
B vs N
C vs M
D vs J
E vs K
================================
A vs L
B vs N
C vs M
D vs K
E vs J
================================
A vs M
B vs J
C vs K
D vs L
E vs N
================================
A vs M
B vs J
C vs K
D vs N
E vs L
================================
A vs M
B vs J
C vs L
D vs K
E vs N
================================
A vs M
B vs J
C vs L
D vs N
E vs K
================================
A vs M
B vs J
C vs N
D vs K
E vs L
================================
A vs M
B vs J
C vs N
D vs L
E vs K
================================
A vs M
B vs K
C vs J
D vs L
E vs N
================================
A vs M
B vs K
C vs J
D vs N
E vs L
================================
A vs M
B vs K
C vs L
D vs J
E vs N
================================
A vs M
B vs K
C vs L
D vs N
E vs J
================================
A vs M
B vs K
C vs N
D vs J
E vs L
================================
A vs M
B vs K
C vs N
D vs L
E vs J
================================
A vs M
B vs L
C vs J
D vs K
E vs N
================================
A vs M
B vs L
C vs J
D vs N
E vs K
================================
A vs M
B vs L
C vs K
D vs J
E vs N
================================
A vs M
B vs L
C vs K
D vs N
E vs J
================================
A vs M
B vs L
C vs N
D vs J
E vs K
================================
A vs M
B vs L
C vs N
D vs K
E vs J
================================
A vs M
B vs N
C vs J
D vs K
E vs L
================================
A vs M
B vs N
C vs J
D vs L
E vs K
================================
A vs M
B vs N
C vs K
D vs J
E vs L
================================
A vs M
B vs N
C vs K
D vs L
E vs J
================================
A vs M
B vs N
C vs L
D vs J
E vs K
================================
A vs M
B vs N
C vs L
D vs K
E vs J
================================
A vs N
B vs J
C vs M
D vs K
E vs L
================================
A vs N
B vs J
C vs M
D vs L
E vs K
================================
A vs N
B vs K
C vs M
D vs J
E vs L
================================
A vs N
B vs K
C vs M
D vs L
E vs J
================================
A vs N
B vs L
C vs M
D vs J
E vs K
================================
A vs N
B vs L
C vs M
D vs K
E vs J
================================
A vs N
B vs M
C vs J
D vs K
E vs L
================================
A vs N
B vs M
C vs J
D vs L
E vs K
================================
A vs N
B vs M
C vs K
D vs J
E vs L
================================
A vs N
B vs M
C vs K
D vs L
E vs J
================================
A vs N
B vs M
C vs L
D vs J
E vs K
================================
A vs N
B vs M
C vs L
D vs K
E vs J
================================

*/
#include <iostream>
#include <cmath>
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
	cout << "* 习题:" << "2." << (xuehao - 1) % 2 + 15 << "\t\t*" << endl;
	for (int a = 0; a < 25; a += 1)
		cout << '*';
	cout << "\n\n\n";
	cout << "Press Enter to continue" << endl;
	cin.get();



	//枚举到底什么用啊
	enum YIDUI{J=1,K,L,M,N};


	for (int t1 = J; t1 <= N; t1++) {
		for (int t2 = J; t2 <= N; t2++) {
			for (int t3 = J; t3 <= N; t3++) {
				for (int t4 = J; t4 <= N; t4++) {
					for (int t5 = J; t5 <= N; t5++) {
						if (t1 != t2 && t1 != t3 && t1 != t4 && t1 != t5 && t2 != t3 && t2 != t4 && t2 != t5 && t3 != t4 && t3 != t5 && t4 != t5) {		//组合不可相等
							if (t1 != J && t4 != M && t5 != M) {																						//题目要求
								
								cout << "A vs ";
								switch (t1)
								{
								case 1:cout << 'J' << endl; break;
								case 2:cout << 'K' << endl; break;
								case 3:cout << 'L' << endl; break;
								case 4:cout << 'M' << endl; break;
								case 5:cout << 'N' << endl; break;
								}

								cout << "B vs ";
								switch (t2)
								{
								case 1:cout << 'J' << endl; break;
								case 2:cout << 'K' << endl; break;
								case 3:cout << 'L' << endl; break;
								case 4:cout << 'M' << endl; break;
								case 5:cout << 'N' << endl; break;
								}

								cout << "C vs ";
								switch (t3)
								{
								case 1:cout << 'J' << endl; break;
								case 2:cout << 'K' << endl; break;
								case 3:cout << 'L' << endl; break;
								case 4:cout << 'M' << endl; break;
								case 5:cout << 'N' << endl; break;
								}

								cout << "D vs ";
								switch (t4)
								{
								case 1:cout << 'J' << endl; break;
								case 2:cout << 'K' << endl; break;
								case 3:cout << 'L' << endl; break;
								case 4:cout << 'M' << endl; break;
								case 5:cout << 'N' << endl; break;
								}
								
								cout << "E vs ";
								switch (t5)
								{
								case 1:cout << 'J' << endl; break;
								case 2:cout << 'K' << endl; break;
								case 3:cout << 'L' << endl; break;
								case 4:cout << 'M' << endl; break;
								case 5:cout << 'N' << endl; break;

								}
								
								cout << "================================"<<endl;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}