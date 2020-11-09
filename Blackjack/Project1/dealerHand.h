#pragma once
#include <numeric>
#include "deck.h"

class DealerHand {

private:

	vector <int> dealerHand;
	int totalDealerHand;

public:

	void addDealerCard(Deck*);
	int handDealerTotal();
	int dealerHandSize();
	int getCards(int i);
	void addHiddenCard(int hiddenCard);

};