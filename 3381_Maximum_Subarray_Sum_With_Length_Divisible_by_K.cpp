//Kadanes Algo
//TC=O(k*(n/k))=O(n), SC=O(n)
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long maxsum=LONG_LONG_MIN;
        int n=nums.size();
        vector<long long> psum(n);
        psum[0]=nums[0];
        for(int i=1;i<n;++i) psum[i]+=nums[i]+psum[i-1];
        for(int srt=0;srt<k;++srt){
            long long currsum=0;
            int i=srt;
            while(i<n && i+k-1<n){
                int j=i+k-1;
                long long subsum=psum[j]- ((i==0)?0:psum[i-1]);
                currsum=max(subsum,currsum+subsum);
                maxsum=max(maxsum,currsum);
                i+=k;
            }
        }
        return maxsum;
    }
};
