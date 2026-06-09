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
