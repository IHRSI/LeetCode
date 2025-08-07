//Used Sliding Window
//35 ms , 75mb
class Solution {
public:
    int totalFruit(vector<int>& fruits) {//TC=O(n) , SC=O(1)
        int n=fruits.size();
        int ans=0,left=0;
        unordered_map<int,int> us;
        for(int r=0;r<n;++r){
            ++us[fruits[r]];
            while(us.size()>2){
                --us[fruits[left]];
                if(us[fruits[left]]==0) us.erase(fruits[left]);
                ++left;
            }
            ans=max(ans,r-left+1);
        }
        return ans;
    }
};

//Best efficient
//3ms 70mb
class Solution {
public:
    int totalFruit(vector<int>& fruits) {//TCF=O(n), SC=O(1)
        int n = fruits.size(), left = 0, maxLen = 0;
        int type1 = -1, type2 = -1;
        int count1 = 0, count2 = 0;
        for (int right = 0; right < n; ++right) {
            int fruit = fruits[right];
            if (fruit == type1 || fruit == type2) {
            } 
            else if (type1 == -1 || count1 == 0) {
                type1 = fruit;
                count1 = 0;
            } else if (type2 == -1 || count2 == 0) {
                type2 = fruit;
                count2 = 0;
            } else {
                while (count1 > 0 && count2 > 0) {
                    int f = fruits[left++];
                    if (f == type1) count1--;
                    else if (f == type2) count2--;
                }
                if (count1 == 0) {
                    type1 = fruit;
                    count1 = 0;
                } else {
                    type2 = fruit;
                    count2 = 0;
                }
            }
            if (fruit == type1) ++count1;
            else if (fruit == type2) ++count2;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

//Used vector improves TC and degrades SC
//18ms 111.5mb
class Solution {
public:
    int totalFruit(vector<int>& fruits) {//TC=O(n) , SC=O(10^5)
        const int MAX_TYPE = 1e5 + 1;
        vector<int> count(MAX_TYPE, 0);
        int distinct = 0, left = 0, maxLen = 0;
        for (int right = 0; right < fruits.size(); ++right) {
            if (count[fruits[right]]++ == 0)
                ++distinct;
            while (distinct > 2) {
                if (--count[fruits[left]] == 0)
                    --distinct;
                ++left;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
