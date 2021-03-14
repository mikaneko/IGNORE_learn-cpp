
//1
//1       1
//1       2       1
//1       3       3       1
//1       4       6       4       1
//1       5       10      10      5       1
//1       6       15      20      15      6       1
//1       7       21      35      35      21      7       1
//1       8       28      56      70      56      28      8       1
//1       9       36      84      126     126     84      36      9       1



#include <iostream>
using namespace std;



void YHsanjiao(int mar[][19],int floor) {
	
	for (int i = 0; i < floor; i++) {
		mar[i][floor - 1 - i] = 1;
		mar[i][floor - 1 + i] = 1;
	}

	mar[2][9] = 2;
	for (int i = 2; i < floor; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < i-1; j += 2) {
				mar[i][floor - 1 + j] = mar[i - 1][floor - 1 + j + 1] + mar[i - 1][floor - 1 + j - 1];
				mar[i][floor - 1 - j] = mar[i - 1][floor - 1 - j + 1] + mar[i - 1][floor - 1 - j - 1];
			}
		}
		else {
			for (int j = 1; j < i-1; j += 2) {
				mar[i][floor - 1 + j] = mar[i - 1][floor - 1 + j + 1] + mar[i - 1][floor - 1 + j - 1];
				mar[i][floor - 1 - j] = mar[i - 1][floor - 1 - j + 1] + mar[i - 1][floor - 1 - j - 1];
			}
		}
			

	}
	
	
}

void coutYHsanjiao(int yh[][19], int floor) {
	//金字塔输出
	for (int i = 0; i < floor; i++) {
		for (int j = 0; j < 2*floor-1; j++) {
			if (yh[i][j] != 0) {
				cout << yh[i][j] << '\t';
			}
			else {
				cout << '\t';
			}

		}
		cout << endl;
	}
	//左对齐输出
	for (int i = 0; i < floor; i++) {
		for (int j = 0; j < 2 * floor - 1; j++) {
			if (yh[i][j] != 0) {
				cout << yh[i][j] << '\t';
			}
		}
		cout << endl;
	}

}

int main() {

	const int floor = 10;

	int yh[10][19]={ 0 };



	YHsanjiao(yh, 10);

	coutYHsanjiao(yh, 10);

	

	
	return 0;
}