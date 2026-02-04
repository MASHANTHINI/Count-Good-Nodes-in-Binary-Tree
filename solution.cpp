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
    int cnt=0;
    void maxpath(TreeNode* root,int mx){
        if(root==nullptr){
            return ;
        }
        if(root->val>=mx)
        cnt++;
        mx=max(mx,root->val);
        maxpath(root->left,mx);
        maxpath(root->right,mx);

    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;
        maxpath(root,INT_MIN);
        return cnt;
    }
};
