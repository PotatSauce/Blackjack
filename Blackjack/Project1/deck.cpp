#include "deck.h"

void Deck::deckShuffle() {

	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++)
		swap(deck[i], deck[rand() % 52]);

}

int Deck::getCard() {

	int card = deck.front();
	deck.erase(deck.begin());
	return card;

}