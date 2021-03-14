//utf-8 (should compile with ansi-gbk)
//LF 4space

/*
ϰ��4.3��ϰ��5.10��Time��

����ͷ�ļ�<ctime>�ж��������ʱ�亯����
��������ʱ���ࣨTimeDate����
- ���ݳ�Ա�������ꡢ�¡��պ�ʱ���֡��롣
- ������Ա��������������ʱ������ʱ�䣬����������ö�����͡�
��̣�
-  ʹ�ú��ʵ�ͷ�ļ�ok
-  ��д��������ඨ��ok
-  ���忽�����캯��ok
-  �������ʱĬ�Ϲ��캯��ȡ��ǰʱ����г�ʼ��ok
-  ��ʾʱ��ʱ��ȡ��ʾʱ�̵�ʱ�䲢��ʾ������
-  ��main()�м������в�����ok

˵����
ͷ�ļ�<ctime>�ж���һ������ʱ��Ľṹ��
struct tm {
   int tm_sec;         // �룬��Χ�� 0 �� 59
   int tm_min;         // �֣���Χ�� 0 �� 59
   int tm_hour;        // Сʱ����Χ�� 0 �� 23
   int tm_mday;        // һ���еĵڼ��죬��Χ�� 1 �� 31
   int tm_mon;         // �·ݣ���Χ�� 0 �� 11
   int tm_year;        // �� 1900 �������
   int tm_wday;        // һ���еĵڼ��죬��Χ�� 0 �� 6
   int tm_yday;        // һ���еĵڼ��죬��Χ�� 0 �� 365
   int tm_isdst;       // �Ƿ���ʱ��
};

ͷ�ļ�<ctime>�л�������һϵ������ʱ�亯�����������ݼ��α���¼�������磺
1. ����  time_t time(time_t *tp)        ����ȡ��ǰʱ�䣬time_t �������ͣ�
   ����� 1970 �� 1 �� 1 �� 00:00:00 ��ʼ�������������������ʱ�䣩�������׵�ַΪ tp �ĵ�Ԫ�ڡ�
2. ���� tm *localtime(const time_t *tp) ��tp��ַ��Ԫ�е�ʱ��ת��Ϊ����ʱ��ṹ�ĵ���ʱ��
3. ���� tm *gmtime(const time_t *tp)    ת��Ϊ����ʱ��ṹ�ĸ�������ʱ��
4. ���� char *asctime(tm *tb)           �� tb ��ַ��Ԫ�е� tm �ṹ������ʱ��ת��Ϊ�ַ���������ʾ����
   ���й��и�ʽ���磺    Sun   Sep   16   01:03:52   1973

����������ʹ�÷�����
    time_t tp;
	time(&tp);  //Ϊtp��ֵ
	tm* pNow;
    pNow=localtime(&tp);   //�⺯��localtime��覴ã�����ԭ�򵽵�7�½���
    cout<<pNow->tm_year<<endl;
 	cout<<pNow->tm_mon<<endl;
 	cout<<pNow->tm_hour<<endl;
 	cout<<asctime(pNow)<<endl<<endl;

���п⺯��localtime�ɸ��ð�ȫ����localtime_s��ʹ�÷������£�
 	time_t tp;
	time(&tp);  //Ϊtp��ֵ
	tm  nowTime;
	tm *pNow=&nowTime;  //ʹpNowָ��ָ��������ĵ�ַ
    localtime_s(pNow, &tp);
*/

#include <ctime>
#include <iostream>

using namespace std;

enum type_month
{
    Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec
};

class TimeDate
{
public:
    TimeDate()
    {
        time_t timestamp;                           //��ʱ���
        time(&timestamp);                           //����ǰʱ�����ʱ���
        tm timenow;
        tm *timenowpointer = &timenow;
        localtime_s(timenowpointer, &timestamp);    //��ʱ���ת��Ϊtm
        Year = timenow.tm_year + 1900;
        Month = type_month(timenow.tm_mon);
        MDay = timenow.tm_mday;
        Hour = timenow.tm_hour;
        Minute = timenow.tm_min;
        Second = timenow.tm_sec;
    }

    TimeDate(const TimeDate &_td)
    {
        Year = _td.Year;
        Month = _td.Month;
        MDay = _td.MDay;
        Hour = _td.Hour;
        Minute = _td.Minute;
        Second = _td.Second;
    }

    void show_time()
    {
        printf("%04d-%02d-%02d %02d:%02d:%02d", Year, Month, MDay, Hour, Minute, Second);
        printf("\n");
    }

    void show_time_now()
    {
        time_t timestamp;                           //��ʱ���
        time(&timestamp);                           //����ǰʱ�����ʱ���
        tm timenow;
        tm *timenowpointer = &timenow;
        localtime_s(timenowpointer, &timestamp);    //��ʱ���ת��Ϊtm
        Year = timenow.tm_year + 1900;
        Month = type_month(timenow.tm_mon);
        MDay = timenow.tm_mday;
        Hour = timenow.tm_hour;
        Minute = timenow.tm_min;
        Second = timenow.tm_sec;
        //���ϸ����Թ��캯��
        printf("%04d-%02d-%02d %02d:%02d:%02d", Year, Month, MDay, Hour, Minute, Second);
        printf("\n");
    }

    void set_time_all(int _Y, int _M, int _D, int _h, int _m, int _s)
    {
        Year = _Y;
        Month = type_month(_M);
        MDay = _D;
        Hour = _h;
        Minute = _m;
        Second = _s;
    }

private:
    type_month Month;
    int Year, MDay, Hour, Minute, Second;
};


int main()
{
    TimeDate obj_test1;
    obj_test1.show_time();

    TimeDate obj_test2;
    obj_test2.set_time_all(9999, 88, 77, 66, 55, 44);
    obj_test2.show_time();
    obj_test2.show_time_now();

    return 0;
}