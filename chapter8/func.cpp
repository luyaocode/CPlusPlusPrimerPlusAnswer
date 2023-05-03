#include <iostream>
#include <cstring>
#include "func.h"
using namespace std;

void printStr(const char* ch, int times)
{
	if (times == 0)
	{
		cout << ch << endl;
	}
	else
	{
		cout << ch << endl;
	}
}

void setCandyBar(CandyBar& bar, const char* maker, double weight, int calorie)
{
	bar.maker = maker;
	bar.weight = weight;
	bar.calorie = calorie;
	cout << "Set." << endl;
}

void showCandyBar(const CandyBar& bar)
{
	cout << "Show bar:" << endl;
	cout << bar.maker << endl;
	cout << bar.weight << endl;
	cout << bar.calorie << endl;
}

void toUpperCase(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = toupper(s[i]);
	}
}
void toUpperCaseCycle()
{
	string s;
	while (1)
	{
		cout << "Enter a string:" << endl;
		getline(cin, s);
		toUpperCase(s);
		cout << s << endl;
	}
}

void set(stringy& x, char ch[])
{
	char* str = new char[strlen(ch)];
	strcpy_s(str, strlen(ch) + 1, ch);
	x.str = str;
	x.ct = 1;
	cout << "Set." << endl;
}

void show(const stringy& x, int times)
{
	while (times > 0)
	{
		cout << x.str << endl;
		cout << x.ct << endl;
		times--;
	}
	cout << endl;
}

void show(const char ch[], int times)
{
	while (times > 0)
	{
		cout << ch << endl;
		times--;
	}
	cout << endl;
}

template<typename T>
T max5(T arr[5])
{
	int i = 0;
	T res;
	while (i < 5)
	{
		res = std::max(res, arr[i]);
		i++;
	}
	return res;
}
//Explicit instantiation of max5()
template int max5<int>(int[5]);
template double max5<double>(double[5]);

template<typename T>
T maxn(T arr[], int size)
{
	T res{};
	for (int i = 0; i < size; i++)
	{
		res = std::max(res, arr[i]);
	}
	for (int i = 0; i < size; i++)
	{
		if (res = arr[i]) return arr[i];
	}
	return res;
}

//Explicit instantiation of maxn()
template int maxn(int arr[], int size);
template double maxn(double arr[], int size);

//Explicit specialization of maxn()
template<> const char* maxn(const char* pc[], int size)
{
	int maxLen{};
	int target{};
	for (int i = 0; i < size; i++)
	{
		target = strlen(pc[i]);
		maxLen = std::max(maxLen, target);
	}
	for (int i = 0; i < size; i++)
	{
		if (strlen(pc[i]) == maxLen) return pc[i];
	}
	return pc[0];
}

template<typename T>
T sumArray(T arr[], int n)
{
	T res{};
	for (int i = 0; i < n; i++)
	{
		res += arr[i];
	}
	return res;
}

template int sumArray(int arr[], int n);

template<typename T>
T sumArray(T* arr[], int n)
{
	T res{};
	for (int i = 0; i < n; i++)
	{
		res += *arr[i];
	}
	return res;
}
template double sumArray(double* arr[], int n);
