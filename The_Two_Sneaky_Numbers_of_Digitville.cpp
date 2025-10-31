class Solution {//Hashimg
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {//TC=O(n), SC=O(n)
        int n=nums.size();
        vector<int> hsh(n-2);
        vector<int> ans;
        for(int e: nums){
            ++hsh[e];
            if(hsh[e]==2) ans.push_back(e);
        }
        return ans;
    }
};

class Solution {//Maths
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n = (int)nums.size() - 2;
        int sum = 0, squaredSum = 0;
        for (int x : nums) {
            sum += x;
            squaredSum += x * x;
        }
        int sum2 = sum - n * (n - 1) / 2;
        int squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6;
        int x1 = (sum2 - sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
        int x2 = (sum2 + sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
        return {x1, x2};
    }
};
