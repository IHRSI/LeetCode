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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {//TC=O(n), SC=O(n)
        int n=descriptions.size();
        unordered_map<int,TreeNode*> node;
        unordered_set<int> child;
        for(auto &e: descriptions){
            int par=e[0];
            int chi=e[1];
            if(!node.count(par)) node[par]=new TreeNode(par);
            if(!node.count(chi)) node[chi]=new TreeNode(chi);
            if(e[2]) node[par]->left=node[chi];
            else node[par]->right=node[chi];
            child.insert(chi);
        }
        for(auto &e: descriptions){
            if(child.count(e[0])==0) return node[e[0]];
        }
        return nullptr;
    }
};
