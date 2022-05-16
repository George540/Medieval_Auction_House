// AuctionHouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
#include "AuctionHouse.h"
#include "Utilities.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Player.h"
using namespace std;


int removeInt(vector<int>& list, int choice);
int findInt(vector<int> list, int l, int r, int choice);

int main()
{
    std::cout << "Hello World!\n";

	string str1 = "Excalibur Sword";

	AuctionHouse auctionHouse = AuctionHouse();
	AuctionHouse* ahPtr = &auctionHouse;
	auto ahInventory = ahPtr->getStorage();
	ahPtr->getStorage()->printInventory();

	Player p1 = Player();
	p1.getInventory()->printInventory();

	auto searches = p1.search(*ahInventory, "Brandish");
	
	for (const auto& s : searches)
	{
		s.print();
	}

	auto item = p1.getInventory()->getSwords().at(0);
	p1.placeAuction(*ahInventory, &item, 0, 1200);

	auctionHouse.getStorage()->printInventory();
	p1.getInventory()->printInventory();

	p1.buy(*ahInventory, "Excalibur Sword");

	auctionHouse.getStorage()->printInventory();
	p1.getInventory()->printInventory();


	ahPtr = nullptr;
	delete ahPtr;
}

int removeInt(vector<int>& list, int choice) {
	auto it = find(list.begin(), list.end(), choice);

	if (it != list.end())
		cout << choice << " found. Remove from storage" << endl;
	else {
		cout << choice << " NOT found. Cancelling action" << endl;
		return choice;
	}

	int index = distance(list.begin(), it);
	int temp = list.at(index);
	list.erase(list.begin() + index);
	return temp;
}

int findInt(vector<int> list, int l, int r, int choice) {
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (list[mid] == choice) return mid;

		if (list[mid] > choice) return findInt(list, l, mid - 1, choice);

		return findInt(list, mid + 1, r, choice);
	}

	return -1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
