#include "MenuMapFunctions.h"

string timeStampBuilder() 
{
	time_t currentTime = time(0);
	tm nowTimeStructure = {};
	char buffer[26] = {};


	localtime_s(&nowTimeStructure, &currentTime);
	asctime_s(buffer, 26, &nowTimeStructure);
	strftime(buffer, sizeof(buffer), "_%d_%m_%Y_%H_%M_%S", &nowTimeStructure);
	
	std::string timeStamp(buffer);
	
	return timeStamp;
}

string outputFileNameBuilder() 
{
	string fileName = "frequency";
	string fileType = ".dat";

	string timeStampCreator = timeStampBuilder();
	string timeStamp = timeStampCreator;

	string outputFileName = fileName + timeStamp + fileType;

	return outputFileName;
}

void optionOne(GroceryItemMap& groceryItems)
{

	string searchItem;
	string enterItem = " Please enter an Item to search for: ";

	cout 
		<< endl
		<< enterItem;

	cin 
		>> searchItem;

	for (int i = 0; i < searchItem.length(); ++i) {
		searchItem.at(i) = tolower(searchItem.at(i)); // converts string to lowercase
	}

	searchItem[0] = toupper(searchItem[0]); // converts the first letter to uppercase

	auto groceryIterator = groceryItems.find(searchItem);

	if (groceryIterator != groceryItems.end()) {
		system("CLS");
		cout
			<< repeatCharacter(51, '*')
			<< endl
			<< endl
			<< " "
			<< groceryIterator->first
			<< ": "
			<< groceryIterator->second->getQuantity()
			<< endl
			<< endl;

	}
	else {
		string error = "Item does not exist, please try again.";
		cout
			<< endl
			<< error
			<< endl
			<< endl;
		optionOne(groceryItems);
	}
	

}

void optionTwo(GroceryItemMap& groceryItems)
{
	system("CLS");
	printWithInteger(groceryItems);
}

void optionThree(GroceryItemMap& groceryItems)
{
	system("CLS");
	printWithHistogram(groceryItems);
}

int optionFour(GroceryItemMap& groceryItems, int programDriver)
{
	programDriver = 4;
	groceryItems.clear();
	return programDriver;
}

void writeOutputFile(GroceryItemMap& groceryItems) 
{

	ofstream outFS;
	string outputFileName = outputFileNameBuilder();

	cout
		<< " Opening file "
		<< outputFileName
		<< endl;

	outFS.open(outputFileName);

	if (!outFS.is_open()) {
		cout
			<< " Could not open file "
			<< outputFileName
			<< endl;
		system("pause");
		exit(-1);

	}

	cout
		<< " Writing File: "
		<< outputFileName
		<< endl;

	for (const auto& pair : groceryItems) {

		outFS
			<< pair.first
			<< " "
			<< pair.second->getQuantity()
			<< endl;
	}
	cout
		<< " Closing: "
		<< outputFileName
		<< endl
		<< endl;
	outFS.close();
	system("CLS");
}

void readToMap(GroceryItemMap& groceryItems)
{
	ifstream inFS;
	std::string name;
	string inputFileName = "CS210_Project_Three_Input_File.txt";

	cout
		<< " Opening file "
		<< inputFileName
		<< endl;

	inFS.open(inputFileName);


	if (!inFS.is_open()) {
		cout
			<< " Could not open file "
			<< inputFileName
			<< endl;
		system("pause");
		exit(-1);

	}

	cout
		<< " Writing File: "
		<< inputFileName
		<< endl;
	
	/* ***Note*** See TODO: Attempt 8 in ScratchFile.cpp(included in folder but not in the project), for attempted implementation of callback method to override addItem() in GroceryItem, while avoiding inheritance. 
	*/
	while (!inFS.eof()) {
		while (inFS >> name) {

			auto groceryIterator = groceryItems.find(name); // to find GroceryItem in map
			
			if (groceryIterator != groceryItems.end()) {
				int quantity = groceryIterator->second->getQuantity(); // retrieve the quantity of current GroceryItem in iteration
				
				quantity += 1;

				auto newGroceryItem = std::make_unique<GroceryItem>(name, quantity); // create unique GroceryItem pointer to store in map value
				
				groceryItems.erase(groceryIterator); // erase existing GroceryItem from map
				groceryItems.insert({ name, std::move(newGroceryItem) }); // insert new GroceryItem into map using the name as the key, and the object as the value

			}
			else {
				auto newGroceryItem = std::make_unique<GroceryItem>(name); // create unique GroceryItem pointer to store in map value
				groceryItems.insert({ name, std::move(newGroceryItem) }); // insert new GroceryItem into map using the name as the key, and the object as the value
			}
		}
	}
	cout
		<< "Closing "
		<< inputFileName
		<< endl
		<< endl;
	inFS.close();
	system("CLS");
}

int parseUserInput(GroceryItemMap& groceryItems) 
{

	int programDriver = 0;

	while (programDriver != 4) {
		//system("cls");

		// Print menu
		printMenu();

		// Get user choice
		int choice;

		cout << " Enter your choice: ";
		cin >> choice;

		// Handle user choice
		switch (choice) {
		case 1:
			optionOne(groceryItems);
			break;
		case 2:
			optionTwo(groceryItems);
			break;
		case 3:
			optionThree(groceryItems);
			break;
		case 4:
			optionFour(groceryItems, programDriver);
			cout << endl << " Daily Tally Complete!\n";
			return 0;
		default:
			cout << "\n Invalid choice. Please try again.\n";
			system("pause");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
	}
	return 0;
}

string repeatCharacter(int length, char characterToRepeat) {
	return string(length, characterToRepeat);
}

void printMenu() 
{
	int length = 51;
	string asterisks = repeatCharacter(length, '*');
	string optionOne = " 1 - Search for Item Purchased and Display Quantity";
	string optionTwo = " 2 - Daily Purchases with Integer Quantity";
	string optionThree = " 3 - Daily Purchases with Histogram Quantity";
	string optionFour = " 4 - Exit Program";

	cout
		<< endl
		<< asterisks 
		<< endl;
	cout << optionOne << endl;
	cout << optionTwo << endl;
	cout << optionThree << endl;
	cout << optionFour << endl;
	cout
		<< asterisks 
		<< endl << endl;
}

void printWithInteger(GroceryItemMap& groceryItems) 
{
	std::cout
		<< repeatCharacter(51, '*')
		<< endl;

	// Accessing elements by name
	for (const auto& pair : groceryItems) {
		const std::string& name = pair.first;
		const int& quantity = pair.second->getQuantity();

		std::cout
			<< " "
			<< name 
			<< ": "
			<< quantity
			<< std::endl;
		continue;
	}
}

void printWithHistogram(GroceryItemMap& groceryItems)
{
	std::cout
		<< repeatCharacter(51, '*')
		<< endl;

	// Accessing elements by name
	for (const auto& pair : groceryItems) {
		const std::string& name = pair.first;
		const int& quantity = pair.second->getQuantity();
		
		string asterisks;
		int i;

		for (i = 0; i < quantity; ++i) {
			asterisks += repeatCharacter(1, '$');
		}
			
		std::cout
			<< " "
			<< name 
			<< ": "
			<< asterisks
			<< std::endl;

		continue;
	}
}