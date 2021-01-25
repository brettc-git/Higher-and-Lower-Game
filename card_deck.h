#pragma once

#include <iostream>

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "card.h"

using std::string;
using std::vector;

const int deck_size = 52;

class card_deck
{
private:
	vector<Card> deck;  // Dynamically allocate memory for 52 cards;
public:
	card_deck(); // Constructor
	~card_deck(); // Deconstructor
	void shuffleDeck(); 
	vector<Card> dealCards(vector<Card> set);
};


