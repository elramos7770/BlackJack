#include <iostream>
#include <cstdlib>
using namespace std;
/*****************************/
/**********Classes************/
/*****************************/


class Card {
public:
	Card();
	Card(int a, int b);
	void setSuite(int a);
	void setValue(int a);
	int getSuite();
	int getValue();
	string printValue();
	string printSuite();
	int getRank();
	friend ostream& operator<<(ostream& out, Card& c);
private:
	int suite;
	int value;
};
class Player {
public:
	Player();
	friend ostream& operator<<(ostream& out, Player& p);
	void hit(Card c);
	int getHandValue();
	void setHandValue();
private:
	vector <Card> hand;
	int handValue;
};
class Dealer {
public:
	Dealer();
	void makeDeck(); // initializes the deck
	void shuffleDeck();
	void printDeck();
	int getHandValue(); // Grabs the value of the hand
	void setHandValue(); // Resets hand value to zero when the game ends.
	friend ostream& operator<<(ostream& out, Dealer& d);
	void hit(Card c); // Gets a new card.
	Card deal(int x); // Deals card to whoever hits.
private:
	Card deck[52];
	vector <Card> hand;
	int handValue;
};
class Table {
public:
	void setPlayers(int n);
	Dealer getDealer();
	Player getPlayer(int a);
	void clearTable();
	int getPlayerHandValue(int a);
	int getDealerHandValue();
	void makeDeck();
	void printDeck();
	void shuffleDeck();
	void dealerHit(Card c);
	void playerHit(int a, Card c);
private:
	Dealer dealer;
	vector <Player> players;
};
