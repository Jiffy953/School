#include <iostream>

class Node
{
  public:
    int data;
    Node *next;
    void push(int data);
    int pop();
    void printList();
};

Node* top;


void Node::push(int data)
{
  Node* temp = new Node();

  if(!temp)
  {
    std::cout << "\nCannot be allocated" << std::endl;
    exit(1);
  }
  temp->data=data;
  temp->next=top;
  top = temp;
}

int Node::pop()
{
  Node* temp;
  int x;
  if(top == NULL)
  {
    std::cout << "\nStack Underflow" << std::endl;
    exit(1);
  }
  else
  {
    top->data=x;
    top = top->next;
  }
}

void Node::printList()
{
  Node* temp;
  if(top == NULL)
  {
    std::cout << "\nStack underflow";
    exit(1);
  }
  else
  {
    temp = top;
    while(temp != NULL)
    {
      std::cout << temp->data << "-> ";
      temp = temp->next;
    }
  }
}




int main() {
  Node myStack;
  myStack.push(10);
  myStack.push(10);
  //myStack.printList();
  myStack.pop();
}
