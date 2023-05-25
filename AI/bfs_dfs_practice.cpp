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
//----------------------------------------

void bfs(node *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
}

//---------------------------------------------------
void dfs(node *node)
{
    if (node == NULL)
    {
        return;
    }

    dfs(node->left);

    cout << node->data << " ";

    dfs(node->right);
}

int main()
{
    node *root = newNode(20);

    root->left = newNode(10);
    root->right = newNode(14);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(4);

    cout << "Depth first search:" << endl;
    dfs(root);

    cout << "\nbreath first search: " << endl;
    bfs(root);

    return 0;
}