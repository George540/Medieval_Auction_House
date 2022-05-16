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
#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>
#include "Utilities.h"
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
	for (auto& sword : swords) {
		if (search.find(sword.getName()) != std::string::npos) {
			Item* found = &sword;
			searches.push_back(*found);
			found = NULL;
			delete found;
		}
	}

	cout << "Axes with the following characters: " << endl;
	auto axes = storage.getAxes();
	for (auto& axe : axes) {
		if (search.find(axe.getName()) != std::string::npos) {
			Item* found = &axe;
			searches.push_back(*found);
			found = NULL;
			delete found;
		}
	}

	cout << "Handguns with the following characters: " << endl;
	auto handguns = storage.getHandguns();
	for (auto& handgun : handguns) {
		if (search.find(handgun.getName()) != std::string::npos) {
			Item* found = &handgun;
			searches.push_back(*found);
			found = NULL;
			delete found;
		}
	}

	cout << "Bombs with the following characters: " << endl;
	auto bombs = storage.getBombs();
	for (auto& bomb : bombs) {
		if (search.find(bomb.getName()) != std::string::npos) {
			Item* found = &bomb;
			searches.push_back(*found);
			found = NULL;
			delete found;
		}
	}

	cout << "Armor with the following characters: " << endl;
	auto armors = storage.getArmors();
	for (auto& armor : armors) {
		if (search.find(armor.getName()) != std::string::npos) {
			Item* found = &armor;
			searches.push_back(*found);
			found = NULL;
			delete found;
		}
	}

	cout << "Helmets with the following characters: " << endl;
	auto helmets = storage.getHelmets();
	for (auto& helmet : helmets) {
		if (search.find(helmet.getName()) != std::string::npos) {
			Item* found = &helmet;
			searches.push_back(*found);
			found = NULL;
			delete found;
		}
	}

	cout << "Shields with the following characters: " << endl;
	auto shields = storage.getShields();
	for (auto& shield : shields) {
		if (search.find(shield.getName()) != std::string::npos) {
			Item* found = &shield;
			searches.push_back(*found);
			found = NULL;
			delete found;
		}
	}

	cout << "Costumes with the following characters: " << endl;
	auto costumes = storage.getCostumes();
	for (auto& costume : costumes) {
		if (search.find(costume.getName()) != std::string::npos) {
			Item* found = &costume;
			searches.push_back(*found);
			found = NULL;
			delete found;
		}
	}

	cout << "Accessories with the following characters: " << endl;
	auto accessories = storage.getAccessories();
	for (auto& accessory : accessories) {
		if (search.find(accessory.getName()) != std::string::npos) {
			Item* found = &accessory;
			searches.push_back(*found);
			found = NULL;
			delete found;
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

	selected.setBid(0);
	selected.setBuy(0);

	return selected;
}

void Player::placeAuction(Inventory* auctionStorage, Item* item, int startBid, int buyOut) {
	auto itemName = item->getName();

	cout << "Placing Item: " << itemName << endl;

	if (ContainsInsensitiveString(itemName, "Sword") && inventory.hasSword(itemName) && static_cast<Sword*>(item) != nullptr) {
		inventory.removeSword(itemName);
		auctionStorage->addSword(*static_cast<Sword*>(item));
	}
	else if (ContainsInsensitiveString(itemName, "Axe") && inventory.hasAxe(itemName) && static_cast<Axe*>(item) != nullptr) {
		inventory.removeAxe(itemName);
		auctionStorage->addAxe(*static_cast<Axe*>(item));
	}
	else if (ContainsInsensitiveString(itemName, "Handgun") && inventory.hasHandgun(itemName) && static_cast<Handgun*>(item) != nullptr) {
		inventory.removeHandgun(itemName);
		auctionStorage->addHandgun(*static_cast<Handgun*>(item));
	}
	else if (ContainsInsensitiveString(itemName, "Bomb") && inventory.hasBomb(itemName) && static_cast<Bomb*>(item) != nullptr) {
		inventory.removeBomb(itemName);
		auctionStorage->addBomb(*static_cast<Bomb*>(item));
	}
	else if (ContainsInsensitiveString(itemName, "Armor") && inventory.hasArmor(itemName) && static_cast<Armor*>(item) != nullptr) {
		inventory.removeArmor(itemName);
		auctionStorage->addArmor(*static_cast<Armor*>(item));
	}
	else if (ContainsInsensitiveString(itemName, "Helmet") && inventory.hasHelmet(itemName) && static_cast<Helmet*>(item) != nullptr) {
		inventory.removeHelmet(itemName);
		auctionStorage->addHelmet(*static_cast<Helmet*>(item));
	}
	else if (ContainsInsensitiveString(itemName, "Shield") && inventory.hasShield(itemName) && static_cast<Shield*>(item) != nullptr) {
		inventory.removeShield(itemName);
		auctionStorage->addShield(*static_cast<Shield*>(item));
	}
	else if (ContainsInsensitiveString(itemName, "Costume") && inventory.hasCostume(itemName) && static_cast<Costume*>(item) != nullptr) {
		inventory.removeCostume(itemName);
		auctionStorage->addCostume(*static_cast<Costume*>(item));
	}
	else if (ContainsInsensitiveString(itemName, "Accessory") && inventory.hasAccessory(itemName) && static_cast<Accessory*>(item) != nullptr) {
		inventory.removeAccessory(itemName);
		auctionStorage->addAccessory(*static_cast<Accessory*>(item));
	}
	else {
		cout << "Item is not recognized. Auction cancelled." << endl;
		return;
	}

	item->setBid(startBid);
	item->setBuy(buyOut);

	cout << "Bid Price :" << item->getBid() << endl;
	cout << "Buyout Price :" << item->getBuy() << endl;

	cout << itemName << " placed for auction" << endl;
}
