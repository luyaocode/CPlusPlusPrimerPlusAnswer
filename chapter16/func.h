#ifndef CHAPTER16_H__
#define CHAPTER16_H__
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isPalindrome(const string& s);
void palindrome();

void palindrome2();

void readTxt();

//delete same number and sort the arr
int reduce(long arr[], int n);

//template function version
template<typename T>
int reduce2(T arr[], int n);


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
void testATM();
bool newCustomer(double x);

vector<int> lotto(int size, int n);

void ourMutualFriends();

void testSortTime();

struct Review
{
	string title;
	int rating;
	double price;
	Review(const string& t, int r, double p) :title(t), rating(r), price(p) {}
	void show() const
	{
		cout << title << ", " << rating << ", " << price << "\n";
	}
};
void showReview();




#endif


