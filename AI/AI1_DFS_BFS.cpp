
#include <bits/stdc++.h>
using namespace std;


class node {
public:
	int data;
	node *left, *right;
};


void printCurrentLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

int height(node* node)
{
	if (node == NULL)
		return 0;
	else {
		
		int lheight = height(node->left);
		int rheight = height(node->right);

		
		if (lheight > rheight) {
			return (lheight + 1);
		}
		else {
			return (rheight + 1);
		}
	}
}
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}


void printLevelOrder(node* root)  //bfs
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}


void printInorder(node* node)  //dfs
{
    if (node == NULL)
        return;
 
    printInorder(node->left);
 
    
    cout << node->data << " ";
 
    printInorder(node->right);
}


int main()
{
	node* root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);

	cout << "BFS"<<endl;
	printLevelOrder(root);
	
	cout<<"\nDFS"<<endl;
	
	printInorder(root);

	return 0;
}
