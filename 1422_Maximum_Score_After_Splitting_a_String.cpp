class Solution {//TC=SC=O(n)
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int> a(n+1,0);
        for(int i=n-1; i>=0;i--){
            if(s[i]=='1') a[i]=a[i+1] + 1;
            else a[i]=a[i+1];
        }
        int max1=0;
        int count=0;
        for(int i=0; i<n-1;i++){
            if(s[i]=='0'){
                count+=1;
            }
            max1=max(max1,a[i+1]+count);
        }
        return max1;
    }
};
