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
    bool ans=true;
    int check(TreeNode* root){
        if(root==nullptr) return 0;
        int leftv=check(root->left);
        int rightv=check(root->right);
        if(abs(leftv-rightv)>1) ans=false;
        return 1+max(leftv,rightv);
    }
    bool isBalanced(TreeNode* root) {
        check(root);
        return ans;
    }
};