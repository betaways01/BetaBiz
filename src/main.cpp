#include "database.hpp"

int main() {
    // Create tables
    createTables();

    // Insert an item (you'll need to write this function)
    insertItem("Apple", "dozen", 10, 5.0, 10.0, 5.0, 50.0);

    // Update the item's name
    updateItem(1, "Red Apple");

    // Get and print all items
    getItems();

    return 0;
}
