
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *left, *right;
};

node *newNode(int data)
{
	node *Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}
//-----------------bfs-----------------------------


void bfs(node *root)
{
	if (root == NULL)
		return;

	queue<node *> q;
	q.push(root);

	while (!q.empty())
	{
		node *current = q.front();
		q.pop();

		cout << current->data << " ";

		if (current->left)
			q.push(current->left);

		if (current->right)
			q.push(current->right);
	}
}

//------------------------------dfs------------------------------------
void dfs(node *node) // Inorder
{
	if (node == NULL)
		return;

	dfs(node->left);

	cout << node->data << " ";

	dfs(node->right);
}

//---------------------------------------------------------------------
int main()
{
	node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);

	cout << "BFS" << endl;
	bfs(root);

	cout << "\nDFS" << endl;

	dfs(root);

	return 0;
}
