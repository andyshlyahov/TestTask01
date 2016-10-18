#include "OrderBook.h"
#include <iostream>

void OrderBook::insert(int timestamp, int id, float price)
{
	ordersList[id] = std::pair<int, float>(timestamp, price);
}

void OrderBook::erase(int id)
{
	ordersList.erase(id);
}

float OrderBook::currentMax()
{
	float currMax = std::numeric_limits<float>::min();

	for (auto it = ordersList.begin(); it != ordersList.end(); ++it)
	{
		if (it->second.second > currMax)
		{
			currMax = it->second.second;
		}
	}
	return currMax;
}

void OrderBook::showCurrentOrders()
{
	std::cout << "Inserted and non-erased orders:\n";

	for (auto it = ordersList.begin(); it != ordersList.end(); ++it)
	{
		std::cout << "Order #" << it->first << ":time = " << it->second.first << ";price = " << it->second.second << '\n';
	}
}
