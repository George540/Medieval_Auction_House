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
	inline int getDamage() const { return damage; };
	inline int getSpeed() const { return speed; };
	void setDamage(int dmg);
};
