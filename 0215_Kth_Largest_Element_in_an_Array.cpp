//3 methods
//Array,Divide n Conquer, QuickSelect
class Solution {//O(n)-Avg, O(n^2)-Worst , SC=O(1)
// On each partition, the problem size is halved (or close to it). in avg case -refer master theorem
//If the pivot always ends up at one of the ends (e.g., already sorted array), the partitioning only removes one element each time- worst case
public:
    int parti(vector<int> &nums,int l,int r){//O(n) TC of func
        int p=nums[l];
        int i=l+1;
        int j=r;
        while(i<=j){//Sorting descending
            if(nums[i]<p && nums[j]>p){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=p) i++;
            if(nums[j]<=p) j--;
        }
        swap(nums[l],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int pivot=0;
        int l=0;
        int r=nums.size()-1;
        while(true){
            pivot=parti(nums,l,r);
            if(pivot==k-1) break;
            else if(pivot>k-1) r=pivot-1;
            else l=pivot+1;
        }
        return nums[k-1];
    }
};

//Min-Heap
class Solution {//TC=O(nlogk) , SC=O(k)
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i: nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};

//Basic sorting
class Solution { //TC=O(nlogn) , SC=O(1)
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};
