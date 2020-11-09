#pragma once
#include <time.h>
#include <vector>

using namespace std;

class Deck {

private:

	vector <int> deck = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
						 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
						 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
						 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

public:

	void deckShuffle();
	int getCard();

};