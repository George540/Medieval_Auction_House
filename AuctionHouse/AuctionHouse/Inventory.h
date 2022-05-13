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
#include <string>
#include <vector>

class Inventory {
private:
	vector<Sword> swords;
	vector<Axe> axes;
	vector<Handgun> handguns;
	vector<Bomb> bombs;
	vector<Armor> armors;
	vector<Helmet> helmets;
	vector<Shield> shields;
	vector<Costume> costumes;
	vector<Accessory> accessories;
public:
	Inventory();
	~Inventory();
	vector<Sword> getSwords() const { return swords; }
	vector<Axe> getAxes() const  { return axes; }
	vector<Handgun> getHandguns() const { return handguns; }
	vector<Bomb> getBombs() const { return bombs; }
	vector<Armor> getArmors() const { return armors; }
	vector<Helmet> getHelmets() const { return helmets; }
	vector<Shield> getShields() const { return shields; }
	vector<Costume> getCostumes() const { return costumes; }
	vector<Accessory> getAccessories() const { return accessories; }

	void addSword(Sword sword) { swords.push_back(sword); }
	void addAxe(Axe axe) { axes.push_back(axe); }
	void addHandgun(Handgun handgun) { handguns.push_back(handgun); }
	void addBomb(Bomb bomb) { bombs.push_back(bomb); }
	void addArmor(Armor armor) { armors.push_back(armor); }
	void addHelmet(Helmet helmet) { helmets.push_back(helmet); }
	void addShield(Shield shield) { shields.push_back(shield); }
	void addCostume(Costume costume) { costumes.push_back(costume); }
	void addAccessory(Accessory accessory) { accessories.push_back(accessory); }

	Sword removeSword(string itemName);
	Axe removeAxe(string itemName);
	Handgun removeHandgun(string itemName);
	Bomb removeBomb(string itemName);
	Armor removeArmor(string itemName);
	Helmet removeHelmet(string itemName);
	Shield removeShield(string itemName);
	Costume removeCostume(string itemName);
	Accessory removeAccessory(string itemName);

	bool hasSword(string itemName);
	bool hasAxe(string itemName);
	bool hasHandgun(string itemName);
	bool hasBomb(string itemName);
	bool hasArmor(string itemName);
	bool hasHelmet(string itemName);
	bool hasShield(string itemName);
	bool hasCostume(string itemName);
	bool hasAccessory(string itemName);

	void printInventory();
};
