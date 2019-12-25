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
using namespace std;

AuctionHouse::AuctionHouse() : storage() {
	Sword sword1 = Sword("Brandish", 1000, 0, "normal", 2, 6);
	Sword sword2 = Sword("Avenger", 32000, 5000, "elemental", 6, 3);
	Sword sword3 = Sword("Ice Calibur", 15000, 3500, "ice", 4, 5);
	Sword sword4 = Sword("Executor Blade", 23000, 1500, "elemental", 5, 8);
	Sword sword5 = Sword("Tutrus Knife", 2400, 500, "shadow", 3, 5);
	Sword sword1 = Sword("Brandish", 1000, 0, "normal", 2, 6);
}