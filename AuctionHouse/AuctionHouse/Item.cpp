#include "Item.h"
#include <string>
#include <iostream>

Item::Item() : buyprice(0), bidprice(0) {};

Item::~Item() {};

Item::Item(std::string id, int buy, int bid, std::string tp) : label(id), buyprice(buy), bidprice(bid), form(tp) {}

void Item::setBuy(int buy) { buyprice = buy; }

void Item::setBid(int bid) { bidprice = bid; }

void Item::setType(std::string tp) { form = tp;  }

void Item::print() const { std::cout << "[" << label << ", " << form << "]" << std::endl; }