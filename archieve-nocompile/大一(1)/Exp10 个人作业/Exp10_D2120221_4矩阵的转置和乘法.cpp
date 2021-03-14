//可正常使用，经测试
#include <iostream>
using namespace std;

//创建元素为1的矩阵
void createMatrix(int data[], int length, int min, int max) {
	for (int i = 0; i < length; i++) {
		data[i] = 1;
	}
	return;
}
void outputMatrix(const int data[], int row, int column) {
	for (int i = 0; i < row*column; i++) {
		cout << data[i]<<'\t';
		if(i%column==column-1){
			cout << endl;
		}
	}
	cout << endl;
	return;
}
void MatrixTrans(const int A[], int AT[], int row, int column) {
	for (int n = 0; n < column; n++) {
		for (int i = 0; i < row; i++) {
			AT[(n *row)+ i] = A[n+(i * column)];
		}
	}
	return;
}


//利用矩阵乘法的定义算法
void MatrixMulti(int result[], const int AT[], const int B[], int row, int column1, int column2) {
	
	int sum = 0;
	for (int x = 0; x < column1; x++) {
		for (int n = 0; n < column2; n++) {
			for (int i = 0; i < row; i++) {
				sum += AT[(x * row)+i] * B[i * column2 + n];
			}
			result[(x*column2)+n] = sum;
			//debug//cout<<sum<<endl;
			sum = 0;
		}
	}
	
	return;
}

int main() {


	//TEST1
	const int ROW = 3;
	const int COLUMN1 = 6;
	const int COLUMN2 = 7;
	
	int matrix1[ROW * COLUMN1] = { 0 };
	int matrix2[ROW * COLUMN2] = { 0 };

	createMatrix(matrix1, ROW * COLUMN1, 1, 1);
	createMatrix(matrix2, ROW * COLUMN2, 1, 1);

	outputMatrix(matrix1, ROW , COLUMN1);
	outputMatrix(matrix2, ROW , COLUMN2);

	int middle[COLUMN1 * ROW] = { 0 };
	int result[COLUMN1 * COLUMN2] = { 0 };


	MatrixTrans(matrix1, middle, ROW, COLUMN1);
	outputMatrix(middle, COLUMN1, ROW);


	MatrixMulti(result, middle, matrix2, ROW, COLUMN1, COLUMN2);
	outputMatrix(result, COLUMN1, COLUMN2);

	/*for (int i = 0; i < COLUMN1 * COLUMN2; i++) {
		cout<<result[i] << endl;
	}*/
	//用于debug

	cout << "TEST2==============================================" << endl;
	//TEST2

	const int testROW = 3;
	const int testCOL1 = 6;
	const int testCOL2 = 4;
	int testMatrix1[testROW * testCOL1] = { 8,10,12,23,1,3,5,7,9,2,4,6,34,45,56,2,4,6 };
	int testMatrix2[testROW * testCOL2] = { 3,2,1,0,-1,-2,9,8,7,6,5,4 };


	outputMatrix(testMatrix1, testROW, testCOL1);
	outputMatrix(testMatrix2, testROW, testCOL2);

	int test_middle[testCOL1 * testROW] = { 0 };
	int test_result[testCOL1 * testCOL2] = { 0 };


	MatrixTrans(testMatrix1, test_middle, testROW, testCOL1);
	outputMatrix(test_middle, testCOL1, testROW);


	MatrixMulti(test_result, test_middle, testMatrix2, testROW, testCOL1, testCOL2);
	outputMatrix(test_result, testCOL1, testCOL2);


	
	return 0;

}