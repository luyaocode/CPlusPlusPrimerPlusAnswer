#include "func.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

//是否是非法（合法：正整数或正小数）
bool isIllegal(const string str)
{
	if (empty(str)) return true;
	if (str[0] == '0' || !isdigit(str[0])) return true;
	for (char c : str)
	{
		if (!isdigit(c) && c != '.') return true;
	}
	if (str[str.length() - 1] == '.') return true;
	return false;
}


bool isInteger(const string str)
{
	if (empty(str)) return false;
	if (str[0] == '0') return false;
	for (char c : str)
	{
		if (!isdigit(c)) return false;
	}
	return true;
}

//是否合法（合法：正整数且小于等于）
bool isIntegerLessOrEqual(const string str, const int max)
{
	if (empty(str)) return false;
	if (str[0] == '0' && str.length() > 1) return false;
	for (char c : str)
	{
		if (!isdigit(c)) return false;
	}
	if (stoi(str) > max) return false;
	return true;
}
//是否合法（合法：正整数且小于）
bool isIntegerLess(const string str, const int max)
{
	if (empty(str)) return false;
	if (str[0] == '0' && str.length() > 1) return false;
	for (char c : str)
	{
		if (!isdigit(c)) return false;
	}
	if (stoi(str) >= max) return false;
	return true;
}
bool isLLLess(const string str, const unsigned long long max)
{
	if (empty(str)) return false;
	if (str[0] == '0' && str.length() > 1) return false;
	for (char c : str)
	{
		if (!isdigit(c)) return false;
	}
	if (stoll(str) >= max) return false;
	return true;
}

//判断是否非法（合法：正整数、正小数，数值小于12）
bool isIllegal2(const string str, const int x)
{
	if (empty(str)) return true;
	if (str[0] == '0' || !isdigit(str[0])) return true;
	for (char c : str)
	{
		if (!isdigit(c) && c != '.') return true;
	}
	if (str[str.length() - 1] == '.') return true;
	if (stof(str) >= x) return true;
	return false;
}


void transFootToInch()
{
	string height_s;
	float height;
	const int x = 12;
	while (true) {
		cin.clear(); // 清空输入缓冲区
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入行
		cout << "Enter the number of your height(inches): ";
		cin >> height_s;
		if (!isIllegal(height_s))
		{
			height = stof(height_s);
			int i = (int)floor(height / x);
			cout << i << "feet, " << height - i * x << "inches." << endl;
			break;
		}
	}
}

void calBMI()
{
	string foot_s;
	string inch_s;
	string weight_s;
	int foot;
	float inch;
	float height;
	float weight;
	double bmi;
	const int x = 12;
	const float y = 0.0254f;
	const float z = 2.2f;
	while (true) {

		cout << "Enter the number of your height(feet): ";
		cin >> foot_s;
		if (isInteger(foot_s))
		{
			foot = stoi(foot_s);
			break;
		}
		cin.clear(); // 清空输入缓冲区
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入行
	}

	while (true)
	{
		cin.clear(); // 清空输入缓冲区
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入行
		cout << "Enter the number of your height(inches): ";
		cin >> inch_s;
		if (!isIllegal2(inch_s, x))
		{
			inch = stof(inch_s);
			height = (foot * x + inch) * y;
			break;
		}
	}

	while (true)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter the number of your weight(pounds): ";
		cin >> weight_s;
		if (!isIllegal(weight_s))
		{
			weight = stof(weight_s) / z;
			break;
		}
	}
	bmi = weight / pow(height, 2);
	cout << "Your height is " << foot << "feet " << inch << " inches." << endl;
	cout << "Your weight is " << stof(weight_s) << " poinds." << endl;
	cout << "Your BMI is " << bmi << " ." << endl;


}

void transLatitude()
{
	string degree;
	string minute;
	string second;
	int deg;
	int min;
	int sec;
	float res;
	const int x = 60;
	const int MaxLatitude = 90;
	cout << "Enter a latitude in degrees, minutes and seconds: " << endl;

	while (1)
	{
		cout << "First, Enter the degree: ";
		cin >> degree;
		if (isIntegerLessOrEqual(degree, MaxLatitude))
		{
			deg = stoi(degree);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	while (1)
	{
		cout << "Next, Enter the minutes of arc: ";
		cin >> minute;
		if (isIntegerLess(minute, x))
		{
			min = stoi(minute);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	while (1)
	{
		cout << "Finally, Enter the seconds of arc: ";
		cin >> second;
		if (isIntegerLess(second, x))
		{
			sec = stoi(second);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	res = deg + float(min / x) + float(sec / pow(x, 2));
	cout << deg << " degrees, " << min << " minutes, " << sec << " seconds = " << res << " degrees. " << endl;


}

void transSecondToDay()
{
	string seconds_s;
	long long seconds;
	long day;
	int hour;
	int min;
	int sec;
	const int d = 24 * 60 * 60;
	const int h = 60 * 60;
	const int m = 60;
	while (1)
	{
		cout << "Enter the number of seconds: ";
		cin >> seconds_s;
		if (isLLLess(seconds_s, ULLONG_MAX))
		{
			seconds = stoi(seconds_s);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	day = long(seconds / d);
	seconds -= day * d;
	hour = int(seconds / h);
	seconds -= hour * h;
	min = int(seconds / m);
	sec = int(seconds - min * m);
	cout << stoi(seconds_s) << " seconds = " << day << " days, " << hour << " hours, " << min << " minutes, " << sec << " seconds. " << endl;
}

void showPopulation()
{
	string all_s;
	string us_s;
	long long all;
	long long us;
	while (1)
	{
		cout << "Enter the world's population: ";
		cin >> all_s;
		if (isLLLess(all_s, ULLONG_MAX))
		{
			all = stoll(all_s);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (1)
	{
		cout << "Enter the population of the US: ";
		cin >> us_s;
		if (isLLLess(us_s, ULLONG_MAX))
		{
			us = stoll(us_s);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "The population of the US is " << (double(us) / all) * 100 << "% of the world's population." << endl;
}

void howManyMilesCanOneGallonOfGasOlineRun()
{
	string miles_s;
	string gallons_s;
	float miles;
	float gallons;
	while (1)
	{
		cout << "Enter the miles: ";
		cin >> miles_s;
		if (!isIllegal(miles_s))
		{
			miles = stof(miles_s);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (1)
	{
		cout << "Enter the gallons: ";
		cin >> gallons_s;
		if (!isIllegal(gallons_s))
		{
			gallons = stof(gallons_s);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "One gallon of gasline can run " << miles / gallons << " miles." << endl;
}

void transEU2US()
{
	string eu_s;
	float eu;
	float us;
	const float x = 62.14;
	const float y = 3.875;
	while (1)
	{
		cout << "Enter the fuel consumption with EU style: ";
		cin >> eu_s;
		if (!isIllegal(eu_s))
		{
			eu = stof(eu_s);
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	us = 1 / (eu / x / y);
	cout << us << endl;

}


