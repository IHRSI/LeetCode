//Brute Force
class Solution { //TC=O(n), SC=O(1)
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size();++i){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};

//Using modified binary search
class Solution {//TC=0(logn), SC=O(1)
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;        
    }
};
