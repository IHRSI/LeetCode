class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {//TC=O(n) , SC=O(101)
        int ans=0;
        int arr[101]={0};
        int maxfreq=0;
        for(int e: nums){
            ++arr[e];
            if(arr[e]>maxfreq) maxfreq=arr[e];
        }
        for(int i=1;i<101;++i){
            if(arr[i]==maxfreq) ans+=maxfreq;
        }
        return ans;
    }
};
