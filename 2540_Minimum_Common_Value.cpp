//2ptr - efficient
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {//TC=O(n+m), SC=O(1)
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]==nums2[j]) return nums1[i];
            else if(nums1[i]>nums2[j]) ++j;
            else ++i;
        }
        return -1;
    }
};

//Can also be done using un-set but will take SC, and using BS in O(nlogm) time where m>n
