#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Blackjack.hpp"
using namespace std;

/***********************************/
/*****Friend Functions**************/
/***********************************/

ostream& operator<<(ostream& out, Card& c) {
	out << c.printValue() << " of " << c.printSuite();
	return out;
}

/***********************************/
/******Card Class Functions ********/
/***********************************/
Card::Card() {
	suite = 0;
	value = 0;
}
Card::Card(int a, int b) {
	suite = a;
	value = b;
}
void Card::setSuite(int a) {
	suite = a;
}
void Card::setValue(int a) {
	value = a;
}
int Card::getSuite() {
	return suite;
}
int Card::getValue() {
	return value;
}
string Card::printValue() {
	string Value[] = { "joker","ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","jack", "queen", "king" };
	return Value[value];
}
string Card::printSuite() {
	string Suite[] = { "joker", "hearts", "clubs", "diamonds", "spades" };
	return Suite[suite];
}
int Card::getRank() {
	if (value > 10) {
		return 10;
	}
	return value;
}

/********************************?
/******Dealer Class Function*****/
/********************************/
Dealer::Dealer() {
	handValue = 0;
}
void Dealer::makeDeck() {
	int i, j, k = 0;
	Card temp;
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 14; j++) {
			temp.setSuite(i);
			temp.setValue(j);
			deck[k] = temp;
			k++;
		}
	}
}
void Dealer::shuffleDeck() {
	int i, random;
	Card temp;
	srand(time(NULL));
	for (i = 0; i < 52; i++) {
		random = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[random];
		deck[random] = deck[i];
	}
}
void Dealer::printDeck() {
	int i;
	for (i = 0; i < 52; i++) {
		cout << deck[i] << endl;
	}
}
int Dealer::getHandValue() {
	int i, val = 0;
	for (i = 0; i < hand.size(); i++) {
		val += hand.at(i).getRank();
	}
	return val;
}
void Dealer::setHandValue() {
	while (hand.size() > 0) {
		hand.pop_back();
	}
}
void Dealer::hit(Card c) {
	hand.push_back(c);
}
Card Dealer::deal(int x) {
	return deck[x];
}
/************************************/
/******* Player Functions ***********/
/************************************/
Player::Player() { 
	handValue = 0;
}

int Player::getHandValue() {
	int i, val = 0;
	for (i = 0; i < hand.size(); i++) {
		val += hand.at(i).getRank();
	}
	return val;
}
void Player::setHandValue() {
	while (hand.size() > 0) {
		hand.pop_back();
	}
}
void Player::hit(Card c) {
	hand.push_back(c);
}

/*************************************/
/*********** Table Classes ***********/
/*************************************/

void Table::setPlayers(int n) {
	int i;
	Player init;
	for (i = 0; i < n; i++) {
		players.push_back(init); // Fills the table with default players.
	}
}
Dealer Table::getDealer() {
	return dealer;
}
Player Table::getPlayer(int a) {
	return players.at(a);
}

void Table::clearTable() {
	while (players.size() > 0) {
		players.at(players.size() - 1).setHandValue();
		players.pop_back();
	}
	dealer.setHandValue();
}
int Table::getPlayerHandValue(int a) {
	return  players.at(a).getHandValue();
}
int Table::getDealerHandValue() {
	return dealer.getHandValue();
}
void Table::dealerHit(Card c) {
	dealer.hit(c);
}
void Table::playerHit(int a, Card c) {
	players.at(a).hit(c);
}
void Table::makeDeck() {
	dealer.makeDeck();
}
void Table::printDeck() {
	dealer.printDeck();
}
void Table::shuffleDeck() {
	dealer.shuffleDeck();
}