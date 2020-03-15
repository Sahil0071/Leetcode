/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>a;
    void inorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* build(int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int m=(l+r)/2;
        TreeNode* n=new TreeNode(a[m]);
        n->left=build(l,m-1);
        n->right=build(m+1,r);
        return n;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* x;
        inorder(root);
        x=build(0,a.size()-1);
        return x;
    }
};
