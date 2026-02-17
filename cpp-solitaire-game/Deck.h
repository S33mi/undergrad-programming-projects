#ifndef DECK_H
#define DECK_H
#include "PlayingCard.h"
#include "PileOfCards.h"
#include <iostream>
using namespace std;
class Deck
{
private:
	PlayingCard *deck[52];
	int size;
public:
	Deck();
	int getSize();
	bool  IsEmpty();
	PlayingCard Remove(int i);
	~Deck();
};
#endif
