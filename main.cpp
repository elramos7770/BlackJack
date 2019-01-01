#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include "Blackjack.hpp"
using namespace std;


/************************************/
/******** Main Driver ***************/
/************************************/
int main() {
	Table table;
	int numPlayers, i, hit, ccard = 0;// ccard keeps track of how many cards have been drawn
	cout << "how many players? " << endl << "Enter the desired amount of players a max of 4" << endl;
	cin >> numPlayers;
	// prompts for how many players are wanted.
	while (numPlayers < 1 || numPlayers > 4) {
		cout << "Invalid number, try again" << endl;
		cin >> numPlayers;
	}
	table.setPlayers(numPlayers);
	table.makeDeck();
	table.shuffleDeck();
	// goes through each players turn
	for (i = 0; i < numPlayers; i++) {
		cout << "Player " << i+1 << "'s turn " << endl; // i+1 because it starts at 0
		do {
			cout << "Type 1 to hit or 2 to pass" << endl;
			cin >> hit;
			while (hit != 1 && hit != 2) {
				cout << "Invalid number, try again" << endl;
				cin >> hit;
			}
			if (hit == 1) {
				// deals the player a card then increments the cards index
				table.playerHit(i , table.getDealer().deal(ccard));
				cout << "You drew the " << table.getDealer().deal(ccard) << endl;
				ccard++;
			}
			cout << "Your current hand value is " << table.getPlayerHandValue(i) << endl;
		//will prompt till the players hand is invalid or till the player passes
		}while (table.getPlayerHandValue(i) <= 21 && hit != 2);
	}
	cout << "Dealer's turn" << endl;
	while (table.getDealerHandValue() < 15) {
		table.dealerHit(table.getDealer().deal(ccard));
		cout << "Dealer drew the " << table.getDealer().deal(ccard) << endl;
		cout << "The Dealer's current hand value is " << table.getDealerHandValue() << endl;
		ccard++;
		Sleep(1000);
	}
	for (i = 0; i < numPlayers; i++) {
		if (table.getPlayerHandValue(i) <= 21 && table.getPlayerHandValue(i) > table.getDealerHandValue() || table.getDealerHandValue() > 21) {
			cout << "congrats player " << i + 1 << " won!" << endl;
		}
		else {
			cout << "Player " << i + 1 << " lost." << endl;
		}
	}
	system("Pause");
}
