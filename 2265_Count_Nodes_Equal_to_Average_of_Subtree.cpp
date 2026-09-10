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
    pair<int,int> dfs(TreeNode* root){//TC=O(n), SC=O(h), h=logn for balanced and h=n for skewed tree
        if(!root)return {0,0};
        auto[a1,b1]=dfs(root->left);
        auto[a2,b2]=dfs(root->right);
        int nodesum=a1+a2+root->val, nodect=b1+b2+1;
        if(nodesum/nodect==root->val) ++cnt;
        return {nodesum,nodect};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};
