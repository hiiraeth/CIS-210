#pragma once
#ifndef GROCERY_H
#define GROCERY_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>

class Grocery
{
public:
	Grocery(std::string item);

	void addItem();
	std::string getNameOfItem() const;
	int getQuantityOfItem() const;

	static std::map<std::string, Grocery> loadInventory(const std::string& filename);

private:
	std::string name;
	int quantity;
};

#endif
