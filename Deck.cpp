/*
  File: Deck.h
  Author:  Andrew Cunningham, Jessica Lewis
  Course:  COMP 220, Computer Programming II
  Date:    22 September 2014
  Description:  This file provides the definition of the data types
				for the Deck class.
*/

#include "Deck.h"

using std::cout;
using std::cin;
using std::endl;

Deck::Deck() // The default constructor creates the deck vector made of Card objects
{
	vector <Card> deck;
}


void Deck::dealDeck() // Splits the pre-shuffled deck evenly into two, adding every Card into either the userHand vector or compHand vector
{
	cout << "User Hand:\n";
	for (int i = 0; i < 26; i++)
	{
		userDeck.push_back(deck[i]);
		cout << userDeck[i].name() << "\n";
	}

	cout << "\n";

	cout << "Comp Hand:\n";
	for (int j = 0; j < 26; j++)
	{
		compDeck.push_back(deck[j + 26]);
		cout << compDeck[j].name() << "\n";
	}

	return;
}

void Deck::makeDeck() // Creates and initializes every card object and puts it into the deck vector; Also shuffles the deck at the end
{
	Card c1(deuce, clubs);
	deck.push_back(c1);
	Card c2(trey, clubs);
	deck.push_back(c2);
	Card c3(four, clubs);
	deck.push_back(c3);
	Card c4(five, clubs);
	deck.push_back(c4);
	Card c5(six, clubs);
	deck.push_back(c5);
	Card c6(seven, clubs);
	deck.push_back(c6);
	Card c7(eight, clubs);
	deck.push_back(c7);
	Card c8(nine, clubs);
	deck.push_back(c8);
	Card c9(ten, clubs);
	deck.push_back(c9);
	Card c10(jack, clubs);
	deck.push_back(c10);
	Card c11(queen, clubs);
	deck.push_back(c11);
	Card c12(king, clubs);
	deck.push_back(c12);
	Card c13(ace, clubs);
	deck.push_back(c13);
	Card c14(deuce, diamonds);
	deck.push_back(c14);
	Card c15(trey, diamonds);
	deck.push_back(c15);
	Card c16(four, diamonds);
	deck.push_back(c16);
	Card c17(five, diamonds);
	deck.push_back(c17);
	Card c18(six, diamonds);
	deck.push_back(c18);
	Card c19(seven, diamonds);
	deck.push_back(c19);
	Card c20(eight, diamonds);
	deck.push_back(c20);
	Card c21(nine, diamonds);
	deck.push_back(c21);
	Card c22(ten, diamonds);
	deck.push_back(c22);
	Card c23(jack, diamonds);
	deck.push_back(c23);
	Card c24(queen, diamonds);
	deck.push_back(c24);
	Card c25(king, diamonds);
	deck.push_back(c25);
	Card c26(ace, diamonds);
	deck.push_back(c26);
	Card c27(deuce, hearts);
	deck.push_back(c27);
	Card c28(trey, hearts);
	deck.push_back(c28);
	Card c29(four, hearts);
	deck.push_back(c29);
	Card c30(five, hearts);
	deck.push_back(c30);
	Card c31(six, hearts);
	deck.push_back(c31);
	Card c32(seven, hearts);
	deck.push_back(c32);
	Card c33(eight, hearts);
	deck.push_back(c33);
	Card c34(nine, hearts);
	deck.push_back(c34);
	Card c35(ten, hearts);
	deck.push_back(c35);
	Card c36(jack, hearts);
	deck.push_back(c36);
	Card c37(queen, hearts);
	deck.push_back(c37);
	Card c38(king, hearts);
	deck.push_back(c38);
	Card c39(ace, hearts);
	deck.push_back(c39);
	Card c40(deuce, spades);
	deck.push_back(c40);
	Card c41(trey, spades);
	deck.push_back(c41);
	Card c42(four, spades);
	deck.push_back(c42);
	Card c43(five, spades);
	deck.push_back(c43);
	Card c44(six, spades);
	deck.push_back(c44);
	Card c45(seven, spades);
	deck.push_back(c45);
	Card c46(eight, spades);
	deck.push_back(c46);
	Card c47(nine, spades);
	deck.push_back(c47);
	Card c48(ten, spades);
	deck.push_back(c48);
	Card c49(jack, spades);
	deck.push_back(c49);
	Card c50(queen, spades);
	deck.push_back(c50);
	Card c51(king, spades);
	deck.push_back(c51);
	Card c52(ace, spades);
	deck.push_back(c52);

	for (int i = 0; i < 1000; i++)	//randomize deck 
	{
		int randI = rand()%52;
		int randI2 = rand()%52;
		Card tempCard = deck.at(randI);
		deck.at(randI) = deck.at(randI2);
		deck.at(randI2) = tempCard;
	}

	dealDeck(); //Here it calls dealDeck to deal the Deck to the two players, the userHand vector and the compHand vector

}
