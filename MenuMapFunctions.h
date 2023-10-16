#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "GroceryItem.h"
using namespace std;

/* Map Alias of std::map<std::string, std::unique_ptr<GroceryItem>>
 * Creates a map that uses the GroceryItem name as the Key and a unique_ptr<GroceryItem> object as value 
 * @param key - std::string - the name associated with each GroceryItem created
 * @param value - std::unique_ptr<GroceryItem>> - uses class constructors to create GroceryItem pointer Ojbects
 */
using GroceryItemMap = std::map<std::string, std::unique_ptr<GroceryItem>>;

/* Formats and outputs menu.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
void optionOne(GroceryItemMap& groceryItems);

/* Formats and outputs menu.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
void optionTwo(GroceryItemMap& groceryItems);

/* Formats and outputs menu.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
void optionThree(GroceryItemMap& groceryItems);

/* Formats and outputs menu.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @param int - programDriver variable
 * @returns int - integer value 4 is returned to break while loop
 */
int optionFour(GroceryItemMap& groceryItems, int programDriver);


/* Creates a string of characters equivalent to integer value
 * @param int - number of times the char value will be repeated.
 * @param char - character of choice
 * @returns string- 
 */
string repeatCharacter(int, char);

/* Formats and outputs menu.
 * @param - none
 * @returns - nothing
 */
void printMenu();

/*
 * This method writes the GroceryItem name and quantity to file.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - the populated Map of GroceryItem objects
 * @returns - nothing
 */
void writeOutputFile(GroceryItemMap& groceryItems);

/* Reads input file into GroceryItemMap.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
void readToMap(GroceryItemMap& groceryItems);

/* Handles User Input. Calls functions as necessary for each menu Item. Handles input Error as needed.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
int parseUserInput(GroceryItemMap& groceryItems);

/* Formats and outputs contents of GroceryItemMap with integer values for number of times the item was in the input file.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
void printWithInteger(GroceryItemMap& groceryItems);

/* Formats and outputs contents of GroceryItemMap with a histogram representation of occurances of items read into map.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
void printWithHistogram(GroceryItemMap& groceryItems);

/* Gets current time and creates string representation to add timestamp to backup file names.
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
string timeStampBuilder();

/* Combines "Backup" + timeStampBuilder() + ".dat" to create unique timestamped backup files
 * @param std::map<std::string, std::unique_ptr<GroceryItem>>& - none
 * @returns - nothing
 */
string outputFileNameBuilder();