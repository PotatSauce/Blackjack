#include "blackjack.h"

Blackjack::Blackjack() {

	deckPoint = &deckOb;

}

void Blackjack::runGame() {

	runningStatus(true);
	deckOb.deckShuffle();
	firstDraw();
	printTable();

}

void Blackjack::runningStatus(bool gameStat) {

	gameStatus = gameStat;

}

void Blackjack::completionStatus(bool winStat) {

	winStatus = winStat;

}

bool Blackjack::isRunning() {

	return gameStatus;

}

bool Blackjack::isComplete() {

	return winStatus;

}

void Blackjack::printTable() {

	while (isRunning()) {

		system("cls");
		cout << "Dealers hand: " << dealerHand.handDealerTotal() << " / Cards in hand:";
		for (int i = 0; i < dealerHand.dealerHandSize(); i++) {

			cout << " " << dealerHand.getCards(i);

		}
		cout << " x" << endl;
		cout << "Players hand: " << playerHand.handPlayerTotal() << " / Cards in hand:";
		for (int i = 0; i < playerHand.playerHandSize(); i++) {

			cout << " " << playerHand.getCards(i);

		}
		cout << endl;
		input();

	}

	if (isComplete()) {

		system("cls");
		cout << "Dealers hand: " << dealerHand.handDealerTotal() << " / Cards in hand:";
		for (int i = 0; i < dealerHand.dealerHandSize(); i++) {

			cout << " " << dealerHand.getCards(i);

		}
		cout << endl;
		cout << "Players hand: " << playerHand.handPlayerTotal() << " / Cards in hand:";
		for (int i = 0; i < playerHand.playerHandSize(); i++) {

			cout << " " << playerHand.getCards(i);

		}
		cout << endl;
		cout << "\nPlayer has won.";

	}

	if (!isComplete()) {

		system("cls");
		cout << "Dealers hand: " << dealerHand.handDealerTotal() << " / Cards in hand:";
		for (int i = 0; i < dealerHand.dealerHandSize(); i++) {

			cout << " " << dealerHand.getCards(i);

		}
		cout << endl;
		cout << "Players hand: " << playerHand.handPlayerTotal() << " / Cards in hand:";
		for (int i = 0; i < playerHand.playerHandSize(); i++) {

			cout << " " << playerHand.getCards(i);

		}
		cout << endl;
		cout << "\nDealer has won.";

	}

}


void Blackjack::input() {

	char selection;
	cout << "\nHit (h) or stay (s)?" << endl;
	cin >> selection;

	switch (selection) {

	case 'h':
		hit();
		break;
	case 's':
		stay();
		break;

	}

}


void Blackjack::hit() {

	playerHand.addPlayerCard(deckPoint);

	if (playerHand.isOverLimit()) {

		completionStatus(false);
		runningStatus(false);

	}
	if (isMaxEligible()) {

		completionStatus(true);
		runningStatus(false);

	}

}

void Blackjack::stay() {

	dealerDrawTillLimit();

}

void Blackjack::firstDraw() {

	for (int i = 0; i < 2; i++) {

		playerHand.addPlayerCard(deckPoint);

	}

	dealerHand.addDealerCard(deckPoint);
	hiddenCard = deckOb.getCard();

	if (playerHand.handPlayerTotal() == 21) {

		completionStatus(true);
		runningStatus(false);

	}

}

void Blackjack::dealerDrawTillLimit() {

	dealerHand.addHiddenCard(hiddenCard);

	while (dealerHand.handDealerTotal() < 17) {

		dealerHand.addDealerCard(deckPoint);

	}

	if (dealerHand.handDealerTotal() > 21) {

		completionStatus(true);
		runningStatus(false);

	}

	else if (dealerHand.handDealerTotal() == 21) {

		completionStatus(false);
		runningStatus(false);

	}

	else {

		if (dealerHand.handDealerTotal() > playerHand.handPlayerTotal()) {

			completionStatus(false);
			runningStatus(false);

		}
		else if (dealerHand.handDealerTotal() < playerHand.handPlayerTotal()) {

			completionStatus(true);
			runningStatus(false);

		}
		else if (dealerHand.handDealerTotal() == playerHand.handPlayerTotal()) {

			completionStatus(true);
			runningStatus(false);

		}

	}

}

bool Blackjack::isMaxEligible() {

	if (playerHand.handPlayerTotal() == 21) {

		return true;

	}

	else return false;

}