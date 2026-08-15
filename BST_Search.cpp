// Problem: BST Search

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include<bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val)
{
    if(root == NULL)
    return (new TreeNode(val));

    if(val < root->data)
    {
        root->left = insert(root->left, val);
    }

    else 
    {
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode* BST(TreeNode* root, int val)
{
    if(root == NULL)
    return NULL;

    TreeNode* temp = root;

    while(temp != NULL)
    {
        if(val == temp->data)
        return temp;

        else if(val < temp->data)
        temp = temp->left;

        else
        temp = temp->right;
    }

    return temp;
}

int main()
{
   int n;
   cin >> n;

   TreeNode* root = NULL;

   while(n > 0)
   {
    int x;
    cin >> x;

    root = insert(root, x);
    n--;
   }

   cout << "Enter value to search:";
   int value;
   cin >>value;

   if(BST(root, value) == NULL)
   cout << "Not found";

   else 
   cout << "Found";


   return 0;
}