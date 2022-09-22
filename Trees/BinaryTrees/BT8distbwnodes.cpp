#include <bits/stdc++.h>
using namespace std;
struct node
{
    struct node *left;
    struct node *right;
    int data;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
int findlevel(node *root, int value, int level)
{
    if (root == NULL)
        return -1;
    if (root->data == value)
        return level;
    int left = findlevel(root->left, value, level + 1);
    int right = findlevel(root->right, value, level + 1);
    return (left != -1) ? left : right;
}
node *distancehelper(node *root, int node1, int node2, int &dist1, int &dist2, int &tdist, int level)
{
    if (root == NULL)
        return NULL;
    if (root->data == node1)
    {
        dist1 = level;
        return root;
    }
    if (root->data == node2)
    {
        dist2 = level;
        return root;
    }
    node *left = distancehelper(root->left, node1, node2, dist1, dist2, tdist, level);
    node *right = distancehelper(root->right, node1, node2, dist1, dist2, tdist, level);
    if (left && right)
    {
        tdist = dist1 + dist2 - 2 * level;
        return root;
    }
    return (left != NULL) ? left : right;
}
int finddistance(node *root, int node1, int node2)
{
    int dist1 = -1;
    int dist2 = -1;
    int tdist;
    node *lca = distancehelper(root, node1, node2, dist1, dist2, tdist, 1);
    if (dist1 != -1 && dist2 != -1)
    {
        return tdist;
    }
    if (dist1 != -1)
    {
        tdist = findlevel(root, node2, 0);
        return tdist;
    }
    if (dist2 != -1)
    {
        tdist = findlevel(root, node1, 0);
        return tdist;
    }
    return -1;
}
// Optimized Approach
node *LCA(node *root, int node1, int node2)
{
    if (root == NULL)
        return NULL;
    if (root->data == node1 || root->data == node2)
        return root;
    node *leftlca = LCA(root->left, node1, node2);
    node *rightlca = LCA(root->right, node1, node2);
    if (leftlca && rightlca)
        return root;
    return (leftlca != NULL) ? leftlca : rightlca;
}
int find(node *root, int value)
{
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    int left = find(root->left, value);
    int right = find(root->right, value);
    if (!left and !right)
        return 0;
    else
        return left + right + 1;
}
int distance(node *root, int node1, int node2)
{
    node *lca = LCA(root, node1, node2);
    int val1 = find(lca, node1);
    int val2 = find(lca, node2);
    return val1 + val2 - 2;
}
int main()
{
    /*
                 1
              /     \
             2       3
           /  \       \
          5    6       8
                        \
                         9
    */
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(6);
    root->right->right = new node(8);
    root->right->right->right = new node(9);
    cout << "The Distance between Nodes [5,9] is " << distance(root, 5, 9) << endl;
    cout << "The Distance between Nodes [1,9] is " << distance(root, 1, 9) << endl;
    cout << "The Distance between Nodes [2,9] is " << finddistance(root, 2, 9) << endl;
}