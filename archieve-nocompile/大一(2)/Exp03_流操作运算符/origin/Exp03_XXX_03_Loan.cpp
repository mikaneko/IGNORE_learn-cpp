/*
����� Loan�������������������в���
- ���û���������ܶ���������ޣ�����������
- �ֱ��Եȶ��͵ȶϢ��������ڻ���ƻ��������㷨��PPT.
- �Դ����ܶ�50��Ԫ��10�꣬������5.39%Ϊ�����Ƚ����ַ��������ܶ�Ĳ�ֵ��
- �Դ����ܶ�5��Ԫ��1�꣬������7%Ϊ����������ڻ���ļƻ����ļ�����ȡ�ļ���
  ���������̨������������±�
  
  �ļ���дҪ��
- ��д���������txt�ļ���ע�⣺�洢ʱ�����ֵķָ��������ȡʱ�޷�ʵ�֣�
- ��д���򣬶�ȡ�ļ����ݣ������console���ڡ�
  ��ע���ļ�����������֤���������˵ĳ�����һ���ļ�����Ҳ���ҵ����Ե��ļ���

  
��������txt�ļ������������

�����ܶ�: 50��Ԫ 
��������: 10
����������: 7 %
�ȶϢ������ƻ�: �ۼ���Ϣ1916.05Ԫ���ۼƻ���51916.05Ԫ
Monthly   Payment(Ԫ)   Interest(Ԫ)   Principal(Ԫ)   Balance(Ԫ)
 1        4326.34       291.67         4034.67         45965.33
 ......    
    
�ȶ�𷨻���ƻ�:  �ۼ���Ϣ1895.83Ԫ���ۼƻ���51895.83Ԫ
Monthly   Payment(Ԫ)   Interest(Ԫ)   Principal(Ԫ)   Balance(Ԫ)
 1        4458.33       291.67         4166.67         45833.33
 ......  

*/

//���Ա�����Ķ��壬�����ο����ɸ�����Ҫ���ж��塣
//��ĳ�Ա��������Ҫ���ж��塣
class MonthlyPayment
{
private:
	unsigned NoMonth;      //����ĵ�n����
	double   monPay;       //��n���µĻ����
	double   monCorpus;    //��n���µĻ����еı�����
	double   monInterest;  //��n���µĻ����е���Ϣ��
	double   balance;      //�������
public:	
};

class Loan
{
private:
    double   amount;        //�����ܶ�  Loan Amount
    double   annualIRate;   //������    Annual Interest Rate
    unsigned numOfYear;     //��������  Number of Years
    //����Ϊ�û�����Ļ�����Ϣ
    
    //�������ݳ�Ա���а���Ҫ����
    unsigned sumMonth;      //�ܻ�������
    MonthlyPayment equalCorpus; //�ȶ��Equality corpus method 
    MonthlyPayment equalCandI;  //�ȶϢ��Equality corpus and interest method 
    unsigned sumPayEC;      //�ȶ���ܻ����
    unsigned sumPayECI;     //�ȶϢ���ܻ����
    unsigned delta;         //���ֻ��ʽ�ܻ����Ĳ��
public:		
} 