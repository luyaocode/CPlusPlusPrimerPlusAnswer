#ifndef WINE_H__
#define WINE_H__

#include <string>
#include <valarray>
namespace WINE
{
	using std::string;
	using std::valarray;

	typedef valarray<int> ArrayInt;

	template<typename T, typename U>
	class Pair
	{
	private:
		T years;
		U bottles;
	public:
		Pair() {};
		Pair(const int y[], const int bot[]);
		virtual ~Pair() {};
	};

	template<>
	class Pair<ArrayInt, ArrayInt>
	{
	private:
		ArrayInt years;
		ArrayInt bottles;
	public:
		Pair() :years(), bottles() {}
		Pair(const int yea[], const int bot[])
		{
			years = ArrayInt(yea, sizeof(yea) / sizeof(int));
			bottles = ArrayInt(bot, sizeof(bot) / sizeof(int));
		}
		Pair(const ArrayInt& yea, const ArrayInt& bot) { years = yea; bottles = bot; };
		virtual ~Pair() {};
		ArrayInt yearsArr() const { return years; }
		ArrayInt bottlesArr() const { return bottles; }
		void set(const ArrayInt& yea, const ArrayInt& bot) { years = yea; bottles = bot; };

	};

	typedef Pair<ArrayInt, ArrayInt> PairArray;

	class Wine
	{
	private:
		string label;
		PairArray pair;
		int types;//how many types of wine group by the year 
	public:
		Wine() :label("none"), pair(), types() {}
		Wine(const char* lab, int t) :
			label(lab), types(t), pair() {}
		Wine(const char* lab, int t, const int yes[], const int bot[]) :
			label(lab), types(t), pair{ yes, bot } {}
		void getBottles();
		const string& getLabel() const;
		int sum() const;
		virtual ~Wine() {}
		void show() const;
	};

	//use private inheritance
	class Wine2 :private PairArray
	{
	private:
		string label;
		int types;
	public:
		Wine2() :label("none"), types(0), Pair() {}
		Wine2(const char* lab, int t) :label(lab), types(t), Pair() {}
		Wine2(const char* lab, int t, const int yes[], const int bot[]) :
			label(lab), types(t), Pair(yes, bot) {}
		void getBottles();
		const string& getLabel() const { return label; }
		int sum() const { return bottlesArr().sum(); }
		virtual ~Wine2() {}
		void show() const;
	};
};
void testWine();
void testWine2();



#endif