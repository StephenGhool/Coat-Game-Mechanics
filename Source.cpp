#include"AI_thinking.h"
#include "randomizedeck.h"
#include"gamesetup.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>


//things to be done
//create a lift function for each team to determine who wins 
//fix the AI so that it does not play void
//create a loop so that user will only be able to choose numbers, otherwise bounce and tell them choose again
//fix player3

std::string dealt; 

std::string player1[13];
std::string player2[13];
std::string player3[13];
std::string player4[13];

//used to store the present suit
std::string present[13];

//stores the suit that is trump
std::string trump[13];
//what johan did



std::string suit[4][13];  //stores the suits 

std::string shuffleddeck[4][13];
//std::string player[4]; //stores the players cards i.e random value cards......need code from JOHAN 



//idt we really need this
class cards
{
private:
	std::string  deck[13][4];

public:
	cards() {};

	void random(int n)
	{
		int x = 0; int prev = 0;
		srand(time(NULL));

		for (int j = 0; j < 13; j++)
		{
			x = rand() % 52;
			for (int i = 0; i < 52; i++)
			{

				if (x == dealt[i])
				{
					x = rand() % 52;
				}

				if (x != dealt[i])
				{
					dealt[j + n] = x;
				}

			}

			if (n == 0)
			{
				player1[j] = x;
			}
			if (n == 13)
			{
				player2[j] = x;
			}
			if (n == 26)
			{
				player3[j] = x;
			}
			if (n == 39)
			{
				player4[j] = x;
			}

		}
	}

	int check(int a[],int n, int b)
	{
		//i changed things around in this function... so look at the one on the group if needed
		for (size_t i = 0; i < 4; i++)
		{
			if (a[i] == b)
			{
				a[i] = rand() % 52;
			}
		}
	}

	void print(std::string a, int n)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << a[i] << " ";
		}
		std::cout << "\n";
	}

	void randomdeck()
	{
		int x = 0; char temp;
		srand(time(NULL));


		for (int i = 0; i < 52; i++)
		{
			int x = rand() % 52;

			for (int j = 0; j < i; j++)
			{
				temp = char(dealt[j]);

				if (temp == char('x'))
				{
					x = rand() % 52;
					j = -1;
				}
			}

			dealt[i] = char(x);
		}
	}

	void random2(std::string a, int n)
	{


		for (int i = 0; i < 14; i++)
		{
			a[i] = dealt[n + i];

		}
	}

};



//presentsuit function
/*
void presentsuit(std::string firstcard[])//determines the suit played by the first player for a round
{
	//the code compares the first card played to the various suits to determine the suit.
	//2D string arrays are utilized to store the suits

	// string used to store the 12 cards of the present suit

	/*
	suit[0]=spades
	suit[1]=clubs
	suit[2]=hearts
	suit[3]=diamonds
	
	std::string card = firstcard[0];
	char findsuit = card[1];
	for (int j = 0; j < 4; j++)//moves through the differnt suits
	{

		for (int i = 0; i < 13; i++)//traverses through each suit
		{
			if (card == suit[j][i])// comparing against each suit until it finds the suit being played
			{
				for (int a = 0; a < 13; a++)
				{
					present[a] = suit[j][a];
				}
			}
		}
	}
	return ;
}
*/

std::string clubs;
std::string spades;
std::string hearts;
std::string diamonds;




//this functions allows the user to see the cards they have and then are to choose one
void userinput(int pplplayed,std::string present[], std::string cardsplayed[])
{
	//the user's cards was allocated player[4] in the string array
	//comparing the user's card to the present suit


	int choice = 0;

	//display cards
	std::cout << "\n\nThe following are your cards choose a number to select one\n";
	for (int i = 0; i < 13; i++)
	{
		std::cout << i+1 <<"  - " <<player4[i] <<" \n";// player4 array has the user cards
	}

		//choose any card to play
		//std::cout << "Select a number betweeb 1 to 13 to choose a card to be played";
		std::cin >> choice;
		std::cout << "\nCard choosen to be played is: " << player4[choice-1] << std::endl;
		cardsplayed[pplplayed] = player4[choice - 1];
		player4[choice - 1] = "void";
	
}



//creating the deck 
/*
void unshuffleddeck()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 2; j <= 14; j++)
		{
			randomizedeck deck(i, j);
			suit[i-1][j-2] = deck.value();
		}
	}
	return;
}
*/


//randomly assigned array
int randomarr[52]{ 34, 5, 10, 41, 47, 46, 25, 1, 44, 17, 18, 27, 3, 20, 19, 6, 29, 50, 51, 13, 22, 40, 39, 49, 28, 36, 24, 12, 37, 9, 45, 26, 30, 0, 8, 15, 35, 21, 33, 43, 4, 14, 16, 38, 23, 11, 7, 42, 31, 2, 32, 48 };

int arr[52];
/*
void randomnumbers()
{
	srand(52);
	for (int i = 0; i < 52; i++)
	{
		arr[i] = (rand() % 52);
	}


	for (int i = 0; i < 52; i++)
	{
		std::cout<< arr[i] << " ";
	}

	//this for loop is to ensure the function randomizes only one number
	for (int i = 0; i < count; i++)
	{
		if (temp == arr[i])
		{
			temp = (rand() % 50) + 1;
			changed++;
			i = -1;
		}

		if (i == (count - 1) && changed == 0)
		{
			arr[count] = temp;
		}

	}
	count++;

}
*/


//shuffles the cards
void shuffle() 
{
		srand(time(NULL));

		int temp = 0; int count = 0, changed=0;  //to store the rand value so that we can compare the new generated value to ensure ot was not store as yet.
		for (int i = 0; i < 4; i++)
		{
			
			for (int j = 0; j < 13; j++)
			{
				
				temp = randomarr[count];
				count++;
			
				if (temp < 13)//first suit ranges from index i=0 to i=12 @ j=0
				{
					shuffleddeck[i][j] = suit[0][temp];
				}

				if (temp > 12 && temp < 26)//first suit ranges from index i=0 to i=12 @ j=0
				{
					shuffleddeck[i][j] = suit[1][temp-13];

				}

				if (temp > 25 && temp < 39)//first suit ranges from index i=0 to i=12 @ j=0
				{
					shuffleddeck[i][j] = suit[2][temp-26];

				}

				if (temp > 38 && temp < 52)//first suit ranges from index i=0 to i=12 @ j=0
				{
					shuffleddeck[i][j] = suit[3][temp-39];

				}
			}
		}
}


//printing of shuffled and unshuffled cards
void printcards(std::string a)
{
	//double for loop to print the 2d array
	for (int i = 0; i < 4; i++)
	{
		if (a == "suit")
		{
			for (int j = 0; j < 13; j++)
			{

				std::cout << suit[i][j] << " ";
			}
			std::cout << "\n";
		}

		if (a=="shuffled")
		{
			for (int j = 0; j < 13; j++)
			{

				std::cout << shuffleddeck[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}

//determines the winning team
void wteam(int lift1, int lift2)
{
	if (lift1>lift2)
	{
		std::cout << "\n\nThe winner is team 1\n";
	}
	else
	{
		std::cout << "\n\nThe winner is team 2\n";
	}
}

//determines when to increment each team's lift
void increment(int *lift1, int *lift2, int winner)
{
	if (winner==0||winner==2)
	{
		lift1++;
	}
	else
	{
		lift2++;
	}
}

//assigning the cards to players
void playercardassignment(std::string a[],int playernum)
{
	for (int i = 0; i < 13; i++)
	{
		a[i] = shuffleddeck[playernum][i];
	}
}

//populates the trump array with the chosen suit
void choosetrump()
{
	int atrump = 0;

	std::cout << "\n\nPlease choose trump\n";
	std::cout << "HEARTS - 0\n";
	std::cout << "DIAMONDS - 1\n";
	std::cout << "CLUBS - 2\n";
	std::cout << "SPADES- 3\n";
	std::cout << "Trump: ";
	std::cin >> atrump;

	if (atrump == 0)
	{
		for (int i = 0; i < 13; i++)
		{
			trump[i] = suit[0][i]; //sets trump as spades
			std::cout << trump;
		}
	}

	if (atrump == 1)
	{
		for (int i = 0; i < 13; i++)
		{
			trump[i] = suit[1][i]; //sets trump as spades
			std::cout << trump;
		}
	}

	if (atrump == 2)
	{
		for (int i = 0; i < 13; i++)
		{
			trump[i] = suit[2][i]; //sets trump as spades
			std::cout << trump;
		}
	}

	if (atrump == 3)
	{
		for (int i = 0; i < 13; i++)
		{
			trump[i] = suit[3][i]; //sets trump as spades
			std::cout << trump;
		}
	}

}

//shows the cards that the user can play
void userchoice()
{

}

int main()
{
	int rounds = 0, totalcardsplayed = 0;  int currentwinner = 0;
	std::string playedcard[4]; std::string cardsplayed[4]; int highestindex = 0, lift = 0;
	char hold;
	int lift1 = 0, lift2 = 0;

	AI_thinking a;
	gamesetup set;

	//suit[number_of_cards_in_suit][suit]
	//suit[0][0] ={"2" };//spades
	//suit[1][0] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };//clubs
	//suit[2][0] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };//hearts
	//suit[3][0] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };//diamonds
	
	
	cards randomizecard;

	//displaying the deck
	set.unshuffleddeck(suit);
	std::cout << "The following is all the cards in the pack\n";
	printcards("suit");


	std::cout << "\n\n";
	shuffle();
	printcards("shuffled");

	//assigment of cards to  players array

	playercardassignment(player1, 0);
	playercardassignment(player2, 1);
	playercardassignment(player3, 2);
	playercardassignment(player4, 3);

	for (int i = 0; i < 13; i++)
	{
		std::cout << player4[i];

	}
	//randomizecard.randomdeck();//throwing an error check this function
	
	//randomizecard.random2(player1, 0);
	
	//randomizedeck rdeck(4,52);

	choosetrump();

	//instantiate classes
	


	while ((lift1+lift2) != 7)
	{
		
			if (currentwinner==0)
			{
				//player[currentwinner] is used so that the code would be generalized and as fair as possible i.e. ensuring the AI does not mix up the cards
				
				playedcard[0] = a.AI(player1, 0, trump, highestindex, cardsplayed, present);
				std::cout <<"\n player "<<currentwinner+1<<" card :"<< playedcard[0]<<" ";

				
				set.presentsuit(playedcard, suit, present);

				playedcard[1] = a.AI(player2, 1, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner+2 << " card :" << playedcard[1] << " ";

				playedcard[2] = a.AI(player3, 2, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner +3<< " card :" << playedcard[2] << " ";

				//user players here
				userinput(3,present,playedcard);
				
				currentwinner=a.winner(playedcard,present,trump);// we will compare the cards playered with the present suit array to determine the winner i.e. card with
										 // highest index in the array wins.

				std::cout << "\nThe current winner is player: " << currentwinner+1 << std::endl;
				lift++;
				increment(&lift1, &lift2, currentwinner);
				wteam(lift1, lift2);
				//a.AI(player2, 1, trump);
				//a.AI(player3, 2, trump);
				
			
			}


			if (currentwinner==1)
			{

				//player 1
				playedcard[0] = a.AI(player2, 0, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner+1  << " card :" << playedcard[0] << " ";

				//present suit
				set.presentsuit(playedcard, suit, present);

				//player 2
				playedcard[1] = a.AI(player3, 1, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner + 2 << " card :" << playedcard[1] << " ";

				//user players here
				//player 3
				userinput(2, present, playedcard);

				//player 4
				playedcard[3] = a.AI(player1, 3, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner  << " card :" << playedcard[3] << " ";

				

				currentwinner = a.winner(playedcard, present, trump);// we will compare the cards playered with the present suit array to determine the winner i.e. card with
																	 // highest index in the array wins.

				std::cout << "The current winner is player: " << currentwinner + 1 << std::endl;
				lift++;

		
			}

			if (currentwinner == 2)
			{
				
				
				//player1
				playedcard[0] = a.AI(player3, 0, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner+1 << " card :" << playedcard[0] << " ";
				
				//present suit determination
				set.presentsuit(playedcard, suit, present);

				//user players here:
				//player 2
				userinput(1, present, playedcard);

				//player 3
				playedcard[2] = a.AI(player1, 2, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner-1 << " card :" << playedcard[2] << " ";

				
				//player 4
				playedcard[2] = a.AI(player2, 3, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner  << " card :" << playedcard[2] << " ";



				currentwinner = a.winner(playedcard, present, trump);// we will compare the cards playered with the present suit array to determine the winner i.e. card with
																	 // highest index in the array wins.

				std::cout << "\nThe current winner is player: " << currentwinner + 1 << std::endl;
				lift++;

		
			}
			
			if (currentwinner == 3)
			{

				
				//user players here: 
				//player 1
				userinput(0, present, playedcard);
				set.presentsuit(playedcard, suit, present);

				//player2
				playedcard[1] = a.AI(player1, 1, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner -2 << " card :" << playedcard[1] << " ";
				


				//player 3
				playedcard[2] = a.AI(player2, 2, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner -1 << " card :" << playedcard[2] << " ";


				//player 4
				playedcard[3] = a.AI(player3, 3, trump, highestindex, cardsplayed, present);
				std::cout << "\n player " << currentwinner  << " card :" << playedcard[3] << " ";



				currentwinner = a.winner(playedcard, present, trump);// we will compare the cards playered with the present suit array to determine the winner i.e. card with
																	 // highest index in the array wins.

				std::cout << "\nThe current winner is player: " << currentwinner + 1 << std::endl;
				lift++;


			}
			rounds++;
		
	}

	system("pause");
	return 0;
}