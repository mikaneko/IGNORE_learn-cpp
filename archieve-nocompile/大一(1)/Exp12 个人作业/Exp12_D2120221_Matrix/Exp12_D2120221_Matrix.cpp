//7       8       - 1     - 10     - 8     - 3.6
//6       - 5     - 1     5        9       2.8
//6       5       8       5        - 8      3.2
//5       8       6       0        - 7      2.4
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<iomanip>

using namespace std;

void createMatrix(double data[], int row, int column, int min, int max) {
	srand(time(0));

	for (int i = 0; i < row-1; i++) {
		for (int j = 0; j < column-1; j++) {
			int randnum = rand() % (max - min + 1) + min;
			data[column * i + j] = randnum;
		}
	}
	return;
}

void avrgRow(double data[], int row, int column) {
	for (int i = 0; i < row - 1; i++) {
		double sum = 0;
		for (int j = 0; j < column - 1; j++) {
			sum += data[column * i + j];
		}
		data[i*column + (column-1)] = sum / (column - 1);
	}
	return;
}
void sumColumn(double* data, int row, int column){
	for (int j = 0; j < column; j++) {
		double sum = 0;
		for (int i = 0; i < row-1; i++) {
			sum += data[i * column + j];
		}
		data[column * (row - 1) + j] = sum;
	}
	return;
}
void saveData(const double data[], int row, int column, char file[]) {
	ofstream ofile;
	ofile.open(file);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			ofile << setprecision(2) <<data[column * i + j] << '\t';
		}
		ofile << endl;
	}
	cout <<"save"<< endl;
	ofile.close();
	return;
}
void outputData(const double* data, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << setprecision(2) << data[column * i + j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main() {
	

	const unsigned int ROW = 4;
	const unsigned int COLUMN = 6;
	double matrix[ROW][COLUMN];
	char filename[] = "Exp12_D2120221_Matrix.txt";
	createMatrix(matrix[0], ROW, COLUMN, -10, 10);// &matrix[0][0] = matrix[0]= matrix
	avrgRow(matrix[0], ROW, COLUMN);
	sumColumn(matrix[0], ROW, COLUMN);
	saveData(matrix[0], ROW, COLUMN, filename);
	outputData(matrix[0],ROW,COLUMN);



	return 0;
}