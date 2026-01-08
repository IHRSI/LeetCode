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
    long long totsum=0;
    long long maxprod=INT_MIN;
    const int m=1e9+7;
    void dfstot(TreeNode* node){
        if(node==nullptr) return;
        totsum+=node->val;
        dfstot(node->left);
        dfstot(node->right);
    }
    long long dfs(TreeNode* node){
        if(node==nullptr) return 0;
        long long left=dfs(node->left);
        long long right=dfs(node->right);
        long long subsum=left+right+node->val;
        maxprod=max(maxprod,subsum*(totsum-subsum));
        return subsum;
    }
    int maxProduct(TreeNode* root) {
        dfstot(root);//TC=O(n)
        dfs(root);//TC=O(n)
        return maxprod%m;
    }
};

SC=
| Tree Type | Height `H` | Space      |
| --------- | ---------- | ---------- |
| Balanced  | `log N`    | `O(log N)` |
| Skewed    | `N`        | `O(N)`     |
