#include <iostream>
#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList {
    node<T> *head;
public:

    // Linked List Constructor
    LinkedList() {
        head = nullptr;
    }

    // Linked List add function
    void add(T data) { // Same as pushBack
        pushBack(data);
    }

    void remove(node<T>** refrence, int key)
    {
        node<T>* temp = *refrence;
        node<T>* prev = nullptr;
        if(temp != nullptr && temp->data == key)
        {
            *refrence = temp -> next;
            delete temp;
            return;
        }
        else
        {
            while (temp != nullptr && temp->data != key)
            {
                prev = temp;
                temp = temp -> next;
            }
            if(temp== nullptr)
            {
                return;
            }
            prev->next=temp->next;
            delete temp;
        }
    }

    // Linked List push back
    void pushBack(T data) {
        if (head) {  // Check head not equal to nullptr ( linked list is not empty )
            node<T> *p;
            p = head;
            while (p->getNext()) { // Find the last node
                p = p->getNext();
            }
            p->setNext(new node<T>(data));
        } else { // if linkedlist empty
            head = new node<T>(data);
        }
    }

    // Linked List push front
    void pushFront(T data) {
        head = new node<T>(data, head);
    }

    // Linked list insert after
    //void insertAfter(node<T> *referenceNode, )


    // Linked List print function
    void printLinkedList() {
        node<T> *p = head;
        while (p != nullptr) {
            std::cout << p->getData() << std::endl;
            p = p->getNext();
        }
    }

    // Linked List Destructor
    virtual ~LinkedList() {
        node<T> *p = nullptr;
        while (head) {
            p = head;
            delete p;
            head = head->getNext();
        }
    }
};


#endif //LINKEDLIST_H
