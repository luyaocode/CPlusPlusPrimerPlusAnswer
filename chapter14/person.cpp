#include "person.h"

Card::Card()
{
	suits[0] = "Spades";
	suits[1] = "Hearts";
	suits[2] = "Diamonds";
	suits[3] = "Clubs";
	for (int i = 0; i < RANKS; i++)
	{
		ranks[i] = i + 1;
	}
	suitindex = 0;
	rankindex = 0;
}

Card::Card(string sui[], int ran[])
{
	for (int i = 0; i < SUITS; i++)
	{
		suits[i] = sui[i];
	}
	for (int i = 0; i < RANKS; i++)
	{
		ranks[i] = ran[i];
	}
	suitindex = 0;
	rankindex = 0;
}


Card::Card(const Card& card)
{
	for (int i = 0; i < SUITS; i++)
	{
		suits[i] = card.suits[i];
	}
	for (int i = 0; i < RANKS; i++)
	{
		ranks[i] = card.ranks[i];
	}
	suitindex = card.suitindex;
	rankindex = card.rankindex;
}

Card& Card::operator=(const Card& card)
{
	for (int i = 0; i < SUITS; i++)
	{
		suits[i] = card.suits[i];
	}
	for (int i = 0; i < RANKS; i++)
	{
		ranks[i] = card.ranks[i];
	}
	suitindex = card.suitindex;
	rankindex = card.rankindex;
	// TODO: 在此处插入 return 语句
	return *this;
}

const Card& PokerPlayer::draw()
{
	srand(time(0));
	int i1 = rand() % 4;
	int i2 = rand() % 13 + 1;
	card.set(i1, i2);
	return card;
}

void testPoker()
{
	Gunslinger gun;
	PokerPlayer poker;
	BadDude bad("张", "三", 1.2, 9);
	gun.show();
	poker.show();
	bad.show();
}
