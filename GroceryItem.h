#pragma once
#include<string>
#include<functional>

/* GroceryItem Class - to create pointer objects of type GroceryItem.
 * 
 */
extern class GroceryItem {

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

	private:
		std::string name;
		int quantity;
};