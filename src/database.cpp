#include <iostream>
#include "database.hpp"

sqlite3* connect() {
    sqlite3* db;
    int exit = sqlite3_open("./data/betabiz.db", &db);

    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
        return nullptr;
    } else {
        std::cout << "Opened database successfully!" << std::endl;
        return db;
    }
}


void createTables() {
    sqlite3* db = connect();
    char* messageError;

    std::string sql = "CREATE TABLE IF NOT EXISTS items ("
                      "id INTEGER PRIMARY KEY,"
                      "itemName TEXT,"
                      "units TEXT,"
                      "numberOfUnits INTEGER,"
                      "wholesalePrice REAL,"
                      "retailPrice REAL,"
                      "expectedProfit REAL,"
                      "percentageProfit REAL"
                      ");"
    
                      "CREATE TABLE IF NOT EXISTS purchases ("
                      "id INTEGER PRIMARY KEY,"
                      "itemId INTEGER,"
                      "dateOfPurchase TEXT,"
                      "amountOfPurchase REAL,"
                      "FOREIGN KEY(itemId) REFERENCES items(id)"
                      ");"
                      
                      "CREATE TABLE IF NOT EXISTS miscellaneous ("
                      "id INTEGER PRIMARY KEY,"
                      "date TEXT,"
                      "itemType TEXT,"
                      "amount REAL,"
                      "description TEXT"
                      ");"
                      
                      "CREATE TABLE IF NOT EXISTS cashClosing ("
                      "id INTEGER PRIMARY KEY,"
                      "date TEXT,"
                      "cash REAL,"
                      "bankMoney REAL,"
                      "total REAL"
                      ");"
                      
                      "CREATE TABLE IF NOT EXISTS credits ("
                      "id INTEGER PRIMARY KEY,"
                      "customerId INTEGER,"
                      "itemId INTEGER,"
                      "amount INTEGER,"
                      "price REAL,"
                      "date TEXT,"
                      "reminderDate TEXT,"
                      "FOREIGN KEY(itemId) REFERENCES items(id),"
                      "FOREIGN KEY(customerId) REFERENCES customers(id)"
                      ");"
                      
                      "CREATE TABLE IF NOT EXISTS customers ("
                      "id INTEGER PRIMARY KEY,"
                      "name TEXT,"
                      "contactInfo TEXT"
                      ");"
                      "CREATE TABLE IF NOT EXISTS sales ("
                      "id INTEGER PRIMARY KEY,"
                      "itemId INTEGER,"
                      "date TEXT,"
                      "quantitySold INTEGER,"
                      "totalAmount REAL,"
                      "FOREIGN KEY(itemId) REFERENCES items(id)"
                      ");";

    int exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table: " << messageError << std::endl;
        sqlite3_free(messageError);
    } else {
        std::cout << "Tables created successfully" << std::endl;
    }

    sqlite3_close(db);
}

/*CRUD Implementation*/
/* Create*/
void insertItem(const std::string& itemName, const std::string& units, int numberOfUnits, double wholesalePrice, double retailPrice, double expectedProfit, double percentageProfit) {
    sqlite3* db = connect();
    std::string sql = "INSERT INTO items (itemName, units, numberOfUnits, wholesalePrice, retailPrice, expectedProfit, percentageProfit) VALUES (?, ?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, itemName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, units.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, numberOfUnits);
    sqlite3_bind_double(stmt, 4, wholesalePrice);
    sqlite3_bind_double(stmt, 5, retailPrice);
    sqlite3_bind_double(stmt, 6, expectedProfit);
    sqlite3_bind_double(stmt, 7, percentageProfit);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

/*Read (select)*/
void getItems() {
    sqlite3* db = connect();
    std::string sql = "SELECT * FROM items;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* itemName = sqlite3_column_text(stmt, 1);
        // Continue retrieving other columns...
        std::cout << "Item: " << itemName << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

/*Update*/
 void updateItem(int id, const std::string& itemName) {
    sqlite3* db = connect();
    std::string sql = "UPDATE items SET itemName = ? WHERE id = ?;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, itemName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

/*Delete*/
void deleteItem(int id) {
    sqlite3* db = connect();
    std::string sql = "DELETE FROM items WHERE id = ?;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

