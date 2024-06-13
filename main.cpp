// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include "Boat.h"
// using namespace std;

// int minValueItem = 0;

// void solve(Boat& curr_boat, Boat& best_boat) {
//     if (curr_boat.cantAddMore(minValueItem)) {
//         if (curr_boat.getTotalValue() > best_boat.getTotalValue()) {
//             best_boat = curr_boat;
//         }
//     } else {
//         for (int i = 0; i < curr_boat.getListSize(); i++) {
//             curr_boat.addItem(i);
//             solve(curr_boat, best_boat);
//             curr_boat.removeItem();
//         }
//     }
// }

// int main() {
//     int boatCapacity;
//     int numItems;

//     cout << "Enter the boat capacity: ";
//     cin >> boatCapacity;

//     cout << "Enter the number of items for boats: ";
//     cin >> numItems;

    // vector<Item> items;

    // // Loop to get weight and value for each item and store them in the vector
    // for (int i = 0; i < numItems; ++i) {
    //     int weight, value;
    //     cout << "Enter weight and value for item " << i + 1 << ": ";
    //     cin >> weight >> value;
    //     items.push_back(Item(weight, value));
    // }

    // // Display items stored in the vector
    // cout << "Items stored in the vector:" << endl;
    // for (size_t i = 0; i < items.size(); ++i) {
    //     const auto& item = items[i];
    //     cout << "Item" << i << " - Weight: " << item.weight << ", Value: " << item.value << endl;
    // }

//     // Find the minimum value item based on weight
//     if (!items.empty()) {
//         auto minValItem = min_element(items.begin(), items.end(), [](const Item& a, const Item& b) {
//             return a.value < b.value;
//         });
//         minValueItem = minValItem->weight;
//     }
//     cout<< "Min value found: " << minValueItem << endl;

//     // Create boats
//     Boat myBoat(boatCapacity);
//     Boat best_boat(boatCapacity);

    // // Perform the recursive solving
    // solve(myBoat, best_boat);

//     // Output the results
//     cout << "Best Boat Details:" << endl;
//     best_boat.print();
//     cout << "Best Boat Total Value: " << best_boat.getTotalValue() << endl;
//     cout << "Best Boat Number of Items: " << best_boat.getListSize() << endl;
//     cout << "Items in the Best Boat's Partial Solution:" << endl;
//     for (int index : best_boat.getPartialSolution()) {
//         cout << "Item" << index << " - Weight: " << items[index].weight << ", Value: " << items[index].value << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include "Boat.h"

using namespace std;

int globalMinWeight = 100000;

void solve(Boat& curr_boat, Boat& best_boat) {
    if(curr_boat.getTotalWeight() > curr_boat.getCapacity())
        cout << "ERROR " << endl;
    if (curr_boat.cantAddMore(globalMinWeight)) {
        if (curr_boat.getTotalValue() > best_boat.getTotalValue()) {
            best_boat = curr_boat;
        }
    } else {
        for (int i = 0; i < curr_boat.getListSize(); i++) {
            curr_boat.addItem(i);
            solve(curr_boat, best_boat);
            curr_boat.removeItem();
        }
    }
}


int main() {
    int capacity, num_items;

    cout << "Enter the weight capacity of the boat: ";
    cin >> capacity;

    cout << "Enter number of items for the boat: ";
    cin >> num_items;

    Boat curr_boat(capacity);
    Boat best_boat(capacity);

    vector<Item> items;

    // Loop to get weight and value for each item and store them in the vector
    for (int i = 0; i < num_items; ++i) {
        int weight, value;
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> weight >> value;
        curr_boat.boatItemList.push_back(Item(weight, value));

        if (weight < globalMinWeight) {
            globalMinWeight = weight;
        }
    }

    // Display items stored in the vector
    cout << "Items stored in the vector:" << endl;
    for (size_t i = 0; i < curr_boat.boatItemList.size(); ++i) {
        const auto& item = curr_boat.boatItemList[i];
        cout << "Item" << i << " - Weight: " << item.weight << ", Value: " << item.value << endl;
    }

    cout << "globalMinWeight = " << globalMinWeight<< endl;

    // Perform the recursive solving
    solve(curr_boat, best_boat);

    best_boat.print();

    return 0;
}

