// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2

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

TreeNode* createBT(vector<int>&arr)
{
    if(arr.empty())
    return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty())
    {
       TreeNode* current = q.front();
       q.pop();

       if(arr[i] != -1)
       {
         current->left = new TreeNode(arr[i]);
         q.push(current->left);
       }
       i++;

       if(i< arr.size()-1 && arr[i] != -1)
       {
        current->right = new TreeNode(arr[i]);
         q.push(current->right);
       }
       i++;
    }

    return root;
}

TreeNode* BT_LCA(TreeNode* root, int p, int q)
{
    if(root == NULL)
    return NULL;

    else if(root->data == p || root->data == q)
    return root;

    else
    {
        TreeNode* left = BT_LCA(root->left, p, q);
        TreeNode* right = BT_LCA(root->right, p, q);

        if(left != NULL && right != NULL)
        return root;

        else if(left != NULL)
        return left;

        return right;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int>arr;

    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    TreeNode* root = createBT(arr);

    cout << "Enter values for which LCA has to be find: ";

    int a,b;
    cin >> a >> b;

    TreeNode* LCA = BT_LCA(root, a, b);

    if(LCA == NULL)
    cout << "No LCA";

    else 
    cout << "LCA of " << a << " & " << b << " is: " << LCA->data;

    return 0;
} 
