#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::string;

const string suits[] = { "S", "H", "C", "D" }; // Spades, Hearts, Clubs, Diamonds


class Card {

private:
	string suit; 
	int face;
	
public:
	Card() : suit(), face() {};
	Card(string s, int num) : suit(s), face(num) {};
	string printCard();
	string getSuit();
	int getFace();
};