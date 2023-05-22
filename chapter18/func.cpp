#include "func.h"
#include "vector"
#include <algorithm>
using namespace std;

template<typename T>
T averange_list(vector<T> v)
{
	T total = 0;
	for_each(v.begin(), v.end(),
		[&total](T i) {total += i; });
	return total / v.size();
}

template<>
double averange_list(vector<double> v)
{
	double total = 0;
	for_each(v.begin(), v.end(),
		[&total](double i) {total += i; });
	return total / v.size();
}

void testAverangeList()
{
	vector<double> v1 = { 12.1, 324.3, 54.23, 323.3, 34.0, 534.2 };
	vector<int> v2 = { 132,43,435,4,4565,65,76657 };
	vector<double> v3 = { 'a', 'f', 54.23, 323.3, 34.0, 534.2 };
	auto q1 = averange_list(v1);
	auto q2 = averange_list(v2);
	auto q3 = averange_list(v3);
	cout << q1 << "\n";
	cout << q2 << "\n";
	cout << q3 << "\n";
}

void testCpmv()
{
	cout << "==1==\n";
	Cpmv c1;
	cout << "==2==\n";
	Cpmv c2("h", "e");
	cout << "==3==\n";
	Cpmv b1 = c1;
	cout << "==3==\n";
	Cpmv b2(c1);
	cout << "==4==\n";
	c1 = c2;
	cout << "==5==\n";
	Cpmv d2;
	d2 = c1 + c2;
	cout << "==6==\n";
	Cpmv e(c1 + c2);
}

