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