#pragma once
#include "DecorateItem.h"
#include <string>

class Costume : public DecorateItem {
public:
	Costume();
	~Costume();
	Costume(std::string name, int buy, int bid, std::string tp, std::string col);
	void print();
};
