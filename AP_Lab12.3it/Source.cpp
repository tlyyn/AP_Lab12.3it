#include <iostream>

struct Elem {
    Elem* next, * prev;
    int info;
};

void enqueue(Elem*& first, Elem*& last, int value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL) last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL) first = tmp;
}

void printList(Elem* first) {
    Elem* current = first;
    while (current != NULL) {
        std::cout << current->info << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void swapList(Elem*& first, Elem*& last) {
    Elem* current = first;
    Elem* tmp;  // define tmp here
    while (current != NULL) {
        tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
        current = tmp;
    }
    tmp = first;
    first = last;
    last = tmp;
}


int main() {
    Elem* first = NULL, * last = NULL;
    enqueue(first, last, 1);
    enqueue(first, last, 2);
    enqueue(first, last, 3);
    enqueue(first, last, 4);
    enqueue(first, last, 5);
    enqueue(first, last, 6);
    std::cout << "Original list: ";
    printList(first);
    swapList(first, last);
    std::cout << "Swapped list: ";
    printList(first);
    return 0;
}
