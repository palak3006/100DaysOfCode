// Problem: Level Order Traversal

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

TreeNode* createBinaryTree(vector<int>&arr)
{
    if(arr.empty())
    return NULL;

    TreeNode* temp = new TreeNode(arr[0]);
    queue<TreeNode*> q;

    q.push(temp);
    int i = 1;

    while(i < arr.size())
    { 
        TreeNode* current = q.front();
        q.pop();

        if(arr[i] != -1)
        {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if(i < arr.size() && arr[i] != -1)
        {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return temp;
}

void LevelOrderTraversal(TreeNode* root)
{
    if(root == NULL)
    return;

    vector<int> ans;
    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        ans.push_back(current->data);

        if(current->left != NULL)
        q.push(current->left);

        if(current->right != NULL)
        q.push(current->right);
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
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

    TreeNode* root = createBinaryTree(arr);

    cout << "Level Order Traversal" << endl;
    LevelOrderTraversal(root);

    return 0;

}