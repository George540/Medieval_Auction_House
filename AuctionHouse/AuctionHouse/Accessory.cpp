#include "Accessory.h"
#include <iostream>
#include <string>
using namespace std;

Accessory::Accessory() : DecorateItem() {};

Accessory::~Accessory() {};

Accessory::Accessory(string name, int buy, int bid, string tp, string col) : DecorateItem(name, buy, bid, tp, col) {};

Accessory::Accessory(const Accessory& otherItem) :
	DecorateItem(otherItem)
{};

void Accessory::print() const {
	cout << "Accessory: " << getName() << ", Color: " << getColor() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}