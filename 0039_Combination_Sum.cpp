class Solution { //TC=O(2^n) , SC=O(N * (target / min(candidates))) , N is possible combination and other part in no. of element in each combination in worst case.
public:
    vector<vector<int>> v;
    void backtrack(vector<int> &candidates, int i, vector<int> &temp,int left){
        if(left==0){
            v.push_back(temp);
            return;
        }
        else if(left<0 || i==candidates.size()) return;
        temp.push_back(candidates[i]);
        backtrack(candidates,i,temp,left-candidates[i]);
        temp.pop_back();
        backtrack(candidates,i+1,temp,left);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int left=target;
        backtrack(candidates,0,temp,left);
        return v;
    }
};
