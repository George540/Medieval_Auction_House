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
#include <iostream>
using namespace std;

Inventory::Inventory() : swords(0), axes(0), handguns(0), bombs(0), armors(0), helmets(0), shields(0), costumes(0), accessories(0) {}

Inventory::~Inventory() {}

Sword Inventory::removeSword(int choice) {
	Sword temp = swords.at(choice);
	swords.erase(swords.begin() + choice);
	return temp;
}

Axe Inventory::removeAxe(int choice) {
	Axe temp = axes.at(choice);
	axes.erase(axes.begin() + choice);
	return temp;
}

Handgun Inventory::removeHandgun(int choice) {
	Handgun temp = handguns.at(choice);
	handguns.erase(handguns.begin() + choice);
	return temp;
}

Bomb Inventory::removeBomb(int choice) {
	Bomb temp = bombs.at(choice);
	bombs.erase(bombs.begin() + choice);
	return temp;
}

Armor Inventory::removeArmor(int choice) {
	Armor temp = armors.at(choice);
	armors.erase(armors.begin() + choice);
	return temp;
}

Helmet Inventory::removeHelmet(int choice) {
	Helmet temp = helmets.at(choice);
	helmets.erase(helmets.begin() + choice);
	return temp;
}

Shield Inventory::removeShield(int choice) {
	Shield temp = shields.at(choice);
	shields.erase(shields.begin() + choice);
	return temp;
}

Costume Inventory::removeCostume(int choice) {
	Costume temp = costumes.at(choice);
	costumes.erase(costumes.begin() + choice);
	return temp;
}

Accessory Inventory::removeAccessory(int choice) {
	Accessory temp = accessories.at(choice);
	accessories.erase(accessories.begin() + choice);
	return temp;
}

