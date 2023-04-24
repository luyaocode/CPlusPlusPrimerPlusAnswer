/*显示您的姓名和地址*/
#include <iostream>
#include "func.h"
#include <string>
using namespace std;
void printInfo()
{
	cout << "YourName" << endl;
	cout << "YourAddr" << endl;
}

/*输入以long为单位的距离，转换为码（1 long=220 码）*/
void transDist()
{
	int dist;
	cin >> dist;
	cout << dist * 220 << endl;
}
/**/
void printPiece1()
{
	cout << "Three blind mice" << endl;
}
void printPiece2()
{
	cout << "See how they run" << endl;
}

void transYearToMonth()
{
	int age;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Months: " << age * 12 << endl;
}

void transCelToFah()
{
	float cel;
	cout << "Please enter a Celsius value: ";
	cin >> cel;
	cout << cel << " degrees Celsius is " << cel * 1.8 + 32 << " degrees Fahrenheit.";
}

void transLightYearToAstronomicalUnit()
{
	double light;
	cout << "Enter the number of light years: ";
	cin >> light;
	cout << light << " light years = " << light * 63240 << " astronomical units." << endl;
}

bool isInteger(string str)
{
	if (str.empty()) return false;
	for (char c : str)
	{
		if (!isdigit(c)) return false;
	}
}
/*检验用户输入的是否是数值？-用str接收输入，用isInteger()判断是否是整数，
用stoi()转换为整数？*/
void printTime()
{
	string hour_s="";
	string minute_s ="";
	int hour = 0;
	int minute = 0;

	while (true)
	{
		cin.clear(); // 清空输入缓冲区
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入行
		cout << "Enter the number of hours: ";
		cin >> hour_s;
		if (isInteger(hour_s))
		{
			hour = stoi(hour_s);
			if (hour >= 0 && hour<=24)
			{
				break;
			}
		}
	}
	hour = stoi(hour_s);

	while (true)
	{
		cin.clear(); // 清空输入缓冲区
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入行
		cout << "Enter the number of minutes: ";
		cin >> minute_s;
		if (isInteger(minute_s))
		{
			minute = stoi(minute_s);
			if (minute >= 0 && hour < 60)
			{
				break;
			}
		}
	}
	minute = stoi(minute_s);
	cout << "Time: " << hour << ":" << minute << endl;
}


