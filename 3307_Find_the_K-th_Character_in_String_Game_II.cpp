//Upgrade of Q 3304
//Backtrack thinking from kth postion to 1st position.
//Like if we want char at 10th place we backtrack to 2th pos then from 2nd to 1st.
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {//TC=O(logK) , SC=O(1) , TC dosnt depend on operations size
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if ((1ll << t) == k) {
                t--;
            }
            k = k - (1ll << t);
            if (operations[t]) {
                ans++;
            }
        }
        return 'a' + (ans % 26);
    }
};

//3304 builtin_popcount method logic used - this is easy than above but up one is also good for understanding
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {//TC=O(logK) , SC=O(1) , TC dosnt depend on operations size
        int ans=0,ct=0;//ct stores the current opteration number happening
        k--;
        while(k>0){
            if(k&1){
                if(operations[ct]) ++ans; 
            }
            ++ct;
            k>>=1;
        }
        return 'a'+(ans%26);
    }
};

//Alternative way of the above code - used for instead of while
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        k--;
        for (int i = __lg(k); i >= 0; i--) {
            if (k >> i & 1) {
                ans += operations[i];
            }
        }
        return 'a' + (ans % 26);
    }
};

//Approach - Recursion
//T.C : O(log(k))
//S.C : O(log(k))) of system stack
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // Base case: If k is 1, the result is the initial character 'a'
        if (k == 1) {
            return 'a';
        }
        int n = operations.size();  // Size of the operations array
        int opType;                 // Store the operation type (0 or 1)
        long long len = 1;          // Start with length 1 (initial 'a')
        long long newK;             // To store the adjusted k value
        // Traverse through the operations array to determine the operation type
        for (int i = 0; i < n; i++) {
            len *= 2;               // Double the length at each step
            if (len >= k) {         // If the current length surpasses or equals k
                opType = operations[i];  // Get the current operation type
                newK = k - len / 2;      // Adjust k for the next recursive call
                break;                   // Break as we have found the required operation
            }
        }
        // Recursively find the character before the operation is applied
        char res = kthCharacter(newK, operations);
        // If operation type is 0, return the character as is
        if (opType == 0) 
            return res;
        // If operation type is 1, transform the character ('a' becomes 'b', etc.)
        if (res == 'z') 
            return 'a';  // Handle wrap-around from 'z' to 'a'
        return res + 1;   // Increment character by 1
    }
};
