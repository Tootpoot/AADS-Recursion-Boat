#ifndef BOAT_H
#define BOAT_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

class Boat {
public:
    Boat(int capacity);
    Boat(); //Dummy constructor
    int getCapacity() const;
    void print() const;
    bool cantAddMore(const Boat& boat, int minValueItem) const;
    void addItem(const Item& item);
    void removeItem();
    const vector<Item>& getItems() const;
    int getTotalValue() const;  // Method to calculate total value
    int getNumberOfItems() const;  // Method to get number of items

private:
    int capacity;
    vector<Item> items;
};

#endif // BOAT_H
