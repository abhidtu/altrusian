// Created by linux on 13/1/16.

#include <iostream>
#include <unistd.h>

using namespace std;

#include "../linked_lists/doubly/DoublyLinkedList.h"

int main() {

    LibAlDs::DoublyLinkedList list;

    LibAlDs::List *linkedList = &list;

    linkedList->insertAtBeginning(1);
    linkedList->insertAtBeginning(2);
    linkedList->insertAtEnd(3);
    linkedList->insertAtEnd(4);
    //linkedList->deleteFromBeginning();
    //linkedList->deleteFromEnd();
    //linkedList->deleteFromEnd();
    //linkedList->deleteFromEnd();

    cout << linkedList->size();
    cout << linkedList->isEmpty();

    return 0;
}