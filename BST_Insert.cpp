// Problem: BST Insert

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include<bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val)
{
    if(root == NULL)
    return (new TreeNode(val));

    if(val < root->val)
    {
        root->left = insert(root->left, val);
    }

    else 
    {
        root->right = insert(root->right, val);
    }

    return root;
}


TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        return new TreeNode(val);

        TreeNode* temp = root;

        while(true)
        {
            if(val < temp->val)
            {
                if(temp->left == NULL)
                {
                    temp->left = new TreeNode(val);
                    break;
                }
                temp = temp->left;
            }
            
            else 
            {
                if(temp->right == NULL)
                {
                    temp->right = new TreeNode(val);
                    break;
                }
                temp = temp->right;
            }
        }

        return root;
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

        ans.push_back(current->val);

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

   TreeNode* root = NULL;

   while(n > 0)
   {
    int x;
    cin >> x;

    root = insert(root, x);
    n--;
   }

   cout << "Enter value to insert:";
   int value;
   cin >>value;

   insertIntoBST(root, value);

   LevelOrderTraversal(root);
   return 0;
}