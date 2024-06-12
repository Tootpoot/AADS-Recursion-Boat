#include "Boat.h"
#include <stack>

Boat::Boat(int capacity)
    : capacity(capacity) {}

Boat::Boat(){
    capacity = numeric_limits<int>::max();
    
}

int Boat::getCapacity() const {
    return capacity;
}

void Boat::print(stack<Item> itemStack) const {
    cout << "Boat Capacity: " << capacity << endl;
    cout << "Items on the boat:" << endl;
    while (!itemStack.empty()) {
        const auto& item = itemStack.top();
        cout << "Weight: " << item.weight << ", Value: " << item.value << endl;
        itemStack.pop();
    }
}

bool Boat::cantAddMore(int minValueItem) const {
    int totalWeight = 0;
    for (const auto& existingItem : items) {
        totalWeight += existingItem.weight;
    }
    return (totalWeight + minValueItem > capacity);
}

void Boat::addItem(const Item& item) {
    items.push_back(item);
}

void Boat::removeItem() {
    if (!items.empty()) {
        items.pop_back();
    } else {
        cout << "No items to remove." << endl;
    }
}

const vector<Item>& Boat::getItems() const {
    return items;
}

int Boat::getTotalValue() const {
    int totalValue = 0;
    for (const auto& item : items) {
        totalValue += item.value;
    }
    return totalValue;
}

int Boat::getNumberOfItems() const {
    return items.size();
}
