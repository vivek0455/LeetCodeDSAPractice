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
int levelOrder(TreeNode* root){
    if(!root)return 0;
    queue<pair<TreeNode*, long>> q;
    q.push({root,0});
    int maxwidth = 0;
    while(!q.empty() ){
        int n = q.size();
        int minn= q.front().second;
        int first=0;         int last =0;
        for(int i=0;i<n;i++){
            pair<TreeNode*,long> tem = q.front();
             q.pop();
            TreeNode* temp = tem.first;
            long index = tem.second-minn; //subtract to prevent int overflow
            if(i==0)first = (int)index;
             if(i== n-1)last = (int)index;
           
            
            if(temp->left){ 
                           q.push({temp->left, 2*index+1});}
            if(temp->right){ 
                            q.push({temp->right, 2*index+2});}
        }
 
       int diff = last-first+1;  
 
       maxwidth = max(diff, maxwidth);
    }
    return maxwidth;
}
    int widthOfBinaryTree(TreeNode* root) {
        return levelOrder(root);
    }
};