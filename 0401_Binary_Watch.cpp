class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {//TC=O(720)~O(1), SC=O(1)
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

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {//TC=O(1024)~O(1), SC=O(1)
        vector<string> ans;
        for (int i = 0; i < 1024; ++i) {
            int h = i >> 6, m = i & 63;
            if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return ans;
    }
};
