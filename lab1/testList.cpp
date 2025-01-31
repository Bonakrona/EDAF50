#include <iostream>
#include "list.h"

int main() {
    List list;

    list.insertFirst(1);
    list.insertFirst(5);
    list.insertFirst(4);
    list.insertFirst(1);
    list.insertFirst(3);
    list.insertFirst(2);
    list.insertFirst(1);


    std::cout << "Does 1 exist: " << list.exists(1) <<std::endl;
    std::cout << "Does 6 exist: " << list.exists(6) <<std::endl;

    std::cout << "List size: " << list.size() << std::endl;

    std::cout << "Initial list: " << std::endl;
    list.print();

    list.remove(1, List::DeleteFlag::EQUAL);
    std::cout << "List where the ones are removed: " << std::endl;
    list.print();

    std::cout << "Is the list empty? : " << list.empty() <<std::endl;

    return 0;
}