// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

// Example:
// Input:
// 5
// 4 2 5 1 3
// 4 5 2 3 1

// Output:
// 1 2 4 5 3

// Explanation:
// Postorder gives root at end, inorder divides left and right subtrees.

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

int postIndex;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                    int left, int right)
{
    if(left > right)
        return NULL;

    // Last element of postorder is the root
    int rootValue = postorder[postIndex--];

    TreeNode* root = new TreeNode(rootValue);

    // Find root in inorder
    int index = left;

    while(inorder[index] != rootValue)
    {
        index++;
    }

    // Since postorder is being traversed backwards,
    // build right subtree first
    root->right = buildTree(inorder, postorder,
                            index + 1, right);

    root->left = buildTree(inorder, postorder,
                           left, index - 1);

    return root;
}

void preorder(TreeNode* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    cin >> n;

    vector<int> inorder(n);
    vector<int> postorder(n);

    for(int i = 0; i < n; i++)
        cin >> inorder[i];

    for(int i = 0; i < n; i++)
        cin >> postorder[i];

    postIndex = n - 1;

    TreeNode* root = buildTree(inorder, postorder,
                               0, n - 1);

    preorder(root);

    return 0;
}