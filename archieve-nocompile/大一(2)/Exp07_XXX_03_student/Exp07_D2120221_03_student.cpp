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

//hehe
#define myString mystring

#include <string>
#include <iostream>
#include <cstring>
using namespace std;
#include "Exp07_D2120221_02_myString.cpp"

class student
{
private:
    char id[10];      //注意各种边界保护措施
    string name;      //已完备封装的类，简单好用
    myString address; //测试你的myString类对大三元的定义
    double *score;    //成绩数组的起始地址
    int scoreNum;     //成绩门数
public:
    student(const char *i = 0, const string n = "", const myString a = "", const double *s = 0, const int sn = 0);
    student(const student &);
    ~student();
    void show();
    student &operator=(const student &);
    friend istream &operator>>(istream &is, student &st);
    friend ostream &operator<<(ostream &is, const student &st);
};

student::student(const char *i, const string n, const myString a, const double *s, const int sn)
{
    strcpy(id, i);
    name = n;
    address = a;
    scoreNum = sn;
    if (scoreNum != 0)
    {
        score = new double[scoreNum];
    }
    else
    {
        score = NULL;
    }
    for (int i = 0; i < scoreNum; i++)
    {
        score[i] = s[i];
    }
}

student::student(const student &st)
{
    strcpy(id, st.id);
    name = st.name;
    address = st.address;
    scoreNum = st.scoreNum;
    if (score)
    {
        delete score;
    }
    score = new double[scoreNum];
    for (int i = 0; i < scoreNum; i++)
    {
        score[i] = st.score[i];
    }
}
student::~student()
{
    if (score)
    {
        delete[] score;
    }
}

void student::show()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "ScoreNum: " << scoreNum << endl;
    for (int i = 0; i < scoreNum; i++)
    {
        cout << score[i] << "  ";
    }
    cout << endl;
}

student &student::operator=(const student &st)
{
    strcpy(id, st.id);
    name = st.name;
    address = st.address;
    scoreNum = st.scoreNum;
    if (score)
    {
        delete score;
    }
    score = new double[scoreNum];
    for (int i = 0; i < scoreNum; i++)
    {
        score[i] = st.score[i];
    }
}

istream &operator>>(istream &is, student &st)
{
    is >> st.id;
    is >> st.name;
    is >> st.address;
    is >> st.scoreNum;
    if (st.score)
    {
        delete st.score;
    }
    st.score = new double[st.scoreNum];
    for (int i = 0; i < st.scoreNum; i++)
    {
        is >> st.score[i];
    }
}
ostream &operator<<(ostream &os, const student &st)
{
    os << "ID: " << st.id << "Name: " << st.name << "\nAddress: " << st.address << "\nScoreNum: " << st.scoreNum<<'\n';
    for (int i = 0; i < st.scoreNum; i++)
    {
        os << st.score[i] << "  ";
    }
    cout << endl;
    return os;
}

int main(int argc, char **argv)
{
    double fenshu[] = {99.9, 99.8, 99.7};
    student s1("D2120221", "ZhangHX", "YanCheng", fenshu, 3);
    s1.show();
    student s2("12212", "hhh", "nanj", fenshu, 3);
    cin >> s2;
    cout << s2 << endl;

    return 0;
}