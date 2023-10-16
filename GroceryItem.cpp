#include "GroceryItem.h"


GroceryItem::GroceryItem(std::string& name)
	: name(name), quantity(1)
{
}

GroceryItem::GroceryItem(std::string& name, int quantity)
	: name(name), quantity(quantity)
{
}

std::string GroceryItem::getName() const
{
	return name;
}

int GroceryItem::getQuantity() const
{
	return quantity;
}