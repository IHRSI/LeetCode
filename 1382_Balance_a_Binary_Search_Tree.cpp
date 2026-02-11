/*
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
    vector<int> arr;//SC=O(n)
    void dfs(TreeNode* node){
        if(node==nullptr) return;
        dfs(node->left);
        arr.push_back(node->val);
        dfs(node->right);
    }
    TreeNode* baltree(vector<int> &vals,int st, int end){
        if(st>end) return nullptr;
        int mid=st+((end-st)>>1);
        TreeNode* node=new TreeNode(vals[mid]);
        node->left=baltree(arr,st,mid-1);
        node->right=baltree(arr,mid+1,end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {//TC=O(2n)~=O(n), SC=O(n+n+logn)~O(n)
        dfs(root);//TC=O(n), SC=(depth of tree)=O(n) - worst case
        return baltree(arr,0,arr.size()-1);//TC=O(n), SC=O(logn)- as it forms balanced tree so logn height
    }
};
