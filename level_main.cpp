/***************************

Level-Based Method

***************************/

#include <iostream>
#include <vector>
#include "card_deck.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;


// The game will be lenient on equal cards. If the next hidden card is equal to the previous card, this counts as a win.

// If the player gets an answer wrong, gameOver will be set to true, thus ending the game.

void HigherLowerGame(vector<Card> set, bool &gameOver_status)
{
	char choice;

	vector<string> mystery_set(set.size());		// Create a string vector that will mask the set's cards (except for one) with question marks.
	fill(mystery_set.begin()+1, mystery_set.end(), "?");  // Hidden answers 

	mystery_set[0] = set[0].printCard();

	for (int i = 0; i < (set.size()-1) && gameOver_status != true; i++) {  // Display hidden answers
			
			for (auto it : mystery_set) // ? ? ? ? ? ? ? -> D-6 ? ? ? ? ? -> D-6 C-5 ? ? ? ? 
			cout << it << " "; 

			cout << "Higher or Lower? (H/L)" << endl;
			cin >> choice;

			switch (choice) {
			case 'H':
			case 'h':
				if (set[i + 1].getFace() >= set[i].getFace())
					mystery_set[i + 1] = set[i + 1].printCard();
				else {
					gameOver_status = true;
					cout << "Losing Card: " << set[i + 1].printCard() << endl;

					cout << "Answers: " << endl;
					for (auto it_d : set)
						cout << it_d.printCard() << " ";
				 
				}
				break;
			case 'L':
			case 'l':
				if (set[i + 1].getFace() <= set[i].getFace()) {
					mystery_set[i + 1] = set[i + 1].printCard();
				}
				else {
					gameOver_status = true;
					cout << "Losing Card: " << set[i + 1].printCard() << endl;

					cout << "Answers: " << endl;
					for (auto it_d : set)
						cout << it_d.printCard() << " ";
				}
					break;
			default:
				cout << "Invalid choice occurred." << endl;
			}

	}

	if (gameOver_status != true) {
		cout << "You win!" << endl;
		for (auto it_v : mystery_set)
			cout << it_v << " ";
	}
}
