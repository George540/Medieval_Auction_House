#pragma once
#include "Item.h"
#include <string>

class AttackItem : public Item {
private:
	int damage;
	int speed;
public:
	AttackItem();
	~AttackItem();
	AttackItem(std::string name, int buy, int bid, std::string tp, int dmg, int spd);
	AttackItem(const AttackItem& otherAttackItem);
	int getDamage() const { return damage; };
	int getSpeed() const { return speed; };
};
