/*
* ���й���
* ȫ�ֱ���a=300��ȫ�ֱ���b=400��ȫ�ֱ���c=500
* --==main==--
* --==funa==--
* ����c=300��static a=5��static a=305
* cout static a=305������c=300
* --==funb==--
* ����a=400������a=400
* cout ����a=400
* --==funa==--
* ����c=400��static��static a=705
* cout static a=705������c=400
* --==func==--
* ����c=0��
* cout ȫ�ֱ���a=300��ȫ�ֱ���b=400������c=0
* ȫ�ֱ���c=400
* --==main==--
* cout ȫ�ֱ���a=300��ȫ�ֱ���b=400��ȫ�ֱ���c=400
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