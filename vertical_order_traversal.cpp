// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

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
    if (arr.empty())
    return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i=1;

    while(!q.empty()  &&  i < arr.size())
    {
        TreeNode* current = q.front();
        q.pop();

        if(arr[i] != -1)
        {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if(i <arr.size() &&  arr[i] != -1)
        {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

vector<vector<int>> VerticalOrderTraversal(TreeNode* root)
{
    if(root == NULL)
    return {};

    //To store Node and Column
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    //To store column and list of nodes
    map<int, vector<int>> mpp;
    
    vector<vector<int>> ans;

    while(!q.empty())
    {
        auto current = q.front();
        q.pop();

        TreeNode* node = current.first;
        int column = current.second;

        mpp[column].push_back(node->data);

        if(node->left != NULL)
        q.push({node->left, column - 1});
        
        if(node->right != NULL)
        q.push({node->right, column + 1});
    }

    for(auto it : mpp)
    {
        ans.push_back(it.second);
    }
    
    return ans;

}
int main()
{
    int n;
    cin >> n;

    vector<int> arr;

    for(int i=0; i<n;i++)
    {
        int x;
        cin >> x;

        arr.push_back(x);
    }

    TreeNode* root = createBT(arr);

    vector<vector<int>> ans = VerticalOrderTraversal(root);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}