#include "DefenseItem.h"
#include <iostream>
#include <string>
using namespace std;

DefenseItem::DefenseItem() : Item(), defense(0) {};

DefenseItem::~DefenseItem() {};

DefenseItem::DefenseItem(string name, int buy, int bid, string tp, int def) : Item(name, buy, bid, tp), defense(def) {};

DefenseItem::DefenseItem(const DefenseItem& otherDefenseItem) :
	Item(otherDefenseItem),
	defense(otherDefenseItem.defense)
{};

void DefenseItem::setDefense(int def) { defense = def; }