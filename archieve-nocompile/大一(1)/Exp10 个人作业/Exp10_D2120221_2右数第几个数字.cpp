#include <iostream>
using namespace std;

int digit(char num[], int k) {
	int noZeroCount = 0;//���ڼ�¼num[noZeroCount]��������һ����Ч������
	for (int i = 19; i >=0 ; i--) {
		if (num[i] != 0) {
			noZeroCount = i;
			break;
		}
	}//���ڼ�¼num[noZeroCount]��������һ����Ч������

	if (noZeroCount - k + 1 < 0) {
		return -1;
	}
	else {
		char outcome = num[noZeroCount - k + 1];

		return outcome - '0';
	}
}



int main() {
	const int k = 4;//�ɱ༭

	char arr[21]{ 0 }; //��ֹ���20λ��0���µ�20λʧЧ
	cin.getline(arr,21); //��ֹ���20λ��0���µ�20λʧЧ


	cout<<digit(arr, k)<<endl;
	

	return 0;
}