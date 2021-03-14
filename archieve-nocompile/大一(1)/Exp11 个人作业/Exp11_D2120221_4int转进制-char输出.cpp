//45678
//23CACE
//
//45678
//23CACE
//radix 2 8 10 16 available
#include <iostream>
using namespace std;
//#define _MAX_OF_INT_ 2147483647



//循环
void my_itoa(int n, char s[], int radix) {
	int maxpowernum = 0;
	switch (radix) {
	case 2:maxpowernum = 2147483646; break;
	case 8:maxpowernum = 1073741824; break;
	case 10:maxpowernum = 1000000000; break;
	case 16:maxpowernum = 268435456; break;
	}
	bool doOutput = false;
	int ioutput = 0;
	while (maxpowernum >= 1) {
		if (n / maxpowernum != 0) {
			doOutput = 1;
		}
		if (doOutput == 1) {
			s[ioutput] = (n / maxpowernum) + '0';
			if (n / maxpowernum == 10) { s[ioutput] = 'A'; }
			if (n / maxpowernum == 11) { s[ioutput] = 'B'; }
			if (n / maxpowernum == 12) { s[ioutput] = 'C'; }
			if (n / maxpowernum == 13) { s[ioutput] = 'D'; }
			if (n / maxpowernum == 14) { s[ioutput] = 'E'; }
			if (n / maxpowernum == 15) { s[ioutput] = 'F'; }
			ioutput++;
		}
		//		cout << ioutput << endl;
		n = n % maxpowernum;
		maxpowernum /= radix;
	}

	return;
}


//递归
int itoa2(int n, char* data, int radix) {
//	cout << &data << endl;//调试
	static int mpn = 1;
	static bool doInitializeMpn = 1;
	if (doInitializeMpn == 1) {
		switch (radix) {
		case 2:mpn = 2147483646; break;
		case 8:mpn = 1073741824; break;
		case 10:mpn = 1000000000; break;
		case 16:mpn = 268435456; break;
		}
		doInitializeMpn = 0;
	}
	
	static bool doOutput = false;

	if (mpn < 1) {
		//初始化static内容，然后退出递归
		mpn = 1;
		doInitializeMpn = 1;
		doOutput = false;
		return 1;//无用的返回值
	}
	if (n / mpn != 0) {
		doOutput = true;
	}
	
	if (doOutput == true) {
		*data = (n / mpn) + '0';
		if (n / mpn == 10) { *data = 'A'; }
		if (n / mpn == 11) { *data = 'B'; }
		if (n / mpn == 12) { *data = 'C'; }
		if (n / mpn == 13) { *data = 'D'; }
		if (n / mpn == 14) { *data = 'E'; }
		if (n / mpn == 15) { *data = 'F'; }
	//	cout << *data;//调试
		n = n % mpn;
		mpn /= radix;
		return itoa2(n, data + 1, radix);
	}
	else {
	
		n = n % mpn;
		mpn /= radix;
		return itoa2(n, data, radix);
	}
}

int main() {
	//循环（数组指针）
	char str[100] = { 0 };
	char str2[100] = { 0 };
	my_itoa(45678, str, 10);
	my_itoa(2345678, str2, 16);
	cout << str << endl;
	cout << str2 << endl;

	cout << endl;


	//递归（纯指针）
	char str3[100] = { 0 };
	char str4[100] = { 0 };
	//cout << "!111" << &str3 << endl;
	itoa2(45678, str3, 10);
	cout << str3 << endl;
	itoa2(2345678, str4, 16);
	cout << str4 << endl;
	return 0;
}