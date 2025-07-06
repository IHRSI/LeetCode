//OOP concept
/*Since the length of the array nums1 is less than or equal to that of nums2,for the getPairs(tot) operation, we can store the elements of nums2
​in a hash map. Then, we enumerate each element num in nums1 and look up the value corresponding to the key tot−num in the hash map. The sum of these values gives us the answer.*/
class FindSumPairs {//2sum logic
private:
    unordered_map<int,int> freq;//O(m)
    vector<int> nums1,nums2;//SC-O(n+m)
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {//TC=(n+2m+q1+q2*n) , SC=O(n+2m)
        this->nums1=nums1;//O(n)
        this->nums2=nums2;O//O(m)
        for(int &val: nums2) ++freq[val];//O(m)
    }
    //If we choose to delete keys from the hash map when their frequency becomes zero, the map’s space usage remains bounded by O(m), independent of the number of add operations.
    void add(int index, int val) {//q1 calls - O(1)
        --freq[nums2[index]];
        nums2[index]+=val;
        ++freq[nums2[index]];
    }
    
    int count(int tot) {//q2 calls - O(n)
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
