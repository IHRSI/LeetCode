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

//Worst / Best cases SC for dfs
//Balanced tree: H = log N → O(log N) ✅
//Skewed tree: H = N → O(N) ⚠️

//Worst / Best cases for bsf
//Balanced tree: W ≈ N/2 → O(N) ⚠️
//Skewed tree: W = 1 → O(1) ✅

//BFS often runs faster than DFS in practice because it avoids recursion overhead, has better cache locality, and directly matches level-based problems—even though both are O(N).

//BSF
class Solution {
public:
    int maxLevelSum(TreeNode* root) {//TC=O(N), SC=O(N/2) worst case
        queue<TreeNode*> q;
        int lev=0,ans=0;
        int maxsum=INT_MIN;
        q.push(root);
        while(!q.empty()){
            ++lev;
            int currlevsum=0;
            int parent=q.size();
            while(parent--){
                TreeNode* node=q.front();
                q.pop();
                currlevsum+=node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            if(currlevsum>maxsum){
                maxsum=currlevsum;
                ans=lev;
            }
        }
        return ans;
    }
};

//DFS using vector
class Solution {
public:
    vector<int> levsum;
    void dfs(TreeNode* node,int lev){//TC=O(n+H)~O(n), SC=O(H), H is no. of levels, SC in recursion depth is O(H) and in um is O(H) so net O(H)
        if(node==nullptr) return;
        if(levsum.size()==lev) levsum.push_back(node->val);
        else levsum[lev]+=node->val;
        dfs(node->left,lev+1);
        dfs(node->right,lev+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,0);
        int maxsum=INT_MIN;
        int lev=INT_MAX;
        int n=levsum.size();
        for(int i=0;i<n;++i){
            if(levsum[i]>maxsum){
                maxsum=levsum[i];
                lev=i+1;
            }
        }
        return lev;
    }
};

//DFS using UM
class Solution {
public:
    unordered_map<int,int> levsum;
    void dfs(TreeNode* node,int lev){//TC=O(n+H)~O(n), SC=O(H), H is no. of levels, SC in recursion depth is O(H) and in um is O(H) so net O(H)
        if(node==nullptr) return;
        levsum[lev]+=node->val;
        dfs(node->left,lev+1);
        dfs(node->right,lev+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int maxsum=INT_MIN;
        int lev=INT_MAX;
        int n=levsum.size();
        for(int i=1;i<=n;++i){
            if(levsum[i]>maxsum){
                maxsum=levsum[i];
                lev=i;
            }
        }
        return lev;
    }
};
