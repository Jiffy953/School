#include <iostream>
#include <cstring>
using namespace std;

class Stack
	{
		public:
			int top;
			exp exp[100];
			Stack() { top = -1; }
			bool push(char item);
			char pop();
			char peek();
			bool isEmpty();
			int isMatchingPair(char character1, char character2);
			int areParenthesisBalanced(char exp[]);
	};

bool Stack::push(char item)
{
	if (top >= (100 - 1))
	{
		//cout << "Stack Overflow" << endl;
		return false;
	}
	else 
	{
    top++;
		exp[top] = item;
		//cout << item << " is successfully pushed into stack" << endl;
		return true;
	}
}

char Stack::pop()
	{
		if (top < 0)
		{
			//cout << "Stack Underflow" << endl;
			return 0;
		}
		else
		{   
			char x = exp[top];
			//cout << x << " is removed from stack" << endl;
    	top--;
			return x;
		}
}

char Stack::peek()
	{
		if (top < 0)
		{
			//cout << "Stack is Empty" << endl;
			return 0;
		}
		else 
		{
			char x = exp[top];
			return x;
		}
	}

	bool Stack::isEmpty()
{
	return (top < 0);
}


int Stack::isMatchingPair(char character1, char character2) //i didnt use this but it is implemented :)
{
	if(character1 == character2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Stack::areParenthesisBalanced(char exp[])
{
	//pushes an open paren into the stack and will remove it when a close of the same type or string ends
	//if there is parens left in the stack when the string is finished it is unbalanced
	//if it is empty it is balanced
	//limitation: doesnt work if you have close paren before an open but no one writes expressions like that anyways
	size_t len = strlen(exp);
	char temp;
	
	for(int i=0; i <= len; i++)
		{
			 if(exp[i] == '[' || exp[i] == '(' || exp[i] == '{') 
			{
				Stack::push(exp[i]);
			}
			else if(exp[i] == ']')
			{
				temp = Stack::peek();
				Stack::pop();
				if(temp == '}' || temp == ')')
					return 0; 
			}
			else if(exp[i] == '}')
			{
				temp = Stack::peek();
				Stack::pop();
				if(temp == ']' || temp == ')')
					return 0;
			}
			else if(exp[i] == ')')
			{
				temp = Stack::peek();
				Stack::pop();
				if(temp == '}' || temp == ']')
					return 0;
			}
		}
	if(Stack::isEmpty() == true)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
  class Stack s;
	char exp[100];
	cout << "Enter an expression: ";
	cin >> exp;
	if(s.areParenthesisBalanced(exp) == 1)
	{
		cout << "Balanced";
	}
	else
	{
		cout << "Unbalanced";
	}
}