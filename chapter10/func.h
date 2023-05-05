#ifndef CHAPTER10_H__
#define CHAPTER10_H__
#include <string>
using namespace std;

class BankAccount
{
private:
	string name_;
	string account_;
	double balance_;
public:
	BankAccount();
	~BankAccount() {};
	BankAccount(const string& name, const string& account, double balance = 0.0);
	void showInfo() const;
	void deposit(double amount);
	void withdrawal(double amount);
};

class Person
{
private:
	static const int LIMIT = 25;
	string lname;//lastname
	char fname[LIMIT];//firstname
public:
	Person() { lname = ""; fname[0] = '\0'; };
	Person(const string& ln, const char* fn = "Heyyou");
	void show() const;//firstname lastname format
	void formalShow() const;//lastname firstname format
};

class Golf
{
private:
	static const int LEN = 40;
	char fullname[LEN];
	int handicap;
public:
	Golf() { fullname[0] = '\n'; handicap = 0; };
	Golf(const char* fn, int hc);
	int setGolf();
	void setHandicap(int hc);
	void showGolf() const;
};

namespace SALES
{
	class Sales
	{
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double averange;
		double max;
		double min;
	public:
		Sales();
		Sales(double arr[], int n);
		void setSales();
		void showSales() const;
	};
}

struct customer
{
	char fullname[35];
	double payment;
};
class Stack
{
private:
	enum { MAX = 3 };
	customer customers[MAX];
	int top;
public:
	Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const customer& cs);
	bool pop(customer& cs);

};

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showMove() const;//show current x, y value
	//add m.x to x of invoking object to get a new x
	//add m.y to y of invoking object to get a new y
	//create a new Move object initized to new x, y values and return it
	Move add(const Move& m) const;
	void reset(double a = 0, double b = 0);
};

class Plorg
{
private:
	static const int LEN = 19;
	char name[LEN];
	int ci;
public:
	Plorg(const char* n = "Plorga", int cival = 50);
	void show() const;
};

typedef int Item;
void show(Item& item);
class List
{
private:
	static const int LEN = INT16_MAX;
	Item* items = new Item[LEN];
	int count;
public:
	List();
	bool isEmpty() const;
	bool isFull() const;
	bool add(Item& item);
	void visit(void (*pf)(Item& item));

};

#endif
