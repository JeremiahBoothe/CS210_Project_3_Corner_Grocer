/* This program reads from a list of grocery items, stores them in a map with the item name as the key and a pointer to the class object as the value.  The map doesn't allow for duplicates, and when another purchase of an item is logged the quantity of that item is updated if it exists, if it doesn't exist the item is added to the map with a quantity of 1. The new output representing quantity of each item is written to a file dynamically named to represent the timestamp of the execution time, allowing for an incremental storage of the files that can easily be related to a specific date and time. The map is searchable with a menu option to display the quantity of an item as an integer value.  Other menu options allow for displaying the entire list with a quantity of integer values, with a histogram representation of quantity or to exit the program when finished. 
 * @author - Jeremiah Boothe
 * @date - 10/11/2023
 */
#include "MenuMapFunctions.h"

int main() 
{
	GroceryItemMap groceryItems;

	readToMap(groceryItems);
	
	writeOutputFile(groceryItems);

	parseUserInput(groceryItems);
	
	return 0;
}