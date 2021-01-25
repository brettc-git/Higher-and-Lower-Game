#include "card.h"
#include "card_deck.h"

card_deck::card_deck()
{
	deck.resize(52);

	for (int i = 0; i < deck_size; i++) // i < 4
	{
		deck[i] = Card(suits[i % 4], (i % 13) + 1);
	}
}

card_deck::~card_deck()
{
	deck.clear();
}

void card_deck::shuffleDeck()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

vector<Card> card_deck::dealCards(vector<Card> set) {

	auto top = deck.begin();
	auto stop = deck.begin() + set.size();
	vector<Card> hand(top, stop);
	return hand;
}