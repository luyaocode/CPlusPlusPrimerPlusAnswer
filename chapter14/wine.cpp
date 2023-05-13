#include "wine.h"
#include <iostream>
#include <string>
using std::string;
void testWine()
{
	using namespace WINE;
	using std::cout;
	using std::cin;
	char label[100];
	int types;
	cout << "Enter name of wine: ";
	cin.getline(label, 100);
	while (1)
	{
		cout << "Enter number of years: ";
		cin >> types;
		if (cin.fail())
		{
			cout << "Data dismatch.\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (types > 0) break;
	}

	cin.get();
	Wine wine(label, types);
	wine.getBottles();
	wine.show();
	cout << "Bye.\n";

}
void testWine2()
{
	using namespace WINE;
	using std::cout;
	using std::cin;
	char label[100];
	int types;
	cout << "Enter name of wine: ";
	cin.getline(label, 100);
	while (1)
	{
		cout << "Enter number of years: ";
		cin >> types;
		if (cin.fail())
		{
			cout << "Data dismatch.\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (types > 0) break;
	}

	cin.get();
	Wine2 wine(label, types);
	wine.getBottles();
	wine.show();
	cout << "Bye.\n";

}


void WINE::Wine::getBottles()
{
	using std::cout;
	using std::cin;
	cout << "Enter " << label << " data for " << types << " year(s):\n";
	ArrayInt years(types);
	ArrayInt bottles(types);
	int t1;
	int t2;
	for (int i = 0; i < types; i++)
	{
		while (1)
		{
			cout << "Enter year: ";
			cin >> t1;
			if (cin.fail()|| t1 <= 0)
			{
				cout << "Data dismatch.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else 
			{
				years[i] = t1;
				break;
			}
		}
		while (1)
		{
			cout << "Enter bottles for that year(" << years[i] << "): ";
			cin >> t2;
			if (cin.fail() || t2 <= 0)
			{
				cout << "Data dismatch.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				bottles[i] = t2;
				break;
			}

		}
	}
	pair = PairArray(years, bottles);
}
const string& WINE::Wine::getLabel() const
{
	return label;
}
int WINE::Wine::sum() const
{
	return pair.bottlesArr().sum();
}

void WINE::Wine::show() const
{
	using std::cout;
	cout << "Wine: " << label << "\n";
	cout << "\t" << "Year\t" << "Bottles\n";
	for (int i = 0; i < types; i++)
	{
		cout << "\t" << pair.yearsArr()[i] << "\t" << pair.bottlesArr()[i] << "\n";
	}
	cout << "Total bottles for " << label << ": " << sum() << "\n";
}


void WINE::Wine2::getBottles()
{
	using std::cout;
	using std::cin;
	cout << "Enter " << label << " data for " << types << " year(s):\n";
	ArrayInt years(types);
	ArrayInt bottles(types);
	int t1;
	int t2;
	for (int i = 0; i < types; i++)
	{
		while (1)
		{
			cout << "Enter year: ";
			cin >> t1;
			if (cin.fail() || t1 <= 0)
			{
				cout << "Data dismatch.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				years[i] = t1;
				break;
			}
		}
		while (1)
		{
			cout << "Enter bottles for that year(" << years[i] << "): ";
			cin >> t2;
			if (cin.fail()||t2<=0)
			{
				cout << "Data dismatch.\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				bottles[i] = t2;
				break;
			}

		}
	}
	set(years, bottles);

}
void WINE::Wine2::show() const
{
	using std::cout;
	cout << "Wine: " << label << "\n";
	cout << "\t" << "Year\t" << "Bottles\n";
	for (int i = 0; i < types; i++)
	{
		cout << "\t" << yearsArr()[i] << "\t" << bottlesArr()[i] << "\n";
	}
	cout << "Total bottles for " << label << ": " << sum() << "\n";
}
