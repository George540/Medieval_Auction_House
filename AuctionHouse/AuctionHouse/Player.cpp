#include "Player.h"
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
#include "Utilities.h"
#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;

Player::Player() : money(500), name("NONAME"), inventory() {};

Player::~Player() {};

Player::Player(int mon, string id) : money(mon), name(id), inventory() {};

void Player::bid(Item* item, int bid) {
	if (item->getBid() < bid) {
		item->setBid(bid);
		cout << "Player " << name << " has bidded item " << item->getName() << " with a price of " << item->getBid() << " credits" << endl;
	}
	else
		cout << "Bidding price is too low. Cannot bid item" << endl;
}

// Searching is O(tn), where t = number of inventory item types
vector<Item> Player::search(const Inventory& storage, string search) {
	cout << "Searching for items with the following characters: " << search << endl;
	cout << endl;

	vector<Item> searches;

	cout << "Swords with the following characters: " << endl;
	auto swords = storage.getSwords();
	for (const auto& sword : swords) {
		if (search.find(sword.getName()) != std::string::npos) {
			searches.push_back(sword);
		}
	}

	cout << "Axes with the following characters: " << endl;
	auto axes = storage.getAxes();
	for (const auto& axe : axes) {
		if (search.find(axe.getName()) != std::string::npos) {
			searches.push_back(axe);
		}
	}

	cout << "Handguns with the following characters: " << endl;
	auto handguns = storage.getHandguns();
	for (const auto& handgun : handguns) {
		if (search.find(handgun.getName()) != std::string::npos) {
			searches.push_back(handgun);
		}
	}

	cout << "Bombs with the following characters: " << endl;
	auto bombs = storage.getBombs();
	for (const auto& bomb : bombs) {
		if (search.find(bomb.getName()) != std::string::npos) {
			searches.push_back(bomb);
		}
	}

	cout << "Armor with the following characters: " << endl;
	auto armors = storage.getArmors();
	for (const auto& armor : armors) {
		if (search.find(armor.getName()) != std::string::npos) {
			searches.push_back(armor);
		}
	}

	cout << "Helmets with the following characters: " << endl;
	auto helmets = storage.getHelmets();
	for (const auto& helmet : helmets) {
		if (search.find(helmet.getName()) != std::string::npos) {
			searches.push_back(helmet);
		}
	}

	cout << "Shields with the following characters: " << endl;
	auto shields = storage.getShields();
	for (const auto& shield : shields) {
		if (search.find(shield.getName()) != std::string::npos) {
			searches.push_back(shield);
		}
	}

	cout << "Costumes with the following characters: " << endl;
	auto costumes = storage.getCostumes();
	for (const auto& costume : costumes) {
		if (search.find(costume.getName()) != std::string::npos) {
			searches.push_back(costume);
		}
	}

	cout << "Accessories with the following characters: " << endl;
	auto accessories = storage.getAccessories();
	for (const auto& accessory : accessories) {
		if (search.find(accessory.getName()) != std::string::npos) {
			searches.push_back(accessory);
		}
	}

	return searches;
}

void Player::printSearch(const vector<Item> searches) {
	cout << "Searches found: " << endl;
	for (const auto& search : searches) {
		search.print();
	}
}

// Searching is way less than O(n^2)
// This is done by first finding what type of item is it
// Then it iterates through the collection of that specific item only
// without having to iterate through all other irrelevant items
Item Player::buy(Inventory* storage, string itemName) {
	Item selected;

	if (ContainsInsensitiveString(itemName, "Sword")) {
		selected = storage->removeSword(itemName);
	}
	else if (ContainsInsensitiveString(itemName, "Axe")) {
		selected = storage->removeAxe(itemName);
	}
	else if (ContainsInsensitiveString(itemName, "Handgun")) {
		selected = storage->removeHandgun(itemName);
	}
	else if (ContainsInsensitiveString(itemName, "Bomb")) {
		selected = storage->removeBomb(itemName);
	}
	else if (ContainsInsensitiveString(itemName, "Armor")) {
		selected = storage->removeArmor(itemName);
	}
	else if (ContainsInsensitiveString(itemName, "Helmet")) {
		selected = storage->removeHelmet(itemName);
	}
	else if (ContainsInsensitiveString(itemName, "Shield")) {
		selected = storage->removeShield(itemName);
	}
	else if (ContainsInsensitiveString(itemName, "Costume")) {
		selected = storage->removeCostume(itemName);
	}
	else if (ContainsInsensitiveString(itemName, "Accessory")) {
		selected = storage->removeAccessory(itemName);
	}
	else {
		selected = Item();
	}

	return selected;
}
