#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "sqlite/sqlite3.h"
#include <string>

void createTables();
void insertItem(const std::string& itemName, const std::string& units, int numberOfUnits, double wholesalePrice, double retailPrice, double expectedProfit, double percentageProfit);
void getItems();
void updateItem(int id, const std::string& itemName);
void deleteItem(int id);

#endif // DATABASE_HPP
