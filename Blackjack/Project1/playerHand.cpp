#include "playerHand.h"

void PlayerHand::addPlayerCard(Deck *deckPoint) {

	int newCard = deckPoint->getCard();
	if (handPlayerTotal() <= 10 && newCard == 1) {
		newCard = 11;
	}
	playerHand.push_back(newCard);

}

int PlayerHand::handPlayerTotal() {

	totalPlayerHand = accumulate(playerHand.begin(), playerHand.end(),
		decltype(playerHand)::value_type(0));
	return totalPlayerHand;

}

bool PlayerHand::isOverLimit() {

	if (handPlayerTotal() > 21) {
		return true;
	}
	else return false;

}

int PlayerHand::playerHandSize() {

	return playerHand.size();
}

int PlayerHand::getCards(int i) {

	return playerHand[i];

}