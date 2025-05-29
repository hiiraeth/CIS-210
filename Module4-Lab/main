#include "ItemToPurchase.h"
#include <iostream>

int main()
{
	ItemToPurchase item1;
	ItemToPurchase item2;
	ItemToPurchase product;
	int total1, total2;
	
	std::cout << "Item 1\n";
	item1.getItemInfo();
	item1.setItemInfo();
	std::cin.ignore();

	std::cout << "\nItem 2\n";
	item2.getItemInfo();
	item2.setItemInfo();
	product = item1 * item1;
	total1 = product.GetPrice();

	std::cout << "\nTOTAL COST\n";
	std::cout << item1.GetName() << " " << item1.GetQuantity() << " @ $"
		<< item1.GetPrice() << " = $" << product.GetPrice();

	product = item2 * item2;
	total2 = product.GetPrice();
	std::cout << "\n" << item2.GetName() << " " << item2.GetQuantity() << " @ $"
		<< item2.GetPrice() << " = $" << product.GetPrice();

	std::cout << "\n\nTotal: $" << total1 + total2 << "\n";
}
