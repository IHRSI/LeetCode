//2 Pointer - optimal
class Solution {//TC=O(n) the array is traversed only once it will be max O(2n)~O(n). SC=(1) The output array is not counted in the space complexity.
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n=nums.size();
        int i=0;
        for(int j=0;j<n;++j){
            if(nums[j]==key){
                i=max(i,j-k);
                while(i<=min(j+k,n-1)){
                    ans.push_back(i);
                    ++i;
                }
            }
        }
        return ans;
    }
};

//Brute Force
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {//TC=O(n^2) , SC=O(1)
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(abs(i-j)<=k && nums[j]==key){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
