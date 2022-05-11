#include "Helmets.h"
#include <iostream>
#include <string>
using namespace std;

Helmet::Helmet() : DefenseItem() {};

Helmet::~Helmet() {};

Helmet::Helmet(string name, int buy, int bid, string tp, int def) : DefenseItem(name, buy, bid, tp, def) {};

void Helmet::print() const {
	cout << "Helmet: " << getName() << ", Defense: " << getDefense() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}