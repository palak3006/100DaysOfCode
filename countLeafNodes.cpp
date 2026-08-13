// Problem: Count Leaf Nodes

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

TreeNode* createTree(vector<int>&arr)
{
    if(arr.empty())
    return NULL;

    queue<TreeNode*>q;
    TreeNode* temp = new TreeNode(arr[0]);
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

int countLeafNode(TreeNode* root)
{
    if(root == NULL)
    return -1;

    int count = 0;

    stack<TreeNode*> st;

    st.push(root);

    while(!st.empty())
    {
        TreeNode* current = st.top();
        st.pop();

        if(current->left == NULL && current->right == NULL)
        count++;

        if(current->left != NULL)
        st.push(current->left);

        if(current->right != NULL)
        st.push(current->right);
    }

    return count;
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

    TreeNode* root = createTree(arr);

    cout << "Total Number of Leaf Nodes are: " << countLeafNode(root) << endl;

    return 0;
}