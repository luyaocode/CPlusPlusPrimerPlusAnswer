#ifndef CHAPTER8_H__
#define CHAPTER8_H__

#include <string>
void printStr(const char* ch, int times = 0);

struct CandyBar
{
	const char* maker;
	double weight;
	int calorie;
};
void setCandyBar(CandyBar& bar, const char* maker, double weight, int calorie);
void showCandyBar(const CandyBar& bar);

void toUpperCase(std::string& s);
void toUpperCaseCycle();

struct stringy
{
	char* str;
	int ct;
};

void set(stringy& x, char ch[]);
void show(const stringy& x, int times = 1);
void show(const char ch[], int times = 1);

template<typename T>
T max5(T arr[5]);

template<typename T>
T maxn(T arr[], int size);
//template<> const char* maxn(const char* pc[], const int size);

struct depts
{
	char name[50];
	double amount;
};
template<typename T>
T sumArray(T arr[], int n);

template<typename T>
T sumArray(T* arr[], int n);

#endif
