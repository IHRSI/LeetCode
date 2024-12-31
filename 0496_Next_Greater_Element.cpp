//Brute Force method
class Solution { // TC- O(n1*n2*n2) , SC- O(n1)
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans(n1,-1);
        for(int i=0;i<n1;++i){
            for(int j=0;j<n2;++j){
                if(nums1[i]==nums2[j]){
                    for(int k=j ; k<n2; k++){
                        if(nums2[k]>nums1[i]){ 
                            ans[i]=nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
