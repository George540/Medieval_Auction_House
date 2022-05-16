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

class Player {
private:
	Inventory* inventory;
	int money;
	string name;
public:
	Player();
	~Player();
	Player(int mon, string id);
	void bid(Item* item, int bid);
	void buy(Inventory& storage, string itemName);
	vector<Item> search(const Inventory& storage, string search);
	void printSearch(const vector<Item> searches);
	void placeAuction(Inventory& auctionStorage, Item* item, int startBid, int buyOut);
	Inventory* getInventory() { return inventory; }
};
