#ifndef EXC_MEAN_H__
#define EXC_MEAN_H__

#include <stdexcept>
using namespace std;

class BadHmean :public logic_error
{
public:
	BadHmean() :logic_error("hmean(): Invalid arguments: a=-b\n") {}
};

class BadGmean :public logic_error
{
public:
	BadGmean() :logic_error("gmean(): Arguments should be >=0\n") {}
};

//use one catch block
void testExcMean();
double hmean(double a, double b);
double gmean(double a, double b);

class BadHmean2 :public logic_error
{
private:
	double a;
	double b;
public:
	BadHmean2(double x = 0, double y = 0, const string& in = "none") :
		a(x), b(y), logic_error(in) {}
	void print() const;
};
class BadGmean2 :public logic_error
{
private:
	double a;
	double b;
public:
	BadGmean2(double x = 0, double y = 0, const string& in = "none") :
		a(x), b(y), logic_error(in) {}
	void print() const;
};
//use two catch block
void testExcMean2();
double hmean2(double a, double b);
double gmean2(double a, double b);

#endif