#ifndef SOLITAIRE_H
#define SOLITAIRE_H
#include "ConsoleFunctions.h"
#include "PlayingCard.h"
#include "PileOfCards.h"
#include "Deck.h"
#include<cstdlib>
#include<ctime>


class Solitaire
{
private:
	Deck deckofCards;
	PileOfCards stock;
	PileOfCards waste;
	PileOfCards* home[4];
	PileOfCards playingPile[7];
	ConsoleFunctions cf;
public:
	Solitaire();
	void Shuffle();
	void dealToPlayingPiles();
	void DisplayGame();
	~Solitaire();
};
/*public:
	Solitaire(void);
	~Solitaire(void);
};*/
#endif

