// efficient
class Solution { // TC=0(n) , SC=O(1)
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int max1 = 0, temp = 0;
        unordered_set<char> us;
        int l = 0, r = 0;
        while (r < n) {
            if (us.find(s[r]) != us.end()) {
                while (s[l] != s[r]) {
                    us.erase(s[l]);
                    l++;
                    temp--;
                }
                l++;
            } else {
                us.insert(s[r]);
                temp++;
                max1 = max(max1, temp);
            }
            r++;
        }
        return max1;
    }
};
