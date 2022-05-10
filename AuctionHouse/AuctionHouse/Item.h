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
	inline std::string getName() const { return label; };
	inline int getBuy() const { return buyprice; };
	inline int getBid() const { return bidprice; };
	inline std::string getType() const { return form; };
	void setBuy(int buy);
	void setBid(int bid);
	void setType(std::string tp);
	virtual void print() const;
};