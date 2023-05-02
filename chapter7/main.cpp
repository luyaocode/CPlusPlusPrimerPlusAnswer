#include <iostream>
#include "func.h"
#include <string>
using namespace std;
int main()
{
	//Q1
	//const int maxSize = 100;
	//double* res = harmonicMean(maxSize);
	//double* p = res;
	//for (int i = 0; i < maxSize; i++, p++)
	//{
	//	if (*p == 0) break;
	//	cout << *p << endl;
	//}
	//delete[] res;
	//return 0;

	//Q2
	//const int maxSize = 10;
	//float* scores=new float[maxSize];
	//float aver;
	//inputGolfScores(scores,maxSize);
	//showGolfSocres(scores,maxSize);
	//aver = calAverGolfScore(scores,maxSize);
	//cout << "Aver: " << aver << endl;
	//delete[] scores;

	//Q3
	//box box = { "Robin Hipman",1.0f,2.0f,3.0f,NAN };
	//showBoxMembers(box);
	//setBoxVolume(&box);
	//showBoxMembers(box);

	//Q4
	//int numbers, picks;
	//double res = 1.0;
	//const int times = 2;
	//for (int i = 0; i < times; i++)
	//{
	//	cout << "Round " << i+1 << " :Enter the number of total cards and the number of picks : " << endl;
	//	cin >> numbers >> picks;
	//	if (cin.fail()) {
	//		cout << "Data dismatch." << endl;
	//		break;
	//	}
	//	if (numbers < picks)
	//	{
	//		cout << "Data is meaningless." << endl;
	//		break;
	//	}
	//	res = res * probability(numbers, picks);
	//}
	//cout << "Winning probability: " << "1/" << res << endl;

	//Q5
	//int n;
	//long double res;
	//while (1) {
	//	cout << "Enter a number:" << endl;
	//	cin >> n;
	//	if (cin.fail() || n < 0)
	//	{
	//		cout << "Data dismatch." << endl;
	//		return -1;
	//	}
	//	res = calFactorial(n);
	//	cout << n << "! = " << res << endl;
	//}

	//Q6
	//const int MaxSize = 10;
	//double arr[MaxSize];
	//cout << "Valid data in array:" << fillArray(arr, MaxSize) << endl;
	//showArray(arr,MaxSize);
	//reverseArray(arr,MaxSize);
	//showArray(arr,MaxSize);

	//Q7
	//const int MaxSize = 5;
	//double* arr = new double[MaxSize];
	//double* end;
	//end = fill_array(arr, MaxSize);
	//show_array(arr, end);
	//revalue_array(10, arr, end);
	//show_array(arr, end);
	//delete[] arr;

	//Q8a
	//const static int Seasons = 4;
	//const char* snames[Seasons] = { "Spring","Summer","Fall","Winter" };
	//double expenses[Seasons];
	//fillExpenses(snames, expenses);
	//showExpenses(snames, expenses);

	//Q8b
	//const static int Seasons = 4;
	//const char* snames[Seasons] = { "Spring","Summer","Fall","Winter" };
	//exp_st exp;
	//fillExpenses2(snames, exp);
	//showExpenses2(snames, exp);

	//Q9
	//int classSize;
	//while (1)
	//{
	//	cout << "Enter class size(<=10): " << endl;
	//	cin >> classSize;
	//	if (cin.fail() || classSize <= 0)
	//	{
	//		cout << "Data dismatch." << endl;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//student* stu = new student[classSize];
	//initStudents(stu, classSize);
	//int entered = getinfo(stu, classSize);
	//cout << "Valid data: " << entered << endl;
	//for (int i = 0; i < entered; i++)
	//{
	//	display1(stu[i]);
	//	display2(&stu[i]);
	//}
	//display3(stu, entered);
	//delete[] stu;
	//cout << "Done." << endl;

	//Q10
	double nums[2];
	double res;
	double (*pf[3])(double, double);
	pf[0] = powTwoNumbers;
	pf[1] = addTwoNumbers;
	pf[2] = multiplyTwoNumbers;
	int x, y;
	while (1)
	{
		res = 0;
		cout << "Enter two numbers:" << endl;
		for (int i = 0; i < 2; i++)
		{
			cin >> nums[i];
			if (cin.fail())
			{
				cout << "Data dismatch." << endl;
				break;
			}
		}
		x = nums[0];
		y = nums[1];
		cout << "RES:" << endl;
		cout << res << endl;
		for (int i = 0; i < 3; i++)
		{
			res += calculateTwoNumbers(x, y, pf[i]);
			cout << res << endl;
		}
	}


















	return 0;

}