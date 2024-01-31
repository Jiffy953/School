#include <iostream>
using namespace std;
class Node
{
  int data;
  Node *left, *right;

  public:
    Node();
    Node(int);
    Node* Insert(Node*, int);
    Node* DeleteNode(Node*, int);
    void inOrder(Node*);
		Node* minValueNode(Node*);
};

Node::Node(int value)
{
	data = value;
	left = right = NULL;
}

Node* Node::minValueNode(Node* root)
{
	Node* current = root;
	while(current != NULL && current->left != NULL)
		{
			current=current->left;
		}
	return current;
}

void Node::inOrder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	inOrder(root->left);
	cout << root->data;
}

Node* Node::Insert(Node* root, int value)
{
	Node* newNode = new Node(value);
	if(root == NULL)
	{
		return newNode;
	}
	if(value > root->data)
	{
		root->right = Insert(root->right, value);
	}
	else
	{
		root->left = Insert(root->left, value);
	}
	return root;
}

Node* Node::DeleteNode(Node* root, int value)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(value < root->data)
	{
		root->left = DeleteNode(root->left, value);
	}
	else if (value > root->data)
	{
		root->right = DeleteNode(root->right, value);
	}
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		else if(root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = DeleteNode(root->right, temp->data);
	}
	return root;
}


int main() {
  std::cout << "Hello World!\n";
}