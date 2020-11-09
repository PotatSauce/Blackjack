#pragma once
#include <iostream>
#include <numeric>
#include "deck.h"
#include "playerHand.h"
#include "dealerHand.h"

class Blackjack {

private:

	Deck deckOb;
	Deck* deckPoint;
	PlayerHand playerHand;
	DealerHand dealerHand;
	int hiddenCard;
	bool gameStatus;
	bool winStatus;

public:

	Blackjack();
	~Blackjack() {};
	void runGame();
	void runningStatus(bool gameStatus);
	void completionStatus(bool winStatus);
	bool isRunning();
	bool isComplete();
	void printTable();
	void input();
	void hit();
	void stay();
	void firstDraw();
	void dealerDrawTillLimit();
	bool isMaxEligible();

};