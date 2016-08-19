// Created by linux on 13/1/16.

#include <iostream>

using namespace std;

#include "../linked_lists/singly/SinglyLinkedList.h"

int main() {
    altrusian::Lists::SinglyLinkedList list;

    altrusian::List *linkedList = &list;

    linkedList->insertAtBeginning(1);
    linkedList->insertAtBeginning(2);
    linkedList->insertAtEnd(3);
    linkedList->insertAtEnd(4);
    linkedList->insertAtEnd(5);
    linkedList->deleteFromBeginning();
    linkedList->deleteFromEnd();
    linkedList->deleteFromEnd();
    linkedList->deleteFromEnd();
    //linkedList->deleteFromEnd();

    cout << linkedList->size();
    cout << linkedList->isEmpty();

    return 0;
}