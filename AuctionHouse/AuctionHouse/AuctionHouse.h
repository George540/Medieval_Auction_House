#pragma once
#include "Item.h"
#include "DecorateItem.h"
#include "AttackItem.h"
#include "DefenseItem.h"
#include "Armor.h"
#include "Axe.h"
#include "Bomb.h"
#include "Costume.h"
#include "Handgun.h"
#include "Helmets.h"
#include "Shield.h"
#include "Sword.h"
#include <string>
#include <vector>
using namespace std;

class AuctionHouse {
private:
	Inventory storage;
public:
	AuctionHouse();
	~AuctionHouse();
	void sortByPriceIncrease(string choice);
	void sortByPriceDecrease(string choice);
	void sortAtoZ(string choice);
	void sortZtoA(string choice);
};
