#include "func.h"
#include <iostream>
#include <random>
#include <fstream>
#include <string>

Location::Location()
{
	x = y = len = 0;
}

Location::Location(double xval, double yval)
{
	x = xval;
	y = yval;
	len = sqrt(x * x + y * y);
}

double Location::x_val() const
{
	return x;
}

double Location::y_val() const
{
	return y;
}

double Location::len_val() const
{
	return len;
}

Location& Location::operator+(const Location& step)
{
	x += step.x;
	y += step.y;
	len = sqrt(x * x + y * y);
	return *this;
}

void Location::show(std::fstream& fs) const
{
	using std::cout;
	using std::endl;
	fs << "(" << x << ", " << y << ")" << endl;
}
void randomWalk()
{
	using std::cout;
	using std::endl;
	using std::fstream;
	using std::string;

	std::random_device rd;
	std::default_random_engine gen(rd());
	std::uniform_real_distribution<double> dis(-20.0, 20.0);
	Location loc;
	int count = 0;
	double aver = 0.0;
	fstream fs;
	string path = "out.txt";
	fs.open(path);
	if (!fs.is_open())
	{
		cout << "Failed to open " << path << endl;
		return;
	}
	fs << "Target distance: " << Location::Target << ", Step size: " << Location::Step << endl;
	while (loc.len_val() < Location::Target)
	{
		fs << count << ": (x, y) = ";
		loc.show(fs);
		double r1 = dis(gen);
		double r2 = dis(gen);
		Location temp(r1, r2);
		loc = loc + temp;
		count++;
	}
	if (count != 0) aver = loc.len_val() / count;
	fs << count << ": (x, y) = ";
	loc.show(fs);
	fs << "After " << count << " steps: " << endl;
	loc.show(fs);
	fs << "Averange outward distance per step: " << endl;
	fs << aver << endl;

}


VECTOR::Vector::Vector()
{
	x = y = 0.0;
	mode = RECT;
}

VECTOR::Vector::Vector(double n1, double n2, Mode form)
{
	x = n1;
	y = n2;
	mode = form;
}

VECTOR::Vector::~Vector()
{
}

void VECTOR::Vector::polarMode()
{
	mode = POL;
}

void VECTOR::Vector::rectMode()
{
	mode = RECT;
}

void VECTOR::Vector::reset(double n1, double n2, Mode form)
{
	using std::cout;
	using std::endl;
	if (form == RECT)
	{
		x = n1;
		y = n2;
	}
	else if (form == POL)
	{
		x = n1 * cos(n2 * atan(1) / 45);
		y = n1 * sin(n2);
	}
	else
	{
		cout << "Mode dismatch." << endl;
	}
}
VECTOR::Vector VECTOR::Vector::operator+(const Vector& b) const
{
	return Vector(x + b.xVal(), y + b.yVal());
}
std::ostream& VECTOR::operator<<(std::ostream& os, const Vector& v)
{
	if (v.mode == Vector::RECT)
	{
		os << "(x,y) = (" << v.x << ", " << v.y << ")" << std::endl;
	}
	else if (v.mode == Vector::POL)
	{
		os << "(x,y) = " << v.magVal() << ", " << v.angVal() << ")" << std::endl;
	}
	else
	{
		os << "Form error." << std::endl;
	}
	return os;
}
void randWalkVectorVersion()
{
	using namespace VECTOR;
	using std::cout;
	using std::cin;
	using std::endl;
	srand(time(0));//set random-number generator
	double direction;
	Vector step;
	Vector res(0.0, 0.0);
	unsigned long steps;
	double target = 0.0;
	double dstep;
	while (1) {
		steps = 0;
		while (1)
		{
			cout << "Enter target distance: " << endl;
			cin >> target;
			if (cin.fail())
			{
				cout << "Data dismatch. " << endl;
				//clear error flag in istream
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else break;
		}
		while (1)
		{
			cout << "Enter step length: " << endl;
			cin >> dstep;
			if (cin.fail())
			{
				cout << "Data dismatch. " << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else break;
		}
		//cout << res;
		while (res.magVal() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			res = res + step;
			//cout << res;
			steps++;
		}
		cout << "After " << steps << " steps: " << endl;
		cout << res;
		res.polarMode();
		cout << "or\n" << res;
		cout << "Averange outward distance per step: " << endl;
		cout << res.magVal() / steps << endl;
		res.reset(0.0, 0.0);
	}
	cout << "Bye~" << endl;

}

void randWalkNtimes()
{
	using namespace VECTOR;
	using std::cout;
	using std::cin;
	using std::endl;
	using std::max;
	using std::min;

	srand(time(0));//set random-number generator
	double direction = 0.0;
	Vector step;
	Vector res(0.0, 0.0);
	unsigned long steps = 0;
	double target = 0.0;
	double dstep = 0.0;
	int times = 0;
	unsigned long maxCounts = 0;
	unsigned long minCounts = 0;
	unsigned long totalCounts = 0;
	double averCounts = 0.0;
	while (1)
	{
		cout << "Enter times of randwalk you want to run(>0): " << endl;
		cin >> times;
		if (cin.fail())
		{
			cout << "Data dismatch. " << endl;
			//clear error flag in istream
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	}
	unsigned long* counts = new unsigned long[times];
	while (1)
	{
		cout << "Enter target distance: " << endl;
		cin >> target;
		if (cin.fail())
		{
			cout << "Data dismatch. " << endl;
			//clear error flag in istream
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	}
	while (1)
	{
		cout << "Enter step length: " << endl;
		cin >> dstep;
		if (cin.fail())
		{
			cout << "Data dismatch. " << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	}
	for (int i = 0; i < times; i++)
	{
		res.reset(0.0, 0.0);
		step.reset(0.0, 0.0);
		steps = 0;
		while (res.magVal() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			res = res + step;
			steps++;
		}
		counts[i] = steps;
		maxCounts = max(maxCounts, steps);
		if (i == 0) minCounts = steps;
		minCounts = min(minCounts, steps);
	}
	for (int i = 0; i < times; i++)
	{
		totalCounts += counts[i];
	}
	averCounts = totalCounts / times;
	cout << "Times: " << endl;
	cout << times << endl;
	cout << "Max steps: " << endl;
	cout << maxCounts << endl;
	cout << "Min steps: " << endl;
	cout << minCounts << endl;
	cout << "Averange steps: " << endl;
	cout << averCounts << endl;
}


Time::Time()
{
	hours = 0;
	minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::addMin(int m)
{
	minutes += m;
	if (minutes >= 60)
	{
		minutes -= minutes - 60;
		hours += 1;
	}
}

void Time::addHour(int h)
{
	hours += 1;
}

void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time& t1, const Time& t2)
{
	int hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60;
	int minutes = (t1.minutes + t2.minutes) % 60;
	return Time(hours, minutes);
}

Time operator-(const Time& t1, const Time& t2)
{
	int minutes = t1.minutes - t2.minutes;
	int hours = t1.hours - t2.hours;
	if (minutes < 0)
	{
		minutes += 60;
		hours -= 1;
	}
	return Time(hours, minutes);
}

Time operator*(const Time& t, double mult)
{
	int minutes = t.minutes * mult;
	int hours = t.hours * mult;
	if (minutes >= 60)
	{
		hours += minutes / 60;
		minutes = minutes % 60;
	}
	return Time(hours, minutes);
}

Time operator*(double mult, const Time& t)
{
	return t * mult;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes. ";
	return os;
}


Stonewt::Stonewt()
{
	stones = 0;
	pds_left = 0.0;
	pounds = 0.0;
	mode = INT;
}

Stonewt::Stonewt(double pds, Mode form)
{
	if (pds < 0)
	{
		std::cout << "Param err." << std::endl;
	}
	stones = int(pds / Lbs_per_stone);
	pds_left = pds - int(pds / Lbs_per_stone) * Lbs_per_stone;
	pounds = pds;
	mode = form;
}

Stonewt::Stonewt(int sto, double pds, Mode form)
{
	pds_left = pds - int(pds / Lbs_per_stone) * Lbs_per_stone;
	stones = sto + int(pds / Lbs_per_stone);
	pounds = sto * Lbs_per_stone + pds;
	mode = form;
}

Stonewt::~Stonewt()
{
}

double Stonewt::getPounds() const
{
	return pounds;
}

Stonewt Stonewt::operator*(double mult) const
{
	if (mode == INT)
	{
		int x = int(pds_left * mult / Lbs_per_stone);
		return Stonewt(stones * mult + x, pds_left * mult - x * Lbs_per_stone);
	}
	else if (mode == DBL)
	{
		return Stonewt(pounds * mult);
	}
}

bool Stonewt::operator==(const Stonewt& s) const
{
	return pounds == s.pounds;
}

bool Stonewt::operator>=(const Stonewt& s) const
{
	return pounds >= s.pounds;

}

bool Stonewt::operator<=(const Stonewt& s) const
{
	return pounds <= s.pounds;
}

Stonewt operator*(double mult, const Stonewt& s1)
{
	return s1 * mult;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& s)
{
	if (s.mode == Stonewt::INT)
	{
		os << s.stones << " stones, " << s.pds_left << " pounds. ";
	}
	else if (s.mode == Stonewt::DBL)
	{
		os << s.pounds << " pounds. ";
	}
	else
	{
		os << "Mode error. ";
	}
	return os;
}

Stonewt operator+(const Stonewt& s1, const Stonewt& s2)
{
	double pounds = s1.pounds + s2.pounds;
	return Stonewt(pounds, s1.mode);
}

Stonewt operator-(const Stonewt& s1, const Stonewt& s2)
{
	double pounds = s1.pounds - s2.pounds;
	return Stonewt(pounds, s1.mode);
}

void testStonewtClass()
{
	using std::cout;
	using std::endl;
	Stonewt s1;
	Stonewt s2(1, 9.22);
	Stonewt s3(10.00);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s2 + s3 << endl;
	cout << s3 + s2 << endl;
	cout << s2 - s3 << endl;
	cout << s2 * 2 << endl;
	cout << 2 * s2 << endl;


}

void testStonewtClass2()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Stonewt arr[6];
	Stonewt le11[6];
	Stonewt maxItem;
	Stonewt minItem;
	double maxVal;
	double minVal;
	double pds;
	int maxIndex;
	int minIndex;
	Stonewt s = Stonewt(11.0);
	for (int i = 0; i < 3; i++)
	{
		arr[i] = Stonewt(i * 7.5 + 4);
	}
	for (int i = 3; i < 6; i++)
	{
		cout << "Enter 3 numbers of pounds: " << endl;
		cin >> pds;
		if (cin.fail())
		{
			cout << "Data dismatch.";
			break;
		}
		arr[i] = Stonewt(pds);
	}
	maxVal = minVal = arr[0].getPounds();
	maxIndex = minIndex = 0;
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i].getPounds() > maxVal)
		{
			maxVal = arr[i].getPounds();
			maxIndex = i;
		}
		if (arr[i].getPounds() < minVal)
		{
			minVal = arr[i].getPounds();
			minIndex = i;
		}
		if (arr[i] >= s)
		{
			le11[j++] = arr[i];
		}
	}
	cout << "Minimum item: " << endl << arr[minIndex] << endl;
	cout << "Maximum item: " << endl << arr[maxIndex] << endl;
	cout << "11 or larger than 11: " << endl;
	for (int i = 0; le11[i].getPounds() > 0; i++)
	{
		cout << le11[i] << endl;
	}
}

Complex operator~(const Complex& comp)
{
	return Complex(comp.real, -comp.imag);
}

Complex operator*(double x, const Complex& comp)
{
	return comp * x;
}

std::ostream& operator<<(std::ostream& os, const Complex& comp)
{
	if (comp.imag >= 0)
	{
		os << comp.real << " + " << comp.imag << "i";
	}
	else
	{
		os << comp.real << " " << comp.imag << "i";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Complex& comp)
{
	using std::cout;
	using std::endl;
	while (1)
	{
		cout << "Enter real and imaginary part of complex: " << endl;
		is >> comp.real;
		if (is.fail())
		{
			cout << "Data dismatch." << endl;
			break;
		}
		is.get();
		is >> comp.imag;
		if (is.fail())
		{
			cout << "Data dismatch." << endl;
			break;
		}
		is.get();
		break;

	}
	return is;

}


Complex::Complex()
{
	real = 0.0;
	imag = 0.0;

}

Complex::Complex(double x, double y)
{
	real = x;
	imag = y;
}

Complex::~Complex()
{
}


Complex Complex::operator+(const Complex& b) const
{

	return Complex(real + b.real, imag + b.imag);
}

Complex Complex::operator-(const Complex& b) const
{
	return Complex(real - b.real, imag - b.imag);
}

Complex Complex::operator*(const Complex& b) const
{
	return Complex(real * b.real - imag * b.imag, real * b.imag + imag * b.real);
}

Complex Complex::operator*(double x) const
{
	return Complex(real * x, imag * x);
}

void testComplex()
{
	using namespace std;

	Complex a(3.0, 4.0);
	Complex c;
	cout << "Enter a complex number (q to quit):" << endl;
	while (cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " << 2 * c << endl;
		cout << "Enter a complex number (q to quit):" << endl;

	}
	cout << "Done." << endl;
}
