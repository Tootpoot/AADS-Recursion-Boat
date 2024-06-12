#include "Boat.h"

Boat::Boat(int capacity)
    : capacity(capacity) {}

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

bool Boat::cantAddMore(const Item& item, int minValueItem) const {
    int totalWeight = 0;
    for (const auto& existingItem : items) {
        totalWeight += existingItem.weight;
    }

    return (totalWeight + item.weight + minValueItem > capacity);
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
