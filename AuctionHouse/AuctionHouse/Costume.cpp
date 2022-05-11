#include "Costume.h"
#include <iostream>
#include <string>
using namespace std;

Costume::Costume() : DecorateItem() {};

Costume::~Costume() {};

Costume::Costume(string name, int buy, int bid, string tp, string col) : DecorateItem(name, buy, bid, tp, col) {};

void Costume::print() const {
	cout << "Costume Outfit: " << getName() << ", Color: " << getColor() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}