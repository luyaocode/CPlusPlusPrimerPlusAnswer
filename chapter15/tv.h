#ifndef TV_H__
#define TV_H__
#include <iostream>
class Remote;
class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	friend class Remote;
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Tv(int s = Off, int mc = 125) :state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	virtual ~Tv() {}
	void onoff() { state = (state == On ? Off : On); }
	bool ison() { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void setMode();
	void setInput();
	void settings() const;
	void switchMode(Remote& r);
};
class Remote
{
private:
	int ctl;//controls TV or DVD
	int mode;//normol mode or interactive mode
public:
	enum { Normal, Interactive };
	friend class Tv;
	Remote(int c = Tv::TV, int m = Normal) :ctl(c), mode(m) {}
	virtual ~Remote() {}
	void onoff(Tv& tv);
	bool volup(Tv& tv);
	bool voldown(Tv& tv);
	void chanup(Tv& tv);
	void chandown(Tv& tv);
	void setMode(Tv& tv);
	void setInput(Tv& tv);
	void settings(Tv& tv) const;
	void switchMode();
	void showMode() const;
};

void testTv();

#endif