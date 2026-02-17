#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H
#include "ConsoleFunctions.h"
#include <iostream>
using namespace std;
class PlayingCard
{
private:
	int rank; //integer 1 – 13
	int suit; //integer 0 – 3
	char color; // red or black - „b‟ for black , „r‟ for red
	//ConsoleFunctions C;
	bool faceUp; //tells if a card is face up or not
	bool top; //tells if a card is on top of a pile
public:

	static const int Diamond  ;
	static const int Heart  ;
	static const int Spade ;
	static const int Club ;

	//******** ctor ******

	PlayingCard(void);
	PlayingCard(int rank,int suit);
	PlayingCard & operator=(const PlayingCard& c);
	int getSuit();
	int  getRank();

	void display (int x, int y);


	//*************new*********

	bool isFaceUp(); //retunrs value of faceUp
	void setFaceUp(bool); //sets value of faceUp
	bool isTop(); //retunrs value of top
	void setTop(bool); //sets value of top
	//int getSuit(); //getter for suit value
	//int PlayingCard::getRank(); //getter for rank value
	char getColor(); //getter for color value

	//******* dtor *******
	~PlayingCard(void);
};
#endif

