#include "Axe.h"
#include <iostream>
#include <string>
using namespace std;

Axe::Axe() : AttackItem() {};

Axe::~Axe() {};

Axe::Axe(string name, int buy, int bid, string tp, int dmg, int spd) : AttackItem(name, buy, bid, tp, dmg, spd) {};

void Axe::print() {
	cout << "Axe: " << getName() << ", Damage: " << getDamage() << "Speed: " << getSpeed() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}