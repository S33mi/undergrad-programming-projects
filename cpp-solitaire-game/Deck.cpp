#include "Deck.h"


Deck::Deck()
{
	size = 52;
	int j=0;
	for (int i = 1; i<= 13; i++)
	{
		deck[j]= new PlayingCard(i,PlayingCard::Spade);
		j++;
	}
	for (int i = 1; i<= 13; i++)
	{
		deck[j]= new PlayingCard(i,PlayingCard::Diamond);
		j++;
	}
	for (int i = 1; i<= 13; i++)
	{
		deck[j]= new PlayingCard(i,PlayingCard::Club);
		j++;
	}
	for (int i = 1; i<= 13; i++)
	{
		deck[j]= new PlayingCard(i,PlayingCard::Heart);
		j++;
	}


}

int Deck:: getSize()
{
	return this->size;
}
bool Deck:: IsEmpty()
{
	if(size==0)
	{
		cout<<"Deck is already empty"<< endl;
		return true;}
	else
	{
		
		return false;
	}
}
PlayingCard Deck:: Remove(int i)
{
	int r ,s;
	/*r=getRank();
	s=getSuit();*/

	PlayingCard P=*deck[i];
	delete deck[i];
	//deck[i]= new PlayingCard(0,0);

	for(int j = i+1 ; j < this->size ; j++)
	{
		r=deck[j]->getRank();
		s=deck[j]->getSuit();
		deck[j-1] = new PlayingCard(r,s);//deck[j];
		delete deck[j];
		//deck[j]= new PlayingCard(0,0);
		//cout << "                                  hgghhhhjgghjf\n";
	}
	size--;
	return P;
}

Deck::~Deck()
{
	for (int i = 0; i<this->size; i++)
	{
		delete deck[i];
		deck[i]=NULL;
	}
}
