#include <vector>
#include "Card.h"
using std::vector;

class Deck {
public:
	Deck();
	void makeDeck();
	void dealDeck();
	vector <Card> deck;
	vector <Card> userHand;
	vector <Card> compHand;
};
