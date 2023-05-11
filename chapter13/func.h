#ifndef CHAPTER13_H__
#define CHAPTER13_H__

#include <iostream>
class Base
{
public:
	void show() const { std::cout << "Base-show: " << this << "\n"; }
	virtual void print() const { std::cout << "Base: " << this << "\n"; };
};
class Derived :public Base
{
public:
	void show() const { std::cout << "Derived-show: " << this << "\n"; }
	virtual void print() const { std::cout << "Derived: " << this << "\n"; };
};
void testExtends();

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char* per = "none", const char* lab = "none", int sel = 0, double play = 0.0);
	Cd(const Cd& cd);
	virtual ~Cd() {};
	virtual void report() const;
	Cd& operator=(const Cd& cd);
};

class Classic :public Cd
{
private:
	char mainRecords[100];
public:
	Classic(const char* main = "none", const char* per = "none",
		const char* lab = "none", int sel = 0, double play = 0.0);
	Classic(const Classic& c);
	virtual ~Classic();
	virtual void report() const;
	Classic& operator=(const Classic& c);


};
void testClassic();
void Bravo(const Cd& c);

class Cd2
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd2(const char* per = "none", const char* lab = "none", int sel = 0, double play = 0.0);
	Cd2(const Cd2& cd);
	virtual ~Cd2();
	virtual void report() const;
	Cd2& operator=(const Cd2& cd);
};

class Classic2 :public Cd2
{
private:
	char* mainRecords;
public:
	Classic2(const char* main = "none", const char* per = "none",
		const char* lab = "none", int sel = 0, double play = 0.0);
	Classic2(const Classic2& c);
	virtual ~Classic2();
	virtual void report() const;
	Classic2& operator=(const Classic2& c);


};


//new memory space
void testClassic2();
void Bravo2(const Cd2& c);

class ABC
{
private:
	char* label;
	int rating;
public:
	ABC(const char* lab = "none", int rat = 0);
	ABC(const ABC& abc);
	virtual ~ABC();
	char* lab() const { return label; };
	int rat() const { return rating; };
	virtual void view() const = 0;//pure virtual function
	ABC& operator=(const ABC& abc);
};

class BaseDMA :public ABC
{
public:
	BaseDMA(const char* lab = "none", int rat = 0);
	BaseDMA(const BaseDMA& dma);
	virtual ~BaseDMA() {};
	BaseDMA& operator=(const BaseDMA& dma);
	virtual void view() const;
};
class LackDMA :public ABC
{
private:
	enum { COLLEN = 40 };
	char color[COLLEN];
public:
	LackDMA(const char* col = "blank", const char* lab = "none", int rat = 0);
	LackDMA(const LackDMA& dma);
	virtual ~LackDMA();
	LackDMA& operator=(const LackDMA& dma);
	virtual void view() const;
};
class HasDMA :public ABC
{
private:
	char* style;
public:
	HasDMA(const char* sty = "none", const char* lab = "none", int rat = 0);
	HasDMA(const HasDMA& dma);
	virtual ~HasDMA();
	HasDMA& operator=(const HasDMA& dma);
	virtual void view() const;
};
void testABC();


class Port
{
private:
	char* brand;
	char style[20];
	int bottles;
public:
	Port(const char* bra = "none", const char* sty = "none",
		int bot = 0);
	Port(const Port& p);
	virtual ~Port() { delete[] brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int bottleCount() { return bottles; }
	virtual void show() const;
	friend std::ostream& operator<<(std::ostream& os, const Port& p);

};
class VintagePort :public Port
{
private:
	char* nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* nick, const char* bra, const char* sty, int bot);
	VintagePort(const VintagePort& vp);
	virtual ~VintagePort() { delete[] nickname; };
	VintagePort& operator=(const VintagePort& vp);
	virtual void show() const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};
void testPort();









#endif