class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501]={0};
        int n=arr.size();
        for(int i=0;i<n;++i) ++freq[arr[i]];
        for(int i=500;i>0;--i) if(i==freq[i]) return i;
        return -1;
    }
};
