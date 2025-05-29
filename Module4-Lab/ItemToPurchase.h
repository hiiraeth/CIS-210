#pragma once
#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>

class ItemToPurchase
{
public:
	ItemToPurchase();

	void setItemInfo();
	void SetName(std::string name);
	void SetPrice(int price);
	void SetQuantity(int quantity);

	std::string GetName();
	int GetPrice();
	int GetQuantity();
	void getItemInfo();

	ItemToPurchase operator*(ItemToPurchase rhs);
	ItemToPurchase operator+(ItemToPurchase rhs);
private:
	std::string itemName;
	int itemPrice;
	int itemQuantity;
};

#endif
