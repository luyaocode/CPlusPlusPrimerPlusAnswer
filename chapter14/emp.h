#ifndef EMPLOYEE_H__
#define EMPLOYEE_H__
#include <string>
#include <iostream>
using namespace std;
class AbstrEmp
{
private:
	string fullname;
	string lastname;
	string job;
public:
	AbstrEmp() :fullname("none"), lastname("none"), job("none") {}
	AbstrEmp(const string& fn, const string& ln, const string& j) :
		fullname(fn), lastname(ln), job(j) {}
	virtual ~AbstrEmp() = 0 {}
	virtual void showAll() const
	{
		cout << "fullname: " << fullname << "\nlastname: " << lastname << "\njob: " << job << "\n";
	}
	virtual void setAll()
	{
		fullname = "none-set";
		lastname = "none-set";
		job = "none-set";
	}
	friend ostream& operator<<(ostream& os, const AbstrEmp& e)
	{
		os << e.fullname << ", " << e.lastname << ", " << e.job << "\n";
		return os;
	}
};
class Employee :public AbstrEmp
{
public:
	Employee() {}
	Employee(const string& fn, const string& ln, const string& j) :
		AbstrEmp(fn, ln, j) {}
	virtual ~Employee() {}
	virtual void showAll() const
	{
		AbstrEmp::showAll();
	}
	virtual void setAll()
	{
		AbstrEmp::setAll();
	}
};
class Manager :virtual public AbstrEmp
{
private:
	int inchargeof;
protected:
	int inChargeOf() const { return inchargeof; }//output
	int& inChargeOf() { return inchargeof; }//input
public:
	Manager() :AbstrEmp(), inchargeof(0) {}
	Manager(const string& fn, const string& ln, const string& j, int ico) :
		AbstrEmp(fn, ln, j), inchargeof(ico) {}
	Manager(const AbstrEmp& e, int ico) :
		AbstrEmp(e), inchargeof(ico) {}
	Manager(const Manager& m) { inchargeof = m.inchargeof; }
	virtual void showAll() const
	{
		AbstrEmp::showAll();
		cout << "inchargeof: " << inchargeof << "\n";
	}
	virtual void setAll()
	{
		AbstrEmp::setAll();
		inchargeof = 0;
	}

};
class Fink :virtual public AbstrEmp
{
private:
	string reportsto;
protected:
	const string reportsTo() const { return reportsto; };
	string& reportsTo() { return reportsto; }
public:
	Fink() {}
	Fink(const string& fn, const string& ln, const string& j, const string& rep) :
		AbstrEmp(fn, ln, j), reportsto(rep) {}
	Fink(const AbstrEmp& e, const string& rep) :
		AbstrEmp(e), reportsto(rep) {}
	Fink(const Fink& e) {}
	virtual void showAll() const
	{
		AbstrEmp::showAll();
		cout << "reportsto: " << reportsto;
	}
	virtual void setAll()
	{
		AbstrEmp::setAll();
		reportsto = "none-set";
	}

};
class HighFink :public Manager, public Fink
{
public:
	HighFink() {}
	HighFink(const string& fn, const string& ln, const string& j,
		const string& rep, int ico) :
		AbstrEmp(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rep) {}
	HighFink(const AbstrEmp& e, const string& rep, int ico) :
		AbstrEmp(e), Manager(e, ico), Fink(e, rep) {}
	HighFink(const Fink& f, int ico) :Fink(f)
	{
		inChargeOf() = ico;
	}
	HighFink(const Manager& m, const string& rep):Manager(m)
	{
		reportsTo() = "rep";
	}
	HighFink(const HighFink& h) {}
	virtual void showAll() const
	{
		AbstrEmp::showAll();
		cout << "inchargeof: " << inChargeOf() << "\n";
		cout << "reportsto: " << reportsTo() << "\n";
	}
	virtual void setAll()
	{
		AbstrEmp::setAll();
		inChargeOf() = 0;
		reportsTo() = "none-set";
	}

};


void testEmployee();

#endif