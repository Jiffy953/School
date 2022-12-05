
#include <iostream>
#include <string.h>

FILE * outFile;

class itemNode
{
public:
    char name[50];
    int count;
    itemNode *left, *right;

    itemNode()
    {
        name[0]='\0';
        count = 0;
        left = NULL;
        right = NULL;
    }
    itemNode(char itemName[], int population)
    {
        strcpy(name, itemName);
        count = population;
        left = NULL;
        right = NULL;
    }
};

class treeNameNode
{
public:
    char treeName[50];
    treeNameNode *left, *right;
    itemNode *theTree;
    treeNameNode * insert (treeNameNode* root, treeNameNode* element);


    treeNameNode()
    {
        treeName[0]='\0';
        theTree = NULL;
        left = NULL;
        right = NULL;
    }

    treeNameNode(char name[])
    {
        theTree = NULL;
        left = NULL;
        right = NULL;
    }
};

treeNameNode* createTreeNameNode(char *name)
{
    treeNameNode * nameNode = (treeNameNode*)malloc(sizeof(treeNameNode));
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

treeNameNode* insert(treeNameNode* root, treeNameNode* element)
{
    if (root == NULL)
    {
        return element;
    }
    else
    {
        if (strcmp(root->treeName, element->treeName) > 0)
        {
            if (root->left != NULL)
            {
                root->left = insert(root->left, element);
            }
            else
            {
                root->left = element;
            }
        }
        else
        {
            if (root->right != NULL)
            {
                root->right = insert(root->right, element);
            }
            else
            {
                root->right = element;
            }
        }
    }
    return root;
}


treeNameNode *buildNameTree(FILE *inFile, int tnCount)
{
    char temp[50];
    treeNameNode* nameRoot = NULL;
    for(int i=0; i < tnCount; i++)
    {
        fscanf(inFile,"%s", temp);
        treeNameNode* newNameNode = createTreeNameNode(temp);
        nameRoot = insert(nameRoot, newNameNode);
    }
    return nameRoot;
}

//treeNameNode *searchNameNode(treeNameNode *root, char treeName[50])
//{

//}

//void buildOtherTrees(FILE *inFile, treeNameNode *topTree, int itemCount) //the not black ones
//{
//char treeName[50], itemName[50];

//}

int main()
{
    const char *PATH = "/Users/jiffy/CLionProjects/DataStr_Pro2/in.txt";
    FILE* inFile = fopen(PATH, "r");
    int tnCount, itemCount, queryCount;
    fscanf(inFile, "%d %d %d",&tnCount, &itemCount, &queryCount);
    buildNameTree(inFile, tnCount);
}
