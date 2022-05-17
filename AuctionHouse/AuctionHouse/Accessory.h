#pragma once
#include "DecorateItem.h"
#include <string>

class Accessory : public DecorateItem {
public:
	Accessory();
	~Accessory();
	Accessory(std::string name, int buy, int bid, std::string tp, std::string col);
	Accessory(const Accessory& otherItem);
	void print() const;
};
