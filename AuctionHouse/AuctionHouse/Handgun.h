#pragma once
#include "AttackItem.h"
#include <string>

class Handgun : public AttackItem {
public:
	Handgun();
	~Handgun();
	Handgun(std::string name, int buy, int bid, std::string tp, int dmg, int spd);
	void print() const;
};
