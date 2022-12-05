#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *prev;
    Node *next;
};

void insertBeg(Node **headRef, int newData)
{
  Node* newNode = new Node();

  newNode->data = newData;
  newNode->next = *headRef;
  newNode->prev = NULL;
  
  if(*headRef != NULL)
  {
    (*headRef)->prev = newNode;
  }

  *headRef = newNode; 

}

void insertAfter(Node* prev, int newData)
{
  if(prev == NULL)
  {
    return;
  }

  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = prev->next;
  prev->next = newNode;

  if (newNode -> next != NULL)
  {
    newNode -> next -> prev = newNode;
  }

}

void insertAtEnd(Node** headRef, int newData)
{
  Node* newNode = new Node();
  Node* last = *headRef;
  newNode->data = newData;

  if (*headRef == NULL)
  {
    newNode->prev = NULL;
    *headRef = newNode;
    return;
  }
  while(last->next != NULL)
  {
    last = last->next;
  }
  last->next = newNode;
  newNode->prev = last;
}

void printList(Node *node)
{
  while(node != NULL)
  {
    cout<<" "<<node->data<< " ->";
    node = node->next;
  }
  cout<<" NULL\n";
}


int main()
{

  Node* head = NULL;

  insertBeg(&head, 7);
  insertBeg(&head, 20);
  insertBeg(&head, 1);
  insertBeg(&head, 13);
  printList(head);
  insertAfter(head->next->next, 12);
  insertAfter(head->next->next->next, 3);
  insertAfter(head->next->next->next, 8);
  printList(head);
}