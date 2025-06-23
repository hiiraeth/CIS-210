#include "Grocery.h"

// creates the frequency.dat backup file
void frequencyBackup(std::string fileName, std::map<std::string, Grocery> items)
{
	std::ofstream backup(fileName);

	//checks to make sure that the file was created
	if (backup.is_open())
	{
		std::cout << "frequency.dat successfully created.\n\n";
	}
	else
	{
		std::cout << "Failed to create frequency.dat.\n\n";
		system("exit");
	}

	// adds all items and frequencies to .dat backup file
	for (auto const& item : items)
	{
		backup << item.first
			<< ' '
			<< item.second.getQuantityOfItem() << '\n';
	}

	backup.close();
}

void printMainMenu()
{
	std::cout << "|- 1. Find item\n"
		"|- 2. Item frequency\n"
		"|- 3. Item histrogram\n"
		"|- 4. Exit program\n\n";
}

// gets the user input for the main menu choice
int mainMenu()
{
	unsigned int choice;
	using namespace std;

	cout << "Enter option: ";

	cin >> choice;
	return choice;
}

// validation to check if user input is valid
bool checkIfMenuValid(int choice)
{
	if ((choice < 1 || choice > 4) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');

		std::cout << "Please enter a valid menu option.\n\n";
		std::cout << "Enter option: ";
		return false;
	}
	return true;
}

// function to open the file that will be used in main
std::ifstream openFile(std::string file)
{
	if (std::cin.fail())
	{
		std::cout << "Invalid name.";
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	std::ifstream fileToOpen;
	fileToOpen.open(file);

	return fileToOpen;
}

// conducts all the operations based on user choice
void menuChoice(int selection)
{
	std::map<std::string, Grocery> items;
	items = Grocery::loadInventory("inventory.txt");
	std::string groceryItem;

	switch (selection)
	{
	case 1: // looks up item and returns the frequency based on user input
	{
		std::cout << "Enter name of item: ";
		std::cin >> groceryItem;
		std::cout << '\n';

		auto it = items.find(groceryItem);
		if (it != items.end())
		{
			std::cout << it->first
				<< ' '
				<< it->second.getQuantityOfItem() << '\n';
		}
		else 
		{
			std::cout << groceryItem << " was not found. Note it is case sensitive, and items are plural.\n";
		}
		break;
	}

	case 2: // returns a list of all items and their frequencies
		for (auto const& item : items)
		{
			std::cout << item.first
				<< ' '
				<< item.second.getQuantityOfItem() << '\n';
		}
		break;

	case 3: // returns a histogram of items and asterisks based on freq.
		for (auto const& item : items)
		{
			int quantity = item.second.getQuantityOfItem();

			std::cout << item.first
				<< ' '
				<< std::string(quantity, '*') << '\n';
		}
		break;

	case 4: // exits program
		std::cout << "Thank you for using the database. Goodbye!\n";
		break;

	default:
		break;
	}

}

// main program loop
int main()
{
	std::map<std::string, Grocery> items;

	// try-catch block to make sure backup file is created
	try
	{
		items = Grocery::loadInventory("inventory.txt");
		frequencyBackup("frequency.dat", items);
	}
	catch (std::exception e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}

	unsigned int mainMenuChoice = 0;
	std::cout << "Welcome to the Corner Grocer database." << std::endl;
	std::cout << "Please select from one of the following options:" << std::endl;

	// main program loop
	do {
		std::cout << "\n------------------------------------------------\n";
		printMainMenu();
		mainMenuChoice = mainMenu();

		system("cls");

		// input validation to check user input
		if (!checkIfMenuValid(mainMenuChoice))
		{
			std::cin >> mainMenuChoice;
			continue;
		}

		menuChoice(mainMenuChoice);
	} while (mainMenuChoice != 4);

	return 0;
}
