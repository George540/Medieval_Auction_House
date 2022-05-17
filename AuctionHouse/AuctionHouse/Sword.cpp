#include "Sword.h"
#include <iostream>
#include <string>
using namespace std;

Sword::Sword() : AttackItem() {};

Sword::~Sword() {};

Sword::Sword(string name, int buy, int bid, string tp, int dmg, int spd) : AttackItem(name, buy, bid, tp, dmg, spd) {};

Sword::Sword(const Sword& otherSword) :
	AttackItem(otherSword)
{};

void Sword::print() const {
	cout << "Sword: " << getName() << ", Damage: " << getDamage() << "Speed: " << getSpeed() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}