#include <iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;

    Node* insert(Node* list, int d);
    Node*  del(Node *head, int item);
    void print(Node *list);
    void freelist(Node* list);
};

Node* insert(Node* head, int item)
{
  if(head == NULL || item <= head->data)
  {
    Node* newNode = new Node();

    newNode->data = item;
    newNode->next = head;

    return newNode;
  }
  head->next = insert(head->next, item);
  return head;
}

Node* del(Node *head, int item)
{
  if(head == NULL)
  {
    return NULL;
  }
  if(head->data == item)
  {
    Node* rest = head->next;
    delete head;
    return rest;
  }
  head->next = del(head->next, item);
  return head;
}

void print(Node* list)
{
  if(list != NULL)
  {
    cout << "-> " << list->data;
    print(list->next);
  }
}


int main() 
{
  
}