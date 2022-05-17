#pragma once
#include "Item.h"
#include <string>

class DefenseItem : public Item {
private:
	int defense;
public:
	DefenseItem();
	~DefenseItem();
	DefenseItem(std::string name, int buy, int bid, std::string tp, int def);
	DefenseItem(const DefenseItem& otherDefenseItem);
	int getDefense() const { return defense; };
	void setDefense(int dmg);
};
