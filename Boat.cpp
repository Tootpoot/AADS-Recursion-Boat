#include "Boat.h"

Boat::Boat(int capacity)
    : capacity(capacity) {}

Boat::Boat(){
    capacity = std::numeric_limits<int>::max();
}

int Boat::getCapacity() const {
    return capacity;
}

void Boat::print() const {
    cout << "Boat Capacity: " << capacity << endl;
    cout << "Items on the boat:" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        const auto& item = items[i];
        cout << "Item" << i << " - Weight: " << item.weight << ", Value: " << item.value << endl;
    }
}

bool Boat::cantAddMore(const Boat& boat, int minValueItem) const {
    int totalWeight = 0;
    for (const auto& existingItem : boat.getItems()) {
        totalWeight += existingItem.weight;
    }
    return (totalWeight + minValueItem > boat.getCapacity());
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

int Boat::getTotalValue() const {  // Implementation of the method to calculate total value
    int totalValue = 0;
    for (const auto& item : items) {
        totalValue += item.value;
    }
    return totalValue;
}

int Boat::getNumberOfItems() const {  // Implementation of the method to get number of items
    return items.size();
}
