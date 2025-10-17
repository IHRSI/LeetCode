class Solution {//Converted the um soln to vector now we get better runtime and efficient space usage
public:
    int findSmallestInteger(vector<int>& nums, int value) {//TC=O(n), SC=O(value)
            vector<int> mp(value,0);
            for(int e: nums){
                int v=(e%value+value)%value;//This is to handle -ve numbers mod evaluation
                ++mp[v];
            }
            int mex=0;
            while(mp[mex%value]!=0){
                --mp[mex%value];
                mex++;
            }
            return mex;
    }
};
/*
In C++,
(-1 % 5) == -1, not 4.
So if nums contains negatives, your e % value gives a negative remainder — and the logic fails because your map keys are inconsistent.
✅ Fix
You should normalize the remainder to always be non-negative:
int r = ((e % value) + value) % value;
*/

class Solution {//Due to use of um it has bad TC and SC
public:
    int findSmallestInteger(vector<int>& nums, int value) {//TC=O(n), SC=O(value)
            unordered_map<int,int> um;
            for(int e: nums){
                int v=(e%value+value)%value;
                ++um[v];
            }
            int mex=0;
            while(um[mex%value]!=0){
                --um[mex%value];
                mex++;
            }
            return mex;
    }
};
