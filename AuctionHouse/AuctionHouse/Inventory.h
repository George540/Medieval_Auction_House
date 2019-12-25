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
using namespace std;

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
	inline vector<Sword> getSwords() const { return swords; }
	inline vector<Axe> getAxes() const  { return axes; }
	inline vector<Handgun> getHandguns() const { return handguns; }
	inline vector<Bomb> getBombs() const { return bombs; }
	inline vector<Armor> getArmors() const { return armors; }
	inline vector<Helmet> getHelmets() const { return helmets; }
	inline vector<Shield> getShields() const { return shields; }
	inline vector<Costume> getCostumes() const { return costumes; }
	inline vector<Accessory> getAccessories() const { return accessories; }

	inline void addSword(Sword sword) { swords.push_back(sword); }
	inline void addAxe(Axe axe) { axes.push_back(axe); }
	inline void addHandgun(Handgun handgun) { handguns.push_back(handgun); }
	inline void addBomb(Bomb bomb) { bombs.push_back(bomb); }
	inline void addArmor(Armor armor) { armors.push_back(armor); }
	inline void addHelmet(Helmet helmet) { helmets.push_back(helmet); }
	inline void addShield(Shield shield) { shields.push_back(shield); }
	inline void addCostume(Costume costume) { costumes.push_back(costume); }
	inline void addAccessory(Accessory accessory) { accessories.push_back(accessory); }

	Sword removeSword(Sword sword);
	Axe removeAxe(Axe axe);
	Handgun removeHandgun(Handgun handgun);
	Bomb removeBomb(Bomb bomb);
	Armor removeArmor(Armor armor);
	Helmet removeHelmet(Helmet helmet);
	Shield removeShield(Shield shield);
	Costume removeCostume(Costume costume);
	Accessory removeAccessory(Accessory accessory);
};
