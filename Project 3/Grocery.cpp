#include "Grocery.h"
#include "main.h"

// constructor
Grocery::Grocery(std::string item)
{
	name = item;
	quantity = 1;
}

// increases quantity
void Grocery::addItem()
{
	quantity++;
}

std::string Grocery::getNameOfItem() const
{
	return name;
}

int Grocery::getQuantityOfItem() const
{
	return quantity;
}

// method to load the inventory file
std::map<std::string, Grocery> Grocery::loadInventory(const std::string& filename)
{
	std::ifstream inFile;
	std::string item;
	std::map<std::string, Grocery> items;

	inFile = openFile(filename);

	if (!inFile.is_open())
	{
		std::cout << "File failed to open";
	}

	// reads in the lines in the file into the items map
	while (std::getline(inFile, item))
	{
		auto it = items.find(item);
		if (it == items.end())
		{
			items.emplace(item, Grocery(item));
		}
		else
		{
			it->second.addItem();
		}
	}

	inFile.close();
	return items;
}

