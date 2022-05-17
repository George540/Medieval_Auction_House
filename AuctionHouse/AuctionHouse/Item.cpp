#include "Item.h"
#include <string>
#include <iostream>

Item::Item() : label("NONAME"), buyprice(0), bidprice(0), form("NOFORM") {};

Item::~Item() {};

Item::Item(std::string id, int buy, int bid, std::string tp) : label(id), buyprice(buy), bidprice(bid), form(tp) {}

Item::Item(const Item& otherItem) : 
	label(otherItem.label), 
	buyprice(otherItem.buyprice),
	bidprice(otherItem.bidprice), 
	form(otherItem.form)
{};

void Item::print() const { std::cout << "[" << label << ", " << form << "]" << std::endl; }