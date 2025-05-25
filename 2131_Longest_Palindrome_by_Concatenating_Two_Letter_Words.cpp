class Solution { TC= O(n) , SC= O(n)
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string,int> um;
        for (auto &s : words) {
            string rev;
            rev.push_back(s[1]);//O(1)
            rev.push_back(s[0]);//O(1)
            if (um[rev] > 0) {
                // Found a matching reverse pair
                um[rev]--;
                ans += 4;
            } else {
                // Store this word for possible pairing
                um[s]++;
            }
        }
        for(auto &v : um){//Case 3 handling(refer Q)
            if(v.first[0]==v.first[1] && v.second==1){//O(1)
                ans+=2;
                break;
            }
        }
        return ans;
    }
};
