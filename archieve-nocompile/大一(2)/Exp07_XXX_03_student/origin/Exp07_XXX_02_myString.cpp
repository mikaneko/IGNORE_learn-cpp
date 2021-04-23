/*
参考P226，例7.4对c字符串的处理，
完备你自定义的MyString类。使之能自动适应不同的串长度。

主要是三个成员函数的处理，即所谓三规则(rule of three)，大三元(the big three)：
-  拷贝构造函数（深复制）
-  赋值运算符“=”（深复制）
-  析构函数（资源释放）
除上述三个函数，所有改变对象内容的运算符均需多考虑考虑内存的管理
-  如 +=  >> [] 运算符 以及 + 运算符返回的对象

进一步理解类的封装性(encapsulation)
-  数据(成员变量)，对数据的操作(成员函数)
-  运算符重载，提高类的使用体验。
-  安全的内存资源动态申请和释放。
*/

//下列成员函数在你自定义的myString类中，
//若有，改造为动态内存申请的。
//若无，新增这些成员函数，且使用动态内存申请适应串长变化。

class mystring
{  
private:
	char* str;  
	int   last; 
public:  
	mystring();  
	mystring(char *);                    //C风格字符串强制转换为mystring类，要考虑串长  
	mystring(mystring &);                //深复制，要考虑串长 
	~mystring();  
	void show()const;  	
	
	char        & operator[](int i);        //返回引用，可读可写，注意越界处理，测试时，注意用英文字符串测试
	mystring & operator=(mystring &);    //深复制，要考虑串长  
	mystring & operator=(char *);        //C风格字符串强制转换为mystring类，要考虑串长  
	mystring & operator+=(mystring &);   //要考虑串长
	
	//仅支持与本类型对象的运算，故使用成员函数。【不支持与C风格字符串的运算】  
	bool     operator< (const mystring &) const;  
	bool     operator==(const mystring &) const; 
	mystring operator+ (const mystring &) const;  //要考虑返回对象的串长
	  
	friend istream & operator >> (istream &, MyString &);      //要考虑串长
	friend ostream & operator << (ostream &, const MyString &);    	
}; 