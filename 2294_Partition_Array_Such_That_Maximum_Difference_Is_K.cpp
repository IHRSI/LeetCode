class Solution {//TC=O(nlogn) , SC=O(logn) - worst case - goes into sorting
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());//greedy as sorting reduces the no. of comp
        //and Since changing the order of elements does not affect the grouping(forming subsequence), we can sort the array first.
        int ans=1;
        int min_ind=0;
        for(int i=1;i<nums.size();++i){//Greedy approach here: for each group, we include as many numbers as possible.
            if(nums[i]-nums[min_ind]<=k) continue;
            else{
                ans++;
                min_ind=i;
            }
        }
        return ans;
    }
};
