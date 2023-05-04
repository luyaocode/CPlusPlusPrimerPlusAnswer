#include "func.h"
#include <string.h>
#include <iostream>
using namespace std;
void setGolf(golf& g, const char* name, int hc)
{
	strcpy_s(g.fullname, 40, name);
	g.handicap = hc;
}

int setGolf(golf& g)
{
	char name[Len];
	int hc = 0;
	cout << "Enter fullname: ";
	cin.getline(name, Len);
	if (name[0] == '\0')
	{
		cout << "Name is blank." << endl;
		return 0;
	}
	while (1)
	{
		cout << "Enter handicap: ";
		cin >> hc;
		cin.get();
		if (cin.fail())
		{
			cout << "Data dismatch." << endl;
		}
		break;
	}
	setGolf(g, name, hc);
	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showGolf(const golf& g)
{
	cout << g.fullname << ", " << g.handicap << endl;
}

void SALES::setSales(Sales& s, const double arr[], int n)
{
	double total = 0.0;
	double maxValue = arr[0];
	double minValue = arr[0];
	double averange = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < SALES::QUARTERS)
		{
			s.sales[i] = arr[i];
		}
		total += arr[i];
		maxValue = max(maxValue, arr[i]);
		minValue = min(minValue, arr[i]);
	}
	averange = total / n;
	s.max = maxValue;
	s.min = minValue;
	s.averange = averange;
}

void SALES::setSales(Sales& s)
{
	double arr[100]{};
	int n = 0;
	cout << "Enter items of arr(less than 100) : " << endl;
	for (int i = 0; i < 100; i++)
	{
		cin >> arr[i];
		if (cin.fail())
		{
			cout << "Data dismatch." << endl;
			break;
		}
		n++;
	}
	SALES::setSales(s, arr, n);
}

void SALES::showSales(const Sales& s)
{
	for (int i = 0; i < SALES::QUARTERS; i++)
	{
		cout << s.sales[i] << ", ";
	}
	cout << s.max << ", " << s.min << ", " << s.averange << endl;
}
