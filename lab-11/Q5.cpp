#include <iostream>
#include <stdexcept>
using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
    T stock;
    const T maxCapacity;
public:
    InventoryItem(T max) : maxCapacity(max), stock(0) {}
    
    void setStock(T amount) {
        if (amount < 0) throw NegativeStockException();
        if (amount > maxCapacity) throw OverCapacityException();
        stock = amount;
    }
    
    T getStock() const { return stock; }
};

int main() {
    InventoryItem<int> item(100);
    
    try {
        cout << "Setting stock to -5...\n";
        item.setStock(-5);
    } catch (const NegativeStockException&) {
        cout << "Caught NegativeStockException\n";
    }
    
    try {
        cout << "Setting stock to 120...\n";
        item.setStock(120);
    } catch (const OverCapacityException&) {
        cout << "Caught OverCapacityException\n";
    }
}
