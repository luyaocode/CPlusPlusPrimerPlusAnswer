#include "employee.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using std::cout;

void tinyEmployeeSystem()
{
	fstream fs;
	char sel;
	const int Size = 100;
	AbstrEmp* pc[Size];
	int count = 0;
	int index;

	fs.open(AbstrEmp::empFile, ios::in);
	if (!fs.is_open())
	{
		cout << "Open file failed.\n";
		cout << "Create a file.\n";
		fs.open(AbstrEmp::empFile, ios::out);
		fs.close();
		fs.open(AbstrEmp::empFile, ios::in);
	}
	string line;
	while (getline(fs, line))
	{
		if (line.find("Classtype") != string::npos)
		{
			switch (line[11])
			{
			case '0':
			{
				pc[count] = new Employee;
				pc[count]->getAll(fs);
				break;
			}
			case '1':
			{
				pc[count] = new Manager;
				pc[count]->getAll(fs);
				break;
			}
			case '2':
			{
				pc[count] = new Fink;
				pc[count]->getAll(fs);
				break;
			}
			case '3':
			{
				pc[count] = new HighFink;
				pc[count]->getAll(fs);
				break;
			}
			default:
			{
				break;
			}
			}
			count++;
		}
	}
	if (count == 0)
	{
		cout << "table is empty.\n";
	}
	else if (count == Size)
	{
		cout << "###########employee.dat##########\n";
		for (int i = 0; i < count; i++) {
			pc[i]->showAll();
			cout << "\n";
		}
		cout << "\nTotal: " << count<<"\n";
		cout << "#################################\n\n";
		cout << "table is full.\n";
		return;
	}
	else
	{
		cout << "###########employee.dat##########\n";
		for (int i = 0; i < count; i++) {
			pc[i]->showAll();
			cout << "\n";
		}
		cout << "\nTotal: " << count << "\n";
		cout << "#################################\n\n";
	}
	fs.close();
	fs.open(AbstrEmp::empFile, ios::out | ios::app);
	index = count;
	while (count < Size)
	{
		cout << "Create a object(q to quit):\n";
		cout << "a. Employee\n";
		cout << "b. Manager\n";
		cout << "c. Fink\n";
		cout << "d. HignFink\n";
		cin >> sel;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (sel == 'q') break;
		switch (sel)
		{
		case 'a':
		{
			pc[count] = new Employee;
			pc[count]->setAll();
			count++;
			break;
		}
		case 'b':
		{
			pc[count] = new Manager;
			pc[count]->setAll();
			count++;
			break;
		}
		case 'c':
		{
			pc[count] = new Fink;
			pc[count]->setAll();
			count++;
			break;
		}
		case 'd':
		{
			pc[count] = new HighFink;
			pc[count]->setAll();
			count++;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	//write
	for (int i = index; i < count; i++)
	{
		pc[i]->writeAll(fs);
	}

	//read again
	fs.close();
	fs.open(AbstrEmp::empFile, ios::in);
	cout << "###########employee.dat##########\n";
	for (int i = 0; i < count; i++) {
		pc[i]->showAll();
		cout << "\n";
	}
	cout << "\nTotal: " << count << "\n";
	cout << "#################################\n\n";
	fs.close();

}
void Employee::setAll()
{
	classtype = AbstrEmp::EMPLOYEE;
	string fullname;
	string lastname;
	string job;
	cout << "Enter fullname: ";
	getline(cin, fullname);
	cout << "Enter lastname: ";
	getline(cin, lastname);
	cout << "Enter job: ";
	getline(cin, job);
	setFullname(fullname);
	setLastname(lastname);
	setJob(job);
	cout << "\n";
}
void Manager::setAll()
{
	classtype = AbstrEmp::MANAGER;
	string fullname;
	string lastname;
	string job;
	int ico;
	cout << "Enter fullname: ";
	getline(cin, fullname);
	cout << "Enter lastname: ";
	getline(cin, lastname);
	cout << "Enter job: ";
	getline(cin, job);
	while (1)
	{
		cout << "Enter inchargeof: ";
		cin >> ico;
		if (cin.fail() || ico < 0)
		{
			cout << "Data dismatch.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	setFullname(fullname);
	setLastname(lastname);
	setJob(job);
	inchargeof = ico;
	cout << "\n";
}
void Fink::setAll()
{
	classtype = AbstrEmp::FINK;
	string fullname;
	string lastname;
	string job;
	string reportsto;

	cout << "Enter fullname: ";
	getline(cin, fullname);
	cout << "Enter lastname: ";
	getline(cin, lastname);
	cout << "Enter job: ";
	getline(cin, job);
	cout << "Enter reportsto: ";
	getline(cin, reportsto);
	setFullname(fullname);
	setLastname(lastname);
	setJob(job);
	reportsTo() = reportsto;
	cout << "\n";
}
void HighFink::setAll()
{
	classtype = AbstrEmp::HIGHFINK;
	string fullname;
	string lastname;
	string job;
	int ico;
	string reportsto;

	cout << "Enter fullname: ";
	getline(cin, fullname);
	cout << "Enter lastname: ";
	getline(cin, lastname);
	cout << "Enter job: ";
	getline(cin, job);
	while (1)
	{
		cout << "Enter inchargeof: ";
		cin >> ico;
		if (cin.fail() || ico < 0)
		{
			cout << "Data dismatch.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter reportsto: ";
	getline(cin, reportsto);

	setFullname(fullname);
	setLastname(lastname);
	setJob(job);
	inChargeOf() = ico;
	reportsTo() = reportsto;
	cout << "\n";
}
void Employee::getAll(fstream& fs)
{
	string line;
	int index;
	getline(fs, line);
	index = line.find("Fullname");
	if (index == 0)
	{
		setFullname(line.substr(index + strlen("Fullname: ")));
	}
	getline(fs, line);
	index = line.find("Lastname");
	if (index == 0)
	{
		setLastname(line.substr(index + strlen("Lastname: ")));
	}
	getline(fs, line);
	index = line.find("Job");
	if (index == 0)
	{
		setJob(line.substr(index + strlen("Job: ")));
	}
}

void Manager::getAll(fstream& fs)
{
	string line;
	int index;
	getline(fs, line);
	index = line.find("Fullname");
	if (index == 0)
	{
		setFullname(line.substr(index + strlen("Fullname: ")));
	}
	getline(fs, line);
	index = line.find("Lastname");
	if (index == 0)
	{
		setLastname(line.substr(index + strlen("Lastname: ")));
	}
	getline(fs, line);
	index = line.find("Job");
	if (index == 0)
	{
		setJob(line.substr(index + strlen("Job: ")));
	}
	getline(fs, line);
	index = line.find("Inchargeof");
	if (index == 0)
	{
		inChargeOf() = stoi(line.substr(index + strlen("Inchargeof: ")));

	}
}
void Fink::getAll(fstream& fs)
{
	string line;
	int index;
	getline(fs, line);
	index = line.find("Fullname");
	if (index == 0)
	{
		setFullname(line.substr(index + strlen("Fullname: ")));
	}
	getline(fs, line);
	index = line.find("Lastname");
	if (index == 0)
	{
		setLastname(line.substr(index + strlen("Lastname: ")));
	}
	getline(fs, line);
	index = line.find("Job");
	if (index == 0)
	{
		setJob(line.substr(index + strlen("Job: ")));
	}
	getline(fs, line);
	index = line.find("Reportsto");
	if (index == 0)
	{
		reportsTo() = line.substr(index + strlen("Reportsto: "));

	}
}
void HighFink::getAll(fstream& fs)
{
	string line;
	int index;
	getline(fs, line);
	index = line.find("Fullname");
	if (index == 0)
	{
		setFullname(line.substr(index + strlen("Fullname: ")));
	}
	getline(fs, line);
	index = line.find("Lastname");
	if (index == 0)
	{
		setLastname(line.substr(index + strlen("Lastname: ")));
	}
	getline(fs, line);
	index = line.find("Job");
	if (index == 0)
	{
		setJob(line.substr(index + strlen("Job: ")));
	}
	getline(fs, line);
	index = line.find("Inchargeof");
	if (index == 0)
	{
		inChargeOf() = stoi(line.substr(index + strlen("Inchargeof: ")));
	}
	getline(fs, line);
	index = line.find("Reportsto");
	if (index == 0)
	{
		reportsTo() = line.substr(index + strlen("Reportsto: "));

	}
}

const string AbstrEmp::empFile = "employee.dat";

void Employee::writeAll(fstream& fs)
{
	if (!fs.is_open())
	{
		cout << "Open file failed.\n";
		return;
	}
	fs << "Classtype: " << classtype << "\n";
	fs << "Fullname: " << getFullname() << "\n";
	fs << "Lastname: " << getLastname() << "\n";
	fs << "Job: " << getJob() << "\n";
}

void Manager::writeAll(fstream& fs)
{
	if (!fs.is_open())
	{
		cout << "Open file failed.\n";
		return;
	}
	fs << "Classtype: " << classtype << "\n";
	fs << "Fullname: " << getFullname() << "\n";
	fs << "Lastname: " << getLastname() << "\n";
	fs << "Job: " << getJob() << "\n";
	fs << "Inchargeof: " << inchargeof << "\n";

}

void Fink::writeAll(fstream& fs)
{
	if (!fs.is_open())
	{
		cout << "Open file failed.\n";
		return;
	}
	fs << "Classtype: " << classtype << "\n";
	fs << "Fullname: " << getFullname() << "\n";
	fs << "Lastname: " << getLastname() << "\n";
	fs << "Job: " << getJob() << "\n";
	fs << "Reportsto: " << reportsto << "\n";

}
void HighFink::writeAll(fstream& fs)
{
	if (!fs.is_open())
	{
		cout << "Open file failed.\n";
		return;
	}
	fs << "Classtype: " << classtype << "\n";
	fs << "Fullname: " << getFullname() << "\n";
	fs << "Lastname: " << getLastname() << "\n";
	fs << "Job: " << getJob() << "\n";
	fs << "Inchargeof: " << inChargeOf() << "\n";
	fs << "Reportsto: " << reportsTo() << "\n";

}