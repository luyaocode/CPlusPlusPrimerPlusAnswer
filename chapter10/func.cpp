#include "func.h"
#include <iostream>
#include <string>
using namespace std;

BankAccount::BankAccount()
{
	name_ = "";
	account_ = "";
	balance_ = 0.0;
}
BankAccount::BankAccount(const string& name, const string& account, double balance)
{
	name_ = name;
	account_ = account;
	balance_ = balance;
}

void BankAccount::showInfo() const
{
	cout << name_ << endl;
	cout << account_ << endl;
	cout << balance_ << endl;
}

void BankAccount::deposit(double amount)
{
	balance_ += amount;
}

void BankAccount::withdrawal(double amount)
{
	balance_ -= amount;
}

Person::Person(const string& ln, const char* fn)
{
	lname = ln;
	strcpy_s(fname, LIMIT, fn);

}

void Person::show() const
{
	cout << fname << " " << lname << endl;
}

void Person::formalShow() const
{
	cout << lname << " " << fname << endl;
}

Golf::Golf(const char* fn, int hc)
{
	strcpy_s(fullname, LEN, fn);
	handicap = hc;
}

int Golf::setGolf()
{
	char fullname[LEN];
	int handicap;
	cout << "Enter fullname: " << endl;
	cin >> fullname;
	cout << "Enter handicap: " << endl;
	cin >> handicap;
	if (cin.fail())
	{
		cout << "Data dismatch." << endl;
		return 0;
	}
	*this = Golf(fullname, handicap);
	return 1;
}

void Golf::setHandicap(int hc)
{
	this->handicap = hc;
}

void Golf::showGolf() const
{
	cout << this->fullname << ", " << this->handicap << endl;
}

SALES::Sales::Sales()
{
	for (int i = 0; i < QUARTERS; i++)
	{
		sales[i] = 0.0;
	}
	averange = 0.0;
	max = 0.0;
	min = 0.0;
}

SALES::Sales::Sales(double arr[], int n)
{
	using std::max;
	using std::min;
	double total = 0.0;
	double max_val = arr[0];
	double min_val = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (i < QUARTERS)
		{
			this->sales[i] = arr[i];
		}
		total += arr[i];
		max_val = max(max_val, arr[i]);
		min_val = min(min_val, arr[i]);
	}
	this->averange = total / n;
	this->max = max_val;
	this->min = min_val;

}


void SALES::Sales::setSales()
{
	double arr[100]{};
	int n = 0;
	cout << "Enter items of arr(less than 100) : " << endl;
	for (int i = 0; i < 100; i++)
	{
		cin >> arr[i];
		if (cin.fail())
		{
			cout << "Data dismatch." << endl;
			break;
		}
		n++;
	}
	*this = Sales(arr, n);
}

void SALES::Sales::showSales() const
{
	for (int i = 0; i < QUARTERS; i++)
	{
		cout << sales[i] << ", ";
	}
	cout << max << ", " << min << ", " << averange << endl;
}

Stack::Stack()
{
	top = -1;
}

bool Stack::isEmpty() const
{
	return top == -1;
}

bool Stack::isFull() const
{
	return top == MAX - 1;
}

bool Stack::push(const customer& cs)
{
	if (isFull())
	{
		return false;
	}
	else
	{

		customers[++top] = cs;
		return true;
	}
}

bool Stack::pop(customer& cs)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		cs = customers[top--];
		return true;

	}
}

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showMove() const
{
	cout << x << ", " << y << endl;
}

Move Move::add(const Move& m) const
{
	return Move(m.x + x, m.y + y);
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}



Plorg::Plorg(const char* n, int cival)
{
	strcpy_s(name, LEN, n);
	ci = cival;
}

void Plorg::show() const
{
	cout << name << endl;
	cout << ci << endl;
}

List::List()
{
	count = 0;
}

bool List::isEmpty() const
{
	return count == 0;
}

bool List::isFull() const
{
	return count == LEN;
}

bool List::add(Item& item)
{
	if (isFull())
		return false;
	else
	{
		items[count++] = item;
		return true;
	}
}

void List::visit(void(*pf)(Item& item))
{
	for (int i = 0; i < count; i++)
	{
		pf(items[i]);
		cout << ", ";
	}
	cout << endl;
}

void show(Item& item)
{
	cout << item;
}
