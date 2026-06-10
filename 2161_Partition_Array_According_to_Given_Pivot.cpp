class Solution {//Efficient
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {//TC=O(2n)~O(n), SC=O(1)
        int n=nums.size();
        int less=0,eql=0;
        for(int e: nums){
            if(e<pivot) ++less;
            else if(e==pivot) ++eql;
        }
        vector<int> ans(n);
        int idx_l=0,idx_e=less,idx_m=less+eql;
        for(int e: nums){
            if(e<pivot){
                ans[idx_l]=e;
                ++idx_l;
            }
            else if(e==pivot){
                ans[idx_e]=e;
                ++idx_e;
            }
            else{
                ans[idx_m]=e;
                ++idx_m;
            }
        }
        return ans;
    }
};

//2ptr
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {//TC=O(3n)~O(n), SC=O(1)
        int n=nums.size();
        vector<int> ans(n);
        int less=0,more=n-1;
        for(int e: nums){
            if(e<pivot){
                ans[less]=e;
                ++less;
            }
        }
        for(int i=n-1;i>=0;--i){
            if(nums[i]>pivot){
                ans[more]=nums[i];
                --more;
            }
        }
        while(less<=more){
            ans[less]=pivot;
            ++less;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {//TC=O(2n)~O(n), SC=O(n)
        vector<int> less,more;//O(n) SC
        int ct_pivot=0;
        for(int e: nums){
            if(e>pivot) more.push_back(e);
            else if(e<pivot) less.push_back(e);
            else ++ct_pivot;
        }
        vector<int> ans;
        for(int e: less) ans.push_back(e);
        while(ct_pivot--) ans.push_back(pivot);
        for(int e: more) ans.push_back(e);
        return ans;
    }
};
//Simplified for efficiency by making the less arr as ans. Takes less time and space from above
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {//TC=O(2n)~O(n), SC=O(n)
        vector<int> less,more;
        int ct_pivot=0;
        for(int e: nums){
            if(e>pivot) more.push_back(e);
            else if(e<pivot) less.push_back(e);
            else ++ct_pivot;
        }
        while(ct_pivot--) less.push_back(pivot);
        for(int e: more) less.push_back(e);
        return less;
    }
};
