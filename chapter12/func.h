#ifndef CHAPTER12_H__
#define CHAPTER12_H__
#include<iostream>
class Cow
{
private:
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	~Cow();
	Cow(const Cow& c);
	Cow& operator=(const Cow& c);
	void showCow() const;

};
void testCow();

class String
{
private:
	char* str;
	int len;
	static int num;//number of string objects
public:
	static const int CINLIM = 80;//cin input limit
	String();
	String(const char* c);
	String(const String& s); //parameter must be const
	~String();
	int length() const { return len; }
	String& operator=(const char* c);
	String& operator=(const String& s);
	String operator+(const char* c) const;
	String operator+(const String& s) const;
	bool operator==(const char* c) const;
	bool operator==(const String& s) const;
	friend String operator+(const char* c, const String& s);
	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
	friend bool operator==(const char* c, const String& s);

	String& stringUp();
	String& stringLow();
	int has(const char ch) const;

};
void testString();

class Stock
{
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void setTotal() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const char* pc, long n = 0, double val = 0.0);
	~Stock();
	Stock(const Stock& s);
	void buy(long n, double val);
	void sell(long n, double val);
	void update(double val);
	const Stock& topval(const Stock& s) const;
	Stock& operator=(const Stock& s);
	friend std::ostream& operator<<(std::ostream& os, const Stock& s);
};
void testStock();


typedef unsigned long Item;
class Stack
{
private:
	enum { MAX = 10 };
	Item* items;
	int size;
	int top;
public:
	Stack(int n = MAX);
	Stack(const Stack& s);
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& s);
	friend std::ostream& operator<<(std::ostream& os, const Stack& s);

};
void testStack();

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; };
	Customer(long a, int p);
	Customer(const Customer& c);
	~Customer();
	void set(long when);//set random time
	long when() const { return arrive; }
	int ptime() const { return processtime; }
	Customer& operator=(const Customer& c);
	friend std::ostream& operator<<(std::ostream& os, const Customer& c);

};
typedef Customer Class;

class Queue
{
private:
	struct Node
	{
		Class item;
		struct Node* next;
		Node() :item(), next(nullptr) {}
	};
	enum { QSIZE = 10 };
	Node* front;
	Node* rear;
	int items;//current number of items
	const int qsize; //maxinum number of items
	Queue(const Queue& q) :qsize(0), items(0), front(nullptr), rear(nullptr) {}
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = QSIZE);
	~Queue();
	bool isEmpty() const { return items == 0; }
	bool isFull() const { return items == qsize; }
	int count() const { return items; }
	bool enqueue(const Class& item);
	bool dequeue(Class& item);
	Class* head() const;
	void print() const;
};
void testQueue();
void testATM();
bool newCustomer(double x);
void testATM2();










#endif