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

vector<Item> Player::search(const Inventory& storage, string search) {
	cout << "Searching for items with the following characters: " << search << endl;
	cout << endl;

	vector<Item> searches;

	cout << "Swords with the following characters: " << endl;
	for (int i = 0; i < storage.getSwords().size(); i++) {
		if (storage.getSwords().at(i).getName().find(search) != string::npos) {
			Sword found = storage.getSwords().at(i);
			searches.push_back(found);
		}
	}

	cout << "Axes with the following characters: " << endl;
	for (int i = 0; i < storage.getAxes().size(); i++) {
		if (storage.getAxes().at(i).getName().find(search) != string::npos) {
			Axe found = storage.getAxes().at(i);
			searches.push_back(found);
			found.print();
		}
	}

	cout << "Handguns with the following characters: " << endl;
	for (int i = 0; i < storage.getHandguns().size(); i++) {
		if (storage.getHandguns().at(i).getName().find(search) != string::npos) {
			Handgun found = storage.getHandguns().at(i);
			searches.push_back(found);
			found.print();
		}
	}

	cout << "Bombs with the following characters: " << endl;
	for (int i = 0; i < storage.getBombs().size(); i++) {
		if (storage.getBombs().at(i).getName().find(search) != string::npos) {
			Bomb found = storage.getBombs().at(i);
			searches.push_back(found);
			found.print();
		}
	}

	cout << "Armor with the following characters: " << endl;
	for (int i = 0; i < storage.getArmors().size(); i++) {
		if (storage.getArmors().at(i).getName().find(search) != string::npos) {
			Armor found = storage.getArmors().at(i);
			searches.push_back(found);
			found.print();
		}
	}

	cout << "Helmets with the following characters: " << endl;
	for (int i = 0; i < storage.getHelmets().size(); i++) {
		if (storage.getHelmets().at(i).getName().find(search) != string::npos) {
			Helmet found = storage.getHelmets().at(i);
			searches.push_back(found);
			found.print();
		}
	}

	cout << "Shields with the following characters: " << endl;
	for (int i = 0; i < storage.getShields().size(); i++) {
		if (storage.getShields().at(i).getName().find(search) != string::npos) {
			Shield found = storage.getShields().at(i);
			searches.push_back(found);
			found.print();
		}
	}

	cout << "Costumes with the following characters: " << endl;
	for (int i = 0; i < storage.getCostumes().size(); i++) {
		if (storage.getCostumes().at(i).getName().find(search) != string::npos) {
			Costume found = storage.getCostumes().at(i);
			searches.push_back(found);
			found.print();
		}
	}

	cout << "Accessories with the following characters: " << endl;
	for (int i = 0; i < storage.getAccessories().size(); i++) {
		if (storage.getAccessories().at(i).getName().find(search) != string::npos) {
			Accessory found = storage.getAccessories().at(i);
			searches.push_back(found);
			found.print();
		}
	}

}

// Searching is way less than O(n^2)
Item Player::buy(Inventory* storage, int choice1, int choice2) {
	Item selected;

	if (choice1 == 1) {
		selected = storage->getSwords().at(choice2);
		storage->getSwords().erase(storage->getSwords().begin() + choice2);
	}
	else if (choice1 == 2) {
		selected = storage->getAxes().at(choice2);
		storage->getAxes().erase(storage->getAxes().begin() + choice2);
	}
	else if (choice1 == 3) {
		selected = storage->getHandguns().at(choice2);
		storage->getHandguns().erase(storage->getHandguns().begin() + choice2);
	}
	else if (choice1 == 4) {
		selected = storage->getBombs().at(choice2);
		storage->getBombs().erase(storage->getBombs().begin() + choice2);
	}
	else if (choice1 == 5) {
		selected = storage->getArmors().at(choice2);
		storage->getArmors().erase(storage->getArmors().begin() + choice2);
	}
	else if (choice1 == 6) {
		selected = storage->getHelmets().at(choice2);
		storage->getHelmets().erase(storage->getHelmets().begin() + choice2);
	}
	else if (choice1 == 6) {
		selected = storage->getShields().at(choice2);
		storage->getShields().erase(storage->getShields().begin() + choice2);
	}
	else if (choice1 == 7) {
		selected = storage->getCostumes().at(choice2);
		storage->getCostumes().erase(storage->getCostumes().begin() + choice2);
	}
	else if (choice1 == 8) {
		selected = storage->getAccessories().at(choice2);
		storage->getAccessories().erase(storage->getAccessories().begin() + choice2);
	}

	return selected;
}
