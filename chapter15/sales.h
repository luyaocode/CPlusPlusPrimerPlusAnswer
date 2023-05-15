#ifndef SALES_H__
#define SALES_H__
#include <stdexcept>
#include <string>
using namespace std;
class Sales
{
protected:
	enum { MONTHS = 12 };
private:
	int year;
	double gross[MONTHS];
public:
	class Badindex :public logic_error
	{
	private:
		int bi;
	public:
		explicit Badindex(int ix, const string& s = "Index error in Sales object\n") :
			bi(ix), logic_error(s) {}
		int bival() const { return bi; }
		virtual ~Badindex() {}
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() {}
	int showYear() const { return year; }
	virtual double operator[](int i) const;
	virtual double& operator[](int i);


};
class LabeledSales :public Sales
{
private:
	string label;
public:
	class NBadIndex :public Sales::Badindex
	{
	private:
		string lbl;
	public:
		NBadIndex(const string& lb, int ix, const string& s =
			"Index error in LabeledSales object\n") :
			lbl(lb), Badindex(ix, s) {}
		const string& labelval() const { return lbl; }
		virtual ~NBadIndex() {}
	};
	explicit LabeledSales(const string& lb = "none", int yy = 0) :
		Sales(yy), label(lb) {}
	LabeledSales(const string& lb, int yy, const double* gr, int n) :
		label(lb), Sales(yy, gr, n) {}
	virtual ~LabeledSales() {}
	const string& returnLabel() const { return label; }
	virtual double operator[](int i) const;
	virtual double& operator[](int i);
};

void testSales();


#endif
