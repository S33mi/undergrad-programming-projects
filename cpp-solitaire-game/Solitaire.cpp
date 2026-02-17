#include "Solitaire.h"


Solitaire::Solitaire(void)
{
	
	this->stock=PileOfCards(52);
	this->stock.setStartPt(1,1);
	this->stock.setEndPt(6,8);


	this->waste=PileOfCards(52);
	this->waste.setStartPt(8,1);
	this->waste.setEndPt(16,8);

	int x=24,y=32;

	for(int i=0 ;i<4;i++)
	{
		this->home[i]= new PileOfCards(13);
		this->home[i]->setStartPt(x,1);
		this->home[i]->setEndPt(y,8);
		x=x+8;
		y=y+8;
	}

	for(int i=0 ;i<7;i++)
	{
		playingPile[i]=PileOfCards(i+1+13);
	}

}

void Solitaire:: Shuffle()
{
	int i; 
	unsigned seed = time(0);
	srand(seed);
	cout<<"done";
	while (!deckofCards.IsEmpty()) 
	{ 
		cout<<"done";
		i = rand()%deckofCards.getSize(); 
		PlayingCard c = deckofCards.Remove(i); 
		c.setFaceUp(false);
		stock.Add(c); 
	}
}
void Solitaire:: dealToPlayingPiles()
{
	
	for(int i=0; i<7; i++)
	{
		playingPile[i].Add(stock.Remove());
	}
		

}
void Solitaire:: DisplayGame()
{
	this->stock.SimpleDisplay();
	this->waste.SimpleDisplay();
	for(int i=0;i<4;i++)
	{
		home[i]->CascadingDisplay();
	}
	for(int i=0;i<4;i++)
	{
		(playingPile[i]).CascadingDisplay();
	}

}

Solitaire::~Solitaire(void)
{
}
