#include "func.h"

void testExtends()
{
	std::cout << "Begin\n";
	std::cout << "Non-virtual method\n";
	Derived d;
	Base* b = &d;
	Base& b2 = d;
	d.show();
	b->show();
	b2.show();
	Base c = d;
	c.show();
	std::cout << "Virtual methods\n";
	d.print();
	b->print();
	b2.print();
	c.print();
}

void testClassic()
{
	using namespace std;
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Pinao Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	cout << "Using objects directly:\n";
	c1.report();
	c2.report();
	cout << "\n";

	cout << "Using type cd* pointer to objects: \n";
	pcd->report();
	pcd = &c2;
	pcd->report();
	cout << "\n";

	cout << "Calling a function with a Cd reference argument: \n";
	Bravo(c1);
	Bravo(c2);
	cout << "\n";

	cout << "Testing assignment: \n";
	Classic copy;
	copy = c2;
	copy.report();

}

void Bravo(const Cd& c)
{
	using std::cout;
	cout << "Bravo(): cd address is: " << &c << std::endl;
	c.report();
}

void testClassic2()
{
	using namespace std;
	Cd2 c1("Beatles", "Capitol", 14, 35.5);
	Classic2 c2 = Classic2("Pinao Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd2* pcd = &c1;

	cout << "Using objects directly:\n";
	c1.report();
	c2.report();
	cout << "\n";

	cout << "Using type cd* pointer to objects: \n";
	pcd->report();
	pcd = &c2;
	pcd->report();
	cout << "\n";

	cout << "Calling a function with a Cd reference argument: \n";
	Bravo2(c1);
	Bravo2(c2);
	cout << "\n";


	cout << "Testing assignment: \n";
	Classic2 copy;
	copy = c2;
	copy.report();
}

void Bravo2(const Cd2& c)
{
	using std::cout;
	cout << "Bravo(): cd address is: " << &c << std::endl;
	c.report();
}


Cd::Cd(const char* per, const char* lab, int sel, double play)
{
	strcpy_s(performers, strlen(per) + 1, per);
	strcpy_s(label, strlen(per) + 1, lab);
	selections = sel;
	playtime = play;
}

Cd::Cd(const Cd& cd)
{
	const char* per = cd.performers;
	const char* lab = cd.label;
	int sel = cd.selections;
	double play = cd.playtime;
	strcpy_s(performers, strlen(per) + 1, per);
	strcpy_s(label, strlen(per) + 1, lab);
	selections = sel;
	playtime = play;
}

void Cd::report() const
{
	using std::cout;
	using std::endl;
	cout << "performers: " << performers << endl;
	cout << "label: " << label << endl;
	cout << "selections: " << selections << endl;
	cout << "playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& cd)
{
	const char* per = cd.performers;
	const char* lab = cd.label;
	int sel = cd.selections;
	double play = cd.playtime;
	strcpy_s(performers, strlen(per) + 1, per);
	strcpy_s(label, strlen(per) + 1, lab);
	selections = sel;
	playtime = play;
	// TODO: 在此处插入 return 语句
	return *this;
}

Classic::Classic(const char* main, const char* per,
	const char* lab, int sel, double play) :Cd(per, lab, sel, play)
{
	strcpy_s(mainRecords, strlen(main) + 1, main);

}

Classic::Classic(const Classic& c) :Cd(c)
{
	strcpy_s(mainRecords, strlen(c.mainRecords) + 1, c.mainRecords);
}

Classic::~Classic()
{
}

void Classic::report() const
{
	using std::cout;
	using std::endl;
	Cd::report();
	cout << "mainRecords: " << mainRecords << endl;
}

Classic& Classic::operator=(const Classic& c)
{
	Cd::operator=(c);
	strcpy_s(mainRecords, strlen(c.mainRecords) + 1, c.mainRecords);
	// TODO: 在此处插入 return 语句
	return *this;
}

Cd2::Cd2(const char* per, const char* lab, int sel, double play)
{
	performers = new char[strlen(per) + 1];
	label = new char[strlen(per) + 1];
	strcpy_s(performers, strlen(per) + 1, per);
	strcpy_s(label, strlen(per) + 1, lab);
	selections = sel;
	playtime = play;
}

Cd2::Cd2(const Cd2& cd)
{
	const char* per = cd.performers;
	const char* lab = cd.label;
	int sel = cd.selections;
	double play = cd.playtime;
	performers = new char[strlen(per) + 1];
	label = new char[strlen(per) + 1];
	strcpy_s(performers, strlen(per) + 1, per);
	strcpy_s(label, strlen(per) + 1, lab);
	selections = sel;
	playtime = play;
}

Cd2::~Cd2()
{
	delete[] performers;
	delete[] label;
}

void Cd2::report() const
{
	using std::cout;
	using std::endl;
	cout << "performers: " << performers << endl;
	cout << "label: " << label << endl;
	cout << "selections: " << selections << endl;
	cout << "playtime: " << playtime << endl;
}

Cd2& Cd2::operator=(const Cd2& cd)
{
	const char* per = cd.performers;
	const char* lab = cd.label;
	int sel = cd.selections;
	double play = cd.playtime;
	performers = new char[strlen(per) + 1];
	label = new char[strlen(per) + 1];
	strcpy_s(performers, strlen(per) + 1, per);
	strcpy_s(label, strlen(per) + 1, lab);
	selections = sel;
	playtime = play;
	// TODO: 在此处插入 return 语句
	return *this;
}

Classic2::Classic2(const char* main, const char* per,
	const char* lab, int sel, double play) :Cd2(per, lab, sel, play)
{
	mainRecords = new char[strlen(main) + 1];
	strcpy_s(mainRecords, strlen(main) + 1, main);
}

Classic2::Classic2(const Classic2& c) :Cd2(c)
{
	mainRecords = new char[strlen(c.mainRecords) + 1];
	strcpy_s(mainRecords, strlen(c.mainRecords) + 1, c.mainRecords);
}

Classic2::~Classic2()
{
	delete[] mainRecords;
}

void Classic2::report() const
{
	using std::cout;
	using std::endl;
	Cd2::report();
	cout << "mainRecords: " << mainRecords << endl;
}


Classic2& Classic2::operator=(const Classic2& c)
{
	Cd2::operator=(c);
	mainRecords = new char[strlen(c.mainRecords) + 1];
	strcpy_s(mainRecords, strlen(c.mainRecords) + 1, c.mainRecords);
	// TODO: 在此处插入 return 语句
	return *this;
}

ABC::ABC(const char* lab, int rat)
{
	int size = strlen(lab);
	label = new char[size + 1];
	strcpy_s(label, size + 1, lab);
	rating = rat;
}

ABC::ABC(const ABC& abc)
{
	int size = strlen(abc.label);
	label = new char[size + 1];
	strcpy_s(label, size + 1, abc.label);
	rating = abc.rating;
}

ABC::~ABC()
{
}

ABC& ABC::operator=(const ABC& abc)
{
	int size = strlen(abc.label);
	label = new char[size + 1];
	strcpy_s(label, size + 1, abc.label);
	rating = abc.rating;
	// TODO: 在此处插入 return 语句
	return *this;
}

BaseDMA::BaseDMA(const char* lab, int rat) :ABC::ABC(lab, rat)
{
}

BaseDMA::BaseDMA(const BaseDMA& dma) :ABC::ABC(dma)
{
}

BaseDMA& BaseDMA::operator=(const BaseDMA& dma)
{
	ABC::operator=(dma);
	// TODO: 在此处插入 return 语句
	return *this;
}

void BaseDMA::view() const
{
	using std::cout;
	cout << "label: " << lab() << "\n";
	cout << "rating: " << rat() << "\n";
}

LackDMA::LackDMA(const char* col, const char* lab, int rat) :
	ABC(lab, rat)
{
	int size = strlen(col);
	strcpy_s(color, size + 1, col);
}

LackDMA::LackDMA(const LackDMA& dma) :ABC::ABC(dma)
{
	int size = strlen(dma.color);
	strcpy_s(color, size + 1, dma.color);
}

LackDMA::~LackDMA()
{
}

LackDMA& LackDMA::operator=(const LackDMA& dma)
{
	ABC::operator=(dma);
	int size = strlen(dma.color);
	strcpy_s(color, size + 1, dma.color);
	// TODO: 在此处插入 return 语句
	return *this;
}

void LackDMA::view() const
{
	using std::cout;
	cout << "label: " << lab() << "\n";
	cout << "rating: " << rat() << "\n";
	cout << "color: " << color << "\n";

}

HasDMA::HasDMA(const char* sty, const char* lab, int rat) :
	ABC(lab, rat)
{
	int size = strlen(sty);
	style = new char[size + 1];
	strcpy_s(style, size + 1, sty);
}

HasDMA::HasDMA(const HasDMA& dma) :ABC(dma)
{
	int size = strlen(dma.style);
	style = new char[size + 1];
	strcpy_s(style, size + 1, dma.style);
}

HasDMA::~HasDMA()
{
	delete[] style;
}

HasDMA& HasDMA::operator=(const HasDMA& dma)
{
	ABC::operator=(dma);
	int size = strlen(dma.style);
	style = new char[size + 1];
	strcpy_s(style, size + 1, dma.style);
	// TODO: 在此处插入 return 语句
	return *this;
}

void HasDMA::view() const
{
	using std::cout;
	cout << "label: " << lab() << "\n";
	cout << "rating: " << rat() << "\n";
	cout << "style: " << style << "\n";
}
void testABC()
{
	ABC* abc[3];
	HasDMA h("Simple", "L2", 9);
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			abc[i] = new BaseDMA();
			break;
		case 1:
			abc[i] = new LackDMA("Red", "L1", 10);
			break;
		case 2:
		{
			abc[i] = &h;
			break;
		}
		default:
			std::cout << "END\n";
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		abc[i]->view();
		std::cout << "\n";
	}
	std::cout << "Done.\n";
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	// TODO: 在此处插入 return 语句
	return os;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	const Port* p = &vp;//
	os << *p;
	os << ", " << vp.nickname << ", " << vp.year;
	// TODO: 在此处插入 return 语句
	return os;
}

void testPort()
{
	using std::cout;
	using std::endl;
	Port p1;
	Port p2 = Port("Jx", "NP", 888);
	VintagePort vp1;
	VintagePort vp2("Zp", "Zioop", "plq", 1010);
	p1.show();
	p2.show();
	vp1.show();
	vp2.show();
	cout << "------\n";
	cout << p1 << endl;
	cout << p2 << endl;
	cout << vp1 << endl;
	cout << vp2 << endl;
	vp1 = vp2;



}

Port::Port(const char* bra, const char* sty, int bot)
{
	int size = strlen(bra);
	brand = new char[size + 1];
	strcpy_s(brand, size + 1, bra);
	strcpy_s(style, strlen(sty) + 1, sty);
	bottles = bot;
}

Port::Port(const Port& p)
{
	int size = strlen(p.brand);
	brand = new char[size + 1];
	strcpy_s(brand, size + 1, p.brand);
	strcpy_s(style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	int size = strlen(p.brand);
	brand = new char[size + 1];
	strcpy_s(brand, size + 1, p.brand);
	strcpy_s(style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
	// TODO: 在此处插入 return 语句
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	// TODO: 在此处插入 return 语句
	return *this;
}

Port& Port::operator-=(int b)
{
	if (bottles > 0) bottles -= b;
	// TODO: 在此处插入 return 语句
	return *this;
}

void Port::show() const
{
	using std::cout;
	cout << "Brand: " << brand << "\n";
	cout << "Kind: " << style << "\n";
	cout << "Bottles: " << bottles << "\n";

}

VintagePort::VintagePort() :Port()
{
	nickname = new char[1];
	nickname[0] = '\0';
	year = 0;
}

VintagePort::VintagePort(const char* nick, const char* bra, const  char* sty, int bot) :
	Port(bra, sty, bot)
{
	int size = strlen(nick);
	nickname = new char[size + 1];
	strcpy_s(nickname, size + 1, nick);
	year = 0;
}

VintagePort::VintagePort(const VintagePort& vp) :
	Port(vp)
{
	int size = strlen(vp.nickname);
	nickname = new char[size + 1];
	strcpy_s(nickname, size + 1, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	Port::operator=(vp);
	int size = strlen(vp.nickname);
	nickname = new char[size + 1];
	strcpy_s(nickname, size + 1, vp.nickname);
	year = vp.year;
	// TODO: 在此处插入 return 语句
	return *this;
}

void VintagePort::show() const
{
	using std::cout;
	Port::show();
	cout << "nickname: " << nickname << "\n";
	cout << "year: " << year << "\n";

}
