//Linear Scan- logic(inspo Triplet with maxm triangle perimeter)
class Solution {//codewithmike
public:
    int triangleNumber(vector<int>& nums) {//TC=O(n^2), SC=O(1)
        int n=nums.size();
        int ct=0;
        sort(nums.begin(),nums.end());
        for(int k=n-1;k>=2;--k){
            int i=0,j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    ct+=j-i;
                    --j;
                }
                else ++i;
            }
        }
        return ct;
    }
};

class Solution {//BS+Greedy+Sorting+LB func
public:
    int triangleNumber(vector<int>& nums) {//TC=O(n^2*logn),SC=O(logn)
        int ct=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i+2<n;++i){
            for(int j=i+1;j+1<n;++j){
                int ele3=nums[i]+nums[j];
                auto it=lower_bound(nums.begin()+j+1,nums.end(),ele3);
                ct+=it-1-(nums.begin()+j);
            }
        }
        return ct;
    }
};

//Same as above without LB func but BS code
class Solution {
public:
    int binarySearch(const vector<int>& nums, int l, int r, int target) {
        int k = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                k = mid;         // mid is valid
                l = mid + 1;     // try to go right
            } else {
                r = mid - 1;     // go left
            }
        }
        return k;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) 
                continue;
            for (int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j]; //sum of two sides
                int k = binarySearch(nums, j + 1, n - 1, sum);
                if (k != -1) 
                    count += (k - j);
            }
        }
        return count;
    }
};

//Brute Force
class Solution {//TLE
public:
    int triangleNumber(vector<int>& nums) {//TC=O(n^3), SC=O(1)
        int count = 0;
        int n=nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] > nums[k] && 
                        nums[i] + nums[k] > nums[j] && 
                        nums[j] + nums[k] > nums[i]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
