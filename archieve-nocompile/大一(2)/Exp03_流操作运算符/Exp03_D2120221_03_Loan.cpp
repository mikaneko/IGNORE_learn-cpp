//D:\GitCode\IGNORE_learn-cpp\cmake-build-debug\IGNORE_learn_cpp.exe
//==================================================
//Using method of "equal corpus".
//Month	NeedPay		PayCorpus	PayInterest	Balance
//1		4458.33		4166.67		291.67		45833.33
//2		4434.03		4166.67		267.36		41666.67
//3		4409.72		4166.67		243.06		37500.00
//4		4385.42		4166.67		218.75		33333.33
//5		4361.11		4166.67		194.44		29166.67
//6		4336.81		4166.67		170.14		25000.00
//7		4312.50		4166.67		145.83		20833.33
//8		4288.19		4166.67		121.53		16666.67
//9		4263.89		4166.67		97.22		12500.00
//10	4239.58		4166.67		72.92		8333.33
//11	4215.28		4166.67		48.61		4166.67
//12	4190.97		4166.67		24.31		0.00
//SUM_INTEREST = 1895.83
//SUM_PAY = 51895.83
//==================================================
//Using method of "equal cand i".
//Month	NeedPay		PayCorpus	PayInterest	Balance
//1		4326.34		4166.67		159.67		45833.33
//2		4326.34		4166.67		159.67		41666.67
//3		4326.34		4166.67		159.67		37500.00
//4		4326.34		4166.67		159.67		33333.33
//5		4326.34		4166.67		159.67		29166.67
//6		4326.34		4166.67		159.67		25000.00
//7		4326.34		4166.67		159.67		20833.33
//8		4326.34		4166.67		159.67		16666.67
//9		4326.34		4166.67		159.67		12500.00
//10	4326.34		4166.67		159.67		8333.33
//11	4326.34		4166.67		159.67		4166.67
//12	4326.34		4166.67		159.67		0.00
//SUM_INTEREST = 1916.05
//SUM_PAY = 51916.05
//The Delta is: -21
//
//Process finished with exit code 0

//以上是运行结果
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
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

struct StatTrak
{
    double SUM_INTEREST = 0;
    double SUM_PAY = 0;
};

class MonthlyPayment
{
private:
    unsigned NoMonth;      //还款的第n个月
    double monPay;       //第n个月的还款额
    double monCorpus;    //第n个月的还款中的本金数
    double monInterest;  //第n个月的还款中的利息数
    double balance;      //本金余额

public:
    void setNoMonth(unsigned a)
    {
        NoMonth = a;
    }

    void setMonCorpus(double a)
    {
        monCorpus = a;
    }

    void setMonInterest(double a)
    {
        monInterest = a;
    }

    void cal_monPay()
    {
        monPay = monInterest + monCorpus;
    }

    void setBalance(double a)
    {
        balance = a;
    }

    void show_info() const
    {
        std::cout << std::fixed << std::setprecision(2) << NoMonth << "\t\t" << monPay << "\t\t" << monCorpus << "\t\t"
                  << monInterest << "\t\t" << balance
                  << std::endl;
    }

    double getBalance() const
    {
        return balance;
    }

    double getMonCorpus() const
    {
        return monCorpus;
    }

    double getMonPay() const
    {
        return monPay;
    }

    void setMonPay(double a)
    {
        monPay = a;
    }

    double getMonInterest() const
    {
        return monInterest;
    }
};

class Loan
{
private:
    double amount;        //贷款总额  Loan Amount
    double annualIRate;   //年利率    Annual Interest Rate
    unsigned numOfYear;     //贷款年限  Number of Years
    //以上为用户输入的基本信息

    //以下数据成员自行按需要定义
    unsigned sumMonth;      //总还款月数
    MonthlyPayment equalCorpus; //等额本金法Equality corpus method
    MonthlyPayment equalCandI;  //等额本息法Equality corpus and interest method
    unsigned sumPayEC;      //等额本金法总还款额
    unsigned sumPayECI;     //等额本息法总还款额
    int delta;         //两种还款方式总还款额的差额
    double monthIRate;

    std::string writefile_destination;
    bool writefile;

public:
    Loan(double _amount = 0, double _annualIRate = 0, unsigned _numOfYear = 0)
    {
        amount = _amount;
        annualIRate = _annualIRate;
        numOfYear = _numOfYear;
        sumMonth = numOfYear * 12;
        monthIRate = annualIRate / 12;
        writefile = false;
    }

    void show_via_equalCorpus()
    {
        std::ofstream ofile1;
        ofile1.open(writefile_destination, std::ios::app);
        std::cout << "==================================================" << std::endl;
        std::cout << "Using method of \"equal corpus\". " << std::endl;
        std::cout << "Month\tNeedPay\t\tPayCorpus\tPayInterest\tBalance" << std::endl;
        //////
        if (writefile)
        {
            ofile1 << "==================================================" << std::endl;
            ofile1 << "Using method of \"equal corpus\". " << std::endl;
            ofile1 << "Month\tNeedPay\t\tPayCorpus\tPayInterest\tBalance" << std::endl;
        }
        //////

        StatTrak ST;        //设置计数器
        ST.SUM_INTEREST = 0;
        ST.SUM_PAY = 0;

        equalCorpus.setBalance(amount);
        equalCorpus.setMonCorpus(amount / sumMonth);
        for (int i = 1; i <= sumMonth; i++)
        {
            equalCorpus.setNoMonth(i);
            equalCorpus.setMonInterest(equalCorpus.getBalance() * monthIRate);
            ST.SUM_INTEREST += equalCorpus.getMonInterest();                 //统计Intest总和
            equalCorpus.cal_monPay();
            ST.SUM_PAY += equalCorpus.getMonPay();                          //统计Pay总和
            equalCorpus.setBalance(equalCorpus.getBalance() - equalCorpus.getMonCorpus());  //minus the balance
            equalCorpus.show_info();        //show
            //////
            if (writefile)
            {
                ofile1 << std::fixed << std::setprecision(2) << i << "\t\t" << equalCorpus.getMonPay() << "\t\t"
                       << equalCorpus.getMonCorpus() << "\t\t"
                       << equalCorpus.getMonInterest() << "\t\t" << equalCorpus.getBalance()
                       << std::endl;
            }
            //////
        }

        sumPayEC = ST.SUM_PAY;
        std::cout << "SUM_INTEREST = " << ST.SUM_INTEREST << std::endl;
        std::cout << "SUM_PAY = " << ST.SUM_PAY << std::endl;
        //////
        if (writefile)
        {
            ofile1 << "SUM_INTEREST = " << ST.SUM_INTEREST << std::endl;
            ofile1 << "SUM_PAY = " << ST.SUM_PAY << std::endl;
        }
        //////

        ofile1.close();
    }

    void show_via_equalCandI()
    {
        std::ofstream ofile2;
        ofile2.open(writefile_destination, std::ios::app);
        std::cout << "==================================================" << std::endl;
        std::cout << "Using method of \"equal cand i\". " << std::endl;
        std::cout << "Month\tNeedPay\t\tPayCorpus\tPayInterest\tBalance" << std::endl;
        //////
        if (writefile)
        {
            ofile2 << "==================================================" << std::endl;
            ofile2 << "Using method of \"equal cand i\". " << std::endl;
            ofile2 << "Month\tNeedPay\t\tPayCorpus\tPayInterest\tBalance" << std::endl;
        }
        //////

        StatTrak ST;        //设置计数器
        ST.SUM_INTEREST = 0;
        ST.SUM_PAY = 0;

        equalCandI.setBalance(amount);
        equalCandI.setMonCorpus(amount / sumMonth);
        for (int i = 1; i <= sumMonth; i++)
        {
            equalCandI.setNoMonth(i);
            equalCandI.setMonPay(
                    amount * monthIRate * (pow(1 + monthIRate, sumMonth)) / (pow(1 + monthIRate, sumMonth) - 1));
            equalCandI.setMonInterest(equalCandI.getMonPay() - equalCandI.getMonCorpus());
            ST.SUM_INTEREST += equalCandI.getMonInterest();
            ST.SUM_PAY += equalCandI.getMonPay();
            equalCandI.setBalance(equalCandI.getBalance() - equalCandI.getMonCorpus());
            equalCandI.show_info();
            //////
            if (writefile)
            {
                ofile2 << std::fixed << std::setprecision(2) << i << "\t\t" << equalCandI.getMonPay() << "\t\t"
                       << equalCandI.getMonCorpus() << "\t\t"
                       << equalCandI.getMonInterest() << "\t\t" << equalCandI.getBalance()
                       << std::endl;
            }
            //////
        }

        sumPayECI = ST.SUM_PAY;
        std::cout << "SUM_INTEREST = " << ST.SUM_INTEREST << std::endl;
        std::cout << "SUM_PAY = " << ST.SUM_PAY << std::endl;

        //////
        if (writefile)
        {
            ofile2 << "SUM_INTEREST = " << ST.SUM_INTEREST << std::endl;
            ofile2 << "SUM_PAY = " << ST.SUM_PAY << std::endl;
        }
        //////
        ofile2.close();
    }

    void set_file_IO_destination(std::string _destination)
    {
        writefile_destination = _destination;
    }

    void cal_2_methods_and_writefile()
    {
        ////清除原本的文件内容
        std::ofstream ofileclear;
        ofileclear.open(writefile_destination);
        ofileclear.close();
        ////利用追加方式写入文件
        writefile = true;
        show_via_equalCorpus();
        show_via_equalCandI();
        writefile = false;
    }

    void cal_delta()
    {
        delta = (int) sumPayEC - (int) sumPayECI;
    }

    void show_delta()
    {
        std::cout << "The Delta is: " << delta << std::endl;
    }
};


int main()
{
    Loan l1(50000, 0.07, 1);

    // l1.show_via_equalCorpus();
    // l1.show_via_equalCandI();

    l1.set_file_IO_destination("./D2120221_loan_log.txt");
    l1.cal_2_methods_and_writefile();   //use append_method to write files.


    l1.cal_delta();     //calculate delta
    l1.show_delta();

    return 0;

}