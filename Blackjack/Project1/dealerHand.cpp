#include "dealerHand.h"

void DealerHand::addDealerCard(Deck *deckPoint) {

	int newCard = deckPoint->getCard();
	if (handDealerTotal() <= 10 && newCard == 1) {
		newCard = 11;
	}
	dealerHand.push_back(newCard);

}

int DealerHand::handDealerTotal() {

	totalDealerHand = accumulate(dealerHand.begin(), dealerHand.end(),
		decltype(dealerHand)::value_type(0));
	return totalDealerHand;

}

int DealerHand::dealerHandSize() {

	return dealerHand.size();
}


int DealerHand::getCards(int i) {

	return dealerHand[i];
}


void DealerHand::addHiddenCard(int hiddenCard) {

	if (hiddenCard == 1) hiddenCard = 11;

	dealerHand.push_back(hiddenCard);

}