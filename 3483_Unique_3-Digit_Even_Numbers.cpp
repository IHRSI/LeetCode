//Efficient
class Solution {
public:
    int totalNumbers(vector<int>& digits) {//TC=O(900)~O(1), SC=O(1)
        int ans=0;
        int arr[10]={0};
        for(int e: digits) ++arr[e];
        for(int i=1;i<=9;++i){
            if(arr[i]==0) continue;
            --arr[i];
            for(int j=0;j<=9;++j){
                if(arr[j]==0) continue;
                --arr[j];
                for(int k=0;k<=9;k+=2){
                    if(arr[k]==0) continue;
                    ++ans;
                }
                ++arr[j];
            }
            ++arr[i];
        }
        return ans;
    }
};
