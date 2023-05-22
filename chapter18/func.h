#ifndef CHAPTER18_H__
#define CHAPTER18_H__
#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;
template<typename T>
T averange_list(vector<T> v);
void testAverangeList();

class Cpmv
{
public:
	struct Info
	{
		string qcode;
		string zcode;
	};
private:
	Info* pi;
public:
	Cpmv()
	{
		pi = new Info{ "none","none" };
		cout << "Default constructor.\n";
	}
	Cpmv(const string& q, const string& z)
	{
		pi = new Info{ q,z };
		cout << "constructor\n";
	}
	Cpmv(const Cpmv& c)
	{
		pi = new Info;
		pi->qcode = c.pi->qcode;
		pi->zcode = c.pi->zcode;
		cout << "Copy constructor\n";


	}
	Cpmv& operator=(const Cpmv& c)
	{
		pi = new Info;
		pi->qcode = c.pi->qcode;
		pi->zcode = c.pi->zcode;
		cout << "=\n";
		return *this;

	}
	Cpmv(Cpmv&& c) noexcept
	{
		pi = c.pi;
		c.pi = nullptr;
		cout << "Move constructor\n";

	}
	Cpmv operator=(Cpmv&& c) noexcept
	{
		pi = c.pi;
		c.pi = nullptr;
		cout << "Move =\n";
		return Cpmv(pi->qcode, pi->zcode);
	}
	virtual ~Cpmv()
	{
		delete pi;
		cout << "~Cpmv()\n";

	}
	Cpmv operator+(const Cpmv& c) const
	{
		cout << "+\n";
		Cpmv temp;
		temp.pi->qcode = pi->qcode + c.pi->qcode;
		temp.pi->zcode = pi->zcode + c.pi->zcode;
		return temp;
	}
};

void testCpmv();

template<typename T>
long double sumValue(const T& value)
{
	if constexpr (std::is_arithmetic<T>::value)
		return static_cast<long double>(value);
	else
		return 0;
}

template<typename T, typename... Args>
long double sumValue(const T& value, const Args&... args)
{
	if constexpr (std::is_arithmetic<T>::value)
		return static_cast<long double>(value) + sumValue(args...);
	else
		return sumValue(args...);
}







#endif
