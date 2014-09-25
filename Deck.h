/*
  File: Deck.h
  Author:  Jessica Lewis and Andrew Cunningham
  Course:  COMP 220, Computer Programming II
  Date:    22 September 2014
  Description:  This file provides the definition of the data types
				for the Deck class.
*/

#ifndef ___DECK_H
#define ___DECK_H

#include "Card.h"

#include <vector>
using std::vector;

class Deck {
public:
	friend class Game;	//make game a friend class to deck allowing game to see functions and variables in deck
	Deck();
	void makeDeck();
	//Precondition: Must be called by a deck object
	//Postcondition: fills a deck object with 52 unique cards.
	void dealDeck();
	//Precondition: must be called
	//Postcondition: splits the 52 card deck into 2 26 card decks for each player
	vector <Card> deck;
	vector <Card> userDeck;
	vector <Card> compDeck;
};
#endif
