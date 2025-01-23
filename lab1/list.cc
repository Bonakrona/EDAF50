#include <iostream>
#include "list.h"

List::List() : first(nullptr) {}

List::~List() {
	Node* current = first;
	while(current != 0) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

bool List::exists(int d) const {
	Node* current = first;
	while(current != nullptr) {
		if(current->value == d) {
			return true;
		}
		current = current->next;
	}
	return false;
}

int List::size() const {
	int count = 0;
	Node* current = first;
	while(current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

bool List::empty() const {
	return first == nullptr;
}

void List::insertFirst(int d) {
	Node* newNode = new Node(d, first);
	first = newNode;
}

void List::remove(int d, DeleteFlag df) {
	if(first == nullptr) {
		return;
	}

	while (first != nullptr && first->next != nullptr) {
        bool shouldRemove = false;
        if (df == DeleteFlag::LESS && first->value < d) {
            shouldRemove = true;
        } else if (df == DeleteFlag::EQUAL && first->value == d) {
            shouldRemove = true;
        } else if (df == DeleteFlag::GREATER && first->value > d) {
            shouldRemove = true;
        }

		if(shouldRemove) {
			Node* toDelete = first;
			first = first->next;
			delete toDelete;
		} else {
			break;
		}
	}
	
	Node* current = first;
	while (current != nullptr && current->next != nullptr) {
        bool shouldRemove = false;
        if (df == DeleteFlag::LESS && current->next->value < d) {
            shouldRemove = true;
        } else if (df == DeleteFlag::EQUAL && current->next->value == d) {
            shouldRemove = true;
        } else if (df == DeleteFlag::GREATER && current->next->value > d) {
            shouldRemove = true;
        }

		if(shouldRemove) {
			Node* toDelete = current->next;
			current->next = toDelete->next;
			delete toDelete;
		} else {
			current = current->next;
		}
	}
}

void List::print() const {
	Node* current = first;
	while(current != nullptr) {
		std::cout << current->value << "\n";
		current = current->next;
	}
	std::cout << std::endl;
}

