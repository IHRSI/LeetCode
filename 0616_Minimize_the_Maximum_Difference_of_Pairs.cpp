//Predicate Function -BS
//In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and Insertion Sort, with worst-case space complexity of O(logn).
class Solution {//TC=O(nlogn+Klogn) , SC=(logn)
public:
    int ct_pairs(vector<int> &nums, int max_diff){
        int poss_pair=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=max_diff){
                ++i;//greedy(skipping if we satify condn)
                ++poss_pair;
            }
        }
        return poss_pair;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=nums[nums.size()-1]-nums[0];//hi=k
        while(hi>lo){//FFFFFFTTTTTTT
            int mid=lo+ ((hi-lo)>>1);
            if(ct_pairs(nums,mid)>=p) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};

/*Greedy(why it works here - refer edtorial) approach always brings the most number of valid pairs.
Here we provide a brief explanation: Recall that in the greedy approach, we traverse the array in ascending order. 
Suppose there is another alternative approach that yields more valid pairs compared to the greedy approach. 
We can align the arrays of these two approaches side by side and traverse them together in ascending order until the first point of divergence.
Since the greedy approach always selects the "leftmost" pair, when a divergence occurs, 
the pair from the alternative approach must be "to the right." Let's assume these pairs as (i - 1, i) and (i, i + 1) respectively. 
 As shown in the picture above.So far, both approaches have selected an equal number of valid pairs in subarrays nums[0 ~ i] and nums[0 ~ i + 1], respectively. 
 However, the remaining subarray of the greedy approach (nums[i+1 ~ n-1]) is longer, providing more choices. 
 Thus the valid pairs (if exist) selected from this remaining subarray are guaranteed to be greater than or equal to the pairs 
 from the remaining portion of the alternative approach (nums[i+2 ~ n-1]).
*/
