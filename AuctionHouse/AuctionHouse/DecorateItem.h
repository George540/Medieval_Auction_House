#pragma once
#include "Item.h"
#include <string>

class DecorateItem : public Item {
private:
	std::string color;
public:
	DecorateItem();
	~DecorateItem();
	DecorateItem(std::string name, int buy, int bid, std::string tp, std::string col);
	DecorateItem(const DecorateItem& otherDecorateItem);
	std::string getColor() const { return color; };
	void setColor(std::string col) { color = col; };
};

