#include <bits/stdc++.h>
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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                    int& preIndex, int inStart, int inEnd)
{
    // No elements in this subtree
    if(inStart > inEnd)
        return NULL;

    // First preorder element is the root
    int rootValue = preorder[preIndex++];

    TreeNode* root = new TreeNode(rootValue);

    // Find root in inorder
    int index = inStart;

    while(inorder[index] != rootValue)
    {
        index++;
    }

    // Construct left subtree
    root->left = buildTree(preorder, inorder,
                           preIndex, inStart, index - 1);

    // Construct right subtree
    root->right = buildTree(preorder, inorder,
                            preIndex, index + 1, inEnd);

    return root;
}

void postorder(TreeNode* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

int main()
{
    int n;
    cin >> n;

    vector<int> preorder(n);
    vector<int> inorder(n);

    for(int i = 0; i < n; i++)
        cin >> preorder[i];

    for(int i = 0; i < n; i++)
        cin >> inorder[i];

    int preIndex = 0;

    TreeNode* root = buildTree(preorder, inorder,
                               preIndex, 0, n - 1);

    postorder(root);

    return 0;
}