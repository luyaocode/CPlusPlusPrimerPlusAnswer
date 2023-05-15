#include "exc_mean.h"
#include <iostream>

using namespace std;

void testExcMean()
{
	double x, y;
	while (1)
	{
		cout << "Enter two numbers: ";
		cin >> x;
		cin.get();
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		cin >> y;
		cin.get();
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		try
		{
			cout << "Harmonic mean of " << x << " and " << y << " is " <<
				hmean(x, y) << endl;
			cout << "Geametric mean of " << x << " and " << y << " is " <<
				gmean(x, y) << endl;
		}
		catch (BadHmean& bh)
		{
			cout << bh.what();
			continue;
		}
		catch (BadGmean& bg)
		{
			cout << bg.what();
			break;
		}
	}
	cout << "Bye~\n";
}
//harmonic mean of aand b
double hmean(double a, double b)
{
	if (a == -b) throw BadHmean();
	return 2 * a * b / (a + b);
}

//geometric mean of a and b
double gmean(double a, double b)
{
	if (a < 0 || b < 0) throw BadGmean();
	return sqrt(a * b);
}

void BadHmean2::print() const
{
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "__func__: " << what() << endl;
}

void testExcMean2()
{
	double x, y;
	while (1)
	{
		cout << "Enter two numbers: ";
		cin >> x;
		cin.get();
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		cin >> y;
		cin.get();
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		try
		{
			cout << "Harmonic mean of " << x << " and " << y << " is " <<
				hmean2(x, y) << endl;
			cout << "Geametric mean of " << x << " and " << y << " is " <<
				gmean2(x, y) << endl;
		}
		catch (const logic_error& e)
		{
			const BadHmean2* bh = dynamic_cast<const BadHmean2*>(&e);
			const BadGmean2* gh = dynamic_cast<const BadGmean2*>(&e);
			if (bh)
			{
				bh->print();
				break;
			}
			if (gh)
			{
				gh->print();
				break;
			}
		}
	}
	cout << "Bye~\n";
}
//harmonic mean of aand b
double hmean2(double a, double b)
{
	if (a == -b) throw BadHmean2(a, b, __func__);
	return 2 * a * b / (a + b);
}

//geometric mean of a and b
double gmean2(double a, double b)
{
	if (a < 0 || b < 0) throw BadGmean2(a, b, __func__);
	return sqrt(a * b);
}

void BadGmean2::print() const
{
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "__func__: " << what() << endl;
}
