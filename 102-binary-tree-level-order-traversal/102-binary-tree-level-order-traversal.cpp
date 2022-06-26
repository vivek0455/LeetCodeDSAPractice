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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levelOrdertraversal;
    queue<TreeNode*> q;
    if(root== NULL) return levelOrdertraversal;
    q.push(root);
    
    while(!q.empty()){
        int n= q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
        TreeNode* r1 = q.front();
            q.pop();
            level.push_back(r1->val);
            if(r1->left !=NULL)q.push(r1->left);
            if(r1->right != NULL)q.push(r1->right);
        }
        levelOrdertraversal.push_back(level);
    }
    return levelOrdertraversal;

    }
};