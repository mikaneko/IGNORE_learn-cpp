/*
�ο�P226����7.4��c�ַ����Ĵ���
�걸���Զ����MyString�ࡣʹ֮���Զ���Ӧ��ͬ�Ĵ����ȡ�

��Ҫ��������Ա�����Ĵ�������ν������(rule of three)������Ԫ(the big three)��
-  �������캯������ƣ�
-  ��ֵ�������=������ƣ�
-  ������������Դ�ͷţ�
�������������������иı�������ݵ����������࿼�ǿ����ڴ�Ĺ���
-  �� +=  >> [] ����� �Լ� + ��������صĶ���

��һ�������ķ�װ��(encapsulation)
-  ����(��Ա����)�������ݵĲ���(��Ա����)
-  ��������أ�������ʹ�����顣
-  ��ȫ���ڴ���Դ��̬������ͷš�
*/

//���г�Ա���������Զ����myString���У�
//���У�����Ϊ��̬�ڴ�����ġ�
//���ޣ�������Щ��Ա��������ʹ�ö�̬�ڴ�������Ӧ�����仯��

class mystring
{  
private:
	char* str;  
	int   last; 
public:  
	mystring();  
	mystring(char *);                    //C����ַ���ǿ��ת��Ϊmystring�࣬Ҫ���Ǵ���  
	mystring(mystring &);                //��ƣ�Ҫ���Ǵ��� 
	~mystring();  
	void show()const;  	
	
	char        & operator[](int i);        //�������ã��ɶ���д��ע��Խ�紦������ʱ��ע����Ӣ���ַ�������
	mystring & operator=(mystring &);    //��ƣ�Ҫ���Ǵ���  
	mystring & operator=(char *);        //C����ַ���ǿ��ת��Ϊmystring�࣬Ҫ���Ǵ���  
	mystring & operator+=(mystring &);   //Ҫ���Ǵ���
	
	//��֧���뱾���Ͷ�������㣬��ʹ�ó�Ա����������֧����C����ַ��������㡿  
	bool     operator< (const mystring &) const;  
	bool     operator==(const mystring &) const; 
	mystring operator+ (const mystring &) const;  //Ҫ���Ƿ��ض���Ĵ���
	  
	friend istream & operator >> (istream &, MyString &);      //Ҫ���Ǵ���
	friend ostream & operator << (ostream &, const MyString &);    	
}; 