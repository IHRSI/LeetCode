class Solution {
public:
    int countOdds(int low, int high) {//TC=O(1), SC=O(1)
        if((low&1)==0) ++low;
        if((high&1)==0) --high;
        return ((high-low)>>1)+1;
    }
};

class Solution {
public:
    int countOdds(int low, int high) {//TC=O(n/2), SC=O(1)
        int ans=0;
        while(low<=high){
            if(low&1){
                ++ans;
                low+=2;
            }
            else ++low;
        }
        return ans;
    }
};
