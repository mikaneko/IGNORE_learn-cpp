#include <iostream>
#include<cstring>
using namespace std;

//ASCII偏移量(解密密码)
#define _DELTA_ 2



void enc(char* data,int size) {
	for (int i = 0;i<size; i++) {
		if (data[i] != 0) {
			data[i] = (char)((_DELTA_+(int)data[i])%128);
		}
	}
	cout << "加密成功" << endl;
	return;
}
void dec(char* data,int size,int key) {
	for (int i = 0; i < size; i++) {
		if (data[i] != 0) {
			data[i] = (char)(((int)data[i]+128-key) % 128);
		}
	}
	return;
}


int main() {
	char str[100] = { 0 };

	//enc
	cout << "input string you wanna enc" << endl;
	cin.getline(str, 100);
	cout << str << endl;
	int size = sizeof(str) / sizeof(str[0]);
	enc(str, size);
	cout << str << endl;

	//dec
	int key;
	cout << "input key(提示：密码为" << _DELTA_ << ")" << endl;
	cin >> key;
	dec(str, size,key);
	cout << str << endl;
	return 0;
}