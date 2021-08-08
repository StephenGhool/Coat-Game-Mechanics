#include "AI_thinking.h"
#include<stdlib.h>
#include<time.h>



AI_thinking::AI_thinking()
{
	 std::cout << "\n\nAI uploaded" << std::endl; 
}

void AI_thinking::print(int n)
{
	std::cout << "And Finally johan gay\n";
}

//this functions demonstrates what card the AI wil choose to play
std::string AI_thinking::AI(std::string playernum[], int pplplayed, std::string trump[], int highestcard, std::string cardplayed[], std::string present[])
{
	std::string playing[4];
	int cardsplayed = 1;

	//have to be upgraded to not play trump
	if (pplplayed == 0)
	{
		//sets highest card played to zero for each round
		//pointers may be needed since we are changing the value of a variable in a function

		highestcard = 0;
		srand(time(NULL));
		int i = rand() % 12;
		for (int j = 0; j < 13; j++)
		{
			if (playernum[i] != "void")
			{
				cardplayed[0] = playernum[i]; //allocates the first card played to this array
				playernum[i] = 'void';
				return cardplayed[0];
			}

			if (j == 12) { j = 0; i = rand() % 12; }
		}

		return 0;

		return 0;
	}

	if (pplplayed == 1)
	{
		std::cout << "\nentered pplplayed==1\n";
		//find opponent card in the present suit 
		int opponentrank = findposition(cardplayed[0], present);
		bool highercard = false;

		//does player have present suit

		//the doihave trump function is used to check if the player has the present suit
		if (doihavetrump(playernum, present))
		{
			//opponent plays trump 
			if (trumpplayed(cardplayed[0], trump) == true)
			{
				//then the player should play the lowest present suit they have

				//13 is included as the opponent's rank because they are playing trump which is not in the present suit.... 
				//rank 13 is equivalent for trump being played 
				int temp = highorlow("low", present, playernum, 13);
				cardplayed[1] = playernum[temp];
				playernum[temp] = "void";

				//highercard bool set as true
				highercard = true;
				return cardplayed[1];
			}

			//opponet plays present suit
			if (trumpplayed(cardplayed[0], present) == true)
			
			{
				//player should play higher if they could
				int temp = highorlow("high", present, playernum, opponentrank);

				//means player does not have higher
				if (temp == 20)
				{
					int temp = highorlow("low", present, playernum, 13);
					cardplayed[1] = playernum[temp];
					playernum[temp] = "void";
					highercard = true;
					return cardplayed[1];
				}

				//player could play higher
				if (temp != 20)
				{

					cardplayed[2] = playernum[temp];
					playernum[temp] = "void";
					highercard = true;
					return cardplayed[2];
				}
			}

			//in the case the opponent plays something other than trump and present suit
			else
			{
				//just play the present suit
				for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 13; j++)
					{
						if (playernum[i] == present[j] && playernum[i] != "void")
						{
							cardplayed[1] = playernum[i]; //allocates the card played to this array
							playernum[i] = "void";
							return cardplayed[1];
						}
					}
				}
			}
		}


		//does player have trump
		if (doihavetrump(playernum, trump))
		{
			//if this loop is entered, the player does not have the present suit

			//opponent plays trump
			if (trumpplayed(cardplayed[0], trump) == true)
			{
				opponentrank = position(cardplayed[0], trump);

				//could the player play a higher trump
				//player should play higher if they could
				int temp = highorlow("high", trump, playernum, opponentrank);

				//means player does not have higher
				if (temp == 20)
				{
					int temp = highorlow("low", trump, playernum, 13);
					cardplayed[1] = playernum[temp];
					playernum[temp] = "void";
				
					return cardplayed[1];
				}

				//player could play higher
				if (temp != 20)
				{
					cardplayed[1] = playernum[temp];
					playernum[temp] = "void";
					
					return cardplayed[1];
				}
			}

			//if opponent does not play trump....player low trump
			else
			{
				//this variation to the function does not take into consideration the opponentrank....it just plays the lowest
				//trump in the array
				int temp = highorlow("low", trump, playernum, 0);
				cardplayed[1] = playernum[temp];
				playernum[temp] = "void";
				
				return cardplayed[1];
			}
		}

		//no trump or present suit then play random card
		int i = rand() % 12;
		for (int j = 0; j < 13; j++)
		{
			if (playernum[i] != "void")
			{
				cardplayed[1] = playernum[i]; //allocates the card played to this array
				playernum[i] = 'void';
				bool output = true;
				return cardplayed[1];
			}

			if (j == 12) { j = 0; i = rand() % 12; }
		}


		//if player has the suit called then cant play trump
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				//card is not trump and is the present suit
				if (playernum[i] != trump[j] && playernum[i] == present[j])
				{
					//set this value because if the loop to assign cardsplayed[1] is not entered the AI will know 
					cardplayed[1] = 100;

					//compares card under investigation. It evaluates whether or not it is higher than the previous player
					if (findposition(playernum[i], present) > findposition(cardplayed[0], present))
					{
						highercard = true;
						cardplayed[1] = playernum[i]; //allocates the first card played to this array
						playernum[i] = "void";
						return cardplayed[1];
					}

					if (highercard == false && i == 12)
					{
						for (int i = 0; i < 13; i++)
						{
							for (int j = 0; j < 13; j++)
							{
								if (playernum[i] == present[j] && playernum[i] != "void")
								{
									cardplayed[1] = playernum[i]; //allocates the first card played to this array
									playernum[i] = "void";
									return cardplayed[1];
								}
							}
						}
					}

				}

				//this is the condition that the present suit is trump
				if (doihavetrump(present, trump) == true)
				{
					for (int i = 0; i < 13; i++)
					{
						for (int j = 0; j < 13; j++)
						{
							if (playernum[i] == present[j])
							{
								cardplayed[1] = playernum[i]; //allocates the first card played to this array
								playernum[i] = 'void';
								return cardplayed[1];
							}
						}
					}
				}

				//choose a low trump to play
				if (cardplayed[1] == "100" && i == 12)
				{
					//play lowest trump 
					int min = 100;
					for (int i = 0; i < 13; i++)
					{
						for (int j = 0; j < 13; j++)
						{
							if (playernum[i] == trump[j])
							{
								if ((findposition(playernum[i], present) < min))
								{
									cardplayed[1] = playernum[i];
								}
							}
						}
					}
					return cardplayed[1];
				}
			}
		}

	}

	if (pplplayed == 2)
	{
		bool output = false;
		std::cout << "\nentered pplplayed==2\n";
		std::string partnercard = partner(pplplayed, cardplayed);

		//if partner wins
		if (winner(cardplayed, present, trump) == 0)
		{
			//does player have present suit
			if (doihavetrump(playernum, present))
			{
				//play the lowest card
				int temp = highorlow("low", present, playernum, 13);
				cardplayed[2] = playernum[temp];
				playernum[temp] = "void";
				bool output = true;
				return cardplayed[2];
			}

			//does not have present suit
			else
			{
				int i = rand() % 12;
				for (int j = 0; j < 13; j++)
				{
					if (playernum[i] != "void")
					{
						cardplayed[2] = playernum[i]; //allocates the card played to this array
						playernum[i] = 'void';
						bool output = true;
						return cardplayed[2];
					}

					if (j == 12) { j = 0; i = rand() % 12; }
				}
			
			}

		}

		//if partner does not win
		if (winner(cardplayed, present, trump) != 0)
		{
			//determine if there is a higher card to be played
			int partnerrank = position(partnercard, present);
			int opponentrank = position(cardplayed[1], present);

			//means the opponent did not play the present suit
			if (opponentrank==420)
			{
				opponentrank = 0;

			}


		//does the player have the present suit
			if (doihavetrump(playernum, present))
			{
				//opponent plays trump
				if (trumpplayed(cardplayed[1], trump) == true)
				{
					//13 is included as the opponent's rank because they are playing trump which is not in the present suit.... 
					//rank 13 is equivalent for trump being played 
					int temp = highorlow("low", present, playernum, 13); 
					cardplayed[2]=playernum[temp];
					playernum[temp] = "void";
					bool output = true;
					return cardplayed[2];
				}
			
				//opponent does not play trump
				if(trumpplayed(cardplayed[1], present) == true)
				{
					//player should play higher if they could
					int temp = highorlow("high", present, playernum, opponentrank);

					//means player does not have higher
					if (temp==20)
					{
						int temp = highorlow("low", present, playernum, 13);
						cardplayed[2] = playernum[temp];
						playernum[temp] = "void";
						bool output = true;
						return cardplayed[2];
					}

					//player could play higher
					if (temp!=20)
					{
						cardplayed[2] = playernum[temp];
						playernum[temp] = "void";
						bool output = true;
						return cardplayed[2];
					}
									
				}

				//if the opponent does not play trump or present suit
				//just play the present suit
				for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 13; j++)
					{
						if (playernum[i] == present[j] && playernum[i] != "void")
						{
							cardplayed[2] = playernum[i]; //allocates the card played to this array
							playernum[i] = "void";
							return cardplayed[2];
						}
					}
				}

			}

		// does the player have trump
			if (doihavetrump(playernum, trump))
			{
				//the opponent played trump
				if (trumpplayed(cardplayed[1], trump) == true)
				{
					opponentrank = position(cardplayed[1], trump);

					//could the player play a higher trump
					//player should play higher if they could
					int temp = highorlow("high", trump, playernum, opponentrank);

					//means player does not have higher
					if (temp == 20)
					{
						int temp = highorlow("low", trump, playernum, 13);
						cardplayed[2] = playernum[temp];
						playernum[temp] = "void";
						bool output = true;
						return cardplayed[2];
					}

					//player could play higher
					if (temp != 20)
					{
						cardplayed[2] = playernum[temp];
						playernum[temp] = "void";
						bool output = true;
						return cardplayed[2];
					}
				}

				//the opponent didnt play trump...they played present suit or a different suit
				else
				{
					//this variation to the function does not take into consideration the opponentrank....it just plays the lowes
					//trump in the array
					int temp = highorlow("low", trump, playernum,opponentrank);
					cardplayed[2] = playernum[temp];
					playernum[temp] = "void";
					bool output = true;
					return cardplayed[2];
				}
			}

		//player doesnot have trump and present suit

			if (output == false)
			{
				int i = rand() % 12;
				for (int j = 0; j < 13; j++)
				{
					if (playernum[i] != "void")
					{
						cardplayed[2] = playernum[i]; //allocates the card played to this array
						playernum[i] = 'void';
						bool output = true;
						return cardplayed[2];
					}

					if (j == 12) { j = 0; i = rand() % 12; }
				}
			}
	
		}

	}

	if (pplplayed == 3)
	{
		std::cout << "\nentered pplplayed==3\n";
		std::string partnercard = partner(pplplayed, cardplayed);

		//if partner does not win
		//two opppoents
		if (winner(cardplayed, present, trump) != 1)
		{
			//determine if there is a higher card to be played
			int partnerrank = position(cardplayed[1], present);
			int opponentrank = position(cardplayed[0], present);
			int opponentrank2 = position(cardplayed[2], present);
			int opprank = 0;

			//determines which opponent has the higher card
			if (opponentrank2 > opponentrank)
			{
				opprank = opponentrank2;
			}
			else
			{
				opprank = opponentrank;
			}


			//does player have this suit, if yes is it higher?

					//has the present suit and it is higher than present highest

		    //doihavetrump function is reused to determine if the player has the present suit
			if (doihavetrump(playernum, present))
			{
				//did any of the opponent play trump??
				if (trumpplayed(cardplayed[0], trump) == true || trumpplayed(cardplayed[2], trump) == true)
				{
					//then player will have to play the present suit

					//function used to play low present suit
					int temp = highorlow("low", present, playernum, 13);
					cardplayed[3] = playernum[temp];
					playernum[temp] = "void";
					bool output = true;
					return cardplayed[3];
				}

				if (trumpplayed(cardplayed[0], present) == true || trumpplayed(cardplayed[2], present) == true)
				{
					//player should play higher if they could
					int temp = highorlow("high", present, playernum, opprank);

					//means player does not have higher
					if (temp == 20)
					{
						int temp = highorlow("low", present, playernum, 13);
						cardplayed[3] = playernum[temp];
						playernum[temp] = "void";
						return cardplayed[3];
					}

					//player could play higher
					if (temp != 20)
					{
						cardplayed[3] = playernum[temp];
						playernum[temp] = "void";

						return cardplayed[3];
					}

				}

				//if the opponents did not play the present suit as well as trump
				else
				{
					//just a high present suit
					int temp = highorlow("high", present, playernum, -1);
					cardplayed[3] = playernum[temp];
					playernum[temp] = "void";
					
					return cardplayed[3];
				}

			}

			//player has trump
			if (doihavetrump(playernum, trump))
			{
				//is the trump higher than the opponents trump
				if (trumpplayed(cardplayed[0], trump) == true || trumpplayed(cardplayed[2], trump) == true)
				{
					//finds opponent rank in the trump suit
					opponentrank = position(cardplayed[0], trump);
					opponentrank2 = position(cardplayed[2], trump);
					opprank = 0;

					if (opponentrank2 > opponentrank)
					{
						opprank = opponentrank2;
					}
					else
					{
						opprank = opponentrank;
					}

					//player should play higher if they could
					int temp = highorlow("high", trump, playernum, opprank);

					//means player does not have higher
					if (temp == 20)
					{
						int temp = highorlow("low", trump, playernum, 13);
						cardplayed[3] = playernum[temp];
						playernum[temp] = "void";
						return cardplayed[3];
					}

					//player could play higher
					if (temp != 20)
					{
						cardplayed[3] = playernum[temp];
						playernum[temp] = "void";

						return cardplayed[3];
					}

				}

				//the opponents have played present suit
				if (trumpplayed(cardplayed[0], present) == true || trumpplayed(cardplayed[2], present) == true)
				{
					//just a high trump suit
					int temp = highorlow("high", present, playernum, -1);
					cardplayed[3] = playernum[temp];
					playernum[temp] = "void";

					return cardplayed[3];
				}

				//opponents did not play trump or present suit
				else
				{
					for (int i = 0; i < 13; i++)
					{
						for (int j = 0; j < 13; j++)
						{
							if (playernum[i] == trump[j])
							{
								cardplayed[3] = playernum[i];
								playernum[i] = "void";
								return cardplayed[3];
							}
						}
					}
				}

			}

			//player does not have trump or present suit
			int i = rand() % 12;
			for (int j = 0; j < 13; j++)
			{
				if (playernum[i] != "void")
				{
					cardplayed[0] = playernum[i]; //allocates the first card played to this array
					playernum[i] = 'void';
					return cardplayed[0];
				}

				if (j == 12) { j = 0; i = rand() % 12; }
			}

		}


		//condition for if the partner is winning
		else
		{
			bool hassuit = false;
			bool hastrump = false;
			int lowest = 15; int card_index = 0; int count = 0;

			//does player have the present suit
			if (doihavetrump(playernum, present))
			{		
				int temp = highorlow("low", present, playernum, 0);
				cardplayed[3] = playernum[temp];
				playernum[temp] = "void";
				bool output = true;
				return cardplayed[3];
		
			}
			//just play a random lowest card
			else
			{
				for (int i = 0; i < 13; i++)
				{
					if (playernum[i] != "void")
					{
						cardplayed[3] = playernum[i];
						playernum[i] = "void";
						return cardplayed[3];
					}
				}
			}
			
			

			
					
				

			

		}


	}



}



int AI_thinking::highorlow(std::string HL, std::string suit[], std::string playernum[], int opponentrank)
{
	int low,high,temp=0, temp2 = 15;
	if (HL == "low")
	{
		for (int i = 0; i < 13; i++)
		{
			//finds the lowest card in player array( based on the suit array in the parameter)
			temp = findposition(playernum[i], suit);
			if (temp<temp2)
			{
				temp2=temp;
			}
		}
		return temp2;
	}

	if (HL == "high")
	{
		for (int i = 0; i <13 ; i++)
		{
			temp = findposition(playernum[i], suit);
			if (temp > opponentrank)
			{
				return i;
			}
		}
	}
	
	//returns this if the function does not find a card higher than the opponent card
	return 20;
}

//finds the position of the card in present suit array
int AI_thinking:: findposition(std::string card,std::string present[])
{
	int position = 0;
	for (int i = 0; i < 13; i++)
	{
		if (card==present[i])
		{
			position = i;
			
		}
	}
	return position;
}

//finds the position of a card 
int AI_thinking:: position(std::string card, std::string present[])
{
	int Position = 0;
	
	for (int j = 0; j < 13; j++)
	{
		if (card == present[j])
		{
			Position = j;
			return Position;
		}
	}
	return 420;
}


std::string AI_thinking:: partner(int pplplayed, std::string cardplayed[])
{
	//if(highestcard)
	//for player 3 the partner is player 1 and for player 4, it player 2
	return cardplayed[pplplayed - 2];
}

bool AI_thinking:: doihavetrump(std::string playernum[], std::string trump[])
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (playernum[i]==trump[j])
			{
				return true;
			}
		}
	}
}
 
int AI_thinking:: winner( std::string played[], std::string pres[] ,std::string trump[])
{
	int winner = 0;
	int nextplayer = 0;
	int trumpwinner = -1;//set to this value since the first player can play trump
	int trumpplayed = 0;//so this varible is need to determine if trump is played so automatically the highest trump played will win

	for (int j = 0; j < 4; j++)
	{
		for (int t = 0; t < 13; t++)
		{
			//since the trump is stored in ascending order the high t value will win
			if (played[j]==trump[t])
			{
				if (t>trumpwinner)
				{
					trumpwinner = t;
					nextplayer = j;
					trumpplayed++;

				}
			}

			if (played[j] != trump[t] && trumpplayed==0)
			{
				for (int i = 0; i < 13; i++)
				{
					//this compares the jth card played to the present suit
					if (played[j] == pres[i])
					{
						if (i > winner)
						{
							winner = i;
							nextplayer = j;
						}
					}
				}
			}
		}
	}
	return nextplayer;
}


//determines if trump is played 
bool AI_thinking::trumpplayed(std::string card, std::string trump[])
{
	for (int i = 0; i < 13; i++)
	{
		if (card == trump[i])
		{
			return true;
		}
	}
	return false;
}



/*
int AI_thinking::positioning(int rounds)
{
	if (rounds == 0)
	{
		//AI(player1)
	}
}
*/

AI_thinking::~AI_thinking()
{
}
