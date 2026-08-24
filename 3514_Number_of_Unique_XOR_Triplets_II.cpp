//Using vector bool as we know the limit of max xor value
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {//TC=O(n+log(mx)+n^2+t*n+t)~O(n^2+t*n), SC=O(2t)~O(t)
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int t=1;
        while(t<=mx) t<<=1;
        vector<bool> xorpr(t);
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                xorpr[nums[i]^nums[j]]=1;
            }
        }
        vector<bool> xor3(t);
        for(int i=0;i<t;++i){
            if(xorpr[i]){
                for(int &e: nums) xor3[i^e]=1;
            }
        }
        int triplets=0;
        for(bool b: xor3) if(b) ++triplets;
        return triplets;
    }
};

//UM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {//TC=O(n^2+k*n), SC=O(2k), k=the next nearest pow of 2 next to max element: 2^x ~ 2*max element
        int n=nums.size();
        unordered_set<int> us;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                us.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> triplets;
        for(int xorpair: us){
            for(int e: nums){
                triplets.insert(xorpair^e);
            }
        }
        return triplets.size();
    }
};
