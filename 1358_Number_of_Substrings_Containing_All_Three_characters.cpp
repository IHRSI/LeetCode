//Sliding Window
class Solution {
public:
    int numberOfSubstrings(string s) {//TC=O(2n)~O(n), SC=O(1)
        int ans=0,n=s.size();
        int abc[3]={0};
        int l=0,r=0;
        while(r<n){
            ++abc[s[r]-'a'];
            while(abc[0]>0 && abc[1]>0 && abc[2]>0){
                ans+=n-r;
                --abc[s[l]-'a'];
                ++l;
            }
            ++r;
        }
        return ans;
    }
};

//Last Position Tracking
class Solution {
public:
    int numberOfSubstrings(string s) {//TC=O(n), SC=O(1)
        int len = s.length();
        // Track last position of a, b, c
        vector<int> lastPos = {-1, -1, -1};
        int total = 0;

        for (int pos = 0; pos < len; pos++) {
            // Update last position of current character
            lastPos[s[pos] - 'a'] = pos;

            // Add count of valid substrings ending at current position
            // If any character is missing, min will be -1
            // Else min gives leftmost required character position
            total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }

        return total;
    }
};
