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
#include "AuctionHouse.h"
#include <string>
#include <vector>
using namespace std;


AuctionHouse::AuctionHouse() {
	// Temporary items
	storage = new Inventory();
	Sword sword1 = Sword("Brandish Sword", 1000, 0, "normal", 2, 6);
	Sword sword2 = Sword("Avenger Sword", 32000, 5000, "elemental", 6, 3);
	Sword sword3 = Sword("Ice Calibur Sword", 15000, 3500, "ice", 4, 5);
	Sword sword4 = Sword("Executor Blade Sword", 23000, 1500, "elemental", 5, 8);
	Sword sword5 = Sword("Tutrus Knife Sword", 2400, 500, "shadow", 3, 5);
	Sword sword6 = Sword("Slasher Cutter Sword", 1000, 0, "normal", 2, 6);

	storage->addSword(sword1);
	storage->addSword(sword2);
	storage->addSword(sword3);
	storage->addSword(sword4);
	storage->addSword(sword5);
	storage->addSword(sword6);
}

AuctionHouse::~AuctionHouse()
{
	storage = nullptr;
	delete storage;
}