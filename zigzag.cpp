// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.

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

TreeNode* createBT(vector<int>& arr)
{
    if(arr.empty() || arr[0] == -1)
        return NULL;

    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size())
    {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if(i < arr.size() && arr[i] != -1)
        {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if(i < arr.size() && arr[i] != -1)
        {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

vector<vector<int>> ZigZag(TreeNode* root)
{
    if(root == NULL)
    return {};

    TreeNode* temp = root;

    queue<TreeNode*> q;
    q.push(temp);
    
    vector<vector<int>> ans;

    bool leftToRight = true;

    while(!q.empty())
    {
        int size = q.size();

        vector<int> row(size);

        for(int i=0; i<size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->data;

            if(node->left != NULL)
            q.push(node->left);

            if(node->right != NULL)
            q.push(node->right);
        }

        leftToRight = !leftToRight;
        ans.push_back(row);
    }

    return ans;
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


    vector<vector<int>> ans = ZigZag(root);

    if(!ans.empty())
    {
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=0; j<ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
        }
    }

    return 0;
}