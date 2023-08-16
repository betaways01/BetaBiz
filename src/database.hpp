#include "sqlite/sqlite3.h"

void createTables();
void insertItem(const std::string& itemName, const std::string& units, int numberOfUnits, double wholesalePrice, double retailPrice, double expectedProfit, double percentageProfit);
void getItems();
void updateItem(int id, const std::string& itemName);
void deleteItem(int id);