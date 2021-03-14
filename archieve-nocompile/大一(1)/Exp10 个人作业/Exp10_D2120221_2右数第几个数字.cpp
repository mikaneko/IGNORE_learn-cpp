#include <iostream>
using namespace std;

int digit(char num[], int k) {
	int noZeroCount = 0;//用于记录num[noZeroCount]是右数第一个有效的数字
	for (int i = 19; i >=0 ; i--) {
		if (num[i] != 0) {
			noZeroCount = i;
			break;
		}
	}//用于记录num[noZeroCount]是右数第一个有效的数字

	if (noZeroCount - k + 1 < 0) {
		return -1;
	}
	else {
		char outcome = num[noZeroCount - k + 1];

		return outcome - '0';
	}
}



int main() {
	const int k = 4;//可编辑

	char arr[21]{ 0 }; //防止最后20位填0导致第20位失效
	cin.getline(arr,21); //防止最后20位填0导致第20位失效


	cout<<digit(arr, k)<<endl;
	

	return 0;
}