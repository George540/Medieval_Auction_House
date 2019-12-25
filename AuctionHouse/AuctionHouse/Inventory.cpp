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

Sword Inventory::removeSword(Sword sword) {
	vector<Sword>::iterator it = find(swords.begin(), swords.end(), sword);

	if (it != swords.end())
		cout << sword.getName() << " found. Remove from storage" << endl;
	else {
		cout << sword.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(swords.begin(), it);
	Sword temp = swords.at(index);
	swords.erase(swords.begin() + index);
	return temp;
}

Axe Inventory::removeAxe(Axe axe) {
	vector<Axe>::iterator it = find(axes.begin(), axes.end(), axe);

	if (it != axes.end())
		cout << axe.getName() << " found. Remove from storage" << endl;
	else {
		cout << axe.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(axes.begin(), it);
	Axe temp = axes.at(index);
	axes.erase(axes.begin() + index);
	return temp;
}

Handgun Inventory::removeHandgun(Handgun handgun) {
	vector<Handgun>::iterator it = find(handguns.begin(), handguns.end(), handgun);

	if (it != handguns.end())
		cout << handgun.getName() << " found. Remove from storage" << endl;
	else {
		cout << handgun.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(handguns.begin(), it);
	Handgun temp = handguns.at(index);
	handguns.erase(handguns.begin() + index);
	return temp;
}

Bomb Inventory::removeBomb(Bomb bomb) {
	vector<Bomb>::iterator it = find(bombs.begin(), bombs.end(), bomb);

	if (it != bombs.end())
		cout << bomb.getName() << " found. Remove from storage" << endl;
	else {
		cout << bomb.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(bombs.begin(), it);
	Bomb temp = bombs.at(index);
	bombs.erase(bombs.begin() + index);
	return temp;
}

Armor Inventory::removeArmor(Armor armor) {
	vector<Armor>::iterator it = find(armors.begin(), armors.end(), armor);

	if (it != armors.end())
		cout << armor.getName() << " found. Remove from storage" << endl;
	else {
		cout << armor.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(armors.begin(), it);
	Armor temp = armors.at(index);
	armors.erase(armors.begin() + index);
	return temp;
}

Helmet Inventory::removeHelmet(Helmet helmet) {
	vector<Helmet>::iterator it = find(helmets.begin(), helmets.end(), helmet);

	if (it != helmets.end())
		cout << helmet.getName() << " found. Remove from storage" << endl;
	else {
		cout << helmet.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(helmets.begin(), it);
	Helmet temp = helmets.at(index);
	helmets.erase(helmets.begin() + index);
	return temp;
}

Shield Inventory::removeShield(Shield shield) {
	vector<Shield>::iterator it = find(shields.begin(), shields.end(), shield);

	if (it != shields.end())
		cout << shield.getName() << " found. Remove from storage" << endl;
	else {
		cout << shield.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(shields.begin(), it);
	Shield temp = shields.at(index);
	shields.erase(shields.begin() + index);
	return temp;
}

Costume Inventory::removeCostume(Costume costume) {
	vector<Costume>::iterator it = find(costumes.begin(), costumes.end(), costume);

	if (it != costumes.end())
		cout << costume.getName() << " found. Remove from storage" << endl;
	else {
		cout << costume.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(costumes.begin(), it);
	Costume temp = costumes.at(index);
	costumes.erase(costumes.begin() + index);
	return temp;
}

Accessory Inventory::removeAccessory(Accessory accessory) {
	vector<Accessory>::iterator it = find(accessories.begin(), accessories.end(), accessory);

	if (it != accessories.end())
		cout << accessory.getName() << " found. Remove from storage" << endl;
	else {
		cout << accessory.getName() << " NOT found. Cancelling action" << endl;
		return;
	}
	int index = distance(accessories.begin(), it);
	Accessory temp = accessories.at(index);
	accessories.erase(accessories.begin() + index);
	return temp;
}

