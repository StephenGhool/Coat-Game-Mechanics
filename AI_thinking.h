#pragma once

#include<iostream>
#include<string>

class AI_thinking
{
public:
	AI_thinking();

	void print(int n) ;

	std::string AI(std::string playernum[], int pplplayed,std::string trump[], int highestnum,std::string cardsplayed[], std::string present[]) ;

	int winner( std::string played[], std::string pres[],std::string trump[] );

	std::string partner(int pplplayed,std::string cardplayed[]);

	int findposition(std::string card,std::string present[]);

	bool doihavetrump(std::string playernum[], std::string trump[]);

	int position(std::string card, std::string present[]);
	//void positioning(int rounds);

	bool trumpplayed(std::string card, std::string trump[]);

	int highorlow(std::string HL, std::string trump[], std::string playernum[], int opponentrank);
	
	 
	~AI_thinking();
};

