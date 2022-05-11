#pragma once
#include "DefenseItem.h"
#include <string>

class Armor : public DefenseItem {
public:
	Armor();
	~Armor();
	Armor(std::string name, int buy, int bid, std::string tp, int def);
	void print() const;
};
