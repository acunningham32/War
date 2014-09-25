// Program2.cpp : Defines the entry point for the console application.
/*Authors: Andrew Cunningham, Jessica Lewis, Jason Wichert, Amanda Vitale
Course: COMP 220, Computer Programming II
Date: 22 September 2014
Purpose: The purpose of this code is to play the card game War between one player and the computer*/

#include <iostream>
#include <vector>
#include <ctime>

#include "Card.h"
#include "Deck.h"
#include "Game.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	srand(time(0));

	cout << "Hello, Welcome to our game of War!" << endl << "The rules of War are as follows:" << endl <<
		"This is a two player game in which you will play against the computer." << endl << 
		"You will be dealt 26 cards.  The goal of the game is to win all the cards." << endl <<
		"Both players will turn over the top card in their deck." << endl <<
		"The player with the higher of the two cards wins both of those cards." << endl <<
		"If the cards are of equal value, a war occurs." << endl <<
		"Both players will then flip three cards face down, and then one face up." << endl <<
		"The player with the higher of the two face up cards wins all 10 cards." << endl <<
		"If the new cards are equal as well, another war will occur." << endl <<
		"The player to run out of cards first loses." << endl <<
		"-----------" << endl <<
		"Type 'r' to play the next round, or type 'g' to play the rest of the War game" << endl;
		
	char playAgain = 'Y';

	while ((playAgain == 'Y') || (playAgain == 'y'))
	{
		Deck newDeck;

		newDeck.makeDeck();

		Game g(newDeck);

		char play = ' ';
		do{
			cin >> play;
			if(play == 'r')
			{
				g.playCard();
			}
			else if(play == 'g')
			{
				do {
					g.playCard();
				} while (!g.isGameOver());
				break;
			}
			else
			{
				cout << "Please enter an 'r' or a 'g'" << endl;
			}
		}while(!g.isGameOver());
		cout << "Do you want to play again? Type Y or N" << endl;
		cin >> playAgain;
	}

	cout << "Thanks for playing War!" << endl;

	return 0;
}
