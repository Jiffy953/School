#include <iostream>

class Node
{
	public:
		
		
};

int height(Node *N)
{
	
}

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = left;
	node->right = right;
	node->height = 1;
}

Node *rightRotate(Node  *y)
{
	Node *x = y->left;
	Node *T2 = x->right;
	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(y->left), height(y->right)) + 1;

	return x;
	
}

int getBalance(Node *N)
{
	if (N == NULL)
	{
		return 0;
	}
	return
}


int main() {
  std::cout << "Hello World!\n";
}