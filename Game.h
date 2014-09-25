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
	//Precondition: Called by a game object
	//Postcondition: plays out a round of war, also handles wars (ties)
	bool tie(Card a, Card b);
	//Precondition: Card a and Card b must be passed into it as card objects
	//Postcondition: returns true if it is a tie, false if it is not a tie
	void userAddCard(Card a, Card b);
	//Precondition: Card a and Card b must be card objects
	//Postcondition: adds a, b, and the warCards vector to the user's hand
	void compAddCard(Card a, Card b);
	//Precondition: Card a and Card b must be card objects
	//Postcondition: adds a, b, and the warCards vector to the computer's hand
	void war(Card a, Card b);
	//Precondition: called by playCard if tie() returns true, a and b must be card objects
	//Postcondition: plays out a war (3 cards from each player, playCard() for the 4th card
	bool isGameOver() {return gameOver;}
	//Preconditon: called outside of Game
	//Postcondition: returns the value of gameOver
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
