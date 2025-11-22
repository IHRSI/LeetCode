class Solution {
public:
    int minimumOperations(vector<int>& nums) {//TC=O(n), SC=O(1)
        int op=0;
        for(int e: nums){
            int mod=e%3;
            op+=min(mod,3-mod);
        }
        return op;
    }
};

class Solution {
public:
    int minimumOperations(vector<int>& nums) {//TC=O(n), SC=O(1)
        int op=0;
        for(int e: nums){
            if(e%3) ++op;
        }
        return op;
    }
};
