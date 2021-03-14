#include<iostream>
using namespace std;


char* myStrCat(char* s, const char* ct) {
	int i = 0;//i为定位变量
	while (s[i] != 0) { 
		i++;
	}
	int lengthOfCt = 0;
	while (ct[lengthOfCt] != 0) {
		lengthOfCt++;
	}
	for (int n = 0; n < lengthOfCt; n++) {
		s[i] = ct[n];
		i++;
	}
	s[i] = 0;
	return s;
	//指针s=地址str
}

int myStrLen(const char* s) {
	int i = 0;//i为定位变量
	while (s[i] != 0) {
		i++;
	}
	return i;
}

char* myStrCpy(char* s, const char* ct) {
	int i = 0;
	while (s[i] != 0) {
		s[i] = 0;
		i++;
	}

	int lengthOfCt = 0;
	while (ct[lengthOfCt] != 0) {
		lengthOfCt++;
	}
	int n = 0;
	for (n = 0; n < lengthOfCt; n++) {
		s[n] = ct[n];
	}
	s[n] = 0;

	return s;
}

char* myReverse(char* s) {
	int i = 0;
	while (s[i] != 0) {
		i++;
	}
	i--;//长度减一
	int left = 0;
	int right = i;
	char temp = 0;
	while (left < right) {
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
	return s;
}

int main() {
	char str1[100] = "hello";
	char str2[100] = "world!";
	//1
	myStrCat(str1, str2);
	cout << str1 << endl;
	cout << endl;
	//2
	cout <<"str1_len = "<< myStrLen(str1) << endl;
	cout << endl;
	//3
	myStrCpy(str2, str1);
	cout << str1 << endl;
	cout << str2 << endl;
	cout << endl;
	//4
	myReverse(str2);
	cout << str2 << endl;
	cout << endl;
	return 0;
}