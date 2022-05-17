#pragma once
#include "AttackItem.h"
#include <string>

class Axe : public AttackItem {
public:
	Axe();
	~Axe();
	Axe(std::string name, int buy, int bid, std::string tp, int dmg, int spd);
	Axe(const Axe& otherAxeItem);
	void print() const;
};