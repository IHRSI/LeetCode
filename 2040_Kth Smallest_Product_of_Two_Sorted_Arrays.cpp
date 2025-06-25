class Solution {// Used max heap gave TLE
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {//TC=O(n^2*logk) SC=O(K)
        int n1=nums1.size();
        int n2=nums2.size();
        long long ans;
        priority_queue<long long> mh;
        for(int &i : nums1){
            for(int &j: nums2){
                mh.push(i*1ll*j);
                if(mh.size()>k) mh.pop();
            }            
        }
        return mh.top();
        }
};
