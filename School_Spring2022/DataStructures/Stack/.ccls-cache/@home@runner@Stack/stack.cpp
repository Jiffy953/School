#include <iostream>
using namespace std;

class Stack
{
  int top;
public:
  
  int a[100];
  Stack()
  {
    top = -1;
  }

  bool push(int item);
  int pop();
  int peek();
  bool isEmpty();
};

bool Stack::push(int item)
{
  if(top >= (100 - 1))
  {
    cout << "Stack overflow\n";
    return false + '\n';
  }
  else
  {
    top++;
    a[top] = item;
    cout << item << " was sucessfully added to stack" << endl;
    return true + '\n';
  }
}

int Stack::pop()
{
  if (top == -1)
  {
    cout << "Stack underflow" << endl;
    return 0;
  }
  else
  {
    int x = a[top];
    top--;
    return x + '\n';
  }
}

int Stack::peek()
{
  if(top == -1)
  {
    //cout << "Stack is empty" << endl;
    isEmpty();
  }
  else
  {
    return a[top] + '\n';
  }
}

bool Stack::isEmpty()
{
  if (top == -1)
  {
    return false + '\n';
  }

  else
  {
    return true + '\n';
  }
}


int main() {
  Stack myStack;
  myStack.push(9);
  cout << myStack.peek();
  myStack.pop();
  cout << myStack.peek();
}