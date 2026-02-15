class Solution {
public:
    string addBinary(string a, string b) {//TC=O(m+m)~O(max(n,m)), SC=O(max(n,m))
        int cry=0,sum=0;
        int i=a.size()-1,j=b.size()-1;
        string ans="";
        while(i>=0 || j>=0){
            sum=cry;
            if(i>=0){
                sum+=a[i]-'0';
                --i;
            }
            if(j>=0){
                sum+=b[j]-'0';
                --j;
            }
            ans.push_back(sum%2==0?'0':'1');
            cry=sum>1?1:0;
        }
        if(cry!=0) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
