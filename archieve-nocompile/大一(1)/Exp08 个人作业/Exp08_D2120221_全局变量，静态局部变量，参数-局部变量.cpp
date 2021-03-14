/*
* 运行过程
* 全局变量a=300，全局变量b=400，全局变量c=500
* --==main==--
* --==funa==--
* 参数c=300，static a=5，static a=305
* cout static a=305，参数c=300
* --==funb==--
* 参数a=400，参数a=400
* cout 参数a=400
* --==funa==--
* 参数c=400，static，static a=705
* cout static a=705，参数c=400
* --==func==--
* 参数c=0，
* cout 全局变量a=300，全局变量b=400，参数c=0
* 全局变量c=400
* --==main==--
* cout 全局变量a=300，全局变量b=400，全局变量c=400
*/

#include <iostream>
using namespace std;

int a = 300, b = 400, c = 500;

void funa(int c) {
	static int a = 5;
	a += c;
	cout << a << ' ' << c << '\n';
}

void funb(int a) {
	a = b;
	cout << a << '\n';
}

void func() {
	int c = 0;
	cout << a << ' ' << b << ' ' << c << '\n';
	::c -= 100;
}
int main() {
	funa(a);
	funb(b);
	funa(b);
	func();
	cout << a << ' ' << b << ' ' << c << '\n';
	return 0;
}