//1123 Q is same as this Q
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
//New approach -
/*
Perform BFS and store only the first and last node at the deepest level.
Find the LCA of first and last node.
Thus it is ensured that all the other nodes between the first and last node will be part of the LCA found.
*/
class Solution {//TC=O(2n)~O(n), SC=O(W+H)
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {//SC=O(H)
        if (!root || root == p || root == q)
            return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {//SC=O(W)
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* first;
        TreeNode* last;
        while (!q.empty()) {
            int sz = q.size();
            first = nullptr;
            last = nullptr;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (!first) first = node;
                last = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return lca(root, first, last);
    }
};

//This soln is same as 2pass soln of Q1123
class Solution {//TC=O(2n)~O(n), SC=O(n)
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        mx_dep=mxdep(root);
        return lca(root,0);
    }
};
