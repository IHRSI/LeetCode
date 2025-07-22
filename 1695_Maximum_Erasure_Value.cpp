//Used vector hashing as constraint was ele<10^4, Efficient
class Solution {// 0ms/11ms & 93mb
public:
    int maximumUniqueSubarray(vector<int>& nums) {//TC=O(n) , SC=O(n) but its vector<bool> not um<int>
        int ans=0,temp=0;//Max subarray sun of unique elements
        int n=nums.size();
        vector<bool> hash(10001,0);//Stored unique elements
        int l=0,r=0;
        while(r<n){
            if(hash[nums[r]]){
                while(nums[l]!=nums[r]){
                    hash[nums[l]]=0;
                    temp-=nums[l];
                    ++l;
                }
                ++l;
            }
            else{
                hash[nums[r]]=1;
                temp+=nums[r];
                ans=max(ans,temp);
            }
            ++r;
        }
        return ans;
    }
};
//Used um - find takes O(1) but in worst case due to colisions it can take O(n) takes a bit time as in vector we do hashing in precise O(1)
class Solution {//123ms, 118mb
public:
    int maximumUniqueSubarray(vector<int>& nums) {//TC=O(n) , SC=O(n)
        int ans=0,temp=0;//Max subarray sun of unique elements
        int n=nums.size();
        unordered_set<int> us;//Stored unique elements
        int l=0,r=0;
        while(r<n){
            if(us.find(nums[r])!=us.end()){
                while(nums[l]!=nums[r]){
                    us.erase(nums[l]);
                    temp-=nums[l];
                    ++l;
                }
                ++l;
            }
            else{
                us.insert(nums[r]);
                temp+=nums[r];
                ans=max(ans,temp);
            }
            ++r;
        }
        return ans;
    }
};
