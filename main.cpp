#include <iostream>
#include <stack>
#include "Boat.h"
using namespace std;

int minValueItem = 0; // Global variable

void solve(Boat &curr_boat, Boat &best_boat, stack<Item>& itemStack, const vector<Item>& items) {
    if(curr_boat.cantAddMore(minValueItem)){
        if(curr_boat.getTotalValue() > best_boat.getTotalValue()){
            best_boat = curr_boat;
        }
    }
    else {
        for(int i = 0; i< curr_boat.getNumberOfItems(); i++){
            itemStack.push(items[i]);
            solve(curr_boat, best_boat, itemStack, items);
            curr_boat.removeItem();
        }
    }
}

int main() {
    int boatCapacity;

    // Ask the user for the boat capacity
    cout << "Enter the boat capacity: ";
    cin >> boatCapacity;

    // Create a Boat object with user-provided capacity
    Boat myBoat(boatCapacity);

    int numItems;

    // Prompt the user for the number of items
    cout << "Enter the number of items: ";
    cin >> numItems;

    // Create a vector to hold Items
    vector<Item> items;

    // Loop to get weight and value for each item and store them in the vector
    for (int i = 0; i < numItems; ++i) {
        int weight, value;
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    // Display items stored in the vector
    cout << "Items stored in the vector:" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        const auto& item = items[i];
        cout << "Item" << i << " - Weight: " << item.weight << ", Value: " << item.value << endl;
    }

    // Determine the minimum value item
    if (!items.empty()) {
        auto minValItem = min_element(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.value < b.value;
        });
        minValueItem = minValItem->weight;
    }

    // Create a stack to hold Items
    stack<Item> itemStack;

    // // Push items from the vector to the stack if they can be added to the boat
    // for (const auto& item : items) {
    //     if (!myBoat.cantAddMore(myBoat, minValueItem)) {
    //         itemStack.push(item);
    //         myBoat.addItem(item);
    //     } else {
    //         cout << "Cannot add item with weight: " << item.weight << " and value: " << item.value << " as it exceeds boat capacity." << endl;
    //     }
    // }

    // Display the boat's current state
    // myBoat.print();

    //Create empty boat object
    Boat best_boat;
    // Call the function to demonstrate accessing minValueItem
    solve(myBoat, best_boat, itemStack, items);

    if(best_boat.getTotalValue() < std::numeric_limits<int>::max())
        best_boat.print(itemStack);
    else   
        cout << "No answer found. \n";

    // // Access and pop items from the stack
    // cout << "Removing items from the stack and boat:" << endl;
    // while (!itemStack.empty()) {
    //     Item topItem = itemStack.top();
    //     cout << "Removing item with Weight: " << topItem.weight << ", Value: " << topItem.value << endl;
    //     itemStack.pop();
    //     myBoat.removeItem();
    // }

    // // Display the boat's final state
    // myBoat.print();

    // // Demonstrate accessing items stored in the boat
    // const vector<Item>& storedItems = myBoat.getItems();
    // cout << "Accessing items stored in the boat:" << endl;
    // for (size_t i = 0; i < storedItems.size(); ++i) {
    //     const auto& item = storedItems[i];
    //     cout << "Item" << i << " - Weight: " << item.weight << ", Value: " << item.value << endl;
    // }

    return 0;
}
