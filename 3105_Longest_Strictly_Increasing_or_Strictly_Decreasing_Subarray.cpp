//Optimal
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {//TC=O(n), SC=O(1)
        int incLength = 1, decLength = 1;
        int maxLength = 1;
        for (int pos = 0; pos < nums.size() - 1; pos++) {
            if (nums[pos + 1] > nums[pos]) {
                incLength++;
                decLength = 1;
            } else if (nums[pos + 1] < nums[pos]) {
                decLength++;
                incLength = 1;
            } else {
                incLength = 1;
                decLength = 1;
            }
            maxLength = max({maxLength,incLength, decLength});
        }
        return maxLength;
    }
};

//Brute Force
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {//TC=O(n^2), SC=O(1)
        int maxLength = 0;
        for (int start = 0; start < nums.size(); start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.size(); pos++) {
                if (nums[pos] > nums[pos - 1]) {
                    currLength++;
                } else {
                    break;
                }
            }
            maxLength = max(maxLength, currLength);
        }
        for (int start = 0; start < nums.size(); start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.size(); pos++) {
                if (nums[pos] < nums[pos - 1]) {
                    currLength++;
                } else {
                    break;
                }
            }
            maxLength = max(maxLength, currLength);
        }
        return maxLength;
    }
};
