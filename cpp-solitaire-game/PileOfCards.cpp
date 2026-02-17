#include "PileOfCards.h"



PileOfCards::PileOfCards(void)
{
	this->size=0;
	this->top=-1;
}


PileOfCards::PileOfCards(int size )
{
	this->size=size;
	this->top=-1;
	this->pile = new PlayingCard[size] ;
}
PlayingCard PileOfCards:: Peek()
{
	return pile[top];
}
PlayingCard PileOfCards:: Remove()
{
	//PlayingCard p;
	bool check;
	check=IsEmpty();
	if(!check)
	{
		int i =top-1;
		pile[i].setFaceUp(true);
		pile[i].setTop(true);
		return this->pile[top--];
		//top--;
	}
	else
	{
		//cout<<"Pile is already empty"<< endl<< endl << endl;
		return this->pile[++top];
	}
}
void PileOfCards  :: Add(PlayingCard p)
{
	bool check;
	check=IsFull();
	if(!check)
	{
		pile[top].setFaceUp(false);
		pile[top].setTop(false);
		top++;
		pile[top]=p;
		pile[top].setFaceUp(true);
		pile[top].setTop(true);
		//int y =this->endPt.y+2;
		//this->setEndPt(this->endPt.x,y);
	}
	else
	{
		cout << "\n The pile is full Playing card can be not added "<< endl<< endl << endl;	
	}

}
bool PileOfCards:: IsEmpty()
{
	if(top==-1)
	{
		cout<<"Pile is already empty"<< endl;
		return true;}
	else
	{
		
		return false;
	}
}
bool PileOfCards:: IsFull()
{
	if(top==size-1)
	{
		//cout << "\n The pile is full Playing card can be not added "<< endl<< endl << endl;
		return true;}
	else
		return false;
}


////////////***************** new ******************/////////////////


int PileOfCards::getTop()
{
	return this->top; 
}//returns value of top 
void PileOfCards::setStartPt(int x, int y)
{
	this->startPt.x=x;
	this->startPt.y=y;
}//sets startPt point 
point PileOfCards::getStartPt()
{
	return this->startPt;
}//returs startPt 
void PileOfCards::setEndPt(int x, int y)
{
	this->endPt.x=x;
	this->endPt.y=y;
}//sets endPt point 
point PileOfCards::getEndPt()
{
	return this->endPt;
}//returs endPt 
PileOfCards& PileOfCards::operator=(const PileOfCards& poc)
{
	this->top=poc.top;
	this->size=poc.size;
	this->endPt=poc.endPt;
	this->startPt=poc.startPt;
	this->pile=poc.pile;
	return *this;
}//overload //assignment operator 
PlayingCard PileOfCards::viewCard(int i)//It is just like peek function but //returns a card at index i rather //than top card and no card is //removed from pile 
{
	return pile[i];
}
void PileOfCards::SimpleDisplay()//only displays top card of a pile,and //starting point of display is startPt, if //pile is empty a 6x8 dark_green rectangle //will be printed. 
{
	if(IsEmpty())
	{
		ConsoleFunctions x ;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<6;j++)
			{
				x.SetColor(ConsoleColor::green ,ConsoleColor:: green);
				cout << " ";
			}
		}
	}
	else
	{
		this->pile[top].display(this->startPt.x,this->startPt.y);
	}
}
void PileOfCards::CascadingDisplay()//gives cascading display of a pile of //cards as , and starting point of //display is startPt, if pile is empty, //a 6x8 dark_green rectangle will be //printed.
{
	int x1= this->startPt.x;
	int y= this->startPt.y;
	if(IsEmpty())
	{
		ConsoleFunctions x ;
		x.SetCursorAt(this->startPt.x,this->startPt.y);
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<6;j++)
			{
				x.SetColor(ConsoleColor::green ,ConsoleColor:: green);
				cout << " ";
			}
			y++;
			x.SetCursorAt(x1,y);
		}
	}
	else
	{
		int a = this->startPt.y;
		for(int i=0 ; i<this->size ; i++)
		{
			this->pile[i].display(this->startPt.x,a);
			a+=2;
		}
	}
}

PileOfCards::~PileOfCards(void)
{
	delete []pile ;
}
