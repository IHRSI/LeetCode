//Best approach- Two pointers
class Solution {// TC=(n^2), SC=O(n^2) - worst case - valid triplets inserted
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;// removing duplicates
            int sum=0-nums[i];//2sum logic
            int j=i+1;
            int k=n-1;
            while(j<k){// Two pointer concept
                if(sum==nums[j]+nums[k]){
                    while(j<k && nums[j]==nums[j+1]) j++;// removing duplicates
                    while(j<k && nums[k]==nums[k-1]) k--;// removing duplicates
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]<sum) j++;
                else k--;
            }
        }
        return ans;
    }
};

//Optimised but TLE - used 2sum logic
class Solution { //TC=O(n^2logn) SC=O(n^2)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> demo;
        for(int i=0;i<n;i++){
            unordered_set<int> us;
            int sum2=0-nums[i];
            for(int j=i+1;j<n;j++){
                int x=sum2-nums[j];
                if(us.find(x)!=us.end()){
                    vector<int> triplet={nums[i],nums[j],x};
                    sort(triplet.begin(), triplet.end());
                    demo.insert(triplet);
                }
                us.insert(nums[j]);
            }
        }
        vector<vector<int>> ans;
        for(auto e : demo) ans.push_back(e);
        return ans;
    }
};


//Brute force TLE
class Solution { // TC=O(n^3*logn) , SC=O(n^3)-notice sc
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> sv;
        for(int i=0; i<n-2;++i){
            for(int j=i+1; j<n-1;++j){
                for(int k=j+1; k<n;++k){
                    if(nums[i]+nums[j]+nums[k]==0){
                        sv.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        vector<vector<int>> v;
        for(auto a: sv){
            v.push_back(a);
        }
        return v;
    }
};
