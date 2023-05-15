#include "sales.h"
#include <iostream>
using namespace std;
Sales::Sales(int yy) :
	year(yy)
{
	for (int i = 0; i < MONTHS; i++)
	{
		gross[i] = 0.0;
	}
}
Sales::Sales(int yy, const double* gr, int n) :
	year(yy)
{
	n = (n < MONTHS ? n : MONTHS);
	for (int i = 0; i < n; i++)
	{
		gross[i] = gr[i];
	}
}

double Sales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS) throw Badindex(i);
	return gross[i];
}

double& Sales::operator[](int i)
{
	if (i < 0 || i >= MONTHS) throw Badindex(i);
	return gross[i];
}

double LabeledSales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS) throw NBadIndex(returnLabel(), i);
	return Sales::operator[](i);
}

double& LabeledSales::operator[](int i)
{
	if (i < 0 || i >= MONTHS) throw NBadIndex(returnLabel(), i);
	return Sales::operator[](i);
}

void testSales()
{

	double vals1[12] =
	{
		1202,1220,1302,1320,1321,1389,
		1902,1820,1849,1378,1645,173
	};
	double vals2[12] =
	{
		12,42,15,36,86,57,
		32,54,47,48,32,21
	};
	Sales sales1(2021, vals1, 12);
	LabeledSales sales2("Blogstar", 2022, vals2, 12);
	cout << "First try block: \n";
	try
	{
		cout << "Tear: " << sales1.showYear() << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << sales1[i] << " ";
			if (i % 6 == 5)
			{
				cout << endl;
			}
		}
		cout << "Year: " << sales2.showYear() << endl;
		cout << "Label = " << sales2.returnLabel() << endl;
		for (int i = 0; i <= 12; i++)//out of bound
		{
			cout << sales2[i] << " ";
			if (i % 6 == 5)
			{
				cout << endl;
			}
		}
		cout << "End of try block 1\n";
	}
	catch (const Sales::Badindex& e)
	{
		const LabeledSales::NBadIndex* ex = dynamic_cast<const LabeledSales::NBadIndex*>(&e);
		if (ex)
		{
			cout << ex->what();
			cout << "Company: " << ex->labelval() << endl;
			cout << "Bad index: " << ex->bival() << endl;
		}
		else
		{
			cout << e.what();
			cout << "Bad index: " << e.bival() << endl;
		}
	}
	cout << "Next try block:\n";
	try
	{
		sales1[20];//out of bound
	}
	catch (const Sales::Badindex& e)
	{
		const LabeledSales::NBadIndex* ex = dynamic_cast<const LabeledSales::NBadIndex*>(&e);
		if (ex)
		{
			cout << ex->what();
			cout << "Company: " << ex->labelval() << endl;
			cout << "Bad index: " << ex->bival() << endl;
		}
		else
		{
			cout << e.what();
			cout << "Bad index: " << e.bival() << endl;
		}
	}
	cout << "Done.\n";
}
