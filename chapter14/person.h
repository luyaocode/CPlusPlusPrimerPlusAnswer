#ifndef PERSON_H__
#define PERSON_H__
#include <string>
#include <iostream>
using std::string;
using std::cout;

class Person
{
private:
	string name;
	string surname;
public:
	Person() :name("none"), surname("none") {}
	Person(const string& snm, const string& nm) :name(nm), surname(snm) {}
	virtual ~Person() = 0 {}
	virtual void show() const { cout << surname << name << "\n"; }
};

class Gunslinger :virtual public Person
{
private:
	double time;
	int scars;
public:
	Gunslinger(double t = 0.0, int sca = 0) :time(t), scars(sca) {}
	Gunslinger(const Person& per, double t, int sca) :Person(per), time(t), scars(sca) {}
	Gunslinger(const string& nm, const string& snm, double t, int sca) :Person(nm, snm), time(t), scars(sca) {}
	virtual ~Gunslinger() {}
	double draw() const { return time; }
	virtual void show() const
	{
		Person::show();
		cout << time << ", " << scars << "\n";
	}
};

class Card
{
private:
	enum { SUITS = 4, RANKS = 13 };
	string suits[SUITS];
	int ranks[RANKS];
	int suitindex;
	int rankindex;
public:
	Card();
	Card(string sui[], int ran[]);
	Card(const Card& card);
	virtual ~Card() {};
	Card& operator=(const Card& card);
	void set(int i1, int i2) { suitindex = i1, rankindex = i2; }
	void show() const { cout << suits[suitindex] << " " << ranks[rankindex]; }
};

class PokerPlayer :virtual public Person
{
private:
	Card card;
public:
	PokerPlayer() {}
	explicit PokerPlayer(const Card& c) { card = c; }
	virtual ~PokerPlayer() {}
	const Card& draw();
	virtual void show() { Person::show(); }
};

class BadDude :public Gunslinger, public PokerPlayer
{
public:
	BadDude() {}
	BadDude(const string& nm, const string& snm, double t, int sca) :Person(nm, snm), Gunslinger(t, sca) {}
	BadDude(const BadDude& bad) {}
	virtual ~BadDude() {}
	double gdraw() { return Gunslinger::draw(); }
	const Card& cdraw() { return PokerPlayer::draw(); }
	virtual void show()
	{
		Gunslinger::show();
		cdraw().show();
	}
	BadDude& operator=(const BadDude& bad) {}

};

void testPoker();


#endif