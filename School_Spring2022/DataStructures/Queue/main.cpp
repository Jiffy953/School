#include <iostream>
class Node
{
  public:
    int data;
    Node* next;

  Node(int d)
  {
    data = d;
    next = NULL;
  }
};

class Queue
{
  public:
    Node *front, *rear;
    Queue()
    {
      front = rear = NULL;
    }


    void enqueue(int x)
    {
      Node* newNode = new Node(x);

      if(rear == NULL)
      {
        front = rear = newNode;
        return;
      }

      rear -> next = newNode;
      rear = newNode;
    }

    void dequeue()
    {
      if(front == NULL)
      {
        return;
      }
      Node* temp = front;
      front = front -> next;

      if (front == NULL)
      {
        rear = NULL;
      }
      delete temp;
    }
};


void front();

void isEmpty();

void size();


int main() {
  

}