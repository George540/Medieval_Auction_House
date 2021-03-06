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
	Inventory inventory;
	int money;
	string name;
public:
	Player();
	~Player();
	Player(int mon, string id);
	void bid(Item* item, int bid);
	Item buy(Inventory* storage, int choice1, int choice2);
	vector<Item> search(const Inventory& storage, string search);
	void auction(Inventory* storage, Item item);
};
