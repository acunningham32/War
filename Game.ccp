/*
  File: Game.cpp
  Author:  Jason Wichert, Andrew Cunningham, Amanada Vitale
  Course:  COMP 220, Computer Programming II
  Date:    22 September 2014
  Description:  This file provides the definition for the functions in the Game class.
*/

#include "Game.h"
#include "vector"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void Game::playCard(Deck &myDeck)
{
	//Check if either user is out of cards, if not, play the hand.
	if(myDeck.userHand.size() <= 0)
	{
		cout << "User is out of cards: Computer wins!" << endl;
		return;
	}
	else if(myDeck.compHand.size() <= 0)
	{
		cout << "Computer is out of cards: User wins!" << endl;
		return;
	}
	else
	{
		//take the cards from each vector and compare them.
		//userCard = userHand.at(0);	//what is userCard and compCard??? where is it defined?
		//compCard = compHand.at(0);
		//userHand.erase(0);
		//compHand.erase(0);

		//maybe instead of the code above??

		Card userCard = myDeck.userHand.at(0);	//do we need to make this i or will it always be 0?
		Card compCard = myDeck.compHand.at(0);
		myDeck.userHand.erase(myDeck.userHand.begin() + 0);
		myDeck.compHand.erase(myDeck.userHand.begin() + 0);
		
		//myDeck.compHand.erase(0);
		//not sure why dot operator is not working for erase, says an overload function is needed? 
		//tried to look up other functions that could be used instead of erase, couldn't find anything
		//thought it might be something with not being able to change userHand and compHand because of pass by reference?? 
		//erase function is working in war function
	
		if(userCard > compCard) //What is c_user and c_comp??? and where is .getValue() define? deleted : c_user.getValue() > c_comp.getValue() 
		{
			userAddCard(myDeck, userCard, compCard);
		}
		else if(tie(userCard, compCard))
		{
			war(myDeck, userCard, compCard);
		}
		else
		{
			compAddCard(myDeck, userCard, compCard);
		}
	}
	return;
}

bool Game::userWin(Card a, Card b)
{
	if ( a > b) //cannot be done without overloading >
	{
		return true;
		cout << "The user has won this round." << endl;
	}
	return false;
	cout << "The computer has won this round." << endl;
}

bool Game::tie(Card a, Card b)
{
	if (a == b) //cannot be done without overloading ==
	{
		return true;
		cout << "This round is a tie." << endl;
	}
}

void Game::userAddCard(Deck &myDeck, Card a, Card b)
{
	if (!warCards.size() == 0)
	{
		myDeck.userHand.push_back(a);
		myDeck.userHand.push_back(b);
		warCards.clear();
	}
}

void Game::compAddCard(Deck &myDeck, Card a, Card b)
{
	if (!warCards.size() == 0)
	{
		myDeck.compHand.push_back(a);
		myDeck.compHand.push_back(b);
		warCards.clear();
	}
}

void Game::war(Deck &myDeck, Card userCard, Card compCard)
{
	//Check if each user has at least 3 cards
	if ((myDeck.userHand.size() < 3) && (myDeck.userHand.size() < myDeck.compHand.size()))	//error: says myDeck is undefined again, not sure why
	{
		cout << "User is out of cards: Computer wins!" << endl;	
		return;
	}
	else if ((myDeck.compHand.size() < 3) && (myDeck.compHand.size() < myDeck.userHand.size()))	//maybe we should mke these 3's constants? 
	{
		cout << "Computer is out of cards: User wins!" << endl;
		return;
	}
	else if(myDeck.compHand.size() < 3 && myDeck.compHand.size() == myDeck.userHand.size())
	{
		cout << "You ran out of cards at the same time. It's a draw!" << endl;
	}
	else
	{
		warCards.push_back(userCard);
		warCards.push_back(compCard);
		for(int i = 0; i < 3; i++)
		{
			warCards.push_back(myDeck.userHand.at(0));
			myDeck.userHand.erase(myDeck.userHand.begin() + 0);
			//myDeck.userHand.erase(0);
			warCards.push_back(myDeck.compHand.at(0));
			myDeck.compHand.erase(myDeck.compHand.begin() + 0);
			//myDeck.compHand.erase(myDeck.compHand(0));
		}
		playCard(myDeck); 
	}
	return;
}

Game::Game(Deck d) {
	d = a;
}
