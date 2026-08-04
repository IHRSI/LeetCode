//Less time more space
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {//TC=O(n+n+n+r)~O(n+r), SC=O(r)
        int larg=*max_element(nums.begin(),nums.end());
        int smal=*min_element(nums.begin(),nums.end());
        int r=larg-smal+1;//r=range of numbers
        vector<bool> present(r);
        for(int e:nums) present[e-smal]=1;
        vector<int> ans;
        for(int i=0;i<r;++i){
            if(!present[i]) ans.push_back(i+smal);
        }
        return ans;
    }
};

//More time less space
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {//TC=O(nlogn+r), SC=O(logn)
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n-1;++i){
            for(int j=nums[i]+1;j<nums[i+1];++j) ans.push_back(j);
        }
        return ans;
    }
};
