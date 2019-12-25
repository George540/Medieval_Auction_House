#include "Armor.h"
#include <iostream>
#include <string>
using namespace std;

Armor::Armor() : DefenseItem() {};

Armor::~Armor() {};

Armor::Armor(string name, int buy, int bid, string tp, int def) : DefenseItem(name, buy, bid, tp, def) {};

void Armor::print() {
	cout << "Armor: " << getName() << ", Defense: " << getDefense() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}