#ifndef CHAPTER7_H__
#define CHAPTER7_H__
double* harmonicMean(int maxSize);
double calHarmonicMean(double x, double y);

void initArr(float* socres, int maxSize);
void inputGolfScores(float* scores, int maxSize);
void showGolfSocres(float* scores, int maxSize);
float calAverGolfScore(float* scores, int maxSize);

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void showBoxMembers(box box);
void setBoxVolume(box* box);

double probability(unsigned int numbers, unsigned picks);

long double calFactorial(unsigned int n);

int fillArray(double arr[], int size);
void showArray(double arr[], int size);
void reverseArray(double arr[], int size);

double* fill_array(double* begin, int size);
void show_array(double* begin, double* end);
void revalue_array(double r, double* begin, double* end);

void fillExpenses(const char* snames[], double expenses[]);
void showExpenses(const char* snames[], double expenses[]);

struct exp_st
{
	double expenses[4];
};
void fillExpenses2(const char* snames[], exp_st& exp);
void showExpenses2(const char* snames[], exp_st& exp);

const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
void initStudents(student stu[], int n);
int getinfo(student stu[], int n);
void display1(student stu);
void display2(const student* ps);
void display3(const student stu[], int n);

double addTwoNumbers(double x, double y);
double multiplyTwoNumbers(double x, double y);
double powTwoNumbers(double x, double y);
double calculateTwoNumbers(double x, double	y, double (*pf)(double x, double y));



#endif