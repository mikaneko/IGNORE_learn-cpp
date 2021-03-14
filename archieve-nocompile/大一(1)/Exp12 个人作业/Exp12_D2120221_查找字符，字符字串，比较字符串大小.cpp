//HEX：8ffcae
//008FFCAC
//HEX：0
//HEX：8ffc45
//008FFC40
//HEX：8ffb6a
//008FFB68
//HEX：0
//008FFC40
//1
//- 1
//0
//- 1
//1
#include<iostream>
using namespace std;

char* myStrChr(const char* s, char c) {
	int i = 0;
	while (s[i] != 0) {
		if (c == s[i]) {
			return (char*)&s[i];
			//return (char*)s+i;
		}
		i++;
	}
	return NULL;
}

char* myStrStr(const char* s1, const char* s2) {

	//s1遍历，如果s1[i]==s2[0]，则令bool为true，接下来比较s1[i+1]和s2[1]等等等，循环s2的长度次，
	//如果不相等，则bool为false且，回到s1[i+1]，s2重置为0，进行当前比较
	//这样应该就没bug了


	bool isContained = false;
	int j = 0;//数组形式-控制s1的进度
	int bi = 0;//数组形式-控制当首字母相同时，连续相互比较时的进度
	while (s1[j] != 0 && s2[0] != 0) {
		//cout << j << endl;
		if (s1[j] == s2[0]) {
			isContained = true;

			bi = 0;//重置bi
			while ((s2[bi] != 0) && (s1[j + bi] != 0)) {
				//cout << s1[bi];
				//cout << s2[j + bi] << endl;

				if (s1[j + bi] != s2[bi]) {
					isContained = false;
					bi = 0;
					break;
				}
				bi++;
			}
		}
		//cout << isContained << endl;
		//cout << j << endl;
		if (isContained == true) {
			return (char*)&s1[j];
		}
		//cout << endl;
		j++;
	}
	return NULL;
}


int myStrCmp(const char* s1, const char* s2) //字符串排序 大小比较(ASCII)
{
	int i = 0;//数组做类指针
	while (s1[i] != 0 && s2[i] != 0) {
		if (s1[i] > s2[i]) {
			return 1;
		}
		if (s1[i] < s2[i]) {
			return -1;
		}
		i++;
	}
	if (s1[i] == 0 && s2[i] != 0) {
		//cout << "小于" << endl;
		return -1;
	}
	if (s1[i] != 0 && s2[i] == 0) {
		//cout << "大于" << endl;
		return 1;
	}
	return 0;

}

int main() {
	//q1
	char str[100] = "hellocpp";

	cout << "HEX：" << hex << (int)myStrChr(str, 'l') << endl;
	cout << hex << &str << endl;//用于对比

	cout << "HEX：" << hex << (int)myStrChr(str, 'a') << endl;

	//q2
	char str1[100] = "hellocppiloveyou";
	char str2[100] = "cppilove";
	char str3[100] = "ststst123";
	char str4[100] = "stst123";
	cout << "HEX：" << hex << (int)myStrStr(str1, str2) << endl;
	cout << hex << &str1 << endl;//用于对比

	cout << "HEX：" << hex << (int)myStrStr(str3, str4) << endl;
	cout << hex << &str3 << endl;//用于对比

	cout << "HEX：" << hex << (int)myStrStr(str1, str4) << endl;
	cout << hex << &str1 << endl;//用于对比

	//q3
	cout << dec;//转回10进制


	cout << myStrCmp("aBACD", "Abcd") << endl;//a>A 1
	cout << myStrCmp("a1234", "b12345") << endl;//a<b -1
	cout << myStrCmp("abcd", "abcd") << endl;//相等 0
	cout << myStrCmp("abcd", "abcde") << endl;//\0<e -1 
	cout << myStrCmp("abcde", "abcd") << endl;//e>\0 1

	return 0;
}