#ifndef CHAPTER6_H__
#define CHAPTER6_H__
#include <string>
void printKeyBoard();
void printAverange();
void menuDemo();
struct bop
{
	char fullname[50];
	char title[50];
	char bopname[50];
	int preference;//0=fullname,1=title,2=bopname;
};
void showBopInfo();

void calTax();

struct donor
{
	std::string name;
	double amount=0;
};
void showDonation();

void countWordsOnConsole();

void countCharactersInFile();

void showDonation2();


#endif

