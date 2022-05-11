#pragma once
#include "DefenseItem.h"
#include <string>

class Shield : public DefenseItem {
public:
	Shield();
	~Shield();
	Shield(std::string name, int buy, int bid, std::string tp, int def);
	void print() const;
};
