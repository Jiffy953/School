#include <iostream>
#include<stack>
using namespace std;

int main() {
  stack<int> stack;
  stack.push(10);
  stack.push(1);
  stack.push(9);

  while(!stack.empty())
  {
    cout << " " << stack.top();
    stack.pop();
  }
}