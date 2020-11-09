#pragma once
#include <numeric>
#include "deck.h"

class PlayerHand {

private:

	vector <int> playerHand;
	int totalPlayerHand;

public:

	void addPlayerCard(Deck*);
	int handPlayerTotal();
	bool isOverLimit();
	int playerHandSize();
	int getCards(int i);

};