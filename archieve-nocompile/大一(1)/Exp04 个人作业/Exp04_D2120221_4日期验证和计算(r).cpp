/*

提交程序清单4
4、实验四-5 ，DayInYear不限实现方式，尝试多种方
案实现（每个人的脑洞不同，程序可有万千呈现）。
要求1. 键盘输入年月日，合理简洁的输入提示。
Tips：本题与第3题一样，略有难度，若实现有困难的
同学，也可实现本题部分功能，即DateValidity：键盘
输入一个日期如：1900年2月29日，判断该日期是否为合法日
期并输出判断结果。
要求：在程序顶部用注释给出你的测试结果，下列几
个输入输出范例：
输入：1900 2 29 输出：日期非法
输入：2020 1 2 输出：2020年1月2日是2020年的第2天

*/
#include <iostream>
using namespace std;

int main() {
	while (1) {
		int year = 0, month = 0, day = 0, v_dayinmonth = 0, sumday = 0;
		bool basic_validate = 0, dual_validate = 0;
		bool runnian = 0;

		//第一次基本validate
		while (basic_validate == 0) {
			cout << "请输入年，月，日: \t";
			cin >> year >> month >> day;
			cout << year << "年" << month << "月" << day << "日" << endl;
			if (((year >= 1000) && (year <= 3000) && (month >= 1) && (month <= 12) && (day >= 1) && (day <= 31)) == 1) {
				basic_validate = 1;
			}
			else {
				if (year < 1000 || year>3000) { cout << "年输入错误。" << endl; }
				if (month < 1 || month>12) { cout << "月输入错误。" << endl; }
				if (day < 1 || day>31) { cout << "日输入错误。" << endl; }
			}
		}

		//判断闰年
		if ((year % 4 == 0) & (year % 100 != 0)) { runnian = 1; }
		else if ((year % 400) == 0) { runnian = 1; }
		else { runnian = 0; }

		//判断月份的天数，进行第二次validate
		switch (month) {
		case 1:v_dayinmonth = 31; break;
		case 2: {if (runnian == 1) { v_dayinmonth = 29; } else { v_dayinmonth = 28; } break; }
		case 3:v_dayinmonth = 31; break;
		case 4:v_dayinmonth = 30; break;
		case 5:v_dayinmonth = 31; break;
		case 6:v_dayinmonth = 30; break;
		case 7:v_dayinmonth = 31; break;
		case 8:v_dayinmonth = 31; break;
		case 9:v_dayinmonth = 30; break;
		case 10:v_dayinmonth = 31; break;
		case 11:v_dayinmonth = 30; break;
		case 12:v_dayinmonth = 31; break;
		}
		//第二次验证日期,直接结束
		while(dual_validate==0){
			if (day > v_dayinmonth) { cout << "日输入有错\n请重新输入日：" << endl; cin >> day; }
			else { dual_validate = 1; }
		}

		//每月天数的数组
		int dayinmonth[]{ 31,0,31,30,31,30,31,31,30,31,30,31 };
		if (runnian == 1) { dayinmonth[1] = 29; }
		else { dayinmonth[1] = 28; }

		//循环累加天数
		for (int i = 1; i < month; i += 1) {
			sumday += dayinmonth[i - 1];
		}
		sumday += day;
		cout << year << "年" << month << "月" << day << "日是" << year << "年的第" << sumday << "日" << endl;
		cout << "\n\n=====================================\n\n";

	}
		return 0;
}