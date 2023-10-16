/* - General includes for attempts 1-7
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include "GroceryItem.h"

using namespace std;
*/



// ****TODO: Attempt 8 - good starting point for this experiment attempt at using a callback to override class functions from outside a class to work in addItem() and removeItem() as class specific functions****
#pragma once
#include <string>
#include <functional>

#pragma once
#include<string>
#include<functional>
GroceryItem Class - to create pointer objects of type GroceryItem.


class GroceryItem {
public:
	/* Constructor called for Items not already in GroceryItemMap.  Sets quantity to 1 on first add.
	 * @param string& - the name read from input file to represent item
	 * @returns - constructed GroceryItem
	 */
	GroceryItem(std::string& name);

	/* Constructor called when Item already exists in GroceryItem.  Used to replace the previous item with the incremented value.
	 * @param string& - the name read from input file to represent item
	 * @returns - constructed GroceryItem with new quantity incremented for each occurance
	 */
	GroceryItem(std::string& name, int quantity);

	/* Retrieves the name of GroceryItem
	 * @param value - none
	 * @returns const std::string - name of GroceryItem
	 */
	std::string getName() const;

	/* Retrieves the quantity of GroceryItem
	 * @param - none
	 * @returns const int - quantity of item purchased
	 */
	int getQuantity() const;

	void addItem(std::function<void(const GroceryItem&)> callback) {
		onItemProcessedCallback = callback;
	}

	void addItem() {
		// Perform item processing logic...

		// Notify the callback function
		if (onItemProcessedCallback) {
			onItemProcessedCallback(*this);
		}
	}

private:
	std::string name;
	int quantity;

	std::function<void(const GroceryItem&)> onItemProcessedCallback;

};


void customProcessingLogic(const GroceryItem& item) {
	// Custom processing logic...
	std::cout << "Item processed: " << item.getName() << std::endl;
}

int main() {
	// Might work with the auto generation method after the next return 0;?
	GroceryItem item("ExampleItem");

	// Set the callback function?
	item.addItem(customProcessingLogic);

	// Process the item?
	item.processItem();

	return 0;
}

while (!inFS.eof()) {
		while (inFS >> name) {

			auto groceryIterator = groceryItems.find(name);
			if (groceryIterator != groceryItems.end()) {
				int quantity = groceryIterator->second->getQuantity();
				quantity += 1;
				auto myobj = std::make_unique<GroceryItem>(name, quantity);
				groceryItems.erase(groceryIterator);
				groceryItems.insert({ name, std::move(myobj) });

			}
			else {
				auto myobj = std::make_unique<GroceryItem>(name);
				groceryItems.insert({ name, std::move(myobj) });
			}
		}
	}
*/





/* TODO: attempt 7
 std::map<std::string, std::unique_ptr<GroceryItem>> readToMap(std::map<string, std::unique_ptr<GroceryItem>> groceryItems) {

	 ifstream inFS;

	 string readString;
	 int readInt;

	 std::string name;
	 int quantity = 0;

	 cout
		 << "Opening file CS210_Project_Three_Input_File.txt"
		 << endl;
	 inFS.open("CS210_Project_Three_Input_File.txt");


	 if (!inFS.is_open()) {
		 cout
			 << "Could not open file CS210_Project_Three_Input_File.txt."
			 << endl;
	 }

	 cout
		 << "Writing File: CS210_Project_Three_Input_File.txt"
		 << endl;

	 for (int i = 0; i < 10; ++i) {
		 //name = "STRING";
		 //quantity = 0.7;

		 // Dynamically generate a name (e.g., "Account0", "Account1", ...)
		 std::string name = "Account" + std::to_string(i);

		 auto myobj = std::make_unique<GroceryItem>(name, quantity);

		 // Insert into the map using the generated name as the key
		 groceryItems.insert({ name, std::move(myobj) });
	 }

	 cout
		 << "Closing CS210_Project_Three_Input_File.txt"
		 << endl
		 << endl;
	 inFS.close();

	 return groceryItems;

 }



std::map<std::string, std::unique_ptr<GroceryItem>> readToMap(std::map<std::string, std::unique_ptr<GroceryItem>> groceryItems) {

	ifstream inFS;
	string groceryItemList;

	if (!inFS.is_open()) {
		cout
			<< "Could not open file CS210_Project_Three_Input_File.txt."
			<< endl;
	}

	cout
		<< "Writing File: CS210_Project_Three_Input_File.txt"
		<< endl;

	cout
		<< "Opening file CS210_Project_Three_Input_File.txt"
		<< endl;
	inFS.open("CS210_Project_Three_Input_File.txt");

	//ifstream inFS;


	//string readString;
	//int readInt;

	std::string name;
	int quantity = 0;

	for (int i = 0; i < 10; ++i) {
		//name = "STRING";
		//quantity = 0.7;
		// Dynamically generate a name (e.g., "Account0", "Account1", ...)
		std::string name = "Account" + std::to_string(i);
		auto myobj = std::make_unique<GroceryItem>(name, quantity);
		// Insert into the map using the generated name as the key
		groceryItems.insert({ name, std::move(myobj) });
	}



	return groceryItems;

} */





/* TODO: Attempt 6
 * This method reads fahrenheightTemperature.txt into vector objects
 * @param std::vector<cities> - the empty vector for city objects
 * @returns std::vector<cities> - the now populated vector of city objects
 */
 /*
 std::map<std::string, GroceryItem> readToMap(std::map<std::string, GroceryItem> groceryItems) {

	 ifstream inFS;

	 string readString;
	 int readInt;

	 cout
		 << "Opening file FahrenheitTemperature.txt"
		 << endl;
	 inFS.open("FahrenheitTemperature.txt");


	 if (!inFS.is_open()) {
		 cout
			 << "Could not open file FahrenheitTemperature.txt."
			 << endl;
	 }

	 cout
		 << "Writing File: FahrenheitTemperature.txt"
		 << endl;

	 while (!inFS.eof()) {

		 inFS >> readString;
		 inFS >> readInt;

		 //cities city;
		 //city.setName(readString);
		 //city.setTemp(readInt);
		 //cityTemperatures.push_back(city);
	 }
	 cout
		 << "Closing FahrenheitTemperature.txt"
		 << endl
		 << endl;
	 inFS.close();

	 return groceryItems;

 }
 */






 /* TODO: Attempt 5
  * This method writes the vector objects to celsiusTemperature.
  * @param std::vector<cities> - the populated vector of city objects
  * @returns - nothing
  */
  /*
  void writeOutputFile(std::map<std::string, GroceryItem>& groceryItems) {

	  ofstream outFS;

	  cout
		  << "Opening file CelsiusTemperature.txt"
		  << endl;


	  outFS.open("CelsiusTemperature.txt");

	  if (!outFS.is_open()) {
		  cout
			  << "Could not open file CelsiusTemperature.txt."
			  << endl;
	  }

	  cout
		  << "Writing File: CelsiusTemperature.txt"
		  << endl;

	  for (const auto& pair : groceryItems) {
		  const std::string& itemName = pair.first;
		  const GroceryItem& quantity = pair.second;

		  //const std::string itemName = item.getName();
		  //int itemQuantity = item.getQuantity();

		  //double celsius = convertToCelsius(cityTemp);

		  outFS
			  << itemName
			  << " "
			  << fixed
			  << setprecision(2)
			  << pair.second->getQuantity
			  << endl;
	  }
	  cout
		  << "Closing CelsiusTemperature.txt"
		  << endl
		  << endl;
	  outFS.close();
  }*/











  /* TODO: attempt 4
  int main() {
	  set<GroceryItem> items;
	  ifstream inFs;

	  string readString;
	  int readInt;

	  //string itemName = "";
	  //string* item;
	  //GroceryItem->item;


	  //auto existingItem = items.find(*item);

	  if (existingItem != items.end()) {

	  }

	  for (GroceryItem item : items) {

	  }

	  return 0;
  }*/













/* TODO: Attempt 3
int main() {
	std::map<std::string, std::unique_ptr<GroceryItem>> groceryItems;
	//std::multimap<std::string, std::unique_ptr<InvestmentAccount>> investmentAccounts;


	readToMap(groceryItems);

	// wrap the following code through the for loop in a function that populates the map
	std::string name;
	int quantity = 0;

	for (int i = 0; i < 10; ++i) {
		//name = "STRING";
		//quantity = 0.7;

		// Dynamically generate a name (e.g., "Account0", "Account1", ...)
		std::string name = "Account" + std::to_string(i);

		auto myobj = std::make_unique<GroceryItem>(name, quantity);

		// Insert into the map using the generated name as the key
		groceryItems.insert({ name, std::move(myobj) });
	}

	std::string additionalName = "Account11";

	auto additionalAccount = std::make_unique<GroceryItem>(additionalName, 66);

	// Insert the additional account into the map
	groceryItems.insert({ additionalName, std::move(additionalAccount) });

	//InvestmentAccount Account0(33.00, 500.00);
	//investmentAccounts.emplace(std::move(Account0));

	auto it = groceryItems.find(additionalName);
	if (it != groceryItems.end()) {
		//Update the initialAmount for the existing account
		//it->second->quantity(15);  // Change 15.0 to the new initialAmount
	}
	else {
		std::cout << "Account not found." << std::endl;
	}

	// Accessing elements by name
	for (const auto& pair : groceryItems) {
		const std::string& name = pair.first;
		const int& quantity = pair.second->getQuantity();

		// Do something with accountName and account
		std::cout << name << ": " << pair.second->getName() << ", " << pair.second->getQuantity() << std::endl;

		continue;
	}

	cout << "";

	return 0;
} */


/* TODO: Attempt 2
int main() {
	std::map<std::string, std::unique_ptr<InvestmentAccount>> investmentAccounts;

	double initialAmount = 0.0;
	double annualInterestRate = 0.0;

	for (int i = 0; i < 10; ++i) {
		initialAmount += 0.5;
		annualInterestRate += 0.7;

		// Dynamically generate a name (e.g., "Account0", "Account1", ...)
		std::string accountName = "Account" + std::to_string(i);

		auto myobj = std::make_unique<InvestmentAccount>(initialAmount, annualInterestRate);

		// Insert into the map using the generated name as the key
		investmentAccounts.insert({ accountName, std::move(myobj) });
	}

	std::string additionalAccountName = "Account0";

	auto additionalAccount = std::make_unique<InvestmentAccount>(33.0, 66.0);

	// Insert the additional account into the map
	investmentAccounts.insert({ additionalAccountName, std::move(additionalAccount) });

	//InvestmentAccount Account0(33.00, 500.00);
	//investmentAccounts.emplace(std::move(Account0));

	auto it = investmentAccounts.find(additionalAccountName);
	if (it != investmentAccounts.end()) {
		// Update the initialAmount for the existing account
		it->second->setInitialAmount(15.0);  // Change 15.0 to the new initialAmount
	}
	else {
		std::cout << "Account not found." << std::endl;
	}

	// Accessing elements by name
	for (const auto& pair : investmentAccounts) {
		const std::string& accountName = pair.first;
		InvestmentAccount& account = *(pair.second);

		// Do something with accountName and account
		std::cout << accountName << ": " << account.getInitialAmount() << ", " << account.getAnnualInterestRate() << std::endl;

		continue;
	}



	cout << "";

	return 0;
}*/












/* TODO: Attempt 1
int main() {
	std::vector<std::unique_ptr<InvestmentAccount>> investmentAccounts;
	//std::vector<std::shared_ptr<InvestmentAccount>> investmentAccounts;
	//std::vector<std::make_unique<InvestmentAccount>> investmentAccounts;

	// Bad Idea
	//InvestmentAccount* myobj = new InvestmentAccount(3.0, 4.0);
	// ...
	//delete myobj;

	double initialAmount = 0.0;
	double annualInterestRate = 0.0;
	int monthlyDeposit = 0.0;
	int length = 3;

	for (int i = 0; i < 10; ++i) {
		initialAmount += .5;
		annualInterestRate += .7;
		monthlyDeposit = 50;

		// Good Idea
		//auto myobj = std::make_unique<InvestmentAccount>(initialAmount, annualInterestRate); // C++14
		//auto myobj = std::unique_ptr<InvestmentAccount>(new InvestmentAccount(constructor_param1, constructor_param2)); // C++11
		//auto mybuffer = std::make_unique<char[]>(length); // C++14
		//auto mybuffer = std::unique_ptr<char[]>(new char[length]); // C++11
		// or for reference counted objects
		//auto myobj = std::make_shared<InvestmentAccount>(initialAmount, annualInterestRate);
		// ...
		// myobj is automatically freed for you whenever it is no longer used.
		//investmentAccounts.push_back(std::move(myobj));

		//push_back for make_shared
		//investmentAccounts.push_back(myobj);

		InvestmentAccount myobj = std::make_unique<string[]>(length);
		//investmentAccounts.push_back(std::make_unique<InvestmentAccount>(initialAmount, annualInterestRate, monthlyDeposit));

		auto& account = *investmentAccounts[i];
		// Update the values of the object

		account.setInitialAmount(initialAmount);
		account.setAnnualInterestRate(annualInterestRate);

		continue;
	}


	return 0;
}*/