#include "Boat.h"
#include <iostream>
#include <map>

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
    int counter = 0;
    map<int, int> counts;
    cout<< "The solution contains: " << endl;
    for(const auto& item: partial_solution){
        counts[item]++;
    }

    for(const auto& pair : counts){
        cout << pair.second << " Item" << pair.first << endl;
    }

    cout << endl << "Total weight: ";
    int weight_sum = 0;
    bool first = true;
    for(const auto& pair : counts){
        if (!first) {
            cout << " + ";
        }
        cout << pair.second << " * " << boatItemList[pair.first].weight;
        weight_sum += pair.second * boatItemList[pair.first].weight;
        first = false;
    }
    cout << " = " << weight_sum << endl;

    cout << "Total value: ";
    int value_sum = 0;
    first = true;
    for(const auto& pair : counts){
        if (!first) {
            cout << " + ";
        }
        cout << pair.second << " * " << boatItemList[pair.first].value;
        value_sum += pair.second * boatItemList[pair.first].value;
        first = false;
    }
    cout << " = " << value_sum << endl;


}

bool Boat::cantAddMore(int minVal) const {
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

int Boat::getItemWeight(int i) const {
    return boatItemList[i].weight;
}
