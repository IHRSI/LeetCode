//Finding the pivot= start of original unrotated array
class Solution {
public:
    int findpiv(vector<int> & arr,int n){//eg- {3,4,5,1,2} pivot idx=3 i.e arr[3]=1
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[r]) l=mid+1;
            else r=mid;
        }
        return r;
    }
    int binser(vector<int> &arr,int l,int r,int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {//TC=O(3logn)~O(logn), SC=O(1)
        int  n=nums.size();
        int pivot=findpiv(nums,n);
        int idx=binser(nums,0,pivot-1,target);
        if(idx!=-1) return idx;
        return binser(nums,pivot,n-1,target);
    }
};

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
            int mid = left + ((right-left)>>1);

            if (nums[mid] == target) {
                return mid;
            } else if (nums[left]<=nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;        
    }
};
