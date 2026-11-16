class Solution {
public:
    string digitSum(string s, int k) {//TC=O(nlog(k)n) - base k, SC=O(n)
        while(s.size()>k){
            string temp="";
            int n=s.size();
            for(int i=0;i<n;i+=k){
                int val=0;
                for(int j=i;j<min(n,i+k);++j) val+=s[j]-'0';
                temp+=to_string(val);
            }
            s=temp;
        }
        return s;
    }
};
