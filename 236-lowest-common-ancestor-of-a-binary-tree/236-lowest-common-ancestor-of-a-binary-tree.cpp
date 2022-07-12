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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* target1, TreeNode* target2) {
    if(root== NULL || root== target1 || root== target2)return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, target1, target2);
    TreeNode* right = lowestCommonAncestor(root->right, target1, target2);
    
   if(left == NULL)return right;
   else if(right == NULL)return left;
   else return root;
    }
};