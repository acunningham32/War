#define ___GAME_H

#include <vector>
using std::vector;

class Game {
public:
	void playCard(Deck &myDeck);
	bool userWin(Card a, Card b);
	bool tie(Card a, Card b);
	void userAddCard(Deck &myDeck, Card a, Card b);
	void compAddCard(Deck &myDeck, Card a, Card b);
	void war(Deck &myDeck, Card a, Card b);
	Game(Deck d);
private:
	vector<Card> warCards;
	Deck a;
};

#endif
