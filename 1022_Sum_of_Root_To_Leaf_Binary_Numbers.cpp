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
class Solution {//TC=O(n), SC=O(H)
public:
    int sum=0;
    void dfs(TreeNode * node, int num){
        if(!node) return;
        num=(num<<1) + node->val;
        if(!node->left && !node->right) sum+=num;
        dfs(node->left, num);
        dfs(node->right,num);
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};
