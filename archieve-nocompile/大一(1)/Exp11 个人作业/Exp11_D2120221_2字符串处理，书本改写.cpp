#include<iostream>
#include<string>
using namespace std;


void trim(char* s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	i--;
	while (s[i] == ' ') {
		s[i--] = '\0';
	}
	return;
}

void leftstring(char* s1,char* s2,int n) {
	int i;
	for (i = 0; i < n; i++) {
		s2[i] = s1[i];
	}
	s2[i] = '\0';
	return;
}
int index(char* s1, char* s2) {
	bool b = 0;
	int i, j, n = -1, n1 = strlen(s1), n2 = strlen(s2);
	for (i = 0; i < n1; i++) {
		if (s1[i] == s2[0]) {
			b = 1;
			for (j = 1; j < n2; j++) {
				if (s1[i + j] != s2[j]) {
					b = 0;
					break;
				}
			}
		}
		if (b == 1) {
			n = 1;
			break;
		}
	}
	return n;
}
int main() {
	char str1[] = "I'm student. ", str2[] = "student ", str3[4];
	int n;
	cout << "1_str1:" << str1 << "长度为:" << strlen(str1) << endl;
	trim(str1);
	cout << "2_str1:" << str1 << "长度为:" << strlen(str1) << endl;
	leftstring(str1, str3, 3);
	cout << "str3:" << str3 << "长度为:" << strlen(str3) << endl;
	cout << "str2:" << str2 << endl;
	n = index(str1, str2);
	if (n != -1) {
		cout << "str1 contain str2, from num.(start from 0)" << n << endl;
	}
	else {
		cout << "str1 dont contain str2" << endl;
	}
	return 0;
}