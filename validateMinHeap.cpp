// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.

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

        if(i < arr.size() && arr[i] != -1)
        {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

//after single NULL no new node should be there
bool completeBinaryTree(TreeNode* root)
{
    if(root == NULL)
    return true;

    queue<TreeNode*> q;
    q.push(root);

    bool foundNull = false;

    while(!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        if(current == NULL)
        foundNull = true;

        else 
        {
            //after null node is encountered
            if(foundNull)
            return false;

            q.push(current->left);
            q.push(current->right);
        }
    }

    return true;
}

bool validMinHeap(TreeNode* root)
{
    if(root == NULL)
    return true;

    if(root->left != NULL && root->data > root->left->data)
    return false;
    
    if(root->right != NULL && root->data > root->right->data)
    return false;

    return validMinHeap(root->left) && validMinHeap(root->right);
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

   TreeNode* root = createBT(arr);

   if(completeBinaryTree(root)== true)
   {
      if(validMinHeap(root) == true)
      cout << "Valid Min Heap";

      else
      cout << "Not a valid min heap";
   }

   else
   cout <<"Not a valid min heap";

   return 0;
}