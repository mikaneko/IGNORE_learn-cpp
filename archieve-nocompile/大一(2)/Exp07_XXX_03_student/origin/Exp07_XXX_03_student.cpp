/*
实验18，二-3，完善student类。
编程要求：
1. 增加合适的头文件
2. 增加成员函数深拷贝
3. 增加成员函数深赋值 
4. 定义析构函数 
5. 增加友元函数operator>>和operator<<实现学生资料的整体输入和输出；
6. 在main函数中增加语句对深拷贝和深赋值函数进行测试；
7. 在main函数中增加语句对学生资料的整体输入和输出进行测试；
*/

class student	
{
private:
	char       id[10];        //注意各种边界保护措施
	string     name;          //已完备封装的类，简单好用
	myString   address;       //测试你的myString类对大三元的定义
	double    *score;         //成绩数组的起始地址
	int        scoreNum;      //成绩门数
public:
	student(const char *i=0 ,const string n="", const myString a="", const double *s=0, const int sn=0);
	~student();
	void show();
}；
