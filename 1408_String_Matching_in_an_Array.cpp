class Solution {// TC-O(n^2 * m^2) , SC=O(n) , brute force
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};
