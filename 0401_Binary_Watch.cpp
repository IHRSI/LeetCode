class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {//TC=O(720)~O(1), SC=O(720)~O(1) to store the ans - worst case
        vector<string> ans;
        for(int h=0;h<12;++h){
            for(int m=0;m<60;++m){
                if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn){//O(1)
                    ans.push_back(to_string(h)+":"+(m<10?"0":"")+to_string(m));//O(1)
                }
            }
        }
        return ans;
    }
};
