// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

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

TreeNode* createBST(TreeNode* root, int val)
{
    if(root == NULL)
    return new TreeNode(val);

    else if(root->data <= val)
    root->right = createBST(root->right, val);

    else 
    root->left = createBST(root->left, val);

    return root;
}

TreeNode* LCA(TreeNode* root, int p, int q)
{
    if(root == NULL)
    return NULL;

    TreeNode* temp = root;

    while(temp != NULL)
    {
        if(p < temp->data && q < temp->data)
        temp = temp->left;

        else if(p > temp->data && q > temp->data)
        temp = temp->right;

        else 
        return temp;
    }
    return NULL;
}

int main()
{
   int n;
   cin >> n;

   TreeNode* root = NULL;

   for(int i=0; i<n; i++)
   {
    int x;
    cin >> x;

    root = createBST(root, x);
   }

   cout << "Enter values for which you want to find LCA: ";
   int p,q;

   cin >> p >> q;

   TreeNode* LCA_Node = LCA(root, p, q);

   if(LCA_Node == NULL)
   cout << "No LCA";

   else 
   cout << "LCA of " << p << " & " << q << " is: " << LCA_Node->data;

   return 0;
}