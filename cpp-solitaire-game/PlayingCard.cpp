#include "PlayingCard.h"
#include "ConsoleFunctions.h"


PlayingCard::PlayingCard(void)
{
	rank =0;
	suit=0;
	color= 'b';
	top=0;
	faceUp=0;
}

PlayingCard :: PlayingCard(int rank,int suit)
{
	this->rank=rank;
	this->suit=suit;
	if(this->rank<1)
	{
		this->rank=1;
	}
	if(this->rank>13)
	{
		this->rank=13;
	}
	if(this->suit<0)
	{
		this->suit=0;
	}
	if(this->suit>3)
	{
		this->suit=3;
	}

	if(this->suit==0||this->suit==1)
	{
		this->color='r';
	}
	else
	{
		this->color='b';
	}
	/*this->faceUp=face;
	th*///is->top=top;
}


PlayingCard & PlayingCard :: operator=(const PlayingCard & c)
{
	this->rank=c.rank;
	this->suit=c.suit;
	if(this->suit==0||this->suit==1)
	{
		this->color='r';
	}
	else
	{
		this->color='b';
	}
	this->faceUp=c.faceUp;
	this->top=c.top;

	return *this;

}


void PlayingCard::display(int x, int y)
{
	char ch;//=3,d=4,s=5,l=6;
	char ch1;
	if(this->suit==0)
		ch=4;
	else if (this->suit==1)
		ch=3;
	else if (this->suit==2)
		ch=5;
	else
		ch=6;
	//ch = this->suit+3;
	ConsoleFunctions C;
	C.SetCursorAt(x,y);
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(this->faceUp==true&&this->top==true)
			{
				if((j==0&&i==0)||(j==1&&i==0)||(j==4&&i==7)||(j==5&&i==7))//||(this->rank==10 && i==7 && j==3||j==4||j==5) )
				{
					if(this->color=='r')
					{
					
			
							C.SetColor(ConsoleColor::red,ConsoleColor::white);
						if(i==0&&j==0)
						{
							if(this->rank==1)
								cout<<"A";
							else if(this->rank==11)
								cout<<"J";
							else if(this->rank==12)
								cout<<"Q";
							else if(this->rank==13)
								cout<<"K";
							else
								cout << this->rank;
							cout << ch;
						}
						else if(i==7)
						{
							/*if(this->rank==10)
							{
								cout <<"10";
							}
							else
							{*/
							cout << ch;
							if(this->rank==1)
								cout<<"A";
							else if(this->rank==11)
								cout<<"J";
							else if(this->rank==12)
								cout<<"Q";
							else if(this->rank==13)
								cout<<"K";
							else
								cout << this->rank;
							//}
						
						}

					
					}
					else
					{
					
							C.SetColor(ConsoleColor::black,ConsoleColor::white);

						if(i==7)
						{
							/*if(this->rank==10)
							{
								cout <<"10";
							}
							else
							{*/
								cout << ch;
								if(this->rank==1)
									cout<<"A";
								else if(this->rank==11)
									cout<<"J";
								else if(this->rank==12)
									cout<<"Q";
								else if(this->rank==13)
									cout<<"K";
								else
									cout << this->rank;
							//}
						}
						else
						{
							if(this->rank==1)
								cout<<"A";
							else if(this->rank==11)
								cout<<"J";
							else if(this->rank==12)
								cout<<"Q";
							else if(this->rank==13)
								cout<<"K";
							else
								cout << this->rank;
							cout << ch;//this->suit;
						}
					
					}
					if(i==0&&rank==10||i==7&&this->rank==10)
					{
						j+=2;
					}
					else
					{
						j++;}
				
				}
				else
				{
					if(i==7&&j==3&&this->rank==10)
					{
						if(this->suit==0||this->suit==1)
						{
					
								C.SetColor(ConsoleColor::red , ConsoleColor :: white);
						}
						else
						{
								C.SetColor(ConsoleColor::black , ConsoleColor :: white);
						}
						//cout<<ch;
					}
					else
					{
						C.SetColor(ConsoleColor::white ,ConsoleColor:: white);
						cout << " ";
					}
				}
			}
			else if (this->faceUp==false&&this->top==true)
			{
				C.SetColor(ConsoleColor::red ,ConsoleColor:: red);
					cout << " ";
			}
			
		}
		y++;
		C.SetCursorAt(x , y);
	}
	if (this->faceUp==true&&this->top==false)
	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<6;j++)
			{
				if((j==0&&i==0)||(j==1&&i==0)||(j==4&&i==7)||(j==5&&i==7))//||(this->rank==10 && i==7 && j==3||j==4||j==5) )
				{
					if(this->color=='r')
					{
						C.SetColor(ConsoleColor::red,ConsoleColor::white);
						if(i==0&&j==0)
						{
							if(this->rank==1)
								cout<<"A";
							else if(this->rank==11)
								cout<<"J";
							else if(this->rank==12)
								cout<<"Q";
							else if(this->rank==13)
								cout<<"K";
							else
								cout << this->rank;
							cout << ch;
						}
						else if(i==7)
						{
							/*if(this->rank==10)
							{
								cout <<"10";
							}
							else
							{*/
							cout << ch;
							if(this->rank==1)
								cout<<"A";
							else if(this->rank==11)
								cout<<"J";
							else if(this->rank==12)
								cout<<"Q";
							else if(this->rank==13)
								cout<<"K";
							else
								cout << this->rank;
							//}
						
						}

					
					}
					else
					{
					
							C.SetColor(ConsoleColor::black,ConsoleColor::white);

						if(i==7)
						{
							/*if(this->rank==10)
							{
								cout <<"10";
							}
							else
							{*/
								cout << ch;
								if(this->rank==1)
									cout<<"A";
								else if(this->rank==11)
									cout<<"J";
								else if(this->rank==12)
									cout<<"Q";
								else if(this->rank==13)
									cout<<"K";
								else
									cout << this->rank;
							//}
						}
						else
						{
							if(this->rank==1)
								cout<<"A";
							else if(this->rank==11)
								cout<<"J";
							else if(this->rank==12)
								cout<<"Q";
							else if(this->rank==13)
								cout<<"K";
							else
								cout << this->rank;
							cout << ch;//this->suit;
						}
					
					}
					if(i==0&&rank==10||i==7&&this->rank==10)
					{
						j+=2;
					}
					else
					{
						j++;}
				
				}
				else
				{
					if(i==7&&j==3&&this->rank==10)
					{
						if(this->suit==0||this->suit==1)
						{
					
								C.SetColor(ConsoleColor::red , ConsoleColor :: white);
						}
						else
						{
								C.SetColor(ConsoleColor::black , ConsoleColor :: white);
						}
						//cout<<ch;
					}
					else
					{
						C.SetColor(ConsoleColor::white ,ConsoleColor:: white);
						if(i==1)
							cout<<"_";
						else
						    cout << " ";
					}
				}
			}
			y++;
		C.SetCursorAt(x , y);
		}
	}
	else if (this->faceUp==false&&this->top==false)
	{
		for(int i=0 ;i<2;i++)
		{
			for(int j=0;j<6;j++)
			{
				//C.SetColor(ConsoleColor::red ,ConsoleColor:: red);
				if(i==0)
				{
					C.SetColor(ConsoleColor::red ,ConsoleColor:: red);
					cout << " ";
				}
				else if (i==1)
				{
					C.SetColor(ConsoleColor::black ,ConsoleColor:: red);
					cout <<"_";
				}
			}
			y++;
		C.SetCursorAt(x , y);
		}
	}
	cout << endl;
	

}

int PlayingCard:: getSuit()
{
	return this->suit;
}
int PlayingCard :: getRank()
{
	return this->rank;
}


bool PlayingCard::isFaceUp() //retunrs value of faceUp
{

	return this->faceUp;
}
void PlayingCard::setFaceUp(bool f) //sets value of faceUp
{
	this->faceUp = f;

}
bool PlayingCard::isTop() //retunrs value of top
{
	return this->top;

}
void PlayingCard::setTop(bool f) //sets value of top
{
	this->top=f;
}


//int PlayingCard::getSuit(); //getter for suit value
//int PlayingCard::getRank(); //getter for rank value


char PlayingCard::getColor() //getter for color value
{
	return this->color;
}

PlayingCard::~PlayingCard(void)
{

}

const int PlayingCard :: Diamond = 0 ;
const int PlayingCard :: Heart = 1 ;
const int PlayingCard :: Spade = 2 ;
const int PlayingCard :: Club = 3 ;
