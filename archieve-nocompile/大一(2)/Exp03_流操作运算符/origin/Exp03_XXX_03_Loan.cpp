/*
设计类 Loan，并利用这个类完成下列操作
- 由用户输入贷款总额，贷款总年限，贷款年利率
- 分别以等额本金和等额本息法计算分期还款计划。还款算法见PPT.
- 以贷款总额50万元，10年，年利率5.39%为例，比较两种方案还款总额的差值。
- 以贷款总额5万元，1年，年利率7%为例，输出分期还款的计划到文件并读取文件后
  输出到控制台，输出范例见下表。
  
  文件读写要求
- 编写程序，输出到txt文件（注意：存储时各数字的分隔，否则读取时无法实现）
- 编写程序，读取文件数据，输出到console窗口。
  （注意文件的命名，保证你们所有人的程序在一个文件夹下也能找到各自的文件）

  
输出结果到txt文件，输出范例：

贷款总额: 50万元 
贷款年限: 10
贷款年利率: 7 %
等额本息法还款计划: 累计利息1916.05元，累计还款51916.05元
Monthly   Payment(元)   Interest(元)   Principal(元)   Balance(元)
 1        4326.34       291.67         4034.67         45965.33
 ......    
    
等额本金法还款计划:  累计利息1895.83元，累计还款51895.83元
Monthly   Payment(元)   Interest(元)   Principal(元)   Balance(元)
 1        4458.33       291.67         4166.67         45833.33
 ......  

*/

//类成员变量的定义，仅供参考，可根据需要自行定义。
//类的成员函数按需要自行定义。
class MonthlyPayment
{
private:
	unsigned NoMonth;      //还款的第n个月
	double   monPay;       //第n个月的还款额
	double   monCorpus;    //第n个月的还款中的本金数
	double   monInterest;  //第n个月的还款中的利息数
	double   balance;      //本金余额
public:	
};

class Loan
{
private:
    double   amount;        //贷款总额  Loan Amount
    double   annualIRate;   //年利率    Annual Interest Rate
    unsigned numOfYear;     //贷款年限  Number of Years
    //以上为用户输入的基本信息
    
    //以下数据成员自行按需要定义
    unsigned sumMonth;      //总还款月数
    MonthlyPayment equalCorpus; //等额本金法Equality corpus method 
    MonthlyPayment equalCandI;  //等额本息法Equality corpus and interest method 
    unsigned sumPayEC;      //等额本金法总还款额
    unsigned sumPayECI;     //等额本息法总还款额
    unsigned delta;         //两种还款方式总还款额的差额
public:		
} 