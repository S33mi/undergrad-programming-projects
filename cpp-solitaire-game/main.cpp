#include "ConsoleFunctions.h"
#include "PlayingCard.h"
#include "PileOfCards.h"
#include "Deck.h"
#include "Solitaire.h"

int main()
{


Solitaire S;
S.Shuffle();
S.dealToPlayingPiles();
S.DisplayGame();


//	PlayingCard card1(10,3,1,0);
//	card1.display(30,18);
////
//	//s1omo6o;
//	PlayingCard A(3,PlayingCard::Spade);
//	PlayingCard B(2,PlayingCard::Spade);
//	PlayingCard C(4,PlayingCard::Heart);
//	PlayingCard D(5,PlayingCard::Club);
//	PlayingCard E(3,PlayingCard::Diamond);
//	PlayingCard temp (3,PlayingCard::Heart);
//	PileOfCards pile1(5);
//	//****** Adding cards in pile ********/
//	pile1.Add(A);
//	pile1.Add(B);
//	pile1.Add(C);
//	pile1.Add(D);
//	pile1.Add(E);
//	//*Note for Testing:
//	/*The 6th card temp, in the statement below, should not be added to the
//	pile, as at this point pile is full.
//	Write a statement in IsFull function to display an error message if pile is
//	full.
//	*/
////	pile1.Add(temp);
//	//****** Removing Cards from pile *****/
//	temp = pile1.Remove();
//	/* Here you will need to see which card is removed from the pile.
//	For this you need to write display function for class PlayingCard to
//	view a card. */
//	temp.display(0,0);
//	/* According to this scenario, the above statement should display the card
//	3 of Diamond, as this is the card removed from the top of the pile*/
//	temp = pile1.Remove(); //5 of Club should be removed
//	temp.display(0,10);
//	temp = pile1.Remove(); //4 of Heart should be removed
//	temp.display(0,20);
//	temp = pile1.Remove(); //2 of Spade should be removed
//	temp.display(0,30);
//	temp = pile1.Remove(); //3 of Spade should be removed
//	temp.display(0,40);
//	temp = pile1.Remove(); //Now the pile is empty
//	/*Write a print statement in IsEmpty funtion to display an error message when
//	pile is empty*/
//	/////////////////
//
//
//









	//Deck D1;
	//PlayingCard A(10,0);
	//int y = 0;

	//A = D1.Remove(0);
	//A.display(0,y);
	//y=y+10;
	//A = D1.Remove(0);
	//A.display(0,10);
	//y=y+10;
	//A = D1.Remove(0);
	//A.display(0, 20); // three cards removed
	//y=y+10;
	//while(!D1.IsEmpty())
	//{
	//	A = D1.Remove(0);
	//	A.display(0, y);
	//	y=y+10;
	//}
	////cout << "                  1235346\n";
	//
return 0;	
}