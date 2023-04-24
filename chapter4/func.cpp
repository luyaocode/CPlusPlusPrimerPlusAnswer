#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include "func.h"
using namespace std;

//判断字符是否存在于已知字符数组当中,并自动向下取数
bool isExist(char* ch, char g[]) {
	for (int i = 0; i < int(sizeof(g) / sizeof(char)); i++)
	{
		if (g[i] == *ch)
		{
			if (i != int(sizeof(g) / sizeof(char))) *ch = g[i + 1];
			return true;
		}
	}
	return false;
}


struct Student
{
	char firstName[20];
	char lastName[20];
	char grade;
	int age;
};
struct Student2
{
	string firstName = "";
	string lastName = "";
	char grade = 'E';
	int age = 0;
};

void printInfo()
{
	Student stu;
	char g[5] = { 'A','B','C','D','F' };
	cout << "What is your first name? ";
	cin.get(stu.firstName, 20);
	cin.get();
	cout << "What is your last name? ";
	cin.get(stu.lastName, 20);
	cin.get();
	while (true) {
		cout << "What letter grade do you deserve? ";
		cin.get(stu.grade);
		cin.get();
		if (isExist(&stu.grade, g)) break;

	}
	cout << "What is your age? ";
	cin >> stu.age;
	cout << "Name: " << stu.lastName << ", " << stu.firstName << endl;
	cout << "Grade: " << stu.grade << endl;
	cout << "Age: " << stu.age << endl;

}
void printInfo2()
{
	Student2 stu;
	char g[5] = { 'A','B','C','D','F' };
	cout << "What is your first name? ";
	getline(cin, stu.firstName);
	//cin.get();
	cout << "What is your last name? ";
	getline(cin, stu.lastName);
	//cin.get();
	while (true) {
		cout << "What letter grade do you deserve? ";
		cin.get(stu.grade);
		cin.get();
		if (isExist(&stu.grade, g)) break;

	}
	cout << "What is your age? ";
	cin >> stu.age;
	cout << "Name: " << stu.lastName << ", " << stu.firstName << endl;
	cout << "Grade: " << stu.grade << endl;
	cout << "Age: " << stu.age << endl;

}

void printName()
{
	char firstName[20];
	char lastName[20];
	cout << "Enter your first name: ";
	cin.get(firstName, 20);
	cin.get();
	cout << "Enter your last name: ";
	cin.get(lastName, 20);
	cin.get();
	strcat_s(lastName, ", ");
	strcat_s(lastName, firstName);
	cout << "Here's the information in a signal string: "
		<< lastName << endl;
}

void printName2()
{
	string firstName;
	string lastName;
	cout << "Enter your first name: ";
	getline(cin, firstName);
	cout << "Enter your last name: ";
	getline(cin, lastName);
	cout << "Here's the information in a signal string: " << lastName + "," + firstName << endl;

}


struct CandyBar
{
	string type;
	float weight;
	int calorie;
};
void printCandyBar()
{
	CandyBar snack{ "Mocha Munch",2.3f,350 };
	cout << snack.type << ", " << snack.weight << ", " << snack.calorie << endl;
}

void printCandyBars()
{
	CandyBar bar[3];
	srand(time(NULL));
	for (int i = 0; i<int(sizeof(bar) / sizeof(CandyBar)); i++)
	{
		bar[i].type = "type" + to_string(i);
		bar[i].weight = (float)rand() / RAND_MAX * 100;
		bar[i].calorie = rand() % 10 + 100;
	}
	for (CandyBar b : bar)
	{
		cout << b.type << ", " << b.weight << ", " << b.calorie << endl;
	}
}

void printCandyBars2()
{
	int Size = 3;
	CandyBar* bar = new CandyBar[Size];
	srand(time(NULL));
	for (int i = 0; i < Size; i++)
	{
		bar[i].type = "type" + to_string(i);
		bar[i].weight = (float)rand() / RAND_MAX * 100;
		bar[i].calorie = rand() % 10 + 100;
	}
	for (int i = 0; i < Size; i++)
	{
		cout << bar[i].type << ", " << bar[i].weight << ", " << bar[i].calorie << endl;
	}

}

struct Pizza
{
	char corp[100] = "";
	float diam = 0;
	float weight = 0;

};

void pizzaService()
{
	Pizza pizza;
	cout << "Enter pizza's corporation: ";
	cin.get(pizza.corp, 100);
	cin.get();
	cout << "Enter pizza's diameter: ";
	cin >> pizza.diam;
	cin.get();
	cout << "Enter pizza's weight: ";
	cin >> pizza.weight;
	cout << pizza.corp << ", " << pizza.diam << ", " << pizza.weight << endl;

}

void pizzaService2()
{
	Pizza* pizza = new Pizza;
	cout << "Enter pizza's diameter: ";
	cin >> pizza->diam;
	cin.get();
	cout << "Enter pizza's corporation: ";
	cin.get(pizza->corp, 100);
	cin.get();
	cout << "Enter pizza's weight: ";
	cin >> pizza->weight;
	cout << pizza->corp << ", " << pizza->diam << ", " << pizza->weight << endl;
}


bool isInteger(const string str)
{
	if (empty(str)) return false;
	if (str[0] == '0') return false;
	for (char c : str)
	{
		if (!isdigit(c)) return false;
	}
	return true;
}
void runScore()
{
	const int Size = 3;
	array<string, Size> scores;
	int i =0;
	string err = "";
	while (i < Size)
	{
		while (1)
		{
			cout << err + "Enter score: ";
			getline(cin, scores[i]);
			if (isInteger(scores[i]))
			{
				err = "";
				break;
			}
			err = "Illegal value, ";
		}
		i++;

	}
	i = 0;
	while (i< Size)
	{
		cout << to_string(i+1) + ", " + scores[i] << endl;
		i++;
	}
}

