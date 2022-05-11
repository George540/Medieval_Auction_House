#pragma once
#include "AttackItem.h"
#include <string>

class Sword : public AttackItem {
public:
	Sword();
	~Sword();
	Sword(std::string name, int buy, int bid, std::string tp, int dmg, int spd);
	void print() const;
};