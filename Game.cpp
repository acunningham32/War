void Game::playCard()
{
	c_user = userHand.remove(0);
	c_comp = compHand.remove(0);

	if(c_user.getValue() > c_comp.getValue())
	{
		userAddCard(c_user, c_comp);
	}
	else if(tie(c_user, c_comp)
	{
		war(c_user, c_comp);
	}
	else
	{
		compAddCard(c_user, c_comp);
	}	
}

void Game::war(Card c_user, Card c_comp)
{
	warCards.add
}
