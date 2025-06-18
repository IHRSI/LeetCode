// Both solns are completely similar but 1st one is more efficient.
/*But the first version is more efficient because it:
Avoids extra temporaries
Uses brace-init, enabling better compiler optimization
Reduces memory allocation overhead
*/
class Solution {//TC=O(nlogn) , SC=O(logn) it goes in sort, not considering SC of 2d vector ans as its asked to return
public://44ms , 120kb
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());//SC=O(logn)//greedy
        int n=nums.size();
        for(int i=0;i<n;i+=3){//O(n/3)=O(n)
            vector<int> temp;
            if(nums[i+2]-nums[i]<=k){
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else return {};
        }
        return ans;
    }
};
/*
Why This Is Greedy:
You sort the array first — this ensures that closest numbers are grouped together.
Then you greedily pick every group of 3 consecutive numbers (after sorting) and check if the difference between the largest and smallest is within k.
You don't backtrack, nor do you try all combinations. You simply take the smallest unused elements and form the next valid group as early as possible.
🧠 Greedy Choice Property
You assume:
"If I pick the next 3 closest numbers (after sorting), and they satisfy the condition, this choice is safe and optimal."
And that’s the core of greedy — locally optimal → globally correct.
*/
//Extra pushes, and More temporaries adds up across all iterations — especially with large inputs.
class Solution {//TC=O(nlogn) , SC=O(logn) it goes in sort, not considering SC of 2d vector ans as its asked to return
public://133ms, 144kb
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i+=3){
            vector<int> temp;
            if(nums[i+2]-nums[i]<=k){
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
            }
            else{
                vector<vector<int>> emp;
                return emp;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
