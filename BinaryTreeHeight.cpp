// Problem Statement:
// Find the height (maximum depth) of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print the height of the tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 -1

// Output:
// 3

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

TreeNode* LevelOrder(vector<int>&arr)
{
    if(arr.empty())
    return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(i < arr.size())
    {
        TreeNode* current = q.front();
        q.pop();

        if(i<arr.size())
        {
            if(arr[i] != -1)
            {
                current->left = new TreeNode(arr[i]);
                q.push(current->left);
            }
            i++;

            if(arr[i] != -1)
            {
                current->right = new TreeNode(arr[i]);
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}

int maxDepth(TreeNode* root)
{
    if(root == NULL)
    return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left, right);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;

        arr.push_back(x);
    }

    TreeNode* root = LevelOrder(arr);

    cout << "Height of Tree is: " << maxDepth(root) << endl;
    return 0;
}