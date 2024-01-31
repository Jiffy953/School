#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
		Node* insert(Node* root, Node* element);
		void inorder(Node* root);
		int numNodes(Node* root);
		int findKthSmallest(Node* root, int k);

    Node()
		{
      data = 0;
      left = NULL;
      right = NULL;
  	}

    Node(int val)
		{
      data = val;
      left = NULL;
      right = NULL;
    }
};

Node* Node::insert(Node* root, Node* element)
{
  if (root == NULL){
    return element;
  }
  else {
    if (element->data > root->data) {
      if (root->right != NULL)
        root->right = insert(root->right, element);
      else
        root->right = element;
    }
    else {
      if (root->left != NULL)
        root->left = insert(root->left, element);
      else
        root->left = element;
    }
    return root;
  }
}

void Node::inorder(Node *currentPtr) 
{
  if (currentPtr != NULL) 
	{
    inorder(currentPtr->left);
    cout<<" "<<currentPtr->data;
    inorder(currentPtr->right);
  }
}

int Node::numNodes(Node* root)
{
	if(root == NULL)
		return 0;
	return 1+Node::numNodes(root->left) + Node::numNodes(root->right);
}



int Node::findKthSmallest(Node* root, int k)
{
	if(root == NULL)
	{
		return k;
	}
	k = Node::findKthSmallest(root->left, k);
	k--;
	if(k==0)
	{
		return root->data;
	}
	k=Node::findKthSmallest(root->right, k);
	return k;
}

int menu() 
{
  int ans;
  cout<<"\nHere are your choices: \n";
  cout<<"1. Insert an item into your tree.\n";
  cout<<"2. Print out an inorder traversal.\n";
  cout<<"3. Print the number of the nodes. \n";
  cout<<"4. Finding kth smallest element.\n";
  cout<<"5. Exit.\n";
  cin>> ans;
  return ans;
}

int main() {
	Node myNode;
  Node *myRoot=NULL;
  Node* tempNode;
  int nNodes;
  int val;
  int ans;
  int rank;


  ans = menu();
  while (ans<5) {

    if (ans == 1) {

      // Get value to insert.
      cout<<"What value would you like to insert? ";
      cin>>val;
      tempNode = new Node(val); // Create the node.

      // Insert the value.
      myRoot = myNode.insert(myRoot, tempNode);
    }
     if (ans == 2) {

      // Print the values in tree.
      cout<<"Here is an inorder traversal of your tree: ";
      myNode.inorder(myRoot);
      cout<<"\n";
    }


    if (ans == 3) {
      nNodes = myNode.numNodes(myRoot);
      cout<<nNodes;
      cout<<"\n";

    }

    if (ans == 4) {
      cout<<"Which ranked item would you like to find?\n";
      cin>>rank;

      cout<<"The item is: "<< myNode.findKthSmallest(myRoot, rank);
      cout<<"\n";

    }

    

    // See if they want to insert more nodes.
    ans = menu();
  }

  
  return 0;
}