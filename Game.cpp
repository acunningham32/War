void Game::playCard()
{
	//Check if either user is out of cards, if not, play the hand.
	if(userHand.size() <= 0)
	{
		cout << "User is out of cards: Computer wins!" << endl;
		return;
	}
	else if(compHand.size() <= 0)
	{
		cout << "Computer is out of cards: User wins!" << endl;
		return;
	}
	else
	{
		//take the cards from each vector and compare them.
		userCard = userHand.at(0);
		compCard = compHand.at(0)
		userHand.erase(0);
		compHand.erase(0);
	
		if(c_user.getValue() > c_comp.getValue())
		{
			userAddCard(userCard, compCard);
		}
		else if(tie(userCard, compCard)
		{
			war(userCard, compCard);
		}
		else
		{
			compAddCard(userCard, compCard);
		}
	}
	return;
}

void Game::war(Card userCard, Card compCard)
{
	//Check if each user has at least 3 cards
	if(userHand.size() < 3 && userHand.size() < compHand.size())
	{
		cout << "User is out of cards: Computer wins!" << endl;	
		return;
	}
	else if(compHand.size() < 3 && compHand.size() < userHand.size())
	{
		cout << "Computer is out of cards: User wins!" << endl;
		return;
	}
	else if(compHand.size() < 3 && compHand.size() == userHand.size())
	{
		cout << "You ran out of cards at the same time. It's a draw!" << endl;
	}
	else
	{
		warCards.push_back(userCard);
		warCards.push_back(compCard);
		for(int i = 0; i < 3; i++)
		{
			warCards.push_back(userHand.at(0));
			userHand.erase(0);
			warCards.push_back(compHand.at(0));
			compHand.erase(0);
		}
		playCard();
	}
	return;
}
