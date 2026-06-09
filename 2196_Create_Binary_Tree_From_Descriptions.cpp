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
//Best Approach - Constructing Tree From Directly Map and TreeNode Object
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {//TC=O(2n~O(n)), SC=O(2n)~O(n)
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

//BSF - TC=O(3n)~O(n), SC+O(4n)~O(n)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> chi;
        unordered_map<int,vector<pair<int,bool>>> parchi;
        for(auto &e: descriptions){
            int c=e[1];
            chi.insert(c);
            parchi[e[0]].emplace_back(c,e[2]);
        }
        TreeNode *root;
        for(auto &e: descriptions){
            if(chi.count(e[0])==0){
                root=new TreeNode(e[0]);
                break;
            }
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* par=q.front();
            q.pop();
            for(auto &chi_info: parchi[par->val]){
                int val=chi_info.first;
                bool lr=chi_info.second;
                TreeNode *newchi_n=new TreeNode(val);
                q.push(newchi_n);
                if(lr) par->left=newchi_n;
                else par->right=newchi_n;
            }
        }
        return root;
    }
};
//DFS - TC=O(3n)~O(n), SC=O(4n)~O(n)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> chi;
        unordered_map<int,vector<pair<int,bool>>> parchi;
        for(auto &e: descriptions){
            int c=e[1];
            chi.insert(c);
            parchi[e[0]].emplace_back(c,e[2]);
        }
        int root;
        for(auto &e: descriptions){
            if(chi.count(e[0])==0){
                root=e[0];
                break;
            }
        }
        return dfs(root,parchi);
    }
private:
    TreeNode* dfs(int val,unordered_map<int,vector<pair<int,bool>>> &parchi){
        TreeNode* par=new TreeNode(val);
        if(parchi.find(val)!=parchi.end()){
            for(auto &chinfo: parchi[val]){
                int chival=chinfo.first;
                bool lr=chinfo.second;
                if(lr) par->left=dfs(chival,parchi);
                else par->right=dfs(chival,parchi);
            }
        }
        return par;
    }
};
