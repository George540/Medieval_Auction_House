#include "Handgun.h"
#include <iostream>
#include <string>
using namespace std;

Handgun::Handgun() : AttackItem() {};

Handgun::~Handgun() {};

Handgun::Handgun(string name, int buy, int bid, string tp, int dmg, int spd) : AttackItem(name, buy, bid, tp, dmg, spd) {};

void Handgun::print() {
	cout << "Handgun: " << getName() << ", Damage per second: " << getDamage() << "Rate of Fire: " << getSpeed() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}