#include "DefenseItem.h"
#include <iostream>
#include <string>
using namespace std;

DefenseItem::DefenseItem() : Item(), defense(0) {};

DefenseItem::~DefenseItem() {};

DefenseItem::DefenseItem(string name, int buy, int bid, string tp, int def) : Item(name, buy, bid, tp), defense(def) {};

void DefenseItem::setDefense(int def) { defense = def; }