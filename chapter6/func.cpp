#include "func.h"
#include <iostream>
#include <array>
#include <string>
#include <fstream>
using namespace std;
void printKeyBoard()
{
	cout << "Enter anything: " << endl;
	char ch;
	while ((ch = cin.get()) != '@')
	{
		if (!isdigit(ch))
		{
			if (ch >= 'a' && ch <= 'z')
			{
				cout << (char)toupper(ch);
			}
			else if (ch >= 'A' && ch <= 'Z') {
				cout << (char)tolower(ch);
			}
			else
			{
				cout << ch;
			}
		}

	}
}

void printAverange()
{
	const int NumSize = 10;
	double nums[NumSize]{};
	double donation = 0.0;
	double total = 0.0;
	double aver = 0.0;
	int size = 0;
	int largerThanAver = 0;
	cout << "Enter numbers: " << endl;
	while (size < NumSize)
	{
		cin >> donation;
		if (cin.fail())
		{
			cin.clear(); // 清空输入缓冲区的错误标志位;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略当前行的剩余字符
			cout << "Not a number, Break." << endl;
			break;
		}
		else {
			nums[size] = donation;
			size++;
		}
	}
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			total += nums[i];
		}
		aver = total / size;
		for (int i = 0; i < size; i++)
		{
			if (nums[i] > aver)
			{
				largerThanAver++;
			}
		}
	}
	cout << "averange = " << aver << ", " << "largerThanAver = " << largerThanAver << endl;

}

void menuDemo()
{
	char ch;
	cout << "Please enter one of the following choices:" << endl;
	cout << "c) carnivore\t\t" << "p) pianist" << endl;
	cout << "t) tree\t\t\t" << "g)game" << endl;
	while (ch = cin.get())
	{
		if (ch != '\n')
		{
			switch (ch)
			{
			case 'c':
				cout << "A lion is a carnivore." << endl;
				break;
			case 'p':
				cout << "Mozart is a pianist." << endl;
				break;
			case 't':
				cout << "A maple is a tree." << endl;
				break;
			case 'g':
				cout << "Life is a game." << endl;
				break;
			default:
				cout << "Please enter a character in c, p, t and g:";
			}
		}


	}

}

void showBopInfo()
{
	const int MaxSize = 5;
	char ch{};
	bool flag = false;
	array<bop, MaxSize> bops{
		bop{"Wimp Macho", "Manager", "WM", 0},
		bop{"Raki Rhodes", "Junior Programmer", "RR", 1},
		bop{"Celia Laiter", "Cook","MIPS",2},
		bop{"Hoppy Hipman", "Analyst Trainee","HH",1},
		bop{"Pat Hand", "Driver","LOPPY",2},
	};

	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a. display by name\t" << "b. dispaly by title" << endl;
	cout << "c. display by bopname\t" << "d. display by preferencr." << endl;
	cout << "q. quit" << endl;
	while (1)
	{
		if (!flag)
		{
			cout << "Enter your choice: " << endl;
			flag = true;
		}
		else
		{
			cout << "Next choice: ";

		}
		ch = cin.get();
		cin.get();
		if (ch == 'q')
		{
			cout << "Bye." << endl;
			break;
		}
		else
		{
			switch (ch)
			{
			case 'a':
				for (int i = 0; i < MaxSize; i++)
				{
					cout << bops[i].fullname << endl;
				}
				break;
			case 'b':
				for (int i = 0; i < MaxSize; i++)
				{
					cout << bops[i].title << endl;
				}
				break;
			case 'c':
				for (int i = 0; i < MaxSize; i++)
				{
					cout << bops[i].bopname << endl;
				}
				break;
			case 'd':
				for (int i = 0; i < MaxSize; i++)
				{
					switch (bops[i].preference)
					{
					case 0:
						cout << bops[i].fullname << endl;
						break;
					case 1:
						cout << bops[i].title << endl;
						break;
					case 2:
						cout << bops[i].bopname << endl;
						break;
					default:
						cout << "Data Error." << endl;
						break;
					}

				}
			case 'q':
				break;
			default:
				cout << "Enter a character in a, b, c and d:" << endl;
			}

		}
	}
}

void calTax()
{
	double income = 0;
	double tax = 0;
	cout << "Enter your income: ";
	while (1)
	{
		cin >> income;
		if (cin.fail())
		{
			cout << "Not a number, break. " << endl;
			break;
		}
		if (income < 0)
		{
			cout << "Income can't be negetive. " << endl;
			break;
		}
		if (income <= 5000)
		{
			tax = 0;
		}
		else if (income <= 15000)
		{
			tax += (income - 5000) * 0.1;
		}
		else if (income <= 35000)
		{
			tax += 10000 * 0.1 + (income - 15000) * 0.15;
		}
		else if (income > 35000)
		{
			tax += 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
		}
		cout << "Tax: " << tax << endl;

	}

}

void showDonation()
{
	int MaxSize = 10;
	donor* donors = new donor[MaxSize];
	int grandNum = 0;
	for (int i = 0; i < MaxSize; i++)
	{
		donors[i].name = "Donor" + to_string(i);
		donors[i].amount = 9998 + i % 5;
	}
	cout << "Grand Patrons: " << endl;
	for (int i = 0; i < MaxSize; i++)
	{
		if (donors[i].amount > 10000)
		{
			cout << donors[i].name << endl;
			grandNum++;

		}
	}
	if (!grandNum)
	{
		cout << "none" << endl;
	}
	cout << "Patrons: " << endl;
	for (int i = 0; i < MaxSize; i++)
	{
		if (donors[i].amount <= 10000)
		{
			cout << donors[i].name << endl;

		}
	}
	if (grandNum == MaxSize)
	{
		cout << "none" << endl;
	}
	delete[] donors;
}

void countWordsOnConsole()
{
	string word;
	int vowel = 0;
	int consonant = 0;
	int others = 0;
	cout << "Enter words: " << endl;
	while (1)
	{
		cin >> word;
		if (word == "q") break;
		if (!isalpha(word[0]))
		{
			others++;
		}
		else {
			switch (word[0])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				vowel++;
				break;
			default:
				consonant++;
				break;
			}
		}
	}
	cout << vowel << " words beginning with vowels." << endl;
	cout << consonant << " words beginning with consonants." << endl;
	cout << others << " others." << endl;
}

void countCharactersInFile()
{
	string line;
	char ch;
	int count = 0;
	fstream fs;
	fs.open("test.txt");
	if (!fs.is_open())
	{
		cout << "Could not open the file.\n";
		exit(EXIT_FAILURE);
	}
	while (!fs.eof()) 
	{
		getline(fs, line);
		cout << line << endl;
		count+=line.size()+1;
	}
	fs.close();
	cout << count << " characters." << endl;
}

void showDonation2()
{
	int MaxSize;
	fstream fs;
	fs.open("DonorList.txt");
	if (!fs.is_open())
	{
		cout << "Could not open the file.\n";
		exit(EXIT_FAILURE);
	}
	fs >> MaxSize;
	fs.get();
	if (fs.fail()) {
		cout << "Data dismatch.\n";
		return;
	}
	donor* donors = new donor[MaxSize];
	int grandNum = 0;
	string amount;
	for (int i = 0; i < MaxSize; i++)
	{
		getline(fs, donors[i].name);
		getline(fs, amount);
		donors[i].amount = stod(amount);
	}
	cout << "Grand Patrons: " << endl;
	for (int i = 0; i < MaxSize; i++)
	{
		if (donors[i].amount > 10000)
		{
			cout << donors[i].name << endl;
			grandNum++;

		}
	}
	if (!grandNum)
	{
		cout << "none" << endl;
	}
	cout << "Patrons: " << endl;
	for (int i = 0; i < MaxSize; i++)
	{
		if (donors[i].amount <= 10000)
		{
			cout << donors[i].name << endl;

		}
	}
	if (grandNum == MaxSize)
	{
		cout << "none" << endl;
	}
	delete[] donors;
}
