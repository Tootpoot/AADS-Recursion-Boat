#ifndef BOAT_H
#define BOAT_H

#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

class Boat {
private:
    int capacity;
    int totalValue;
    int totalWeight;
    vector<int> partial_solution;

public:
    vector<Item> boatItemList;

    Boat(int capacity);

    void addItem(int index);
    void removeItem();
    int getTotalValue() const;
    int getTotalWeight() const;
    int getListSize() const;
    int getCapacity() const;
    void print() const;
    bool cantAddMore(int minVal) const;
};

#endif // BOAT_H
