#include <iostream>
#include <cstring>

using namespace std;

class Stack
	{
		public:
			int top;
			char exp[100];
			Stack() { top = -1; }
			bool push(char item);
			char pop();
			char peek();
			bool isEmpty();
			string infixToPostFix(string infix);
			int evaluatePostFix(string exp);
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


int helper(char choice)
	{
		if(choice == '/' || choice == '*')
		{
			return 1;
		}
		else if(choice == '+' || choice == '-')
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}


string Stack::infixToPostFix(string infix)
	{
		string postfix;
		for(int i = 0; i < infix.length()+1; i++)
			{
				char temp = infix[i];
				if(temp >= '0' && temp <= '9')
				{
					postfix += temp;
				}
				else if(temp=='(')
				{
					Stack::push('(');
				}
				else if(temp==')')
				{
					while(Stack::peek() != '(' )
						{
							postfix += Stack::peek();
							Stack::pop();
						}
					Stack::pop();
				}				
				else
				{
					while(Stack::isEmpty() == false && helper(infix[i]) <= helper(Stack::peek()))
						{
							postfix += Stack::peek();
							Stack::pop();
						}
					Stack::push(temp);
				}
			}
		while(Stack::isEmpty())
			{
				postfix += Stack::peek();
				Stack::pop();
			}
		return postfix;
	}

int Stack::evaluatePostFix(string exp)
{
	
}


int main()
{
	Stack myStack;
	cout << myStack.infixToPostFix("3+2*(4-1)");
}