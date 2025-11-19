class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {//TC=O(n), SC=O(1)
        int n=bits.size();
        int i=0;
        while(i<n-1){
            if(bits[i]==1) i+=2;
            else ++i;
        }
        if(i==n-1) return 1;
        return 0;
    }
};
