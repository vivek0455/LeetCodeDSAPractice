/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        bool isBalanced(TreeNode* root) {
        int h=0;
        int count = height(root , h);
        if(h == -1) return false;
        
        return true;
        
    }
    
    int height(TreeNode* root , int &h){
        
        if(root == nullptr) return 0;
        
        int lh = height(root->left,h);
        int rh = height(root->right,h);
        
        if(abs(rh - lh) > 1){
            h =  -1;
        }
        return 1+ max(lh,rh);
        
        
    }
};