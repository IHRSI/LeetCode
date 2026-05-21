//2ptr
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {//TC=O(n+m), SC=O(1)
        int ans=0;
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]>nums2[j]){
                ++i;
            }
            else{
                ans=max(ans,j-i);
                ++j;
            }
        }
        return ans;
    }
};

//BS
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {//TC=O(nlogm), SC=O(1)
        int ans=0;
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<n;++i){
            int j=upper_bound(nums2.begin()+i,nums2.end(),nums1[i],greater<int>())-nums2.begin()-1;
            ans=max(ans,j-i);
        }
        return ans;
    }
};
