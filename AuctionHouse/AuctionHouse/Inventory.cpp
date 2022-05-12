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
#include <algorithm>
using namespace std;

Inventory::Inventory() {}

Inventory::~Inventory() {}

Sword Inventory::removeSword(string itemName) {
	auto it = find(swords.begin(), swords.end(), [&itemName](const auto& s) { return s.getName() == itemName; });
	auto& selected = *it;
	swords.erase(swords.begin(), it);
	return selected;
}

Axe Inventory::removeAxe(string itemName) {
	auto it = find(axes.begin(), axes.end(), [&itemName](const auto& a) { return a.getName() == itemName; });
	auto& selected = *it;
	axes.erase(axes.begin(), it);
	return selected;
}

Handgun Inventory::removeHandgun(string itemName) {
	auto it = find(handguns.begin(), handguns.end(), [&itemName](const auto& h) { return h.getName() == itemName; });
	auto& selected = *it;
	handguns.erase(handguns.begin(), it);
	return selected;
}

Bomb Inventory::removeBomb(string itemName) {
	auto it = find(bombs.begin(), bombs.end(), [&itemName](const auto& b) { return b.getName() == itemName; });
	auto& selected = *it;
	bombs.erase(bombs.begin(), it);
	return selected;
}

Armor Inventory::removeArmor(string itemName) {
	auto it = find(armors.begin(), armors.end(), [&itemName](const auto& a) { return a.getName() == itemName; });
	auto& selected = *it;
	armors.erase(armors.begin(), it);
	return selected;
}

Helmet Inventory::removeHelmet(string itemName) {
	auto it = find(helmets.begin(), helmets.end(), [&itemName](const auto& h) { return h.getName() == itemName; });
	auto& selected = *it;
	helmets.erase(helmets.begin(), it);
	return selected;
}

Shield Inventory::removeShield(string itemName) {
	auto it = find(shields.begin(), shields.end(), [&itemName](const auto& s) { return s.getName() == itemName; });
	auto& selected = *it;
	shields.erase(shields.begin(), it);
	return selected;
}

Costume Inventory::removeCostume(string itemName) {
	auto it = find(costumes.begin(), costumes.end(), [&itemName](const auto& c) { return c.getName() == itemName; });
	auto& selected = *it;
	costumes.erase(costumes.begin(), it);
	return selected;
}

Accessory Inventory::removeAccessory(string itemName) {
	auto it = find(accessories.begin(), accessories.end(), [&itemName](const auto& a) { return a.getName() == itemName; });
	auto& selected = *it;
	accessories.erase(accessories.begin(), it);
	return selected;
}

void Inventory::printInventory() {
	cout << "AUCTION HOUSE INVENTORY" << endl;

	cout << swords.size() << " swords are up for auctions" << endl;
	for (const auto& sword : swords) {
		sword.print();
	}

	cout << endl;

	cout << axes.size() << " axes are up for auctions" << endl;
	for (const auto& axe : axes) {
		axe.print();
	}

	cout << endl;

	cout << handguns.size() << " handguns are up for auctions" << endl;
	for (const auto& handgun : handguns) {
		handgun.print();
	}

	cout << endl;

	cout << bombs.size() << " bombs are up for auctions" << endl;
	for (const auto& bomb : bombs) {
		bomb.print();
	}

	cout << endl;

	cout << armors.size() << " armors are up for auctions" << endl;
	for (const auto& armor : armors) {
		armor.print();
	}

	cout << endl;

	cout << helmets.size() << " helmets are up for auctions" << endl;
	for (const auto& helmet : helmets) {
		helmet.print();
	}

	cout << endl;

	cout << shields.size() << " shields are up for auctions" << endl;
	for (const auto& shield : shields) {
		shield.print();
	}

	cout << endl;

	cout << costumes.size() << " costumes are up for auctions" << endl;
	for (const auto& costume : costumes) {
		costume.print();
	}

	cout << endl;

	cout << accessories.size() << " accessories are up for auctions" << endl;
	for (const auto& accessory : accessories) {
		accessory.print();
	}

	cout << endl;
}

