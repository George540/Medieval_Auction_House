#include "Shield.h"
#include <iostream>
#include <string>
using namespace std;

Shield::Shield() : DefenseItem() {};

Shield::~Shield() {};

Shield::Shield(string name, int buy, int bid, string tp, int def) : DefenseItem(name, buy, bid, tp, def) {};

void Shield::print() const {
	cout << "Shield: " << getName() << ", Defense: " << getDefense() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}