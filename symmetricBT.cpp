// Problem Statement:
// Check whether a given binary tree is symmetric around its center.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print YES if symmetric, otherwise NO

// Example:
// Input:
// 7
// 1 2 2 3 4 4 3

// Output:
// YES

// Explanation:
// Left subtree is a mirror image of the right subtree.

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

    while(i < arr.size() && !q.empty())
    {
       TreeNode* current = q.front();
       q.pop();

       if(arr[i] != -1)
       {
         current->left = new TreeNode(arr[i]);
         q.push(current->left);
       }
       i++;

       if(i< arr.size() && arr[i] != -1)
       {
        current->right = new TreeNode(arr[i]);
         q.push(current->right);
       }
       i++;
    }

    return root;
}


bool SymmetricCheck(TreeNode* root1, TreeNode* root2)
{
    if(root1 == NULL || root2 == NULL)
    return root1 == root2;


    if(root1->data != root2->data)
    return false;

    bool left = SymmetricCheck(root1->left, root2->right);
    bool right = SymmetricCheck(root1->right, root2->left);

    return left && right;
}

bool isSymmetric(TreeNode* root)
{
    return root == NULL || SymmetricCheck(root->left, root->right);
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

    bool ans = isSymmetric(root);

    if(ans == false)
    cout << "Not Symmetric";
    

    else
    cout << "Symmetric";
    return 0;
} 