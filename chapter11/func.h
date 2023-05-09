#ifndef CHAPTER11_H__
#define CHAPTER11_H__
#include <iostream>
#include <ostream>

class Location
{
private:
	double x;
	double y;
	double len;
public:
	enum { Target = 100, Step = 20 };
	Location();
	Location(double xval, double yval);
	double x_val() const;
	double y_val() const;
	double len_val() const;
	Location& operator+(const Location& step);
	void show(std::fstream& fs) const;

};
void randomWalk();

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		Mode mode;
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();
		double xVal() const { return x; }
		double yVal() const { return y; }
		double magVal() const { return sqrt(x * x + y * y); }
		double angVal() const { return atan2(y, x); }
		void polarMode();
		void rectMode();
		void reset(double n1, double n2, Mode form = RECT);

		Vector operator+(const Vector& b) const;
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
void randWalkVectorVersion();
void randWalkVectorVersion();
void randWalkNtimes();

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m);
	void addMin(int m);
	void addHour(int h);
	void reset(int h = 0, int m = 0);
	friend Time operator+(const Time& t1, const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	friend Time operator*(const Time& t, double mult);
	friend Time operator*(double mult, const Time& t);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

class Stonewt
{
private:
	enum { Lbs_per_stone = 14 };
	enum Mode { INT, DBL };
	int stones;
	double pds_left;
	double pounds;
	Mode mode;
public:
	Stonewt();
	Stonewt(double pds, Mode form = DBL);
	Stonewt(int sto, double pds = 0.0, Mode form = INT);
	~Stonewt();
	double getPounds() const;
	Stonewt operator*(double mult) const;
	bool operator==(const Stonewt& s) const;
	bool operator>=(const Stonewt& s) const;
	bool operator<=(const Stonewt& s) const;
	friend Stonewt operator+(const Stonewt& s1, const Stonewt& s2);
	friend Stonewt operator-(const Stonewt& s1, const Stonewt& s2);
	friend Stonewt operator*(double mult, const Stonewt& s1);

	friend std::ostream& operator<< (std::ostream& os, const Stonewt& s);

};
void testStonewtClass();
void testStonewtClass2();

class Complex
{
private:
	double real;
	double imag;
public:
	Complex();
	Complex(double a, double i);
	~Complex();
	Complex operator+(const Complex& b) const;
	Complex operator-(const Complex& b) const;
	Complex operator*(const Complex& b) const;
	Complex operator*(double x) const;
	friend Complex operator~(const Complex& comp);
	friend Complex operator*(double x, const Complex& comp);
	friend std::ostream& operator<<(std::ostream& os, const Complex& comp);
	friend std::istream& operator>>(std::istream& is, Complex& comp);
};
void testComplex();









#endif