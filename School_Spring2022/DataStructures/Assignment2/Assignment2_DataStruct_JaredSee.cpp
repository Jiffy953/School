#include <iostream>

class Node
{
  public:
  int data;
  Node * next;
};

void insertBeg(Node** headRef, int newData)
{
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = (*headRef);
  (*headRef) = newNode;
}

void printList(Node *node)
{
  while (node != NULL)
  {
    std::cout<<" "<<node->data<< "->" ;
    node = node->next;
  }
   std::cout<<" NULL\n" ;
}

void removeAll(Node** head, int val)
{

  Node* temp = *head;
  Node* prev = NULL;
  if(temp != NULL && temp->data == val)
  {
    *head = temp->next;
    delete temp;
    return;
  }
  else
  {
    while(temp != NULL && temp->data != val)
    {
      prev = temp;
      temp = temp->next;
    }
    if(temp == NULL)
    {
      return;
    }
    prev->next = temp->next;
    delete temp;
    removeAll(head, val);
  }
}

int size = 0; 
void insertToPlace(Node** head, int val, int place)
{
  
  Node* newNode = new Node(); 
  Node* temp = *head;
  

  int size = 0;

  while(temp != NULL)
  {
    temp = temp->next;
    size++;
  }
  newNode->data = val;
  newNode->next = NULL;
  Node* last = *head;
  Node* temp2 = newNode;

  if(place < 1 || place > size + 1) //fail cond, goes to end
  {
    if (*head == NULL)
    {
      *head = newNode;
      return;
    }
    while(last->next != NULL)
    {
      last = last->next;
    }
  last->next = newNode;
  }
  else //success cond, goes to place
  {
    while(place--)
    {
      if(place == 0)
      {
        temp2 -> next = *head;
        *head = temp2;
      }
      else
      {
        head=&(*head)->next; //confusing but it works
      }
    }
  }
  free(temp); //better to delete manually
}


int main() 
{
  Node *head = NULL;
  insertBeg(&head, 1);
  printList(head);
  insertToPlace(&head, 2, 1); //goes to 1st pos pushing 1 forward
  printList(head);
  insertToPlace(&head, 3, 2);
  printList(head);
  insertToPlace(&head, 4, 100); //goes to end as pos > size
  printList(head);
  insertToPlace(&head, 5, 2); //goes to 2nd place, does not start count at 0
  printList(head);
}