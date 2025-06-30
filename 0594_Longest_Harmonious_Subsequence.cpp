//Subsequence Q
//Memory Allocation Overhead:
//unordered_map constantly allocates new buckets when resizing takes time.
//vector + sorting uses tight, compact memory .Takes less time


//class Solution {//Best efficient - used 2pointer/sliding window
public:
    int findLHS(vector<int>& nums) {//TC=O(nlogn) , SC=O(1)- sc improved as we used sorting and no hashing, sc of sort in worst case is O(logn)
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0,j=1,n=nums.size();
        while(j<n){//O(n)
            if(nums[j]-nums[i]==1){
                ans=max(ans,j-i+1);
                ++j;
            }
            else if(nums[j]-nums[i]>1){
                ++i;
            }
            else ++j;

        }
        return ans;
    }
};

//Even though your unordered map solution below is O(N) in theory,
//the constants and memory overhead make it slower in practice compared to the beautifully optimized sorting + two-pointer solution above.
//Hashing each key, handling collisions, resizing hash tables → all these internal steps cost time.

class Solution {// Used unordered map with 2sum Q logic
public://Didnt use sorting
    int findLHS(vector<int>& nums) {//TC=O(n) , SC=O(n) worst case if all ele are diff
        int ans=0;
        unordered_map<int,int> freq;
        for(int &ele : nums){
            ++freq[ele];
        }
        for(auto ele: freq){//A-B=1, A=1+B
          //if(freq.count(1+ele.first)) ans=max(ans,ele.second+freq[1+ele.first]);
            if(freq.find(1+ele.first)!=freq.end()) ans=max(ans,ele.second+freq[1+ele.first]);
        }
        return ans;
    }
};

class Solution {//Used ordered map
public:
    int findLHS(vector<int>& nums) {//TC=(nlogn) , SC=O(n) - worst case if all ele are diff
        int ans=0,n=nums.size();
        map<int,int> freq;
        for(int &ele : nums){
            ++freq[ele];
        }
        int n2=freq.size();
        auto prev=freq.begin();
        for(auto it=++freq.begin(); it!=freq.end();++it){//Used iterator variable in loop
            if(it->first - prev->first==1) ans=max(ans,it->second + prev->second);
            ++prev;
        }
        return ans;
    }
};
