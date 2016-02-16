/**
* ChineseCalendar_example.cpp
* @Author   Tu Yongce <yongce (at) 126 (dot) com>
* @Created  2008-12-13
* @Modified 2008-12-13
* @Version  0.1
*/

#include <iostream>
#include <string>
#include "SolarDate.h"
#include "ChineseDate.h"

using namespace std;

void SolarDateUsage();
void ChineseDateUsage();
void ChineseDate2SolarDate();

std::ostream& operator<< (std::ostream &os, const SolarDate &date)
{
    return os << date.m_iyear << "年" << date.m_imonth << "月" << date.m_iday << "日";
}

std::ostream& operator<< (std::ostream &os, const ChineseDate &date)
{
    return os << date.m_iyear << "年" << date.m_imonth << "月" << date.m_iday << "日";
}
#if 0

int main()
{
   // SolarDateUsage();
    //ChineseDateUsage();
    ChineseDate2SolarDate();

    return 0;
}


void SolarDateUsage()
{
    cout << "------------------- SolarDate Usage ----------------------\n";
    const string weeks[7] = {"日", "一", "二", "三", "四", "五", "六"};

    SolarDate today(2008, 12, 16);

    cout << "今天是:\n" << today;
    cout << ", 星期" <<  weeks[today.ToWeek()];
    cout << ", 今年的第" << today.YearDay() << "天\n\n";

    SolarDate firstday(1, 1 ,1);
    int days = today.Diff(firstday);

    cout << firstday << "距今已有" << days << "天\n";
    cout << firstday << "之后的第" << days << "天是";
    firstday.AdjustDays(days);
    cout << firstday << "\n";
    cout << firstday << "之前的第" << days << "天是";
    firstday.AdjustDays(-days);
    cout << firstday << "\n\n";

    days = 1000*1000*100;  // 1亿
    cout << today << "之后的第" << days << "天是";
    SolarDate oneday(today);
    oneday.AdjustDays(days);
    cout << oneday << "\n";
    cout << oneday << "距今" << oneday.Diff(today) << "天\n";
    cout << oneday << "之前的第" << days << "天是";
    oneday.AdjustDays(-days);
    cout << oneday << "\n\n";

    SolarDate birthday(1949, 10, 1);
    days = today.Diff(birthday);

    cout << "中华人民共和国：\n" << birthday;
    cout << ", 已经成立" << days << "天\n";
    cout << birthday << "之后的第" << days << "天是";
    birthday.AdjustDays(days);
    cout << birthday << "\n";
    cout << birthday << "之前的第" << days << "天是";
    birthday.AdjustDays(-days);
    cout << birthday << "\n\n";

    birthday = SolarDate(2006, 2, 14);
    days = today.Diff(birthday);

    cout << "tyc611的生日：\n" << birthday;
    cout << ", 已经注册" << days << "天\n";
    cout << birthday << "之后的第" << days << "天是";
    birthday.AdjustDays(days);
    cout << birthday << "\n";
    cout << birthday << "之前的第" << days << "天是";
    birthday.AdjustDays(-days);
    cout << birthday << "\n\n";
}

void ChineseDateUsage()
{
    cout << "------------------- ChineseDate Usage --------------------\n";

    ChineseDate today(2008, 11, 19);
    ChineseDate birthday(1983, 11, 27);
    int days = today.Diff(birthday);
    cout << "Birthday: " << birthday << ", 已经出生" << days << "天\n";

    cout << birthday << "之后的" << days << "天是";
    birthday.AdjustDays(days);
    cout << birthday << '\n';

    cout << birthday << "之前的" << days << "天是";
    birthday.AdjustDays(-days);
    cout << birthday << "\n\n";
}
#endif

int  main()
{
	int i = 0;
	#if 1
    cout << "------------------- SolateDate Test --------------------\n";
	SolarDate test1[] =
	{
		{1984,12,13},
		{1984,11,22},
		{1945,10,1},
		{2009,11,22},
		{2019,12,13},
		{2049,5,9},
		{2020,1,19},
		{2020,12,19},
	};

	int SolartTestNum = sizeof(test1)/sizeof(SolarDate);
	for(;i < SolartTestNum;i++)
	{
		ChineseDate tmp;
		ConvertToChineseDate(test1[i],tmp);
		cout << "阳历" << test1[i] << "的对应农历是" << tmp << "\n";
	}

	SolarDate solardate = {2009,1,1};
	for(i=0;i < 12; i++)
	{
		GetSolarTermDate(&solardate,i*2+1);
		cout<<"节气"<<(i)*2+1<<"日期是"<<solardate<<endl;
		
		GetSolarTermDate(&solardate,i*2+2);
		cout<<"节气"<<(i)*2+2<<"日期是"<<solardate<<endl;
	}



#else

    cout << "------------------- ChineseDate Usage --------------------\n";
	ChineseDate test2[] =
	{
		//ChineseDate(1984,10,30,false),
		//ChineseDate(1984,10,21,true),
		ChineseDate(1944,4,1),
		ChineseDate(1944,5,1),
		ChineseDate(2020,12,13),
		ChineseDate(2009,11,22),
		ChineseDate(2049,5,9),
	};

	int ChineseTestNum = sizeof(test2)/sizeof(ChineseDate);
	i = 0;
	for(;i < ChineseTestNum;i++)
	{
		cout << "农历" << test2[i] << "的对应阳历是" << test2[i].ToSolarDate() << '\n';
	}
#endif
    return 1;
}

