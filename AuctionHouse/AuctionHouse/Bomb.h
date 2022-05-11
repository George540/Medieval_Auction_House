#pragma once
#include "AttackItem.h"
#include <string>

class Bomb : public AttackItem {
public:
	Bomb();
	~Bomb();
	Bomb(std::string name, int buy, int bid, std::string tp, int dmg, int spd);
	void print() const;
};
