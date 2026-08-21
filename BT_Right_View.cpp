// Problem Statement:
// Print the nodes visible when the binary tree is viewed from the right side.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print right view nodes

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 1 3 6

// Explanation:
// At each level, the rightmost node is visible from the right view.

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

vector<int> ds;
void RightSide(TreeNode* root, int level)
{
        if(root == NULL)
        return;

        if(level == ds.size())
        ds.push_back(root->data);

        RightSide(root->right, level+1);
        RightSide(root->left, level+1);
}
vector<int> rightSideView(TreeNode* root)
{
if(root == NULL)
return {};

RightSide(root, 0);

return ds;
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

    vector<int> ans = rightSideView(root);

    if(!ans.empty())
    {
        for(int i=0; i<ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }

    else
    cout << "No element";
    return 0;
} 