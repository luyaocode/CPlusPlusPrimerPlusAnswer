#ifndef CHAPTER4_H__
#define CHAPTER4_H__
struct Student
{
	char firstName[20];
	char lastName[20];
	char grade;
	int age;
};
//C-style
void printInfo();
//C++ string
struct Student2
{
	string firstName = "";
	string lastName = "";
	char grade = 'E';
	int age = 0;
};
void printInfo2();
//use <cstring>
void printName();
//use <string>
void printName2();

struct CandyBar
{
	string type;
	float weight;
	int calorie;
};
void printCandyBar();
void printCandyBars();
void printCandyBars2();

//披萨公司
struct Pizza
{
	char corp[100] = "";
	float diam = 0;
	float weight = 0;

}; 
void pizzaService();
void pizzaService2();

//跑步成绩
void runScore();

#endif
