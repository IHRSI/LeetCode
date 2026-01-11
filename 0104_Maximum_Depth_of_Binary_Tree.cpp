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
//DFS
class Solution {
public:
    int dfs(TreeNode* node){//TC=O(n), SC=O(max depth it goes)- O(N) in case of skewed and O(logn) in best case
        if(node==nullptr) return 0;
        int left=dfs(node->left);
        int right=dfs(node->right);
        return max(left,right)+1;
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};

//BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {//TC=O(n)
        int maxdep=0;
        queue<TreeNode*> q;
        if(root==nullptr) return 0;
        q.push(root);
        while(!q.empty()){
            ++maxdep;
            int size=q.size();
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return maxdep;
    }
};
/*
SC:
| Tree Type            | Width `W` | Space    |
| -------------------- | --------- | -------- |
| Balanced binary tree | ≈ `N/2`   | **O(N)** |
| Skewed tree          | `1`       | **O(1)** |
*/
