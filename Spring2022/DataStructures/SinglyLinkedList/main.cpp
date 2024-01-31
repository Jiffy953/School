#include <iostream>

using namespace std;
class Node
{
  public:
    int data;
    Node *next;
};

void insertBeg(Node** headRef, int newData)
{
  Node* newNode = new Node();

  newNode->data = newData;
  newNode->next = *headRef;

  *headRef = newNode; 
}



void insertAfter(Node* prevNode, int newData)
{
  if(prevNode == NULL)
  {
    return;
  }

  Node* newNode = new Node();

  newNode->data = newData;
  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

void insertLast(Node** headRef, int newData)
{
  Node* newNode = new Node();

  Node* last = *headRef;
  newNode->data = newData;
  newNode->next = NULL;
  if (*headRef == NULL)
  {
    *headRef = newNode;
    return;
  }
  while(last->next != NULL)
  {
    last = last->next;
  }
  last->next = newNode;
}


void printList(Node *node)
{
  while(node != NULL)
  {
    cout<<" "<<node->data<< "->";
    node = node->next;
  }
  cout<<" NULL\n";
}


void deleteNode(Node** headRef, int key)
{
  Node* temp = *headRef;
  Node* prev = NULL;


  if(temp != NULL && temp->data == key)
  {
    *headRef = temp->next;
    delete temp;
    return;
  }

  else
  {
    while(temp != NULL && temp->data != key)
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
  }

}


//recursive prob the best imp here
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
    removeAll(head, val); //it was
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

  Node* head = NULL;
  insertToPlace(&head, 6, 0);
  printList(head);
  insertToPlace(&head, 5, 5);
  printList(head);
  insertToPlace(&head, 1, 0);
  printList(head);
  insertToPlace(&head, 6, 2);
  printList(head);
}