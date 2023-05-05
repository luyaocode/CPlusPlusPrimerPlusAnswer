#include "func.h"
#include <iostream>
using namespace std;
int main()
{
	//Q1
	//BankAccount acc1;
	//BankAccount acc2{ "Tommy","2220 2293 5148 3243",1000000.00 };
	//acc1.showInfo();
	//acc2.showInfo();
	//acc1.deposit(1.0);
	//acc2.withdrawal(1.0);
	//acc1.showInfo();
	//acc2.showInfo();

	//Q2
	//Person one;
	//Person two("Smythecraft");
	//Person three("Dimwiddy","Sam");
	//one.show();
	//one.formalShow();
	//cout << endl;
	//two.show();
	//two.formalShow();
	//cout << endl;
	//three.show();
	//three.formalShow();

	//Q3
	//const int MaxSize = 10;
	//int size=0;
	//Golf golf[MaxSize];
	//cout << "Enter golf info(no more than 10):" << endl;
	//for (int i = 0; i < MaxSize; i++,size++)
	//{
	//	cout << "No." << i << ": " << endl;
	//	if(golf[i].setGolf()==0) break;
	//}
	//cout << "Show info: " << endl;
	//for (int i=0;i<size;i++)
	//{
	//	golf[i].showGolf();
	//}

	//Q4
	//using namespace SALES;
	//double arr[6] = { 1.1,54.3,21.3,43,31.5,332.1 };
	//Sales s1 = Sales(arr, 6);
	//Sales s2;
	//s2.setSales();
	//s1.showSales();
	//s2.showSales();

	//Q5
	//const int MaxSize = 14;
	//double payTotal = 0.0;
	//Stack stack;
	//customer temp;
	//customer custs[MaxSize] = { {"Aalo",1},{"Iil",90.1},{"Opde",56.2} };
	//cout << (stack.isEmpty() ? "Stack is empty. " : "Init stack. ") << endl;
	//for (int i = 0; i < MaxSize; i++)
	//{
	//	if (stack.push(custs[i]))
	//		cout << "Push " << custs[i].fullname << endl;
	//	else
	//		cout << "Push failed. " << endl;
	//}
	//for (int i = 0; i < MaxSize; i++)
	//{
	//	if (stack.pop(temp))
	//	{
	//		cout << "Pop " << temp.fullname << endl;
	//		payTotal += temp.payment;
	//	}
	//	else
	//		cout << "Pop failed. " << endl;
	//}
	//cout << "Total payments: " << payTotal << endl;
	//cout << "Done." << endl;

	//Q6
	//Move m;
	//Move n{ 1000.0,5000.0 };
	//cout << "Original value:" << endl;
	//m.showMove();
	//n.showMove();
	//cout << "Add: " << endl;
	//m = m.add(n);
	//n = n.add(m);
	//m.showMove();
	//n.showMove();
	//cout << "Reset: " << endl;
	//m.reset();
	//n.reset();
	//m.showMove();
	//n.showMove();

	//Q7
	//Plorg plorg1;
	//Plorg plorg2 = Plorg("Ood Doc");
	//Plorg plorg3 = Plorg("Geki Poxy", 999);
	//plorg1.show();
	//plorg2.show();
	//plorg3.show();

	//Q8
	List list;
	cout << list.isEmpty() ? "list is empty." : "";
	Item items[32] = { 121,13,65,44,23,243,657,6,34,234,23,12,54,6 };
	for (int i = 0; i < 32; i++)
	{
		if(items[i]!=0)
			list.add(items[i]);
	}
	list.visit(show);

}