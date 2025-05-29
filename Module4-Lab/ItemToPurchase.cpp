#include "ItemToPurchase.h"
#include <iostream>

std::string name;
int price, quantity;

ItemToPurchase::ItemToPurchase()
{
	itemName = "none";
	itemPrice = 0;
	itemQuantity = 0;
}

void ItemToPurchase::SetName(std::string name) { itemName = name; }
void ItemToPurchase::SetPrice(int price) { itemPrice = price; }
void ItemToPurchase::SetQuantity(int quantity) { itemQuantity = quantity; }

std::string ItemToPurchase::GetName() { return itemName; }
int ItemToPurchase::GetPrice() { return itemPrice; }
int ItemToPurchase::GetQuantity() { return itemQuantity; }

void ItemToPurchase::getItemInfo() 
{
	std::cout << "Enter the item name:\n";
	std::getline(std::cin >> std::ws, name);

	std::cout << "Enter the item price:\n";
	std::cin >> price;

	std::cout << "Enter the item quantity:\n";
	std::cin >> quantity;
}

void ItemToPurchase::setItemInfo()
{
	SetName(name);
	SetPrice(price);
	SetQuantity(quantity);
}

ItemToPurchase ItemToPurchase::operator*(ItemToPurchase rhs)
{
	ItemToPurchase product;

	product.itemPrice = itemPrice * rhs.itemQuantity;

	return product;
}

ItemToPurchase ItemToPurchase::operator+(ItemToPurchase rhs)
{
	ItemToPurchase totalPrice;

	totalPrice.itemPrice = itemPrice + rhs.itemPrice;

	return totalPrice;
}
