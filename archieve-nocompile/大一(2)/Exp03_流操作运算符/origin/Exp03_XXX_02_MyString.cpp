/*
�ο�P177��5.6.3�Զ����ַ����࣬���Ƹ�����MyString�ࡣ

   ϰ��5.11�������Զ����ַ����� MyString��
   �������������캯�������ƹ��캯��������������
�������������
    [ ] (�߱���д���ʹ���);  
    = (�ֱ��� MyString �� C �ַ�������);  
    + ��+=(��Ӧstrcat);  
    <�� >��==(��Ӧstrcmp) 
   
   ϰ��5.12�� ��ϰ�� 5.8 �е��ַ�����������ֲ�� MyString ���У��뽫����תΪ��Ա������
   ע��Աȳ�Ա��������������ڲ����������кβ�ͬ��
   �ַ�������������
   ��1��char *strcat (char *s, const char *ct); ���� ct �ӵ��� s �ĺ��棬�γ�һ��������
   ��2��int strlen(const char * s); ���ַ������ȵĺ��������ش����������������������� 
   ��3��char * reverse (char *); �����ַ��� s�����ɽ���break����Ϊ��kaerb���� 
   ��4��char * strchr( const char *cs,char c); �����ַ� c �ڴ� cs �е�һ�γ��ֵ�λ�ã�����ָ����ַ���ָ�룬��û�г����򷵻� NULL��
   ��5��char *strstr (const char *cs1,const char *cs2); ���ش� cs2 ��Ϊ�Ӵ��� cs1 �е�һ�γ��ֵ�λ�ã���û�г����򷵻� NULL�� 
   
   
���Ҫ��
-  ��Ӻ��ʵ�ͷ�ļ�
-  ���ظ�ֵ���캯��
-  ���ع�ϵ�����
-  �����±������[]
-  ���ظ�ֵ�����=
-  �����ַ��������������+��+=
-  ���������������<<������ȡ�����>>���μ�9.3.3����9.5 
-  ����ַ����������������Ͷ���
-  ��main()�м������в���

*/



const n=21;        //���������� 20 ���ַ��� 10 ������

class MyString
{
    char str[n];   //����ַ������������� 
    int maxsize;   //������Ԫ�������ɷ�ֹ������磬����Ƚ��� 
    int last;      //����Ԫ������±� 
public:  
    MyString()     //�޲ι��캯��
    {
        last=-1;   
        maxsize=n;   
        str[0]='\0';  
    }
    MyString(const char *s)     //��C�ַ�����������ʼ��ʱ���ý�β����
    {
        last=-1;   
        maxsize=n;   
        do{
            last++; 
            str[last]=s[last];   
        }while(s[last]!='\0'&&last<maxsize-1);   
        str[last] ='\0'; //��β����ʱ������Ӵ�������  
    }
    ~MyString(){}  
    
    void show()const{cout<<str<<'\t';} 
    
    
    
    //==============�����Ӷ���Ĳ���============//
    //���ƹ��캯��
    MyString(const MyString & ms);
    

    //���ع�ϵ�����  
    bool operator< (const MyString &)const;     //�����Ѹ�
    bool operator> (const MyString &)const; 
    bool operator==(const MyString &)const;     //�����Ѹ� 
    bool operator!=(const MyString &)const;
    
    //�±������������������(��ֵ�����)������������(��ֵ�����)���ʷ������á� 
    char &operator[](int);                //����ʱ��ע����Ӣ���ַ�������
    
    //���º�������ֵ��Ϊ���ã�����ø��ƹ��캯��
    MyString &operator=(const char * ms);      //�����Ѹ� �������ص�=�ǰ�C����ַ�������MyString
    MyString operator=(const MyString &);      //�������ص�=�ǰ�MyString��Ķ��󸳸�MyString
    MyString operator+(const MyString &); 
    MyString &operator+=(const MyString &); 
    
    //�����������,��μ�9.3.3����9.5                                      
    friend istream & operator >> (istream &, MyString &); 
    friend ostream & operator << (ostream &, const MyString &);
    
    //ϰ��5.12Ҫ��ĳ�Ա����������������ɣ��Աȳ�Ա��������������������кβ�ͬ��
    
    
}; 

//����<�����
bool MyString::operator<(const MyString & ms) const
{
    int i=0,k;  
    do{
        k=str[i]-ms.str[i];   
        i++;  
    }while(k==0&&i<last&&i<ms.last);  
    
    if(k<0) return true;  
    if(i==last&&i!=ms.last) return true;  
    return false; 
} 

//����==�����
bool MyString::operator==(const MyString & ms) const
{
    int i=0,k;  
    if(last!=ms.last) return false;  
    do{
        k=str[i]-ms.str[i];   
        i++;  
    }while(k==0&&i<last);  
    
    if(k!=0) return false;  
    else return true; 
}

//�������ص�=�ǰ�C����ַ�������MyString  
//���ﷵ��ֵΪ���ã������ø��ƹ��캯�� 
MyString & MyString::operator=(const char * ms)
{
    last=-1;   
    do{
        last++;   
        str[last]=ms[last];  
    }while(ms[last]!='\0'&&last<maxsize-1);  
    str[last] ='\0';    //��β����ʱ������Ӵ������� 
    return *this; 
} 