#ifndef EMPLOYEE_H__
#define EMPLOYEE_H__
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class AbstrEmp
{
private:
	string fullname;
	string lastname;
	string job;
protected:
	void setFullname(const string& fn) { fullname = fn; }
	void setLastname(const string& ln) { lastname = ln; }
	void setJob(const string& j) { job = j; }
	const string& getFullname() const { return fullname; }
	const string& getLastname() const { return lastname; }
	const string& getJob() const { return job; }
public:
	AbstrEmp() :fullname("none"), lastname("none"), job("none") {}
	explicit AbstrEmp(int type) :fullname("none"), lastname("none"), job("none") {}
	AbstrEmp(const string& fn, const string& ln, const string& j, int type = EMPLOYEE) :
		fullname(fn), lastname(ln), job(j) {}
	virtual ~AbstrEmp() = 0 {}
	virtual void showAll() const
	{
		cout << "Fullname: " << fullname << "\nLastname: " << lastname << "\nJob: " << job << "\n";
	}
	virtual void setAll() {}
	virtual void getAll(fstream& fs) {}
	friend ostream& operator<<(ostream& os, const AbstrEmp& e)
	{
		os << e.fullname << ", " << e.lastname << ", " << e.job << "\n";
		return os;
	}
	virtual void read() {}
	virtual void writeAll(fstream& fs) {}

public:
	static const string empFile;
	enum { EMPLOYEE, MANAGER, FINK, HIGHFINK };
};
class Employee :public AbstrEmp
{
private:
	int classtype;
public:
	Employee() :AbstrEmp(), classtype(EMPLOYEE) {}
	Employee(const string& fn, const string& ln, const string& j) :
		AbstrEmp(fn, ln, j), classtype(EMPLOYEE) {}
	virtual ~Employee() {}
	virtual void showAll() const
	{
		AbstrEmp::showAll();
	}
	virtual void setAll();
	virtual void getAll(fstream& fs);
	virtual void read() {}
	virtual void writeAll(fstream& fs);
};
class Manager :virtual public AbstrEmp
{
private:
	int classtype;
	int inchargeof;
protected:
	int inChargeOf() const { return inchargeof; }//output
	int& inChargeOf() { return inchargeof; }//input
public:
	Manager() :AbstrEmp(), classtype(MANAGER), inchargeof(0) {}
	Manager(const string& fn, const string& ln, const string& j, int ico) :
		AbstrEmp(fn, ln, j), classtype(MANAGER), inchargeof(ico) {}
	Manager(const AbstrEmp& e, int ico) :
		AbstrEmp(e), classtype(MANAGER), inchargeof(ico) {}
	Manager(const Manager& m) { classtype = m.classtype; inchargeof = m.inchargeof; }
	virtual void showAll() const
	{
		AbstrEmp::showAll();
		cout << "Inchargeof: " << inchargeof << "\n";
	}
	virtual void setAll();
	virtual void getAll(fstream& fs);
	virtual void writeAll(fstream& fs);

};
class Fink :virtual public AbstrEmp
{
private:
	int classtype;
	string reportsto;
protected:
	const string reportsTo() const { return reportsto; };
	string& reportsTo() { return reportsto; }
public:
	Fink() :AbstrEmp(), classtype(FINK) {}
	Fink(const string& fn, const string& ln, const string& j, const string& rep) :
		AbstrEmp(fn, ln, j), classtype(FINK), reportsto(rep) {}
	Fink(const AbstrEmp& e, const string& rep) :
		AbstrEmp(e), classtype(FINK), reportsto(rep) {}
	Fink(const Fink& e):classtype(FINK) {}
	virtual void showAll() const
	{
		AbstrEmp::showAll();
		cout << "Reportsto: " << reportsto;
	}
	virtual void setAll();
	virtual void getAll(fstream& fs);
	virtual void writeAll(fstream& fs);

};
class HighFink :public Manager, public Fink
{
private:
	int classtype;
public:
	HighFink() :AbstrEmp(), classtype(HIGHFINK) {}
	HighFink(const string& fn, const string& ln, const string& j,
		const string& rep, int ico) :
		AbstrEmp(fn, ln, j), Manager(fn, ln, j, ico),
		classtype(HIGHFINK), Fink(fn, ln, j, rep) {}
	HighFink(const AbstrEmp& e, const string& rep, int ico) :
		AbstrEmp(e), Manager(e, ico),
		classtype(HIGHFINK), Fink(e, rep) {}
	HighFink(const Fink& f, int ico) :
		Fink(f), classtype(HIGHFINK)
	{
		inChargeOf() = ico;
	}
	HighFink(const Manager& m, const string& rep) :
		Manager(m), classtype(HIGHFINK)
	{
		reportsTo() = "rep";
	}
	HighFink(const HighFink& h) :classtype(HIGHFINK) {}
	virtual void showAll() const
	{
		AbstrEmp::showAll();
		cout << "Inchargeof: " << inChargeOf() << "\n";
		cout << "Reportsto: " << reportsTo() << "\n";
	}
	virtual void setAll();
	virtual void getAll(fstream& fs);
	virtual void writeAll(fstream& fs);


};


void tinyEmployeeSystem();

#endif