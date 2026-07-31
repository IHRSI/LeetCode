class Solution {
public:
    int minimumPushes(string word) {//TC=O(n), SC=O(1)
        int arr[26]={0};
        for(char c: word) ++arr[c-'a'];
        sort(arr,arr+26,greater<int>());
        int ans=0;
        for(int i=0;i<26;++i){
            if(arr[i]==0) break;
            ans+=arr[i]*(i/8+1);
        }
        return ans;
    }
};
