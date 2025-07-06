//OOP concept
class FindSumPairs {//2sum logic
private:
    unordered_map<int,int> freq;
    vector<int> nums1,nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {//TC=O(nums1) , SC=O(nums2)
        this->nums1=nums1;
        this->nums2=nums2;
        for(int &val: nums2) ++freq[val];
    }
    
    void add(int index, int val) {
        --freq[nums2[index]];
        nums2[index]+=val;
        ++freq[nums2[index]];
    }
    
    int count(int tot) {
        int left,ans=0;
        for(int &val: nums1){
            left=tot-val;
            if(freq.count(left)) ans+=freq[left];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
