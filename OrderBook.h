#pragma once

#include <map>

class OrderBook
{
public:
	void insert(int timestamp, int id, float price);
	void erase(int id);
	float currentMax();
	void showCurrentOrders();
private:
	std::map<int, std::pair<int, float>> ordersList;
};