#include "card.h"

string Card::printCard()
{
	string f;
	string fullcard;
	switch (face) // I.E. If the face equals 1, display 'A', 11 = 'J', and so on
	{
	case 1:
		f = "A";
		fullcard = suit + "-" + f;
		break;
	case 11:
		f = "J";
		fullcard = suit + "-" + f;
		break;
	case 12:
		f = "Q";
		fullcard = suit + "-" + f;
		break;
	case 13:
		f = "K";
		fullcard = suit + "-" + f;
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		fullcard = suit + "-" + std::to_string(face); // If the face is not an A, J, Q, nor K, then display the card as it is
		break;
	default:
		cout << "Invalid condition!";
	}
	return fullcard;

}

string Card::getSuit()
{
	return suit;
}

int Card::getFace()
{
	return face;
}
