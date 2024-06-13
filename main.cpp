#include <iostream>
#include <vector>
#include "Boat.h"

using namespace std;

int globalMinWeight = 100000;

void solve(Boat& curr_boat, Boat& best_boat) {
    if (curr_boat.cantAddMore(globalMinWeight)) {
        if (curr_boat.getTotalValue() > best_boat.getTotalValue()) {
            best_boat = curr_boat;
        }
    } else {
        for (int i = 0; i < curr_boat.getListSize(); i++) {
            if(curr_boat.getItemWeight(i) <= (curr_boat.getCapacity() - curr_boat.getTotalWeight())){
                curr_boat.addItem(i);
                solve(curr_boat, best_boat);
                curr_boat.removeItem();
            }
        }
    }
}


int main() {
    int capacity, num_items;

    cout << "Enter the weight capacity of the boat: ";
    cin >> capacity;

    cout << "Enter number of valuable items types: ";
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
    
    // Perform the recursive solving
    solve(curr_boat, best_boat);

    best_boat.print();

    return 0;
}

