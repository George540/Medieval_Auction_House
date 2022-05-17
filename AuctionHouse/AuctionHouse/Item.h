#pragma once
#include <string>
class Item {
private:
	int buyprice;
	int bidprice;
	std::string label;
	std::string form;
public:
	Item();
	~Item();
	Item(std::string id, int buy, int bid, std::string tp);
	Item(const Item& otherItem);
	std::string getName() const { return label; };
	int getBuy() const { return buyprice; };
	int getBid() const { return bidprice; };
	std::string getType() const { return form; };
	void setBuy(int buy) { buyprice = buy; };
	void setBid(int bid) { bidprice = bid; };
	void setType(std::string tp) { form = tp; };
	virtual void print() const;
};