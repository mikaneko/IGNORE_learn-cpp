	/*
	例：输入"+3 5"表示3+5
	输入#退出
	*请输入表达式以计算*
	+5 3
	结果为8
	=======================
	例：输入"+3 5"表示3+5
	输入#退出
	*请输入表达式以计算*
	*10 3
	结果为30
	=======================
	例：输入"+3 5"表示3+5
	输入#退出
	*请输入表达式以计算*
	/5 2
	结果为2.5
	=======================
	例：输入"+3 5"表示3+5
	输入#退出
	*请输入表达式以计算*
	-6 4
	结果为2
	=======================
	例：输入"+3 5"表示3+5
	输入#退出
	*请输入表达式以计算*
	#
	*/
#include <iostream>
using namespace std;
 
double Calculate(double, double, char);
double add(double, double);
double minussss(double, double);//minus好像和std::minus冲突，什么玩意儿
double multi(double, double);
double div(double, double);

int main() {
	bool absorb_enter = 0;//cin.get吸收重复运行时上一次的enter

	//循环，直到#时候break
	while (1) {
		double t1=0, t2=0;
		double outcome = 0;
		cout << "例：输入\"+3 5\"表示3+5\n输入#退出" << endl;
		cout << "*请输入表达式以计算*" << endl;
		//input(分离数字和字符)，cin.get吸收重复运行时上一次的enter
		if (absorb_enter == 1) { cin.get(); }
		absorb_enter = 1;
		//input(#的退出)
		char t3 = cin.get();
		if (t3 == '#')
		{
			break;
		}
		cin >> t1;
		cin >> t2;

		//套用函数
		outcome = Calculate(t1, t2, t3);
		cout << "结果为" << outcome << endl;
		cout << "=======================" << endl;

	}

	return 0;
}

double Calculate(double a, double b, char c) {
	if (c == '+') {
		return add(a, b);
	}
	else if (c == '-') {
		return minussss(a, b);
	}
	else if (c == '*') {
		return multi(a, b);
	}
	else if (c == '/') {
		return div(a, b);
	}
	else {
		cout << "符号输入错误。" << endl;
		return 0;
	}
}

double add(double a, double b) {
	return a + b;
}
double minussss(double a, double b) {
	return a - b;
}
double multi(double a, double b) {
	return a * b;
}
double div(double a, double b) {
	if (b == 0) {
		cout << "除数不能为零" << endl;
		return 0;
	}
	else {
		return a / b;
	}
}