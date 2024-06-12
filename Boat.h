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
    int getCapacity() const;
    void print() const;
    bool cantAddMore(const Item& item, int minVal) const;
    void addItem(const Item& item);
    void removeItem();

private:
    int capacity;
    vector<Item> items;
};

#endif // BOAT_H