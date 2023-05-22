#include "functor.h"
#include <list>
#include <algorithm>
#include <iostream>
void testLamada()
{
	using namespace std;

	Toobig<int> f100(100);
	int vals[10]{ 1,400,4635,43,2,100,4435,145,30,120 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);
	auto print = [](int x) {cout << x << " "; };
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), print);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), print);
	cout << endl;
	yadayada.remove_if([](int x) {return x > 100; });
	etcetera.remove_if([](int x) {return x > 200; });

	cout << "after:\n";
	for_each(yadayada.begin(), yadayada.end(), print);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), print);
	cout << endl;

}
