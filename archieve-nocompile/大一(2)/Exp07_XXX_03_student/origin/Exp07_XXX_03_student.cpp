/*
ʵ��18����-3������student�ࡣ
���Ҫ��
1. ���Ӻ��ʵ�ͷ�ļ�
2. ���ӳ�Ա�������
3. ���ӳ�Ա�����ֵ 
4. ������������ 
5. ������Ԫ����operator>>��operator<<ʵ��ѧ�����ϵ���������������
6. ��main��������������������ֵ�������в��ԣ�
7. ��main��������������ѧ�����ϵ����������������в��ԣ�
*/

class student	
{
private:
	char       id[10];        //ע����ֱ߽籣����ʩ
	string     name;          //���걸��װ���࣬�򵥺���
	myString   address;       //�������myString��Դ���Ԫ�Ķ���
	double    *score;         //�ɼ��������ʼ��ַ
	int        scoreNum;      //�ɼ�����
public:
	student(const char *i=0 ,const string n="", const myString a="", const double *s=0, const int sn=0);
	~student();
	void show();
}��
