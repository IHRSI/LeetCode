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
