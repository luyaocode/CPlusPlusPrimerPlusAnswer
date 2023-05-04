#include "func.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//Q1
	//const int MaxSize = 10;
	//int size=0;
	//golf golf[MaxSize];
	//char name[Len];
	//int hc;
	//cout << "Enter golf info(no more than 10):" << endl;
	//for (int i = 0; i < MaxSize; i++,size++)
	//{
	//	cout << "No." << i << ": " << endl;
	//	cout << "Enter fullname: ";
	//	cin.getline(name, Len);
	//	if (name[0] == '\0')
	//	{
	//		cout << "Name is blank. " << endl;
	//		break;
	//	}
	//	cout << "Enter handicap: ";
	//	cin >> hc;
	//	cin.get();
	//	if (cin.fail())
	//	{
	//		cout << "Data dismatch. " << endl;
	//		break;
	//	}
	//	setGolf(golf[i], name, hc);
	//}
	//cout << "Show info: " << endl;
	//for (int i=0;i<size;i++)
	//{
	//	if (golf[i].fullname[0] == '\0') break;
	//	showGolf(golf[i]);
	//}

	//Q2
	//string input;
	//while (1)
	//{
	//	cout << "Enter a line: " << endl;
	//	getline(cin, input);
	//	cout << input.size()<<endl;
	//	if (input == "") break;
	//}
	//cout << "Bye." << endl;

	//Q3
	//chaff c1[2]{};
	//chaff* c2 = new chaff[2];
	//strcpy_s(c1[0].dross,"H");
	//c1[0].slag = 10;
	//strcpy_s(c1[1].dross, "D");
	//c1[1].slag = 342;
	//cout << c1[0].dross << ", " << c1[0].slag<<endl;
	//cout << c1[1].dross << ", " << c1[1].slag<<endl;
	//strcpy_s(c2[0].dross, "s");
	//c2[0].slag = 102;
	//strcpy_s(c2[1].dross, "d");
	//c2[1].slag = 232;
	//cout << c2[0].dross << ", " << c2[0].slag << endl;
	//cout << c2[1].dross << ", " << c2[1].slag << endl;

	//Q4
	using namespace SALES;
	Sales s1{}, s2{};
	double arr[6] = { 1.1,54.3,21.3,43,31.5,332.1 };
	setSales(s1, arr, 6);
	setSales(s2);
	showSales(s1);
	showSales(s2);



	








	return 0;
}
