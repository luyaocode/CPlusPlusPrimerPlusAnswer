#include "func.h"
#include <iostream>
using namespace std;
int main()
{
	//Q1
	//printStr("Hello, world.");
	//printStr("Miao", 99);
	//printStr("Miao", 52);

	//Q2
	//CandyBar bar;
	//const char* maker = "Teff";
	//double weight = 50.1;
	//int calorie = 10000;
	//setCandyBar(bar, maker, weight, calorie);
	//showCandyBar(bar);

	//Q3
	//toUpperCaseCycle();

	//Q4
	//stringy beany;
	//char testing[] = "Reality isn't what it used to be.";
	//set(beany, testing);
	//show(beany);
	//show(beany, 2);
	//testing[0] = 'D';
	//testing[1] = 'u';
	//show(testing);
	//show(testing, 3);
	//show("Done!");

	//Q5
	//cout << "Test template function max5:" << endl;
	//int test1[] = { 12,43,1,421,-65 };
	//double test2[] = { 1.7,54.1,-4.5,-12,12.1 };
	//cout << max5(test1) << endl;
	//cout << max5(test2) << endl;

	////Q6
	//cout << "Test template function maxn:" << endl;
	//int IntSize = 6;
	//int DblSize = 4;
	//int arr[] = { 43,765,1,5,7 };
	//double arr2[] = { 1.6,34.3,278,-1.2 };
	//auto a=maxn(arr, IntSize);
	//cout<<a<<endl;
	//auto b = maxn(arr2, DblSize);
	//cout << b<< endl;
	//cout << "Test explicit specialization." << endl;
	//int PcSize = 5;
	//const char* pc[5];
	//pc[0] = "Life is a journey, not a destination.";
	//pc[1] = "The only way to do great work is to love what you do.";
	//pc[2] = "In three words I can sum up everything I've learned about life: it goes on.";
	//pc[3] = "Believe you can and you're halfway there.";
	//pc[4] = "Be the change you wish to see in the world.";
	//auto c = maxn(pc, PcSize);
	//cout << c << endl;

	//Q7
	int things[6] = { 13,31,103,301,310,130 };
	depts depts[3] =
	{
		{"Ima Wolfe",2400.0 },
		{"Ura Foxe",1300.0},
		{"Iby Stout",1800.0}
	};
	double* pd[3];
	for (int i = 0; i < 3; i++)
	{
		pd[i] = &depts[i].amount;
	}
	int thingSum = 0;
	double deptSum = 0.0;
	thingSum=sumArray(things,6);
	deptSum=sumArray(pd, 3);
	cout << thingSum << endl;
	cout << deptSum << endl;










	return 0;
}