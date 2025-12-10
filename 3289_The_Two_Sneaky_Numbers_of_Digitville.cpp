//XOR Technique : Separating into two groups on the basis of diffrent bit which acts as bit separator
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {//TC=O(4n), SC=O(1)
        int n = (int)nums.size() - 2;
        int y = 0;
        for (int x : nums) {
            y ^= x;
        }
        for (int i = 0; i < n; i++) {
            y ^= i;
        }
        int bitno =__builtin_ctz(y) ;//Bit separator
        int x1 = 0, x2 = 0;
        for (int x : nums) {
            if (x & (1<<bitno)) {
                x1 ^= x;
            } else {
                x2 ^= x;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i & (1<<bitno)) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        return {x1, x2};
    }
};

//Hashing
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();//TC=O(n), SC=O(n)
        vector<int> hsh(n-2);
        vector<int> ans;
        for(int e: nums){
            ++hsh[e];
            if(hsh[e]==2) ans.push_back(e);
        }
        return ans;
    }
};

//Maths: By solving 2 equations
class Solution {
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
