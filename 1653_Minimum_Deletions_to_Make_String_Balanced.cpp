//Prefix Sum
class Solution {
public:
    int minimumDeletions(string s) {//TC=O(2n)~O(n), SC=O(n)
        int n=s.size();
        vector<int> ct_a(n,0);
        ct_a[n-1]=s[n-1]=='a'?1:0;
        for(int i=n-2;i>=0;--i){
            ct_a[i]=ct_a[i+1];
            if(s[i]=='a') ++ct_a[i];
        }
        int ct_b=0;
        int min_del=INT_MAX;
        for(int i=0;i<n;++i){
            min_del=min(min_del,ct_a[i]+ct_b);
            if(s[i]=='b') ++ct_b;
        }
        //For i=n
        min_del = min(min_del, ct_b);//As ct_a=0 at i=n
        return min_del;
    }
};
