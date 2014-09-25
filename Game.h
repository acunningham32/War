/*
  File: Game.h
  Author:  Jessica Lewis
  Course:  COMP 220, Computer Programming II
  Date:    22 September 2014
  Description:  This file provides the definitions of the data types
				for the Game class. 
*/

#ifndef ___GAME_H
#define ___GAME_H

#include "Card.h"
#include "Deck.h"
#include <vector>
using std::vector;

class Game {
public:
	Game();
	Game(Deck d);
	void playCard();
	bool userWin(Card a, Card b);
	bool tie(Card a, Card b);
	void userAddCard(Card a, Card b);
	void compAddCard(Card a, Card b);
	void war(Card a, Card b);
	bool isGameOver() {return gameOver;}
private:
	vector<Card> warCards;
	vector<Card> userHand;
	vector<Card> compHand;
	Deck myDeck;
	bool gameOver;
	int userShuffleCounter;
	int compShuffleCounter;
};

#endif
