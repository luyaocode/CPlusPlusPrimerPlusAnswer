#include "func.h"
#include <iostream>
using namespace std;

double* harmonicMean(int maxSize)
{
	double two[2]{};
	double* harmonic = new double[maxSize];
	double* p = harmonic;
	for (int j = 0; j < maxSize; j++, p++)
	{
		cout << "Enter two numbers: " << endl;
		for (int i = 0; i < 2; i++)
		{
			cin >> two[i];
			if (cin.fail())
			{
				cout << "Data dismatch." << endl;
				break;
			}
		}

		if (!two[0] || !two[1])
		{
			cout << "You entered a 0." << endl;
			*p = 0;
			break;
		}
		*p = calHarmonicMean(two[0], two[1]);
	}
	return harmonic;

}

double calHarmonicMean(double x, double y)
{
	return 2 * x * y / (x + y);
}

void initArr(float* scores, int maxSize)
{
	for (int i = 0; i < maxSize; i++, scores++)
	{
		*scores = NAN;
	}
}
void inputGolfScores(float* scores, int maxSize)
{
	float score = NAN;
	initArr(scores, maxSize);
	cout << "Enter scores:" << endl;
	for (int i = 0; i < maxSize; i++, scores++)
	{
		cin >> score;
		if (cin.fail())
		{
			cout << "Data dismatch." << endl;
			break;
		}
		*scores = score;
	}
}

void showGolfSocres(float* scores, int maxSize)
{
	cout << "Show scores:" << endl;
	for (int i = 0; i < maxSize; i++, scores++)
	{
		if (!isnan(*scores))
			cout << *scores << endl;
	}
}

float calAverGolfScore(float* scores, int maxSize)
{
	float sum = 0.0;
	int count = 0;
	for (int i = 0; i < maxSize; i++, scores++)
	{
		if (!isnan(*scores))
		{
			sum += *scores;
			count++;
		}
	}
	if (!count) return NAN;
	else return sum / count;
}



void showBoxMembers(box box)
{
	cout << "maker: " << box.maker << endl;
	cout << "height: " << box.height << endl;
	cout << "length " << box.length << endl;
	cout << "width " << box.width << endl;
	cout << "volume " << box.volume << endl << endl;
}

void setBoxVolume(box* bptr)
{
	if (bptr == nullptr) return;
	bptr->volume = bptr->height * bptr->length * bptr->width;
	cout << "Set." << endl << endl;
}

double probability(unsigned int numbers, unsigned picks)
{
	int n = numbers;
	int p = picks;
	double res = 1.0;
	for (; p > 0; n--, p--)
	{
		res = res * n / p;
	}
	return res;
}

long double calFactorial(unsigned int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * calFactorial(n - 1);
	}
}

int fillArray(double arr[], int size)
{
	int count = 0;
	double temp = 0.0;
	cout << "Initialize the array autoly." << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i] = NAN;
	}
	cout << "Enter numbers:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		if (cin.fail())
		{
			cout << "Data dismatch." << endl;
			break;
		}
		arr[i] = temp;
		count++;
	}
	return count;
}

void showArray(double arr[], int size)
{
	cout << "Show array:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (!isnan(arr[i]))
		{
			cout << arr[i] << endl;
		}
		else
		{
			break;
		}
	}
}

void reverseArray(double arr[], int size)
{
	cout << "Reverse array." << endl;
	int count = 0;
	double temp = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (isnan(arr[i])) break;
		count++;
	}
	for (int i = 0; i < count / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[count - i - 1];
		arr[count - i - 1] = temp;
	}
}

void init_array(double* begin, int size)
{
	if (begin == nullptr) return;
	double* p = begin;
	for (int i = 0; i < size; i++, p++)
	{
		*p = NAN;
	}
}
double* fill_array(double* begin, int size)
{
	if (begin == nullptr) return nullptr;
	double* end, * p;
	end = p = begin;
	double temp = 0.0;
	init_array(p, size);
	cout << "Enter numbers:" << endl;
	for (int i = 0; i < size; i++, p++)
	{
		cin >> temp;
		if (cin.fail() || temp < 0)
		{
			cout << "Data dismatch." << endl;
			break;
		}
		*p = temp;
		end = p;
	}
	return end;
}

void show_array(double* begin, double* end)
{
	cout << "Show array:" << endl;
	if (begin == nullptr || end == nullptr) return;
	double* p = begin;
	double* q = end;
	for (; p != q; p++)
	{
		cout << *p << endl;
	}
	if (!isnan(*p))
		cout << *p << endl;

}

void revalue_array(double r, double* begin, double* end)
{
	cout << "Revalue array." << endl;
	if (begin == nullptr || end == nullptr) return;
	double* p = begin;
	double* q = end;
	for (; p != q; p++)
	{
		(*p) *= r;
	}
	if (!isnan(*p))
		(*p) *= r;

}

void fillExpenses(const char* snames[], double expenses[])
{
	double temp;
	for (int i = 0; i < 4; i++)
	{
		while (1)
		{
			cout << "Enter " << snames[i] << " expenses:" << endl;
			cin >> temp;
			if (cin.fail() || temp < 0)
			{
				cout << "Data dismatch." << endl;
			}
			else
			{
				break;
			}
		}
		expenses[i] = temp;
	}
}

void showExpenses(const char* snames[], double expenses[])
{
	double total = 0.0;
	cout << "EXPENSES:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << snames[i] << ": $" << expenses[i] << endl;
		total += expenses[i];
	}
	cout << "Total: $" << total;
}



void fillExpenses2(const char* snames[], exp_st& exp)
{
	double temp;
	for (int i = 0; i < 4; i++)
	{
		while (1)
		{
			cout << "Enter " << snames[i] << " expenses:" << endl;
			cin >> temp;
			if (cin.fail() || temp < 0)
			{
				cout << "Data dismatch." << endl;
			}
			else
			{
				break;
			}
		}
		exp.expenses[i] = temp;
	}
}

void showExpenses2(const char* snames[], exp_st& exp)
{
	double total = 0.0;
	cout << "EXPENSES:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << snames[i] << ": $" << exp.expenses[i] << endl;
		total += exp.expenses[i];
	}
	cout << "Total: $" << total << endl;
}

void initStudents(student stu[], int n)
{
	if (stu == nullptr) return;
	cout << "Init." << endl;
	student* p = stu;
	const char names[][30] =
	{
	"Tom",
	"Jerry",
	"Alice",
	"Bob",
	"Charlie",
	"David",
	"Emily",
	"Frank",
	"Grace",
	"Henry"
	};
	const char hobbys[][30] = {
	"reading books",
	"playing sports",
	"watching movies",
	"listening to music",
	"traveling",
	"painting",
	"photography",
	"playing video games",
	"cooking",
	"learning new skills"
	};
	for (int i = 0; i < n; i++, p++)
	{
		if (i < 10)
		{
			strcpy_s((*p).fullname, names[i]);
			strcpy_s((*p).hobby, hobbys[i]);
			(*p).ooplevel = (2 * i + 1) % 10 + 1;
		}
		else
		{
			strcpy_s((*p).fullname, "");
			strcpy_s((*p).hobby, "");
			(*p).ooplevel = NAN;
		}

	}
}
int getinfo(student stu[], int n)
{
	if (stu == nullptr) return -1;
	student* p = stu;
	int count = 0;
	for (int i = 0; i < n; i++, p++)
	{
		if ((*p).fullname[0] == '\0')
		{
			break;
		}
		count++;
	}
	return count;
}
void display1(student stu)
{
	cout << "Display1: " << endl;
	cout << stu.fullname << " ,";
	cout << stu.hobby << " ,";
	cout << stu.ooplevel << endl;
}
void display2(const student* ps)
{
	if (ps == nullptr) return;
	cout << "Display2: " << endl;
	cout << ps->fullname << " ,";
	cout << ps->hobby << " ,";
	cout << ps->ooplevel << endl;
}
void display3(const student stu[], int n)
{
	cout << "Display3: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << stu[i].fullname << " ,";
		cout << stu[i].hobby << " ,";
		cout << stu[i].ooplevel << endl;
	}
}

double addTwoNumbers(double x, double y)
{
	return x+y;
}

double multiplyTwoNumbers(double x, double y)
{
	return x*y;
}

double powTwoNumbers(double x, double y)
{
	return pow(x,y);
}

double calculateTwoNumbers(double x, double y, double(*pf)(double x, double y))
{
	if (pf == nullptr) return 0.0;
	return pf(x, y);
}

