#include "tv.h"
#include <iostream>
bool Tv::volup()
{
	if (volume >= MaxVal) return false;
	else volume++;
	return true;
}

bool Tv::voldown()
{
	if (volume <= MinVal) return false;
	else volume--;
	return true;
}

void Tv::chanup()
{
	channel = channel % maxchannel + 1;
}

void Tv::chandown()
{
	channel = channel == 1 ? maxchannel : channel - 1;
}

void Tv::setMode()
{
	mode = (mode == Antenna ? Cable : Antenna);
}

void Tv::setInput()
{
	input = (input == TV ? DVD : TV);
}

void Tv::settings() const
{
	using std::cout;
	cout << "state: " << state << "\n";
	cout << "volume: " << volume << "\n";
	cout << "maxchannel: " << maxchannel << "\n";
	cout << "channel: " << channel << "\n";
	cout << "mode: " << mode << "\n";
	cout << "input: " << input << "\n";

}


void Tv::switchMode(Remote& r)
{
	if (state == Off) return;
	r.switchMode();
}

void Remote::switchMode()
{
	mode = (mode == Normal ? Interactive : Normal);
}

void Remote::showMode() const
{
	using std::cout;
	cout << "mode: " << mode << "\n";
}

void Remote::onoff(Tv& tv)
{
	tv.onoff();
}

bool Remote::volup(Tv& tv)
{
	return tv.volup();
}

bool Remote::voldown(Tv& tv)
{
	return tv.voldown();
}

void Remote::chanup(Tv& tv)
{
	tv.chanup();
}

void Remote::chandown(Tv& tv)
{
	tv.chandown();
}

void Remote::setMode(Tv& tv)
{
	tv.setMode();
}

void Remote::setInput(Tv& tv)
{
	tv.setInput();
}

void Remote::settings(Tv& tv) const
{
	tv.settings();
}

void testTv()
{
	using std::cout;
	Tv tv;
	Remote re;
	tv.onoff();
	tv.settings();
	re.settings(tv);
	cout << "---test tv---\n";
	re.showMode();
	tv.switchMode(re);
	re.showMode();
	cout << "---test remote---\n";
	re.chandown(tv);
	re.voldown(tv);
	re.settings(tv);
	re.onoff(tv);

	

}
