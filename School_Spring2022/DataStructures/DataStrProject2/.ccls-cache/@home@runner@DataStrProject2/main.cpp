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

		treeNameNode()
	{
		treeName[0]='\0';
		theTree = NULL;
		left = NULL;
		right = NULL;
	}

		treeNameNode(char name[])
	{
		strcpy(treeName, name);
		theTree = NULL;
		left = NULL;
		right = NULL;
	}
};

treeNameNode *buildNameTree(FILE *inFile, int tnCount)
{
	char temp[50];
	if(tnCount >= 0)
	{
		fscanf(inFile,"%s", temp);
		treeNameNode(temp);
		return buildNameTree(inFile, tnCount-1);
	}
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
	FILE * inFile;
	treeNameNode myTreeNameNode;
	inFile = fopen("in.txt", "r");
	int tnCount, itemCount, queryCount;
	fscanf(inFile, "%d%d%d", &tnCount, &itemCount, &queryCount);
	buildNameTree(inFile, tnCount);
	
	
	

}