#pragma once
#include "Item.h"
#include "DecorateItem.h"
#include "AttackItem.h"
#include "DefenseItem.h"
#include "Armor.h"
#include "Axe.h"
#include "Bomb.h"
#include "Costume.h"
#include "Accessory.h"
#include "Handgun.h"
#include "Helmets.h"
#include "Shield.h"
#include "Sword.h"
#include "Inventory.h"
#include <string>
#include <vector>
using namespace std;

class AuctionHouse {
private:
	Inventory storage;
public:
	AuctionHouse();
	~AuctionHouse();
	inline Inventory getStorage() const { return storage; }
	void sortByPriceIncrease(string choice);
	void sortByPriceDecrease(string choice);
	void sortAlphabeticallyIncrease(string choice);
	void sortAlphabeticallyDecrease(string choice);
};
