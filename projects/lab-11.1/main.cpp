/* 
    File: main.cpp 
    Description: This code uses structs and lambda functions to sort pizzas and
    their customers and outputting the results.
    Author: Andrew Gooch
    Email: andrewg6118@student.vvc.edu
    Course#: cis202
    Section#: <30001>
    Date: 6/1/25
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct PizzaOrder {
    std::string name;
    int size;
};



struct PizzaOrderWithPrice {
    std::string name;
    int size;
    double price;
};

int main() {
    std::vector<PizzaOrderWithPrice> orders = {
        {"Alice", 12, 11.99}, {"Bob", 16, 15.49}, {"Charlie", 10, 9.99}, {"Diana", 14, 13.75}
    };

    std::cout << std::endl;
    std::cout << "Original Pizza Orders:\n";
    for (const auto& order : orders){
        std::cout << order.name << " " << order.size << " inches\n";
  }

    std::sort(orders.begin(), orders.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.size < b.size;
    });
    std::cout << "\nSorted by Size (Ascending):\n";
    for (const auto& order : orders){
        std::cout << order.name << " " << order.size << " inches\n";
  }

   std::sort(orders.begin(), orders.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.name < b.name;
    });

    std::cout << "\nSorted by Name (Alphabetical):\n";
     for (const auto& order : orders){
        std::cout << order.name << " " << order.size << " inches\n";
  }

   std::sort(orders.begin(), orders.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.price < b.price;
    });

    std::cout << "\nSorted by Price (Ascending):";
    for (const auto& order : orders){
        std::cout << "\n" << order.name << " " << order.size << " inches $" << order.price;
    }
    return 0;
}
