#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 30
FILE* outFile;

typedef struct itemNode
{
    char name[MAXLEN];
    int count;
    struct itemNode *left, *right;
} itemNode;

typedef struct treeNameNode
{
    char treeName[MAXLEN];
    struct treeNameNode *left, *right;
    itemNode *theTree;
}
treeNameNode;

treeNameNode* createTreeNameNode(char* name)
{
    treeNameNode* nameNode = (treeNameNode*)malloc(sizeof(treeNameNode));
    strcpy(nameNode->treeName, name);
    nameNode->left = NULL;
    nameNode->right = NULL;
    nameNode->theTree = NULL;
    return nameNode;
}

itemNode* createItemNode(char* name, int count)
{

    itemNode* node = (itemNode*)malloc(sizeof(itemNode));
    strcpy(node->name, name);
    node->count = count;
    node->left = NULL;
    node->right = NULL;
    return node;
}

treeNameNode* insertNameNode(treeNameNode* root, treeNameNode* newNode)
{
    if (root == NULL)
    {
        return newNode;
    }
    else
    {
        if (strcmp(root->treeName, newNode->treeName) > 0)
        {
            if (root->left != NULL)
            {
                root->left = insertNameNode(root->left, newNode);
            }
            else
            {
                root->left = newNode;
            }
        }
        else
        {
            if (root->right != NULL)
            {
                root->right = insertNameNode(root->right, newNode);
            }
            else
            {
                root->right = newNode;
            }
        }
    }
return root;
}

// derivation from insertNameNode()
itemNode* insertItemNode(itemNode* treeRoot, itemNode* newNode) {

if (treeRoot == NULL) {
return newNode;
}
else {
// treeRoot name > newNode name
if (strcmp(treeRoot->name, newNode->name) > 0) {
// if an element exists to the left of it's 'root' then call again
if (treeRoot->left != NULL) {
treeRoot->left = insertItemNode(treeRoot->left, newNode);
}
else {
treeRoot->left = newNode;
}
}
// treeRoot name < newNode name OR they are equal strings
else {
// if an element exists to the right of it's 'root' then call again
if (treeRoot->right != NULL) {
treeRoot->right = insertItemNode(treeRoot->right, newNode);
}
else {
treeRoot->right = newNode;
}
}
}
return treeRoot;
}

treeNameNode* buildNameTree(FILE* inFile, int N)
{
    if (inFile == NULL)
    {
        return NULL;
    }
    treeNameNode* nameRoot = NULL;
    char name[MAXLEN];
    for (int x = 0; x < N; x++)
    {
        fscanf(inFile, "%s", name);
        treeNameNode* newNameNode = createTreeNameNode(name);
        nameRoot = insertNameNode(nameRoot, newNameNode);
    }
    return nameRoot;
}

treeNameNode* searchNameNode(treeNameNode* root, char treeName[50]) {

if (root == NULL) {
return NULL;
}

treeNameNode* nameNode;
if (strcmp(root->treeName, treeName) == 0) {
return root;
}
else if (strcmp(root->treeName, treeName) > 0) {
nameNode = searchNameNode(root->left, treeName);
}
else {
nameNode = searchNameNode(root->right, treeName);
}
return nameNode;
}

void populateTrees(FILE* inFile, treeNameNode* nameRoot, int I) {

if (inFile == NULL) {
return;
}

else {
int count;
char treeName[MAXLEN];
char itemName[MAXLEN];
for (int x = 0; x < I; x++) {
fscanf(inFile, "%s %s %d", treeName, itemName, &count);
itemNode* newItemNode = createItemNode(itemName, count);
treeNameNode* treeNode = searchNameNode(nameRoot, treeName);
treeNode->theTree = insertItemNode(treeNode->theTree, newItemNode);
}
}
}

void displayInOrderNameTree(treeNameNode* root) {

if(root != NULL) {
displayInOrderNameTree(root->left);
printf("%s ", root->treeName);
displayInOrderNameTree(root->right);
}
}

void traverseSubTree(itemNode* root) {

if(root != NULL) {
traverseSubTree(root->left);
printf("%s ", root->name);
traverseSubTree(root->right);
}
}