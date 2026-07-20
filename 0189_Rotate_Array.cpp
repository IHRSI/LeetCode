//Best approach - using reverse fn
class Solution {
public:
    void rotate(vector<int>& nums, int k) {//TC=O(n), SC=O(1)
        int n=nums.size();
        k%=n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
//By lambda for reverse - more efficient
class Solution {
public:
    void rotate(vector<int>& nums, int k) {//TC=O(n), SC=O(1)
        int n=nums.size();
        k%=n;
        auto reverse=[&](int i,int j){
            while(i<j){
                swap(nums[i],nums[j]);
                ++i;
                --j;
            }
        };
        reverse(0,n-1);
        reverse(0,k-1);
        reverse(k,n-1);
    }
};

// STL func
class Solution {
public:
    void rotate(vector<int>& nums, int k) {//TC=O(n), SC=O(1)
        int n=nums.size();
        k=k%n;
        std:: rotate(nums.begin(),nums.end()-k,nums.end());
    }
};

//Using additional space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {//TC=O(n), SC=O(n)
        int n=nums.size();
        k%=n;
        vector<int> rotarr(n);
        for(int i=0;i<n;++i){
            rotarr[(i+k)%n]=nums[i];
        }
        nums=rotarr;
    }
};

//Brute Force TLE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {//TC=O(k*n), SC=O(1)
        int n=nums.size();
        k%=n;
        for(int i=0;i<k;++i){
            int last=nums[n-1];
            for(int j=n-1;j>0;--j){
                nums[j]=nums[j-1];
            }
            nums[0]=last;
        }
    }
};
