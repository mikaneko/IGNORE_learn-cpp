//utf-8 (should compile with ansi-gbk)
//LF 4space
//D2120221 Haixin ZHANG

/*
习题4.3，习题5.10，Time类

利用头文件<ctime>中定义的日期时间函数，
定义日期时间类（TimeDate）。
- 数据成员包括：年、月、日和时、分、秒。
- 函数成员包括：设置日期时间和输出时间，其中月请用枚举类型。
编程：
-  使用合适的头文件ok
-  编写程序完成类定义ok
-  定义拷贝构造函数ok
-  定义对象时默认构造函数取当前时间进行初始化ok
-  显示时间时重取显示时刻的时间并显示出来。
-  在main()中检验所有操作。ok

说明：
头文件<ctime>中定义一个日期时间的结构：
struct tm {
   int tm_sec;         // 秒，范围从 0 到 59
   int tm_min;         // 分，范围从 0 到 59
   int tm_hour;        // 小时，范围从 0 到 23
   int tm_mday;        // 一月中的第几天，范围从 1 到 31
   int tm_mon;         // 月份，范围从 0 到 11
   int tm_year;        // 自 1900 起的年数
   int tm_wday;        // 一周中的第几天，范围从 0 到 6
   int tm_yday;        // 一年中的第几天，范围从 0 到 365
   int tm_isdst;       // 是否夏时制
};

头文件<ctime>中还定义了一系列日期时间函数（更多内容见课本附录二），如：
1. 函数  time_t time(time_t *tp)        是提取当前时间，time_t 即长整型，
   代表从 1970 年 1 月 1 日 00:00:00 开始计算的秒数（格林尼治时间），放在首地址为 tp 的单元内。
2. 函数 tm *localtime(const time_t *tp) 将tp地址单元中的时间转换为日期时间结构的当地时间
3. 函数 tm *gmtime(const time_t *tp)    转换为日期时间结构的格林尼治时间
4. 函数 char *asctime(tm *tb)           将 tb 地址单元中的 tm 结构的日期时间转换为字符串（供显示），
   它有固有格式，如：    Sun   Sep   16   01:03:52   1973

几个函数的使用范例：
    time_t tp;
	time(&tp);  //为tp赋值
	tm* pNow;
    pNow=localtime(&tp);   //库函数localtime有瑕疵，具体原因到第7章解析
    cout<<pNow->tm_year<<endl;
 	cout<<pNow->tm_mon<<endl;
 	cout<<pNow->tm_hour<<endl;
 	cout<<asctime(pNow)<<endl<<endl;

其中库函数localtime可改用安全函数localtime_s，使用范例如下：
 	time_t tp;
	time(&tp);  //为tp赋值
	tm  nowTime;
	tm *pNow=&nowTime;  //使pNow指针指向有意义的地址
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
        time_t timestamp;                           //空时间戳
        time(&timestamp);                           //将当前时间放入时间戳
        tm timenow;
        tm *timenowpointer = &timenow;
        localtime_s(timenowpointer, &timestamp);    //将时间戳转化为tm
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
        time_t timestamp;                           //空时间戳
        time(&timestamp);                           //将当前时间放入时间戳
        tm timenow;
        tm *timenowpointer = &timenow;
        localtime_s(timenowpointer, &timestamp);    //将时间戳转化为tm
        Year = timenow.tm_year + 1900;
        Month = type_month(timenow.tm_mon);
        MDay = timenow.tm_mday;
        Hour = timenow.tm_hour;
        Minute = timenow.tm_min;
        Second = timenow.tm_sec;
        //以上复制自构造函数
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