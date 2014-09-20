void Game::playCard()
{
	if(userHand.size() == 0)
	{
		cout << "User is out of cards: Computer wins!" << endl;
		return;
	}
	else if(compHand.size() == 0)
	{
		cout << "Computer is out of cards: User wins!" << endl;
		return;
	}
	else
	{
		userCard = userHand.remove(0);
		compCard = compHand.remove(0);
	
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
	if(userHand.size() < 3)
	{
		cout << "User is out of cards: Computer wins!" << endl;	
		return;
	}
	else if(compHand.size() < 3)
	{
		cout << "Computer is out of cards: User wins!" << endl;
		return;
	}
	else
	{
		warCards.push_back(userCard);
		warCards.push_back(compCard);
		for(int i = 0; i < 3; i++)
		{
			warCards.push_back(userHand.at(0));
			userHand.remove(0);
			warCards.push_back(compHand.at(0));
			compHand.remove(0);
		}
		playCard();
	}
	return;
}
