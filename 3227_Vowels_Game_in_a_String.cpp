class Solution {
public:
    bool doesAliceWin(string s) {//TC=O(n), SC=O(1)
        return any_of(s.begin(),s.end(),[](char c){
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
            //return (0x104111 >> (c - 97)) & 1;//Better soln (faster), Used bitmask of letters of alphabet
        });
    }
};
