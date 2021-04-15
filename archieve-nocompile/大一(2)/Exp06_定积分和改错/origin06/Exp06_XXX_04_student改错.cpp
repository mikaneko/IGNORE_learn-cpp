/*
改正含有错误的源程序，答题要求如下：
1. 所有错误行都带有标识  // *
2. 请在错误行中直接修改，不允许删除有错误的行(直接在错误行修改，把错误语句放在注释区)，
3. 除了带有 //* 标识处，其余部分不允许添加新的语句。
*/

#include<iostream>
#include<iofstream>      // *
#include<string.h>       // *
#include<cstring>
using namespace std;
class student	
{
	char  id[10];
	string  name;
	char   *address;
	double *score;       //成绩数组的起始地址
	int  scoreNumber;    //成绩门数
public:
	
	student(char *i=0 ,string n="", double *s=0, int sn=0, char *a=0 );
	~student();
    void show();
};	
				 
student::student(char *i=0 ,string n="", double *s=0, int sn=0, char *a=0 )   // *
{
	cout << "Constructor" <<endl;
	if(i) id=i;                 // *
	else id[0]='\0';
	name=n;    
	if(s) 
    {
    	score=new char[sn];     // *
	    for(int k=0;k<sn;k++) score[k]=s[k];   
	}
    else score=0;
    
    scoreNumber=sn;
    if(a) 
    {	
    	address=new char;           // *
    	strcpy(address,a);   
    }
    else address=0;
}
student::~student()
{
	cout << "Destructor" <<endl;
	delete [] score;                //*
	if(address) delete address;     //*
}

void student::show ()	
{
	cout<<id<<'\t'<<name<<'\t';
	for(int k=0; k<scoreNumber; k++) cout<<score[k]<<'\t';
	cout<<address;                  //*
	cout<<endl;
}

int main()
{
	istream  my("Exp06_student_mark1.txt");  //*   注意文件名和路径不修改，即""内的字符串不修改
    double mark1[6];
    for(int i=0;i<6;i++) my>>mark1[i];
    my.close;                       //*
	student *ps1=student("04010401","范英明",mark1,6,"东南大学无线电系"); //* 
 	ps1->show(); 
	student s2();                   //*
	s2.show();
	double mark3[10]={99,88,66,77,89,78,56,76,88,96};
	student s3("04006606","王靖雯",mark3,10,"南京大学天文系");
	s3.show();
	//*
	return 0;
}
