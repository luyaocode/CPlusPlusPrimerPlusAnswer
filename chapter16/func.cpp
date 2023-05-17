#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <list>
#include <chrono>
using namespace std;

void palindrome()
{
	string s;
	bool valid = false;
	while (1)
	{
		cout << "Enter a string object: ";
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
		{
			if (!isalpha(s[i]))
			{
				cout << "Invilid input.\n";
				valid = false;
				break;
			}
			valid = true;
		}
		if (valid)
		{
			if (isPalindrome(s)) cout << "Yes.\n";
			else cout << "No.\n";
		}

	}

}
void palindrome2()
{
	string s;
	string res;
	while (1)
	{
		res = "";
		cout << "Enter a string object: ";
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
		{
			if (isalpha(s[i]))
			{
				res += tolower(s[i]);
			}
		}
		cout << "Remove and all toLowerCase: " << res << "\n";
		cout << (isPalindrome(res) ? "Yes.\n" : "No.\n");
	}

}

void readTxt()
{
	fstream fs;
	string path = "Tranquil Stroll-Discovering Nature's Delights.txt";
	vector<string> v;
	string temp;
	fs.open(path);
	if (!fs.is_open()) return;
	for (int i = 0; i < 1000 && !fs.eof(); i++)
	{
		fs >> temp;
		v.push_back(temp);
	}
	fs.close();
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
		if (i % 10 + 1 == 10) cout << "\n";
	}
	cout << "\n";
}


bool isPalindrome(const string& s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}


int reduce(long arr[], int n)
{
	cout << "Origin: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "\n";

	//std::sort
	sort(arr, arr + n);
	cout << "Sort: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "\n";

	//std::unique
	long* newEnd = unique(arr, arr + n);
	int newSize = distance(arr, newEnd);
	cout << "Unique: \n";
	for (int i = 0; i < newSize; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "\n";

	return 0;
}


template<>
int reduce2(long arr[], int n)
{
	cout << "Origin: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "\n";

	//std::sort
	sort(arr, arr + n);
	cout << "Sort: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "\n";

	//std::unique
	long* newEnd = unique(arr, arr + n);
	int newSize = distance(arr, newEnd);
	cout << "Unique: \n";
	for (int i = 0; i < newSize; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "\n";

	return 0;
}

template<>
int reduce2(string arr[], int n)
{

	cout << "Origin: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
	cout << "\n";

	//std::sort
	sort(arr, arr + n);
	cout << "Sort: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
	cout << "\n";

	vector<string> v(arr, arr + n);
	//std::unique
	auto newEnd = unique(v.begin(), v.end());
	v.erase(newEnd, v.end());
	cout << "Unique: \n";
	for (string s : v)
	{
		cout << s << "\n";
	}
	cout << "\n";

	return 0;

}


void testATM()
{
	int time = 0;
	queue<Customer> q;
	queue<Customer> qt;
	const int MaxSize = 10;
	double totalWaitTime = 0.0;
	int alarm = 0;
	Customer* temp = new Customer[6000];
	int cus = 0;
	while (time++ < 60 * 50)
	{
		if (alarm == 0)
		{
			if (!q.empty())
			{
				temp[cus++] = q.front();
				q.pop();
				if (!q.empty()) alarm = q.front().ptime();
			}
			else alarm = 0;
		}
		if (newCustomer(2))
		{
			Customer c;
			c.set(time);
			if (!(q.size() == MaxSize))
			{
				if (q.empty()) alarm = c.ptime();
				q.push(c);
				totalWaitTime += c.ptime();
			}
		}
		alarm--;
		std::cout << time << " :\n";
		qt = q;
		for (int i = 0; i < qt.size(); i++)
		{
			cout << q.front().when() << "\n";
			qt.pop();
		}
		std::cout << "\n";
	}
	std::cout << "total customers: " << cus << "\n";
	std::cout << "total wait time: " << totalWaitTime << "\n";
	std::cout << "averange wait time: " << (cus == 0 ? 0 : totalWaitTime / cus) << "\n";

	delete[] temp;
}

bool newCustomer(double x)
{
	//set rand seed
	srand(time(NULL));
	double temp = (rand() * x / RAND_MAX);
	std::cout << temp << "\n";
	return (temp < 1);
}

vector<int> lotto(int size, int n)
{
	vector<int> temp;
	vector<int> nums;
	for (int i = 0; i < size; i++)
	{
		nums.push_back(i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		random_shuffle(nums.begin(), nums.end());
		temp.push_back(nums[0]);
	}

	return temp;
}

void ourMutualFriends()
{
	set<string> mat;
	set<string> pat;
	set<string> mutual;
	string name;
	cout << "Enter Mat's friends(q to quit): \n";
	while (cin >> name && name != "q")
	{
		mat.insert(name);
	}
	cout << "Enter Pat's friends(q to quit): \n";
	while (cin >> name && name != "q")
	{
		pat.insert(name);
	}
	mutual = mat;
	for (string s : pat)
	{
		mutual.insert(s);
	}
	//sort(mat.begin(), mat.end());
	//sort(pat.begin(), pat.end());
	//sort(mutual.begin(), mutual.end());
	cout << "Mat's friends:\n";
	for (string s : mat)
	{
		cout << s << ", ";
	}
	cout << "\n";
	cout << "Pat's friends:\n";
	for (string s : pat)
	{
		cout << s << ", ";
	}
	cout << "\n";
	cout << "Mutual friends:\n";
	for (string s : mutual)
	{
		cout << s << ", ";
	}
	cout << "\n";
}

void testSortTime()
{
	const int MaxSize = 5000000;
	vector<int> vi0;
	vector<int> vi;
	list<int> li;
	srand(time(0));
	for (int i = 0; i < MaxSize; i++)
	{
		vi0.push_back(rand() * (rand() % 100 + 1));
	}
	vi = vi0;
	for (int i = 0; i < vi0.size(); i++)
	{
		li.push_back(vi0[i]);
	}
	cout << "vector sort\n";
	clock_t sta1 = clock();
	sort(vi.begin(), vi.end());
	clock_t end1 = clock();
	double t1 = (double)(end1 - sta1) / CLOCKS_PER_SEC * 1000;
	cout << t1 << "ms.\n";

	cout << "list sort\n";
	clock_t sta2 = clock();
	li.sort();
	clock_t end2 = clock();
	double t2 = (double)(end2 - sta2) / CLOCKS_PER_SEC * 1000;
	cout << t2 << "ms.\n";

	cout << "sort in vector and copy to list\n";
	clock_t sta3 = clock();
	vi.clear();
	for (int i : li)
	{
		vi.push_back(i);
	}
	li.clear();
	sort(vi.begin(), vi.end());
	for (int i : vi)
	{
		li.push_back(i);
	}
	clock_t end3 = clock();
	double t3 = (double)(end3 - sta3) / CLOCKS_PER_SEC * 1000;
	cout << t3 << "ms.\n";

}

//sort by ASCII
bool operator<(const shared_ptr<Review> a, const shared_ptr<Review> b)
{
	return a->title[0] < b->title[0];
}
bool compareRating(const shared_ptr<Review> a, const shared_ptr<Review> b)
{
	return a->rating < b->rating;
}
bool comparePrice(const shared_ptr<Review> a, const shared_ptr<Review> b)
{
	return a->price < b->price;
}
void showReview()
{
	vector<Review> books;
	books.push_back(Review("Aben", 4, 1.1));
	books.push_back(Review("Wolf", 5, 3.2));
	books.push_back(Review("Poel", 6, 12.1));
	books.push_back(Review("Pck", 1, 9.3));
	books.push_back(Review("abve", 9, 100));
	books.push_back(Review("7d", 10, 121.0));
	books.push_back(Review("3e", 10, 999));
	books.push_back(Review("fd", 9, 1200));

	string title;
	char mode;
	int rating;
	double price;
	cout << "Enter your books(q to quit): \n";
	while (1)
	{
		cout << "Title: ";
		getline(cin, title);
		if (title == "q") break;
		while (1)
		{
			cout << "Rating: ";
			cin >> rating;
			if (cin.fail() || rating < 0 || rating>10)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Data dismatch, try again.\n";
			}
			else
			{
				cin.get();
				break;
			}
		}
		while (1)
		{
			cout << "Price: ";
			cin >> price;
			if (cin.fail() || price < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Data dismatch, try again.\n";
			}
			else
			{
				cin.get();
				break;
			}
		}
		books.push_back(Review(title, rating, price));
		cout << "\n";
	}
	vector<shared_ptr<Review>> origin;
	shared_ptr<Review> temp;
	for (int i = 0; i < books.size(); i++)
	{
		shared_ptr<Review> sptr(&books[i]);
		origin.push_back(sptr);
	}
	vector<shared_ptr<Review>> character = origin;
	vector<shared_ptr<Review>> rating_asc = origin;
	vector<shared_ptr<Review>> rating_dec;
	vector<shared_ptr<Review>> price_asc = origin;
	vector<shared_ptr<Review>> price_dec;
	//bubble sort O(n2)
	for (int i = 0; i < character.size(); i++)
	{
		for (int j = i + 1; j < character.size(); j++)
		{
			if (!(character[i] < character[j]))
			{
				temp = character[i];
				character[i] = character[j];
				character[j] = temp;
			}
		}
	}
	sort(rating_asc.begin(), rating_asc.end(), compareRating);
	for (auto it = rating_asc.rbegin(); it != rating_asc.rend(); it++)
	{
		rating_dec.push_back(*it);
	}
	sort(price_asc.begin(), price_asc.end(), comparePrice);
	for (auto it = price_asc.rbegin(); it != price_asc.rend(); it++)
	{
		price_dec.push_back(*it);
	}
	while (1)
	{

		cout << "How to show the infos? \n";
		cout << "a. By original order.\n";
		cout << "b. By character table sequence.\n";
		cout << "c. By rating ascending order.\n";
		cout << "d. By rating decending order.\n";
		cout << "e. By price ascending order.\n";
		cout << "f. By price decending order.\n";
		cin >> mode;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (mode)
		{
		case 'a':
		{
			for (auto ptr : origin)
			{
				ptr->show();
			}
			break;

		}
		case 'b':
		{
			for (auto ptr : character)
			{
				ptr->show();
			}
			break;

		}
		case 'c':
		{
			for (auto ptr : rating_asc)
			{
				ptr->show();
			}
			break;
		}
		case 'd':
		{
			for (auto ptr : rating_dec)
			{
				ptr->show();
			}
			break;
		}
		case 'e':
		{
			for (auto ptr : price_asc)
			{
				ptr->show();
			}
			break;
		}
		case 'f':
		{
			for (auto ptr : price_dec)
			{
				ptr->show();
			}
			break;
		}
		default:
			cout << "Mode error.\n";
			break;
		}
		cout << "\n";
	}
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
