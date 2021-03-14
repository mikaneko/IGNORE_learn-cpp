#include <iostream>
#include <cmath>
using namespace std;


//数学函数
double MATHf(double MATHx) {
	double MATHt = MATHx * log10(MATHx) - 1;
	return MATHt;
}

//程序主体
int main() {
	int max_calculate = 0;
	double a = 2, b = 3;
	double dx = 0, x1 = 0, x2 = 0, f1 = 0, f2 = 0, epsilon = 0;
	double fa = 0, fb = 0;
	double tmp = 0;
	cout << "请输入最大迭代次数：";
	cin >> max_calculate;
	cout << "请输入误差范围：";
	cin >> epsilon;

	//基本验证
	if (MATHf(a) * MATHf(b) >= 0) {
		cout << "错误" << endl;
		return 0;
	}

	//初始化计算：即将x1设为函数绝对值小对应的自变量，将f1与x1对应。
	if (fabs(MATHf(a)) < fabs(MATHf(b))) { x1 = a; x2 = b; f1 = MATHf(x1); f2 = MATHf(x2); }
	else { x1 = b; x2 = a; f1 = MATHf(x1); f2 = MATHf(x2); }

	//迭代运算公式
	for (int i = 1; i <= max_calculate; i++) {
		dx = (x1 - x2) * f2 / (f2 - f1);

		cout << "dx=" << dx << endl;

		//交换x1x2
		tmp = x1;
		x1 = x2;
		x2 = tmp;
		//x2+dx
		x2 += dx;
		//计算新的f1和f2
		f1 = MATHf(x1);
		f2 = MATHf(x2);

		cout << x2 << endl;

		if ((fabs(dx) < epsilon) || (f2 == 0)) {
			cout << "方程的根是：" << x2 << endl;
			return 0;
		}

	}
	cout << "迭代次数过多" << endl;
	return 0;
}