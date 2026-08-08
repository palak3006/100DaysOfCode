// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers (-1 represents NULL)

// Output Format:
// - Print inorder traversal of the constructed tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 4 2 5 1 3 6

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

TreeNode* levelOrder(vector<int>&arr)
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

        //left child
        if(i < arr.size())
        {
            if(arr[i] != -1)
            {
                current->left = new TreeNode(arr[i]);
                q.push(current->left);
            }
            i++;
        }

        //right child
        if(i < arr.size())
        {
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

vector<int> inorderTraversal(TreeNode* root)
{
    TreeNode* temp = root;
    stack<TreeNode*> st;
    vector<int>ans;

    while(temp != NULL || !st.empty())
    {
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }

        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->data);
        temp = node->right;
    }

    return ans;
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

    TreeNode* root = levelOrder(arr);

    if(root == NULL)
    {
        cout << "Empty Tree";
    }

    else 
    {
        vector<int> traversed = inorderTraversal(root);

        for(int i=0; i<traversed.size(); i++)
        cout << traversed[i] << " ";
    }

    return 0;
}