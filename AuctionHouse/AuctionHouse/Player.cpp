#include "Player.h"
using namespace std;

Player::Player() : money(1500), name("NONAME"), inventory(new Inventory()) {};

Player::~Player()
{
	inventory = nullptr;
	delete inventory;
};

Player::Player(int mon, string id) : money(mon), name(id), inventory() {};

void Player::bid(Item* item, int bid)
{
	if (item->getBid() < bid) {
		item->setBid(bid);
		cout << "Player " << name << " has bidded item " << item->getName() << " with a price of " << item->getBid() << " credits" << endl;
	}
	else
		cout << "Bidding price is too low. Cannot bid item" << endl;
}

void Player::printSearch(const vector<Item> searches)
{
	cout << "Searches found: " << endl;
	for (const auto& search : searches) {
		search.print();
	}
}

// Searching is way less than O(n^2)
// This is done by first finding what type of item is it
// Then it iterates through the collection of that specific item only
// without having to iterate through all other irrelevant items
void Player::buy(Inventory& storage, string itemName)
{
	cout << "Buying item with name: " << itemName << endl;

	Item* selected;

	if (storage.hasSword(itemName)) {
		auto temp = storage.removeSword(itemName);
		selected = new Sword(temp);
	}
	else if (storage.hasAxe(itemName)) {
		auto temp = storage.removeAxe(itemName);
		selected = new Axe(temp);
	}
	else if (storage.hasHandgun(itemName)) {
		auto temp = storage.removeHandgun(itemName);
		selected = new Handgun(temp);
	}
	else if (storage.hasBomb(itemName)) {
		auto temp = storage.removeBomb(itemName);
		selected = new Bomb(temp);
	}
	else if (storage.hasArmor(itemName)) {
		auto temp = storage.removeArmor(itemName);
		selected = new Armor(temp);
	}
	else if (storage.hasHelmet(itemName)) {
		auto temp = storage.removeHelmet(itemName);
		selected = new Helmet(temp);
	}
	else if (storage.hasShield(itemName)) {
		auto temp = storage.removeShield(itemName);
		selected = new Shield(temp);
	}
	else if (storage.hasCostume(itemName)) {
		auto temp = storage.removeCostume(itemName);
		selected = new Costume(temp);
	}
	else if (storage.hasAccessory(itemName)) {
		auto temp = storage.removeAccessory(itemName);
		selected = new Accessory(temp);
	}
	else {
		selected = nullptr;
	}

	if (selected == nullptr) {
		cout << "Item not found. Cancelling buyout." << endl;
		return;
	}

	if (selected != nullptr && selected->getBuy() > money) {
		cout << "Not enough money to buy item. Cancelling buyout." << endl;
		return;
	}

	cout << endl;

	money -= selected->getBuy();
	selected->setBid(0);
	selected->setBuy(0);
	cout << "Current Balance: " << money << endl;

	if (ContainsSubstrictIgnoreCase(selected->getName(), "Sword") && dynamic_cast<Sword*>(selected) != nullptr) {
		inventory->addSword(*dynamic_cast<Sword*>(selected));
	}	
	else if (ContainsSubstrictIgnoreCase(itemName, "Axe") && dynamic_cast<Axe*>(selected) != nullptr) {
		inventory->addAxe(*dynamic_cast<Axe*>(selected));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Handgun") && dynamic_cast<Handgun*>(selected) != nullptr) {
		inventory->addHandgun(*dynamic_cast<Handgun*>(selected));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Bomb") && dynamic_cast<Bomb*>(selected) != nullptr) {
		inventory->addBomb(*dynamic_cast<Bomb*>(selected));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Armor") && dynamic_cast<Armor*>(selected) != nullptr) {
		inventory->addArmor(*dynamic_cast<Armor*>(selected));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Helmet") && dynamic_cast<Helmet*>(selected) != nullptr) {
		inventory->addHelmet(*dynamic_cast<Helmet*>(selected));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Shield") && dynamic_cast<Shield*>(selected) != nullptr) {
		inventory->addShield(*dynamic_cast<Shield*>(selected));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Costume") && dynamic_cast<Costume*>(selected) != nullptr) {
		inventory->addCostume(*dynamic_cast<Costume*>(selected));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Accessory") && dynamic_cast<Accessory*>(selected) != nullptr) {
		inventory->addAccessory(*dynamic_cast<Accessory*>(selected));
	}
	else {
		cout << "ERROR: Item was not added to inventory. ITEM DROPPED." << endl;
	}

	cout << endl;

	selected = nullptr;
	delete selected;
}

vector<Item> Player::search(const Inventory& storage, string search) {
	cout << "Searching for items with the following characters: " << search << endl;
	cout << endl;

	vector<Item> searches;

	cout << "Swords with the following characters: " << endl;
	auto swords = storage.getSwords();
	for (auto& sword : swords) {
		if (ContainsSubstrictIgnoreCase(sword.getName(), search)) {
			searches.push_back(Sword(sword));
		}
	}

	cout << endl;

	cout << "Axes with the following characters: " << endl;
	auto axes = storage.getAxes();
	for (auto& axe : axes) {
		if (ContainsSubstrictIgnoreCase(axe.getName(), search)) {
			searches.push_back(Axe(axe));
		}
	}

	cout << endl;

	cout << "Handguns with the following characters: " << endl;
	auto handguns = storage.getHandguns();
	for (auto& handgun : handguns) {
		if (ContainsSubstrictIgnoreCase(handgun.getName(), search)) {
			searches.push_back(Handgun(handgun));
		}
	}

	cout << endl;

	cout << "Bombs with the following characters: " << endl;
	auto bombs = storage.getBombs();
	for (auto& bomb : bombs) {
		if (ContainsSubstrictIgnoreCase(bomb.getName(), search)) {
			searches.push_back(Bomb(bomb));
		}
	}

	cout << endl;

	cout << "Armor with the following characters: " << endl;
	auto armors = storage.getArmors();
	for (auto& armor : armors) {
		if (ContainsSubstrictIgnoreCase(armor.getName(), search)) {
			searches.push_back(Armor(armor));
		}
	}

	cout << endl;

	cout << "Helmets with the following characters: " << endl;
	auto helmets = storage.getHelmets();
	for (auto& helmet : helmets) {
		if (ContainsSubstrictIgnoreCase(helmet.getName(), search)) {
			searches.push_back(Helmet(helmet));
		}
	}

	cout << endl;

	cout << "Shields with the following characters: " << endl;
	auto shields = storage.getShields();
	for (auto& shield : shields) {
		if (ContainsSubstrictIgnoreCase(shield.getName(), search)) {
			searches.push_back(Shield(shield));
		}
	}

	cout << endl;

	cout << "Costumes with the following characters: " << endl;
	auto costumes = storage.getCostumes();
	for (auto& costume : costumes) {
		if (ContainsSubstrictIgnoreCase(costume.getName(), search)) {
			searches.push_back(Costume(costume));
		}
	}

	cout << endl;

	cout << "Accessories with the following characters: " << endl;
	auto accessories = storage.getAccessories();
	for (auto& accessory : accessories) {
		if (ContainsSubstrictIgnoreCase(accessory.getName(), search)) {
			searches.push_back(Accessory(accessory));
		}
	}

	cout << endl;

	return searches;
}

void Player::placeAuction(Inventory & auctionStorage, Item * item, int startBid, int buyOut) {
	auto itemName = item->getName();

	cout << "Placing Item: " << itemName << endl;

	item->setBid(startBid);
	item->setBuy(buyOut);

	cout << "Bid Price :" << item->getBid() << endl;
	cout << "Buyout Price :" << item->getBuy() << endl;

	if (ContainsSubstrictIgnoreCase(itemName, "Sword") && inventory->hasSword(itemName) && dynamic_cast<Sword*>(item) != nullptr) {
		inventory->removeSword(itemName);
		auctionStorage.addSword(*dynamic_cast<Sword*>(item));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Axe") && inventory->hasAxe(itemName) && dynamic_cast<Axe*>(item) != nullptr) {
		inventory->removeAxe(itemName);
		auctionStorage.addAxe(*dynamic_cast<Axe*>(item));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Handgun") && inventory->hasHandgun(itemName) && dynamic_cast<Handgun*>(item) != nullptr) {
		inventory->removeHandgun(itemName);
		auctionStorage.addHandgun(*dynamic_cast<Handgun*>(item));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Bomb") && inventory->hasBomb(itemName) && dynamic_cast<Bomb*>(item) != nullptr) {
		inventory->removeBomb(itemName);
		auctionStorage.addBomb(*dynamic_cast<Bomb*>(item));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Armor") && inventory->hasArmor(itemName) && dynamic_cast<Armor*>(item) != nullptr) {
		inventory->removeArmor(itemName);
		auctionStorage.addArmor(*dynamic_cast<Armor*>(item));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Helmet") && inventory->hasHelmet(itemName) && dynamic_cast<Helmet*>(item) != nullptr) {
		inventory->removeHelmet(itemName);
		auctionStorage.addHelmet(*dynamic_cast<Helmet*>(item));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Shield") && inventory->hasShield(itemName) && dynamic_cast<Shield*>(item) != nullptr) {
		inventory->removeShield(itemName);
		auctionStorage.addShield(*dynamic_cast<Shield*>(item));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Costume") && inventory->hasCostume(itemName) && dynamic_cast<Costume*>(item) != nullptr) {
		inventory->removeCostume(itemName);
		auctionStorage.addCostume(*dynamic_cast<Costume*>(item));
	}
	else if (ContainsSubstrictIgnoreCase(itemName, "Accessory") && inventory->hasAccessory(itemName) && dynamic_cast<Accessory*>(item) != nullptr) {
		inventory->removeAccessory(itemName);
		auctionStorage.addAccessory(*dynamic_cast<Accessory*>(item));
	}
	else {
		cout << "Item is not recognized. Auction cancelled." << endl;
		return;
	}

	cout << itemName << " placed for auction" << endl;

	cout << endl;
}
