#include "DecorateItem.h"
#include <iostream>
#include <string>
using namespace std;

DecorateItem::DecorateItem() : Item(), color("") {};

DecorateItem::~DecorateItem() {};

DecorateItem::DecorateItem(string name, int buy, int bid, string tp, string col) : Item(name, buy, bid, tp), color(col) {};

DecorateItem::DecorateItem(const DecorateItem& otherDecorateItem) :
	Item(otherDecorateItem),
	color(otherDecorateItem.color)
{};