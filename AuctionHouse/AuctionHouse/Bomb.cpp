#include "Bomb.h"
#include <iostream>
#include <string>
using namespace std;

Bomb::Bomb() : AttackItem() {};

Bomb::~Bomb() {};

Bomb::Bomb(string name, int buy, int bid, string tp, int dmg, int spd) : AttackItem(name, buy, bid, tp, dmg, spd) {};

Bomb::Bomb(const Bomb& otherBomb) :
	AttackItem(otherBomb)
{};

void Bomb::print() const {
	cout << "Bomb: " << getName() << ", Damage: " << getDamage() << "Charge Speed: " << getSpeed() << ", Type: " << getType() << endl;
	cout << "Buying Price: " << getBuy() << ", Bidding Price: " << getBid() << endl;
	cout << endl;
}