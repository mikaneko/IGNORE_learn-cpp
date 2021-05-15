/* 
  ����Ϊǰ�����ճ̶�Ƿ�ѵ�ͬѧ��ơ�
  ���鵫�����������п���80������ͬѧ��ɣ�һ������7λͬѧ����  
  
  �ѽϺ�������Ƶ�ͬѧԼ������20~30������ɱ��⣬���Լ��ĳ̶���ѡ��ɡ�
  ������ҵ��4������һ�ֲ��Է����ɲο����⡣
   
���Ҫ��
-    1 Array�����Ѹ����ֳ�Ա�������������������죬��������ӡ���ݵȡ� 
-    2 ��ɸ��������ĳ�Ա���������ⶨ�壺ע�⣬�����ⶨ�塣
-    3 �����Ԫ���������ڶ��塣
-    4 ���ԣ���ɸ���Ա��������Ԫ�����Ĳ��ԡ�

�Ѹ����Ͳ���һ�����ԶԹ��캯���Ĳ��Խ�ʹ�õ����ι��캯����
������ḻ�ĺ��������Լ��������Ͳ������������ɡ�

���������н��Ϊ��
v1�����ǣ�6 2 7
v2�����ǣ�3 8 4
v3�����ǣ�9 5 1
����v1��v2��v3�õ��������ǣ�6 2 7 3 8 4 9 5 1
*/
#include <cstring>

#include <iostream>
using namespace std;


//======== ��̬����ģ���ඨ�� ========//
template <typename T> class Array
{
    T*  pArr;       //��̬����
    int len;        //��ŵ����ݸ���
public:
    ~Array();       //����
    
    Array();        //�޲ι��죬����ʼ�����Ա����ֵ������̬����ռ�
    Array(int len); //һ�ι��죬��̬����elem����ռ䣬����lenΪ���鳤�ȣ���̬�������ݲ���ʼ����
    Array(int len, const T* pT); //���ι��죬��̬����elem����ռ䣬����lenΪ���鳤�ȣ�����pTΪ����Ϊlen�����飬���ڳ�ʼ��elem���顣
    //�������޸ĺ������������������������ϲ�Ϊһ������ʵ�֣��ϲ����Ҫע���֧�������ԡ�
    
    Array(const Array& pArr);                 //���
    Array& operator=(const Array& arr);       //�ֵr
    Array  operator+(const Array& arr) const; //����+
    
    void print(); //��ӡ������������<<��>>�����ô�ӡ�������� 
    
    //ģ�������Ԫ����������������ɶ��� (WHY???)
    friend istream& operator>>(istream& is, Array& arr) 
	{
		for(int i=0;i<arr.len;i++){
			is>>arr.pArr[i];
		} //��
		return is;
	} 
    friend ostream& operator<<(ostream& os, const Array& arr) 
	{
		if(arr.pArr)
		{
			for(int i=0;i<arr.len;i++)
			{
				os<<arr.pArr[i]<<' ';
			}
		}
		else
		{
			os<<"[ERR]";
		}
		return os;
	}
};

template <typename T>
Array<T>::Array()
{
	len=0;
	pArr=NULL;
}

template <typename T>
Array<T>::Array(int _len)
{
	len=_len;
	pArr=new T[_len];
}


template <typename T>
Array<T>::Array(int _len,const T* pT)
{
	len=_len;
	if(pArr=new T[_len])
	{
		for(int i=0;i<_len;i++){
			pArr[i]=pT[i];
		}
	}
}

template <typename T>
Array<T>::Array(const Array& ar)
{
	len=ar.len;
	pArr=new T[len];  //���ж�
	for(int i=0;i<len;i++){
		pArr[i]=ar.pArr[i];
	}
}


template <typename T>
Array<T> &Array<T>::operator=(const Array& ar)
{
	len=ar.len;
	if(pArr) delete []pArr;
	pArr=new T[len];  //���ж�
	for(int i=0;i<len;i++){
		pArr[i]=ar.pArr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if(pArr)delete []pArr;
}


template <typename T>
Array<T> Array<T>::operator+(const Array& arr) const
{
	int newlen=len+arr.len;
	Array ret(newlen);
	for(int i=0;i<len;i++){
		ret.pArr[i]=pArr[i];
	}
	for(int i=0;i<arr.len;i++){
		ret.pArr[len+i]=arr.pArr[i];
	}
	ret.len=newlen;
	return ret; //�ӷ���
}

template <typename T>
void Array<T>::print()
{
	if(pArr){
		for(int i=0;i<len;i++){
			cout<<pArr[i]<<' ';
		}
	}
	else{
		cout<<"[no arr]";
	}
	cout<<endl;
}








int main()
{
    int matrix[3][3]={
          6, 2, 7,
          3, 8, 4,
          9, 5, 1    };
#if 0    
    Array<int> v1(3,matrix[0]);
    Array<int> v2(3,matrix[1]);
    Array<int> v3(3,matrix[2]);
    Array<int> concat;
    
    cout<<"v1�����ǣ�";     v1.print();
    cout<<"v2�����ǣ�";     v2.print();
    cout<<"v3�����ǣ�";     v3.print();
    concat=v1+v2+v3;
    cout<<"����v1��v2��v3�õ��������ǣ�";
    concat.print();
#endif    





#if 1
	Array<int> test01(6);
	cin>>test01;
	cout<<test01<<endl;

#endif


    return 0;
}
