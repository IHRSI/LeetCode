//The number of times the while loop runs in a iteration is bounded by O(loglogM), and under the given constraints, is at most about 4.
class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {//TC=O(n+nlog2logxM)~O(nloglogM), SC=O(n), M is the max val in nums
        unordered_map<ll,int> freq;
        for(int e: nums) ++freq[e];
        int mxlen=0;
        if(freq.count(1)){
             mxlen=(freq[1]&1)?freq[1]:freq[1]-1;
             freq.erase(1);
        }
        for(auto &[x,_]: freq){
            int len=0;
            ll curr=x;
            while(freq.count(curr) && freq[curr]>1){
                len+=2;
                curr*=curr;
            }
            if(freq.count(curr)==1) ++len;
            else --len;
            mxlen=max(mxlen,len);
        }
        return mxlen;
    }
};
