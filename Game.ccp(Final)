/*
  File: Game.cpp
  Author:  Jason Wichert, Andrew Cunningham, Amanada Vitale
  Course:  COMP 220, Computer Programming II
  Date:    22 September 2014
  Description:  This file provides the definition for the functions in the Game class.
*/

#include "Game.h"

using std::cout;
using std::cin;
using std::endl;

Game::Game() {}

Game::Game(Deck d)	{
	myDeck = d;
	
	for (int i = 0; i < d.userDeck.size(); i++)
	{
		userHand.push_back(d.userDeck.at(i));
	}

	for (int i = 0; i < d.compDeck.size(); i++)
	{
		compHand.push_back(d.compDeck.at(i));
	}
	gameOver = false;
}

void Game::playCard()
{
	cout << "You have " << userHand.size() << " cards left. The computer has " << compHand.size() << " cards left." << endl;

	//Check if either user is out of cards, if not, play the hand.
	if(userHand.size() <= 0)
	{
		cout << "User is out of cards: Computer wins!" << endl;
		gameOver = true;
		return;
	}
	else if(compHand.size() <= 0)
	{
		cout << "Computer is out of cards: User wins!" << endl;
		gameOver = true;
		return;
	}
	else
	{
		Card userCard = userHand.at(userHand.size()-1);
		Card compCard = compHand.at(compHand.size()-1);
		userHand.pop_back();
		compHand.pop_back();
		
		cout << "You have a: " << userCard.name() << " Computer has a : " << compCard.name() << endl;

		if(userCard.getValue() > compCard.getValue()) 
		{
			userAddCard(userCard, compCard);
		}
		else if(tie(userCard.getValue(), compCard.getValue()))
		{
			cout << "There is a war!" << endl;
			war(userCard, compCard);
		}
		else
		{
			compAddCard(userCard, compCard);
		}
	}
	return;
}

bool Game::userWin(Card a, Card b)
{
	if ( a > b) //cannot be done without overloading >
	{
		return true;
		cout << " You won." << endl;
	}
	return false;
	cout << " The computer won." << endl;
}

bool Game::tie(Card a, Card b)
{
	if (a == b) //cannot be done without overloading ==
	{
		return true;
	}
}

void Game::userAddCard(Card a, Card b)
{
	cout << "You won a " << a.name() << " and " << b.name() << endl; 

	userHand.push_back(a);
	userHand.push_back(b);

	if (warCards.size() > 0) {

		cout << "You also won the following cards: ";

		for(int i = 0; i < warCards.size(); i++) {

			cout << warCards.at(i).name() << ", ";

			userHand.push_back(warCards.at(i));
		}

		warCards.clear();
		cout << endl;
	}
}

void Game::compAddCard(Card a, Card b)
{
	cout << "The computer won a " << a.name() << " and " << b.name() << endl;
	compHand.push_back(a);
	compHand.push_back(b);

	if (warCards.size() > 0) {

		cout << "The computer also won the following cards: ";
		
		for(int i = 0; i < warCards.size(); i++) {
			
			cout << warCards.at(i).name() << ", ";
			
			compHand.push_back(warCards.at(i));
		}
	warCards.clear();
	cout << endl;
	}
}

void Game::war(Card userCard, Card compCard)
{
	//Check if each user has at least 3 cards
	if ((userHand.size() < 3) && (userHand.size() < compHand.size()))	//error: says myDeck is undefined again, not sure why
	{
		cout << "User is out of cards: Computer wins!" << endl;	
		gameOver = true;
		return;
	}
	else if ((compHand.size() < 3) && (compHand.size() < userHand.size()))	//maybe we should mke these 3's constants? 
	{
		cout << "Computer is out of cards: User wins!" << endl;
		gameOver = true;
		return;
	}
	else if(compHand.size() < 3 && compHand.size() == userHand.size())
	{
		cout << "You ran out of cards at the same time. It's a draw!" << endl;
		gameOver = true;
		return;
	}
	else
	{
		warCards.push_back(userCard);
		warCards.push_back(compCard);
		for(int i = 0; i < 3; i++)
		{
			warCards.push_back(userHand.at(userHand.size()-1));
			userHand.pop_back();
			warCards.push_back(compHand.at(compHand.size()-1));
			compHand.pop_back();
		}
		playCard(); 
	}
	return;
}
