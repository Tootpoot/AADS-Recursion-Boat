#ifndef BOAT_H
#define BOAT_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Item {
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

class Boat {
public:
    Boat(int capacity);
    Boat();
    int getCapacity() const;
    void print(stack<Item> itemStack) const;
    bool cantAddMore(int minValueItem) const;
    void addItem(const Item& item);
    void removeItem();
    const vector<Item>& getItems() const;
    int getTotalValue() const;
    int getNumberOfItems() const;

private:
    int capacity;
    vector<Item> items;
};

#endif // BOAT_H
