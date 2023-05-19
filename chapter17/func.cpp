#include <iostream>
#include <string>
#include "func.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

void trnansNumber()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	//decimal
	cout.width(15);
	cout << n;

	//octal
	cout << oct;
	cout.width(15);
	cout << 0 << n;

	//hexadecimal
	cout.width(15);
	cout << "0x" << n;

}

void printInfo()
{
	string name;
	double wage_per_hour;
	double hours;

	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your hourly wages: ";
	cin >> wage_per_hour;
	cin.get();
	cout << "Enter number of hours worked: ";
	cin >> hours;

	cout << "First format:\n";
	cout.width(32);
	cout << name;
	cout << ": $";
	cout.width(16);
	cout << wage_per_hour;
	cout << ": ";
	cout.width(8);
	cout << hours << "\n";

	cout << "Second format:\n";
	cout << left;
	cout.width(32);
	cout << name;
	cout << ": $";
	cout.width(16);
	cout << wage_per_hour;
	cout << ": ";
	cout.width(8);
	cout << hours << "\n";

}

void count$()
{
	string text;
	int count = 0;
	cout << "Enter a text end with $: \n";
	getline(cin, text);
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == '$') break;
		else count++;
	}
	cin.putback('$');
	cout << "Number of '$' is " << count << "\n";
}

void cin2File()
{
	string text;
	string line;
	cout << "Enter text end with '$': \n";
	getline(cin, line);
	int i = line.find('$');
	if (line.find('$') != string::npos)
		text += line.substr(0, i) + '\n';
	else
		text += line;
	cout << text;
}

void copyAlltypeFile(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Need src and dest file name.\n";
		exit(EXIT_FAILURE);
	}
	string src = argv[1];
	string dest = argv[2];
	const int buffersize = 1024;
	char buffer[buffersize];

	ifstream ifs;
	ofstream ofs;
	ifs.open(src, ios::binary);
	ofs.open(dest, ios::binary);
	if (!ifs.is_open())
	{
		cout << "Open file failed.\n";
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ifs.read(buffer, buffersize);
		ofs.write(buffer, ifs.gcount());
		if (ifs.eof())
		{
			cout << "Reached the end of the file.\n";
			break;
		}
	}
	cout << "Done.\n";
	ifs.close();
	ofs.close();

}

void combineTexts(const string file1, const string file2)
{
	ifstream ifs1;
	ifstream ifs2;
	ofstream ofs;
	string line1;
	string line2;
	int len1 = 0;
	int len2 = 0;
	ifs1.open(file1);
	ifs2.open(file2);
	ofs.open("combine.txt");
	if (!ifs1.is_open() || !ifs2.is_open())
	{
		cerr << "Open file failed.\n";
		exit(EXIT_FAILURE);
	}
	while (getline(ifs1, line1))
	{
		len1++;
	}
	while (getline(ifs2, line2))
	{
		len2++;
	}
	ifs1.clear();
	ifs2.clear();
	//set fstream pointer to initial position
	ifs1.seekg(0, ios::beg);
	ifs2.seekg(0, ios::beg);
	if (len1 >= len2)
	{
		while (getline(ifs1, line1) && getline(ifs2, line2))
		{
			ofs << line1 + " " + line2 << "\n";
		}
		while (getline(ifs1, line1))
		{
			ofs << line1 << "\n";
		}
	}
	else
	{
		return combineTexts(file2, file1);
	}

	ifs1.close();
	ifs2.close();
	ofs.close();
	cout << "Done.\n";
}

void ourMutualFriends()
{
	string f1 = "mat.dat";
	string f2 = "pat.dat";
	string outfile = "matnpat.dat";
	string friend1;
	string friend2;
	unordered_set<string> mat;
	unordered_set<string> pat;
	unordered_set<string> mutual;
	ifstream ifs1;
	ifstream ifs2;
	ofstream ofs;
	ifs1.open(f1);
	ifs2.open(f2);
	ofs.open(outfile);
	if (!ifs1.is_open() || !ifs2.is_open())
	{
		cout << "Open file failed.\n";
		exit(EXIT_FAILURE);
	}
	while (getline(ifs1, friend1))
	{
		mat.insert(friend1);
	}
	while (getline(ifs2, friend2))
	{
		pat.insert(friend2);
	}
	mutual = mat;
	for (string fri : pat)
	{
		mutual.insert(fri);
	}
	for (string fri : mutual)
	{
		ofs << fri << "\n";
	}

	ifs1.close();
	ifs2.close();
	ofs.close();
	cout << "Done.\n";

}

void testBinaryIO()
{
	vector<string> vso;
	string temp;
	cout << "Enter strings(empty line to quit): \n";
	while (getline(cin, temp) && temp[0] != '\0')
	{
		vso.push_back(temp);
	}
	cout << "Here is your input:\n";
	for_each(vso.begin(), vso.end(), showStr);
	//store in a file
	ofstream ofs("strings.dat", ios::out | ios::binary);
	for_each(vso.begin(), vso.end(), Store(ofs));
	ofs.close();
	//read from file
	vector<string> vsi;
	ifstream ifs("strings.dat", ios::in, ios::binary);
	if (!ifs.is_open())
	{
		cout << "Open file failed.\n";
		exit(EXIT_FAILURE);
	}
	getStrs(ifs, vsi);
	cout << "strings in file: \n";
	for_each(vsi.begin(), vsi.end(), showStr);
	ifs.close();


}

void showStr(const string& s)
{
	cout << s << "\n";
}

void getStrs(ifstream& ifs, vector<string>& vsi)
{
	string buffer;
	char ch;
	int len;
	while (1)
	{
		while (ifs.read(&ch, sizeof(char)))
		{
			if (ch != '\n')
			{
				buffer += ch;
			}
			else break;
		}
		if (!buffer.empty())
		{
			len = stoi(buffer);
			char* buf = new char[len + 1];
			ifs.read(buf, len);
			buf[len] = '\0';
			ifs.read(&ch, 1);
			vsi.push_back(string(buf));
			delete[] buf;
			buffer.clear();
		}
		else
		{
			break;
		}

	}
}

void Store::operator()(const string& s)
{
	string len_s = to_string(s.size());
	ofs.write(len_s.data(), len_s.size());
	ofs.put('\n');
	ofs.write(s.data(), s.size());
	ofs.put('\n');

}
