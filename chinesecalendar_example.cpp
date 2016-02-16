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
    return os << date.m_iyear << "��" << date.m_imonth << "��" << date.m_iday << "��";
}

std::ostream& operator<< (std::ostream &os, const ChineseDate &date)
{
    return os << date.m_iyear << "��" << date.m_imonth << "��" << date.m_iday << "��";
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
    const string weeks[7] = {"��", "һ", "��", "��", "��", "��", "��"};

    SolarDate today(2008, 12, 16);

    cout << "������:\n" << today;
    cout << ", ����" <<  weeks[today.ToWeek()];
    cout << ", ����ĵ�" << today.YearDay() << "��\n\n";

    SolarDate firstday(1, 1 ,1);
    int days = today.Diff(firstday);

    cout << firstday << "�������" << days << "��\n";
    cout << firstday << "֮��ĵ�" << days << "����";
    firstday.AdjustDays(days);
    cout << firstday << "\n";
    cout << firstday << "֮ǰ�ĵ�" << days << "����";
    firstday.AdjustDays(-days);
    cout << firstday << "\n\n";

    days = 1000*1000*100;  // 1��
    cout << today << "֮��ĵ�" << days << "����";
    SolarDate oneday(today);
    oneday.AdjustDays(days);
    cout << oneday << "\n";
    cout << oneday << "���" << oneday.Diff(today) << "��\n";
    cout << oneday << "֮ǰ�ĵ�" << days << "����";
    oneday.AdjustDays(-days);
    cout << oneday << "\n\n";

    SolarDate birthday(1949, 10, 1);
    days = today.Diff(birthday);

    cout << "�л����񹲺͹���\n" << birthday;
    cout << ", �Ѿ�����" << days << "��\n";
    cout << birthday << "֮��ĵ�" << days << "����";
    birthday.AdjustDays(days);
    cout << birthday << "\n";
    cout << birthday << "֮ǰ�ĵ�" << days << "����";
    birthday.AdjustDays(-days);
    cout << birthday << "\n\n";

    birthday = SolarDate(2006, 2, 14);
    days = today.Diff(birthday);

    cout << "tyc611�����գ�\n" << birthday;
    cout << ", �Ѿ�ע��" << days << "��\n";
    cout << birthday << "֮��ĵ�" << days << "����";
    birthday.AdjustDays(days);
    cout << birthday << "\n";
    cout << birthday << "֮ǰ�ĵ�" << days << "����";
    birthday.AdjustDays(-days);
    cout << birthday << "\n\n";
}

void ChineseDateUsage()
{
    cout << "------------------- ChineseDate Usage --------------------\n";

    ChineseDate today(2008, 11, 19);
    ChineseDate birthday(1983, 11, 27);
    int days = today.Diff(birthday);
    cout << "Birthday: " << birthday << ", �Ѿ�����" << days << "��\n";

    cout << birthday << "֮���" << days << "����";
    birthday.AdjustDays(days);
    cout << birthday << '\n';

    cout << birthday << "֮ǰ��" << days << "����";
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
		cout << "����" << test1[i] << "�Ķ�Ӧũ����" << tmp << "\n";
	}

	SolarDate solardate = {2009,1,1};
	for(i=0;i < 12; i++)
	{
		GetSolarTermDate(&solardate,i*2+1);
		cout<<"����"<<(i)*2+1<<"������"<<solardate<<endl;
		
		GetSolarTermDate(&solardate,i*2+2);
		cout<<"����"<<(i)*2+2<<"������"<<solardate<<endl;
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
		cout << "ũ��" << test2[i] << "�Ķ�Ӧ������" << test2[i].ToSolarDate() << '\n';
	}
#endif
    return 1;
}

