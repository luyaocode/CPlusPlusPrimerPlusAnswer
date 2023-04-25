#include "func.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <array>
#include <cstring>
using namespace std;

//判断是否整型(合法：正整数或0)
bool isInteger(const string str)
{
	if (empty(str)) return false;
	for (char c : str)
	{
		if (!isdigit(c)) return false;
	}
	return true;
}
//判断是否非法（合法：正负数、整数、小数）
bool isIllegal(const string str)
{
	if (empty(str)) return true;
	if (!isdigit(str.front()) && str.front() != '+' && str.front() != '-') return true;
	if (!isdigit(str.back())) return true;
	for (char c : str)
	{
		if (!isdigit(c) && c != '+' && c != '-' && c != '.') return true;
	}
	return false;
}
int betweenSum()
{
	string a_s;
	string b_s;
	int a;
	int b;
	while (1)
	{
		cout << "Enter a: ";
		cin >> a_s;
		if (isInteger(a_s))
		{
			a = stoi(a_s);
			break;
		}
	}
	while (1)
	{
		cout << "Enter b: ";
		cin >> b_s;
		if (isInteger(b_s))
		{
			b = stoi(b_s);
			break;
		}
	}
	if (a == b) return a * 2;
	else return (a + b) * (abs(a - b) + 1) / 2;
	return -1;
}

void factorial()
{
	const int ArSize = 16;
	const int Size = 101;
	array<long double, Size> facs;
	facs[0] = 1;
	for (int i = 1; i < Size; i++)
	{
		facs[i] = i * facs[i - 1];
	}
	for (int i = 0; i < ArSize; i++)
	{
		cout << i << "! = " << facs[i] << endl;
	}
	cout << 100 << "! = " << facs[Size - 1];
}

void realTimeSum()
{
	string num_s;
	int num = 0;
	int sum = 0;
	while (1)
	{
		cout << "Enter a number: ";
		getline(cin, num_s);
		if (!isIllegal(num_s))
		{
			if (num_s == "0") break;
			num = stoi(num_s);
			sum += num;
			cout << "sum=" << sum << endl;
		}
	}
}

void investmentValue()
{
	float init = 100;
	float DaphneInvest = 100;
	float CleoInvest = 100;
	int year;
	for (year = 0; CleoInvest <= DaphneInvest; year++)
	{
		DaphneInvest += 0.10 * 100;
		CleoInvest += 0.05 * CleoInvest;
	}
	cout << year << " years later..." << endl;
	cout << "Daphne: " << DaphneInvest << endl;
	cout << "Cleo: " << CleoInvest << endl;


}

void bookSales()
{
	const int Size = 12;
	string months[Size] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int sales[Size];
	int sum = 0;
	string sales_s = "";
	string err = "";
	for (int i = 0; i < Size; i++)
	{
		while (1)
		{
			cout << err + "Enter sales volume of " << months[i] << " :";
			getline(cin, sales_s);
			if (isInteger(sales_s))
			{
				sales[i] = stoi(sales_s);
				err = "";
				break;
			}
			err = "Value err, ";
		}
	}
	for (int i = 0; i < Size; i++)
	{
		cout << months[i] + " :" << sales[i] << endl;
		sum += sales[i];
	}
	cout << "Total: " << sum << endl;

}

void bookSalesOfNYears()
{
	const int MonthSize = 12;
	const int YearSize = 3;
	string years[YearSize] = { "2020","2021","2022" };
	string months[MonthSize] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int sales[YearSize][MonthSize];
	string sales_s;
	int sum[YearSize]{};
	int total{};
	string err = "";
	for (int i = 0; i < YearSize; i++)
	{
		for (int j = 0; j < MonthSize; j++)
		{
			while (1)
			{
				cout << err + "Enter sales volume of " + months[j] + ", " + years[i] + ": ";
				getline(cin, sales_s);
				if (isInteger(sales_s))
				{
					sales[i][j] = stoi(sales_s);
					err = "";
					break;
				}
				err = "Value err, ";

			}
		}
	}
	for (int i = 0; i < YearSize; i++)
	{
		for (int j = 0; j < MonthSize; j++)
		{
			sum[i] += sales[i][j];
		}
	}
	for (int i = 0; i < YearSize; i++)
	{
		cout << years[i] + ": " << sum[i] << endl;
		total += sum[i];
	}
	cout << "Total: " << total << endl;

}

struct Car
{
	string corp;
	int year;
};
void carService()
{
	string in;
	int num;
	int year;
	string err;
	while (1)
	{
		cout << "How many cars do you wish to catlog? ";
		getline(cin, in);
		if (isInteger(in))
		{
			num = stoi(in);
			err = "";
			break;
		}
		err = "Value err, ";
	}
	Car* cars = new Car[num];
	for (int i = 0; i < num; i++)
	{
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "Please enter the make: ";
		getline(cin, cars[i].corp);
		while (1)
		{
			cout << "Please enter the year made: ";
			getline(cin, in);
			if (isInteger(in))
			{
				cars[i].year = stoi(in);
				err = "";
				break;
			}
			err = "Value err, ";
		}
	}
	cout << "Here is your collection: " << endl;;
	for (int i = 0; i < num; i++)
	{
		cout << cars[i].year << " " << cars[i].corp << endl;
	}
}

void countWords()
{
	const int MaxSize = 100;
	char ch[MaxSize];
	int count{};
	cout << "Enter the word: ";
	while (1)
	{
		cin >> ch;
		if (!strcmp("done", ch)) break;
		count++;
	}
	cout << "You entered a total of " << count << " words."<<endl;


}

void printStar()
{
	string num_s;
	int num;
	while (1)
	{
		cout << "Enter number of rows: ";
		getline(cin, num_s);
		if (isInteger(num_s))
		{
			num = stoi(num_s);
			break;
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			cout << ".";
		}
		for (int k = 0; k < i + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

}
