//Just focus on greedy soln. not others they were just for learning.

//Subsequence - maintai order , Choosing a subsequence from the string is equivalent to deleting all the other chars/not considerig it in subsequence.
//Memoization is a programming technique where the results of expensive function calls are stored (or cached) so that when the same inputs occur again,
//the pre-calculated result can be returned without re-executing the function

//Greedy + Bit Simulation (Right to Left)
/*Why the condition if (pow2 <= k) is added:
This is an optimization and a safety check.
Reason:
When pow2 becomes larger than k, there's no point in increasing it further because:
Even the smallest possible remaining '1' (with that pow2) would exceed k (since adding pow2 to val would automatically go beyond k).
Continuing to double pow2 after it exceeds k is useless and could cause overflow in some cases.
*/
class Solution {
public:
    int longestSubsequence(string s, int k) { //TC=O(n) , SC=O(1)
        if(s=="") return 1;
        int ans=0;
        int val=0;
        long long pow2=1;
        int n=s.size();
        for(int i=n-1;i>=0;--i){
            if(s[i]=='0') ++ans;//Greedy - taking all zeros
            else{
                if(val+pow2<=k){
                    ++ans;
                    val+=pow2;
                }
            }
            if (pow2 <= k) pow2 <<= 1;
        }
        return ans;
    }
};

/*for (int i = n - 1; i >= 0; --i) {Alternative way to write
            if (s[i] == '0') {
                cnt++;
            } else {
                if (power < 32 && (val + (1LL << power)) <= k) {
                    val += (1LL << power);
                    cnt++;
                }
            }
            power++;
        }
*/

//Brute force approach could be take the bit or not take using recursion(func(s,k-val,i-1)) traversing from right to left. Don't thing of its code its of no need.
class Solution {//TC=O(2^n) TLE SC=O(1)
public:
    int solve(int idx, int sum, string &s, int k) {
        int l = s.length();
        if(idx < 0) return 0;
        int take = 0, dontTake = 0;
        if(sum + (s[idx]-'0') * pow(2, l-idx-1) <= k) {
            take = 1 + solve(idx - 1, sum + (s[idx]-'0') * pow(2, l - idx - 1), s, k);
        }
        dontTake = solve(idx - 1, sum, s, k);
        return max(take, dontTake);
    }
    int longestSubsequence(string s, int k) {
        return solve(s.length()-1, 0, s, k);
    }
};

//Good learning from this
//Recursion + Memoization (not efficient for this Q) - Takes space to reduce TC from 2^n to n^2 of recursive method.
class Solution {//MEMOIZED (TOP DOWN DP) - O(n^2)
public:
    int solve(int idx, int len, int sum, string &s, int k, vector<vector<int>> &memo) {
        int l = s.length();
        if(idx < 0) return 0;
        if(memo[idx][len] != -1) return memo[idx][len]; //considering index+sum as sum can vary at each index due to take and dont take
        int take = 0, dontTake = 0;
        if(sum + (s[idx]-'0') * pow(2, l-idx-1) <= k) {
            take = 1 + solve(idx - 1, len + 1, sum + (s[idx]-'0') * pow(2, l - idx - 1), s, k, memo);
        }
        dontTake = solve(idx - 1, len, sum, s, k, memo);
        return memo[idx][len] = max(take, dontTake);
    }
    int longestSubsequence(string s, int k) {
        vector<vector<int>> memo(s.length() + 1, vector<int>(s.length() + 1, -1));
        return solve(s.length()-1, 0, 0, s, k, memo);
    }
};

//Reduced memo to 1d as max value of digits considered is only needed to be considered.
class Solution {
public:
    int solve(int idx, int sum, string &s, int k, vector<int> &memo) {//TC=nlogk(said by leetcode) , SC=O(n)
        int l = s.length();
        if(idx < 0) return 0;
        if(memo[idx] != -1) return memo[idx];//considering only index as max gives the max sum
        int take = 0, dontTake = 0;
        if(sum + (s[idx]-'0') * pow(2, l-idx-1) <= k) {
            take = 1 + solve(idx - 1, sum + (s[idx]-'0') * pow(2, l - idx - 1), s, k, memo);
        }
        dontTake = solve(idx - 1, sum, s, k, memo);
        return memo[idx] = max(take, dontTake);
    }
    int longestSubsequence(string s, int k) {
        vector<int> memo(s.length() + 1, -1);
        return solve(s.length()-1, 0, s, k, memo);
    }
};
