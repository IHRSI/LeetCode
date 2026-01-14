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
/*SC=
| Tree type | Height `H` | Space      |
| --------- | ---------- | ---------- |
| Balanced  | `log N`    | `O(log N)` |
| Skewed    | `N`        | `O(N)`     |
*/
class Solution {//TC=O(2n)~O(n)
public:
    int mx_dep=0;
    int mxdep(TreeNode* node){
        if(node==nullptr) return 0;
        int left=0,right=0;
        if(node->left) left=mxdep(node->left)+1;
        if(node->right) right=mxdep(node->right)+1;
        return max(left,right);
    }
    TreeNode* lca(TreeNode* node,int depth){
        if(node==nullptr || depth==mx_dep) return node;
        TreeNode* left=lca(node->left,depth+1);
        TreeNode* right=lca(node->right,depth+1);
        if(left && right) return node;
        return (left)?left:right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        mx_dep=mxdep(root);
        return lca(root,0);
    }
};
