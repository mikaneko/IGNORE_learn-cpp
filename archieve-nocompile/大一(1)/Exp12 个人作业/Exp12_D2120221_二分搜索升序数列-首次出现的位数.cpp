//4
//2
//5
//1
//7
//not found return 4
//
//
//4
//2
//5
//1
//7
//not found return 4
//not found return 9
//not found return 1
#include<iostream>
using namespace std;

int BinarySearchFirst(int x, const int* data, int size) {
	//思路
	int high = size - 1;
	int low = 0;
	int mid = high;

	while (low <= high) {


		mid = (high + low) / 2;
		//cout << "low" << low << '\t' << "high" << high << endl;//debug
		if (data[mid] > x) {
			high = mid - 1;
		}
		if (data[mid] < x) {
			low = mid + 1;
		}
		if (data[mid] == x) {
			for (int i = 0; i <= high - low; i++) {
				//cout << low+i<<'\t'<<data[low + i] << endl;//debug
				if (data[low + i] == x) {
					//cout << "yes" << endl;//debug
					return low + i + 1;
				}
			}
		}

		if ((high == low) && (data[high] != x) && (data[low] != x)) {
			cout << "not found return ";//debug
			while (low<=size) {
				if (data[low] >x) {
					return low+1;
				}
				low++;
			}
			return low;
		}





	}

}

int main() {

	int arr[7] = { 1,2,2,4,5,5,6 };
	int arr2[8] = { 1,2,2,4,5,5,6,7 };
	cout << BinarySearchFirst(4, arr, 7) << endl;
	cout << BinarySearchFirst(2, arr, 7) << endl;
	cout << BinarySearchFirst(5, arr, 7) << endl;
	cout << BinarySearchFirst(1, arr, 7) << endl;
	cout << BinarySearchFirst(6, arr, 7) << endl;
	cout << BinarySearchFirst(3, arr, 7) << endl;

	printf("\n\n");

	cout << BinarySearchFirst(4, arr2, 8) << endl;
	cout << BinarySearchFirst(2, arr2, 8) << endl;
	cout << BinarySearchFirst(5, arr2, 8) << endl;
	cout << BinarySearchFirst(1, arr2, 8) << endl;
	cout << BinarySearchFirst(6, arr2, 8) << endl;
	cout << BinarySearchFirst(3, arr2, 8) << endl;
	cout << BinarySearchFirst(10, arr2, 8) << endl;
	cout << BinarySearchFirst(0, arr2, 8) << endl;

	return 0;

}
