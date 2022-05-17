#pragma once
#include "DefenseItem.h"
#include <string>

class Helmet : public DefenseItem {
public:
	Helmet();
	~Helmet();
	Helmet(std::string name, int buy, int bid, std::string tp, int def);
	Helmet(const Helmet& otherHelmet);
	void print() const;
};
