#include "func.h"
#include <string.h>
#include <iostream>
#include <chrono>
#include <random>

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[30];
	strcpy_s(hobby, 30, "");
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name, 20, nm);
	hobby = new char[30];
	strcpy_s(hobby, 30, ho);
	weight = wt;

}

Cow::~Cow()
{
	delete[] hobby;
}

Cow::Cow(const Cow& c)
{
	hobby = new char[30];
	strcpy_s(name, 20, c.name);
	strcpy_s(hobby, 30, c.hobby);
	weight = c.weight;
}

Cow& Cow::operator=(const Cow& c)
{
	strcpy_s(name, 20, c.name);
	strcpy_s(hobby, 30, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::showCow() const
{
	using std::cout;
	using std::endl;
	cout << name << ", " << hobby << ", " << weight << ". " << endl;
}

void testCow()
{
	Cow c1;
	Cow c2 = Cow("Ja", "Sing", 100.0);
	Cow c3 = c2;
	c1.showCow();
	c2.showCow();
	c3.showCow();
	c1 = c3;
	c1.showCow();
}

int String::num = 0;

void testString()
{
	using namespace std;
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringUp();
	cout << "The string\n" << s2 << "\ncontailns " << s2.has('A')
		<< " 'A' characters in it.\n";
	s1 = "red";
	String rgb[3] = { String(s1),String("green"),String("blue") };
	cout << "Enter the primary color of mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringLow();
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye~\n";
}




String::String()
{
	len = 1;
	str = new char[len + 1];
	str[0] = '\0';
	num++;
}

String::String(const char* c)
{
	//'\n' is not included in strlen(), but strcpy_s() will copy it
	len = strlen(c);
	str = new char[len + 1];
	strcpy_s(str, len + 1, c);
	num++;
}

String::String(const String& s)
{
	//'\n' is not included in length(), but strcpy_s() will copy it
	len = s.length();
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	num++;
}

String::~String()
{
	num--;
	delete[] str;
}

String& String::operator=(const String& s)
{

	len = s.length();
	//should delete[] original space pointer and request new space
	//or ~String() will fail
	delete[] str;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	num++;
	return *this;
}

String& String::operator=(const char* c)
{
	len = strlen(c);
	//should delete[] original space pointer and request new space
	//or ~String() will fail
	delete[] str;
	str = new char[len + 1];
	strcpy_s(str, len + 1, c);
	num++;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}
std::istream& operator>>(std::istream& is, String& s)
{
	char temp[String::CINLIM];
	// get some characters from istream to a array
	is.get(temp, String::CINLIM);
	s = temp;
	// get one character from istream and return its ASCII
	while (is && is.get() != '\n') continue;
	return is;
}

String String::operator+(const char* c) const
{
	int total = len + strlen(c);
	char* temp = new char[total + 1];
	strcpy_s(temp, len + 1, str);
	strcpy_s(temp + len, strlen(c) + 1, c);
	return String(temp);
}

String String::operator+(const String& s) const
{
	int total = len + s.len;
	char* temp = new char[total + 1];
	strcpy_s(temp, len + 1, str);
	strcpy_s(temp + len, s.len + 1, s.str);
	return String(temp);
}

bool String::operator==(const char* c) const
{
	if (len != strlen(c)) return false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != c[i]) return false;
	}
	return true;
}

bool String::operator==(const String& s) const
{
	if (len != s.len) return false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != s.str[i]) return false;
	}
	return true;
}

String& String::stringUp()
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 'a' - 'A';
		}
	}
	return *this;
}

String& String::stringLow()
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 'a' - 'A';
		}
	}
	return *this;
}

int String::has(const char c) const
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c) count++;
	}
	return count;
}

String operator+(const char* c, const String& s)
{
	int total = strlen(c) + s.len;
	char* temp = new char[total + 1];
	strcpy_s(temp, strlen(c) + 1, c);
	strcpy_s(temp + strlen(c), s.len + 1, s.str);
	return String(temp);
}

bool operator==(const char* c, const String& s)
{

	return s == c;
}

void testStock()
{
	using namespace std;
	const int STKS = 4;
	Stock stocks[STKS] = {
		Stock("NanoSmart",12,20.0),
		Stock("Boffo Objects",200,2.0),
		Stock("Monolithic Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5)
	};
	cout << "Stock holdings:\n";
	for (int i = 0; i < STKS; i++)
	{
		cout << stocks[i];
	}
	const Stock* top = &stocks[0];
	for (int i = 0; i < STKS; i++)
	{
		top = &top->topval(stocks[i]);
	}
	cout << "\nMost valuable holding: \n";
	cout << *top;
}


Stock::Stock()
{
	company = new char[1];
	company[0] = '\0';
	shares = 0;
	share_val = 0.0;
	setTotal();

}

Stock::Stock(const char* pc, long n, double val)
{
	company = new char[strlen(pc) + 1];
	strcpy_s(company, strlen(pc) + 1, pc);
	shares = n;
	share_val = val;
	setTotal();

}

Stock::~Stock()
{
	delete[] company;
}


Stock::Stock(const Stock& s)
{
	company = new char[strlen(s.company) + 1];
	strcpy_s(company, strlen(s.company) + 1, s.company);
	shares = s.shares;
	share_val = s.share_val;
	setTotal();
}

void Stock::buy(long n, double val)
{
	using std::cout;
	if (n < 0) return;
	shares += n;
	share_val = val;
	setTotal();
}

const Stock& Stock::topval(const Stock& s) const
{
	if (total_val >= s.total_val) return *this;
	else return s;
}

void Stock::sell(long n, double val)
{
	if (n < 0) return;
	if (n > shares) return;
	shares -= n;
	share_val = val;
	setTotal();
}

void Stock::update(double val)
{
	share_val = val;
	setTotal();
}

Stock& Stock::operator=(const Stock& s)
{
	strcpy_s(company, strlen(s.company) + 1, s.company);
	shares = s.shares;
	share_val = s.share_val;
	setTotal();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Stock& s)
{
	os << s.company << ", " << s.shares << ", " << s.share_val << ", " << s.total_val << std::endl;;
	return os;
}




void testStack()
{
	using std::cout;
	using std::endl;
	Stack s1, s4;
	Stack s2(7);
	Stack s3 = s2;
	s4 = s2;
	Item temp;
	cout << "s1: " << s1;
	cout << "s2: " << s2;
	cout << "s3: " << s3;
	cout << "s4: " << s4;
	for (int i = 0; i < 20; i++)
	{
		if (s2.push(i)) continue;
		else break;
	}
	cout << "s1: " << s1;
	cout << "s2: " << s2;
	cout << "s3: " << s3;
	cout << "s4: " << s4;
	for (int i = 0; i < 4; i++)
	{
		s2.pop(temp);
		cout << "temp: " << temp << endl;
	}
	cout << "s1: " << s1;
	cout << "s2: " << s2;
	cout << "s3: " << s3;
	cout << "s4: " << s4;
	for (int i = 0; i < 100; i++)
	{
		if (s2.pop(temp))
			cout << "temp: " << temp << endl;
		else break;
	}
	cout << "s1: " << s1;
	cout << "s2: " << s2;
	cout << "s3: " << s3;
	cout << "s4: " << s4;


}

Stack::Stack(int n)
{
	if (n <= 0) {
		size = 1;
		std::cout << "n can't be negative.\n";
	}
	else size = n;
	items = new Item[size];
	for (int i = 0; i < size; i++)
	{
		items[i] = 0;
	}
	top = -1;
}

Stack::Stack(const Stack& s)
{
	size = s.size;
	items = new Item[size];
	for (int i = 0; i < size; i++)
	{
		items[i] = s.items[i];
	}
	top = s.top;
}

Stack::~Stack()
{
	delete[] items;
}

bool Stack::isEmpty() const
{
	return top == -1;
}
bool Stack::isFull() const
{
	return top == size - 1;
}

bool Stack::push(const Item& item)
{
	if (isFull()) return false;
	items[++top] = item;
	return true;
}

bool Stack::pop(Item& item)
{
	if (isEmpty()) return false;
	item = items[top--];
	return true;
}

Stack& Stack::operator=(const Stack& s)
{
	size = s.size;
	items = new Item[size];
	for (int i = 0; i < size; i++)
	{
		items[i] = s.items[i];
	}
	top = s.top;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Stack& s)
{
	os << "(";
	for (int i = 0; i < s.top; i++)
	{
		os << s.items[i] << ", ";
	}
	os << s.items[s.top] << ")" << "size = " << s.size << ", top = " << s.top << "\n";
	return os;
}

void testQueue()
{
	Queue q1;
	Queue q2(7);
	q1.print();
	q2.print();
	Customer c1;
	Customer c2(10, 50);
	Customer temp;
	for (int i = 0; i < 20; i++)
	{
		if (q1.enqueue(c2)) continue;
		else break;
	}
	q1.print();
	for (int i = 0; i < 3; i++)
	{
		if (q1.dequeue(temp)) continue;
		else break;
	}
	q1.print();
	for (int i = 0; i < 20; i++)
	{
		if (q1.dequeue(temp)) continue;
		else break;
	}
	q1.print();

}
void testATM()
{
	int time = 0;
	Queue q(10);
	double totalWaitTime = 0.0;
	int alarm = 0;
	Customer* temp = new Customer[6000];
	int cus = 0;
	while (time++ < 60 * 500)
	{
		if (alarm == 0)
		{
			q.dequeue(temp[cus++]);
			if (!q.isEmpty()) alarm = q.head()->ptime();
			else alarm = 0;
		}
		if (newCustomer(5))
		{
			Customer c;
			c.set(time);
			if (!q.isFull())
			{
				if (q.isEmpty()) alarm = c.ptime();
				q.enqueue(c);
				totalWaitTime += c.ptime();
			}
		}
		alarm--;
		std::cout << time << " :\n";
		q.print();
		std::cout << "\n";
	}
	std::cout << "total customers: " << cus << "\n";
	std::cout << "total wait time: " << totalWaitTime << "\n";
	std::cout << "averange wait time: " << totalWaitTime / cus << "\n";

	delete[] temp;

}

// means one customer will come in every x minutes
bool newCustomer(double x)
{
	//set rand seed
	srand(time(NULL));
	std::cout << (rand() * x / RAND_MAX) << "\n";
	return (rand() * x / RAND_MAX < 1);
}

void testATM2()
{
	int time = 0;
	Queue q1(10);
	Queue q2(10);
	double totalWaitTime = 0.0;
	int alarm1 = 0;
	int alarm2 = 0;
	Customer* temp = new Customer[INT16_MAX];
	int cus = 0;
	while (time++ < 60 * 500)
	{
		if (alarm1 == 0)
		{
			q1.dequeue(temp[cus++]);
			if (!q1.isEmpty()) alarm1 = q1.head()->ptime();
			else alarm1 = 0;
		}
		if (alarm2 == 0)
		{
			q2.dequeue(temp[cus++]);
			if (!q2.isEmpty()) alarm2 = q2.head()->ptime();
			else alarm2 = 0;
		}
		if (newCustomer(10))
		{
			Customer c;
			c.set(time);
			if (!q2.isFull() && q2.count() <= q1.count())
			{
				if (q2.isEmpty()) alarm2 = c.ptime();
				q2.enqueue(c);
				totalWaitTime += c.ptime();
			}
			else if (!q1.isFull())
			{
				if (q1.isEmpty()) alarm1 = c.ptime();
				q1.enqueue(c);
				totalWaitTime += c.ptime();
			}
		}
		alarm1--;
		alarm2--;
		std::cout << time << " :\n";
		std::cout << "q1: \n";
		q1.print();
		std::cout << "q2: \n";
		q2.print();
		std::cout << "\n";
	}
	std::cout << "total customers: " << cus << "\n";
	std::cout << "total wait time: " << totalWaitTime << "\n";
	std::cout << "averange wait time: " << totalWaitTime / cus << "\n";

	delete[] temp;

}

Class* Queue::head() const
{
	if (isEmpty()) return nullptr;
	else return &front->next->item;
}

Queue::Queue(int qs) :qsize(qs)
{
	if (qsize < 0)
	{
		items = 0;
		front = nullptr;
		rear = nullptr;
	}
	front = new Node;
	front->next = nullptr;
	rear = front;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::enqueue(const Class& item)
{
	if (isFull()) return false;
	rear->next = new Node;
	rear = rear->next;
	rear->item = item;//
	rear->next = nullptr;
	items++;
	return true;
}

bool Queue::dequeue(Class& item)
{
	if (isEmpty()) return false;
	item = front->next->item;//
	front->next = front->next->next;
	items--;
	if (items == 0) rear = front;// 
	return true;
}
void Queue::print() const
{
	Node* temp = front->next;
	while (temp != nullptr)
	{
		std::cout << temp->item << "\n";
		temp = temp->next;
	}
	std::cout << "items = " << items << ", qsize = " << qsize << "\n";
}


std::ostream& operator<<(std::ostream& os, const Customer& c)
{
	std::cout << c.arrive << ", " << c.processtime;
	return os;
}



void Customer::set(long when)
{
	arrive = when;
	srand(time(0));
	processtime = std::rand() % 3 + 1;
}

Customer::Customer(long a, int p)
{
	arrive = a;
	processtime = p;
}


Customer::Customer(const Customer& c)
{
	arrive = c.arrive;
	processtime = c.processtime;
}

Customer::~Customer()
{
}
Customer& Customer::operator=(const Customer& c)
{
	arrive = c.arrive;
	processtime = c.processtime;
	return *this;
}

