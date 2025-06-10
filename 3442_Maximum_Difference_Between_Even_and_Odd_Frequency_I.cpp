class Solution {//TC=O(n) , SC=O(26)=O(1)
public:
    int maxDifference(string s) {
        int even=INT_MAX;
        int odd=INT_MIN;
        vector<int> freq(26,0);
        for(char c: s){
            freq[c-'a']++;
        }
        for(int i:freq){
            if(i==0) continue;
            if(i%2==0) even=min(even,i);
            else odd=max(odd,i);
        }
        return odd-even;
    }
};
