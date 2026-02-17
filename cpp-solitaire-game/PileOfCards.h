#ifndef PILEOFCARDS_H
#define PILEOFCARDS_H
#include "PlayingCard.h"
#include "ConsoleFunctions.h"
class PileOfCards
{
private:
	PlayingCard *pile;
	int top;
	int size;
	point startPt; 
	point endPt;
public:
	PileOfCards(void);
	PileOfCards (int size );
	PlayingCard Peek();
	PlayingCard Remove();
	void Add(PlayingCard);
	bool IsEmpty();
	bool IsFull();


	////////******** new ///

	int getTop(); //returns value of top 
	void setStartPt(int x, int y); //sets startPt point 
	point getStartPt(); //returs startPt 
	void setEndPt(int x, int y); //sets endPt point 
	point getEndPt(); //returs endPt 
	PileOfCards& PileOfCards::operator=(const PileOfCards& poc);
	PlayingCard viewCard(int i);
	void SimpleDisplay();
	void CascadingDisplay();

	//////////********** 

	~PileOfCards(void);
};
#endif

