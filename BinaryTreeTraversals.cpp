// Problem Statement:
// Perform inorder, preorder, and postorder traversals of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print inorder, preorder, and postorder traversals

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4 2 5 1 6 3 7
// 1 2 4 5 3 6 7
// 4 5 2 6 7 3 1

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

void preorderTraversal(TreeNode* root)
{
    TreeNode* temp = root;
    stack <TreeNode*> st;
    vector<int> ans;

    while(temp != NULL || !st.empty())
    {
        while(temp != NULL)
        {
            ans.push_back(temp->data);
            st.push(temp);
            temp = temp->left;
        }

        TreeNode* current = st.top();
        st.pop();
        temp = current->right;
    }
    
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}


void inorderTraversal(TreeNode* root)
{
    TreeNode* temp = root;
    stack <TreeNode*> st;
    vector<int> ans;

    while(temp != NULL || !st.empty())
    {
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }

        TreeNode* current = st.top();
        st.pop();
        ans.push_back(current->data);
        temp = current->right;
    }
    
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void postorderTraversal(TreeNode* root)
{
    vector<int> ans;
    stack<TreeNode*> st;

    TreeNode* temp = root;
    TreeNode* lastVisited = NULL;

    while(temp != NULL || !st.empty())
    {
        // Go as far left as possible
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }

        TreeNode* current = st.top();

        // If right child exists and hasn't been visited yet
        if(current->right != NULL && lastVisited != current->right)
        {
            temp = current->right;
        }
        else
        {
            // Left and right are finished → visit root
            ans.push_back(current->data);
            lastVisited = current;
            st.pop();
        }
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

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


   cout << endl;
   
   preorderTraversal(root);
   postorderTraversal(root);
   inorderTraversal(root);

   return 0;
   
}