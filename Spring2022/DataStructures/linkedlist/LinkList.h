//
// Created by Jared See on 9/24/21.
//
#include<iostream>
#include "node.h"

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


class LinkList {
public:
    node *head;
    LinkList()
    {
        head = nullptr;
    }
    void addNode(double value) {
        if (head == nullptr)
            head = new node(value);

        else {
            node *p = head;
            while (p->next != nullptr)
                p = p->next;
        }
    }

    void printList()
    {
        node *p=head;
        while (p != NULL)
        {
            std::cout << p->value << std::endl;
        }
    }

    void deleteNode(node *nodePtr)
    {
        node *p=nodePtr;
        node *q=head;
        if (q == nullptr)
        {
            return;
        }
        if (p = head)
        {
            head = head -> next;
            delete p;
            return;
        }
        while(q != nullptr && q->next != p)
        {
            q=q->next;
        }
        if (q == nullptr)
        {
            return;
        }
        q->next=p->next;
        delete p;




    }
    void pushFront(double value);
    void insertAfter(double value, node *nodeElement);

};


#endif //LINKEDLIST_LINKEDLIST_H
