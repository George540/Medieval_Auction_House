#include "AttackItem.h"
#include <iostream>
#include <string>
using namespace std;

AttackItem::AttackItem() : Item(), damage(0), speed(0) {};

AttackItem::~AttackItem() {};

AttackItem::AttackItem(string name, int buy, int bid, string tp, int dmg, int spd) : Item(name, buy, bid, tp), damage(dmg), speed(spd) {};

AttackItem::AttackItem(const AttackItem& otherAttackItem) :
	Item(otherAttackItem),
	damage(otherAttackItem.damage),
	speed(otherAttackItem.speed)
{};