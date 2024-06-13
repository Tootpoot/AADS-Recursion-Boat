// #include "Boat.h"

// Boat::Boat(int capacity)
//     : capacity(capacity), totalValue(0) {}

// // void Boat::print() const {
// //     std::cout << "Boat Capacity: " << capacity << std::endl;
// //     std::cout << "Items on the boat:" << std::endl;
// //     for (size_t i = 0; i < partial_solution.size(); ++i) {
// //         const auto& item = partial_solution[i];
// //         std::cout << "Item" << i << " - Weight: " << item.weight << ", Value: " << item.value << std::endl;
// //     }
// // }

// // bool Boat::cantAddMore(int minValueItem) {
// //     int totalWeight = 0;
// //     for (const auto& item : partial_solution) {
// //         totalWeight += item.weight;
// //     }
// //     return (totalWeight + minValueItem > capacity);
// // }

// void Boat::addItem(int index) {
//     partial_solution.push_back(index);
//     totalValue += boatItemList[index].value;
// }

// void Boat::removeItem() {
//     if (!partial_solution.empty()) {
//         totalValue -= boatItemList.back().value;
//         partial_solution.pop_back();
//     } else {
//         std::cout << "No items to remove." << std::endl;
//     }
// }

// int Boat::getTotalValue()  {
//     return totalValue;
// }

// int Boat::getListSize() {
//     return boatItemList.size();
// }

// int Boat::getWeight()  {
//     int totalWeight = 0;
//     for (const auto& item : partial_solution) {
//         totalWeight += item.weight;
//     }
//     return totalWeight;
// }

// std::vector<int> Boat::getPartialSolution() {
//     return partial_solution;
// }

#include "Boat.h"
#include <iostream>

using namespace std;

Boat::Boat(int capacity) {
    this->capacity = capacity;
    totalValue = 0;
    totalWeight = 0;
}

void Boat::addItem(int index) {
    partial_solution.push_back(index);
    totalValue += boatItemList[index].value;
    totalWeight += boatItemList[index].weight;
}

void Boat::removeItem() {
    if (!partial_solution.empty()) {
        int index = partial_solution.back();
        totalValue -= boatItemList[index].value;
        totalWeight -= boatItemList[index].weight;
        partial_solution.pop_back();
    }
}

void Boat:: print() const {
    cout<< "The solution contains: " << endl;
    for(int i = 0; i < partial_solution.size(); i++){
        cout << "Item" << partial_solution[i] << endl;
    }
    cout << "Total Weight: " <<totalWeight << endl;
    cout << "Total Value: " << totalValue << endl;
}

bool Boat::cantAddMore(int minVal) const {
    cout << "Function called weight is: " << totalWeight << endl;
    return (totalWeight + minVal >= capacity);
}

int Boat::getTotalValue() const {
    return totalValue;
}

int Boat::getTotalWeight() const {
    return totalWeight;
}

int Boat::getListSize() const {
    return boatItemList.size();
}

int Boat::getCapacity() const {
    return capacity;
}
