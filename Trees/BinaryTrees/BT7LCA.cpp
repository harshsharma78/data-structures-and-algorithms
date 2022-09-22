// LCA---> Lowest Common Ancestor(s)
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
node *LCA1(node *root, int node1, int node2)
{
    if (root == NULL)
        return NULL;
    if (root->data == node1 || root->data == node2)
        return root;
    node *left = LCA1(root->left, node1, node2);
    node *right = LCA1(root->right, node1, node2);
    if (left && right)
        return root;
    return (left != NULL) ? left : right;
}

bool findpath2(node *root, vector<int> &path, int value)
{
    if (root == NULL)
        return false;
    path.push_back(root->data);
    if (root->data == value)
        return true;
    if ((root->left && findpath2(root->left, path, value)) || (root->right && findpath2(root->right, path, value)))
        return true;
    // if not present in subtree rooted with root
    path.pop_back();
    return false;
}
int LCA2PathMethod(node *root, int node1, int node2)
{
    vector<int> path1, path2;
    if (root == NULL)
        return -1;
    if (!findpath2(root, path1, node1) || !findpath2(root, path2, node2)) //doesn't find values in both the paths
        return -1;
    int i;
    for (i = 0; (i < path1.size()) && (i < path2.size()); i++)
    {
        if (path1[i] != path2[i])
            break;
    }
    return path1[i - 1];
}

// bool find3(node *root, int key)
// {
//     if (root == NULL)
//         return false;
//     if (root->data == key || find3(root->left, key) || find3(root->right, key))
//         return true;
//     return false;
// }
// node *LCA3(node *root, int node1, int node2, bool &v1, bool &v2)
// {
//     if (root == NULL)
//         return NULL;
//     if (root->data == node1)
//         v1 = true;
//     return root;
//     if (root->data == node2)
//         v2 = true;
//     return root;
//     node *left = LCA3(root->left, node1, node2, v1, v2);
//     node *right = LCA3(root->right, node1, node2, v1, v2);
//     if (left && right)
//         return root;
//     return (left != NULL) ? left : right;
// }
// node *findLCA3(node *root, int node1, int node2)
// {
//     bool v1 = false;
//     bool v2 = false;
//     if (root == NULL)
//         return NULL;
//     node *lca = LCA3(root, node1, node2, v1, v2);
//     if ((v1 && v2) || (v1 && find3(lca, node2)) || (v2 && find3(lca, node1)))
//         return lca;
//     return NULL;
// }
node *LCA3(node *root, int node1, int node2, bool &v1, bool &v2)
{
    // Base case
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches with root's key, report the presence
    // by setting v1 or v2 as true and return root (Note that if a key
    // is ancestor of other, then the ancestor key becomes LCA)
    if (root->data == node1)
    {
        v1 = true;
        return root;
    }
    if (root->data == node2)
    {
        v2 = true;
        return root;
    }

    // Look for keys in left and right subtrees
    node *left_lca = LCA3(root->left, node1, node2, v1, v2);
    node *right_lca = LCA3(root->right, node1, node2, v1, v2);

    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)
        return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}

// Returns true if key k is present in tree rooted with root
bool find3(node *root, int key)
{
    // Base Case
    if (root == NULL)
        return false;

    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->data == key || find3(root->left, key) || find3(root->right, key))
        return true;

    // Else return false
    return false;
}

// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;
node *findLCA3(node *root, int node1, int node2)
{
    // Initialize n1 and n2 as not visited
    bool v1 = false, v2 = false;

    // Find lca of n1 and n2 using the technique discussed above
    node *lca = LCA3(root, node1, node2, v1, v2);

    // Return LCA only if both n1 and n2 are present in tree
    if (v1 && v2 || v1 && find3(lca, node1) || v2 && find3(lca, node2))
        return lca;

    // Else return NULL
    return NULL;
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

    cout << "Lowest Common Ancestor Using Single Traversal Method" << endl;
    node *lca1 = LCA1(root, 1, 9);
    if (lca1 == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << "Least Common Ancestor of [1,9] is " << lca1->data << endl;
    }
    lca1 = LCA1(root, 2, 3); // LCA1(root, 8, 10) this case will return 8 and not NULL,
                             // this case is handled in LPA2 and LPA3 Method

    if (lca1 == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << "Least Common Ancestor of [2,3] is " << lca1->data << endl;
    }

    cout << "Lowest Common Ancestor Using Path Traversal Method" << endl;
    cout << "Least Common Ancestor of [5,6] is " << LCA2PathMethod(root, 5, 6) << endl;
    cout << "Least Common Ancestor of [8,3] is " << LCA2PathMethod(root, 8, 3) << endl;

    cout << "Lowest Common Ancestor Using Single Traversal Method's Modified Version" << endl;
    node *lca3 = findLCA3(root, 2, 6);
    if (lca3 == NULL)
    {
        cout << "Keys Not Present" << endl;
    }
    else
    {
        cout << "Least Common Ancestor of [2,6] is " << lca3->data << endl;
    }
    lca3 = findLCA3(root, 8, 9);
    if (lca3 == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << "Least Common Ancestor of [8,9] is " << lca3->data << endl;
    }
}