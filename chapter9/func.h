#ifndef CHAPTER9_H__
#define CHAPTER9_H__
#include <string>
const int Len = 40;
struct golf
{
	char fullname[Len];
	int handicap;
};
void setGolf(golf& g, const char* name, int hc);
int setGolf(golf& g);
void handicap(golf& g, int hc);
void showGolf(const golf& g);

struct chaff
{
	char dross[20];
	int slag;
};

namespace SALES
{
	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS];
		double averange;
		double max;
		double min;
	};
	void setSales(Sales& s, const double arr[], int n);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}


#endif