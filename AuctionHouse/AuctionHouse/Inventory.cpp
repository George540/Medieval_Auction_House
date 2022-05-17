#include "Inventory.h"

Inventory::Inventory() {}

Inventory::~Inventory() {}

Sword Inventory::removeSword(const string& itemName) {
	auto it = find_if(swords.begin(), swords.end(), [&itemName](const Sword& s) { return s.getName() == itemName; });
	auto selected = move(*it);
	swords.erase(it);
	return selected;
}

Axe Inventory::removeAxe(const string& itemName) {
	auto it = find_if(axes.begin(), axes.end(), [&itemName](const Axe& a) { return a.getName() == itemName; });
	auto selected = move(*it);
	axes.erase(it);
	return selected;
}

Handgun Inventory::removeHandgun(const string& itemName) {
	auto it = find_if(handguns.begin(), handguns.end(), [&itemName](const Handgun& h) { return h.getName() == itemName; });
	auto selected = move(*it);
	handguns.erase(it);
	return selected;
}

Bomb Inventory::removeBomb(const string& itemName) {
	auto it = find_if(bombs.begin(), bombs.end(), [&itemName](const Bomb& b) { return b.getName() == itemName; });
	auto& selected = *it;
	bombs.erase(bombs.begin(), it);
	return selected;
}

Armor Inventory::removeArmor(const string& itemName) {
	auto it = find_if(armors.begin(), armors.end(), [&itemName](const Armor& a) { return a.getName() == itemName; });
	auto selected = move(*it);
	armors.erase(it);
	return selected;
}

Helmet Inventory::removeHelmet(const string& itemName) {
	auto it = find_if(helmets.begin(), helmets.end(), [&itemName](const Helmet& h) { return h.getName() == itemName; });
	auto selected = move(*it);
	helmets.erase(it);
	return selected;
}

Shield Inventory::removeShield(const string& itemName) {
	auto it = find_if(shields.begin(), shields.end(), [&itemName](const Shield& s) { return s.getName() == itemName; });
	auto& selected = *it;
	shields.erase(it);
	return selected;
}

Costume Inventory::removeCostume(const string& itemName) {
	auto it = find_if(costumes.begin(), costumes.end(), [&itemName](const Costume& c) { return c.getName() == itemName; });
	auto selected = move(*it);
	costumes.erase(it);
	return selected;
}

Accessory Inventory::removeAccessory(const string& itemName) {
	auto it = find_if(accessories.begin(), accessories.end(), [&itemName](const Accessory& a) { return a.getName() == itemName; });
	auto selected = move(*it);
	accessories.erase(it);
	return selected;
}

bool Inventory::hasSword(const string& itemName) {
	return find_if(swords.begin(), swords.end(), [&itemName](const Sword& s) { return EqualsIgnoreCase(s.getName(), itemName); }) != swords.end();
}

bool Inventory::hasAxe(const string& itemName) {
	return find_if(axes.begin(), axes.end(), [&itemName](const Axe& a) { return a.getName() == itemName; }) != axes.end();
}

bool Inventory::hasHandgun(const string& itemName) {
	return find_if(handguns.begin(), handguns.end(), [&itemName](const Handgun& h) { return h.getName() == itemName; }) != handguns.end();
}

bool Inventory::hasBomb(const string& itemName) {
	return find_if(bombs.begin(), bombs.end(), [&itemName](const Bomb& b) { return b.getName() == itemName; }) != bombs.end();
}

bool Inventory::hasArmor(const string& itemName) {
	return find_if(armors.begin(), armors.end(), [&itemName](const Armor& a) { return a.getName() == itemName; }) != armors.end();
}

bool Inventory::hasHelmet(const string& itemName) {
	return find_if(helmets.begin(), helmets.end(), [&itemName](const Helmet& h) { return h.getName() == itemName; }) != helmets.end();
}

bool Inventory::hasShield(const string& itemName) {
	return find_if(shields.begin(), shields.end(), [&itemName](const Shield& s) { return s.getName() == itemName; }) != shields.end();
}

bool Inventory::hasCostume(const string& itemName) {
	return find_if(costumes.begin(), costumes.end(), [&itemName](const Costume& c) { return c.getName() == itemName; }) != costumes.end();
}

bool Inventory::hasAccessory(const string& itemName) {
	return find_if(accessories.begin(), accessories.end(), [&itemName](const Accessory& a) { return a.getName() == itemName; }) != accessories.end();
}

void Inventory::printInventory() {
	cout << "INVENTORY" << endl;

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
