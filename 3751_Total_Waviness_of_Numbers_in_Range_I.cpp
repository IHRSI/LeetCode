class Solution {
public:
    int totalWaviness(int num1, int num2) {//TC=O((num2-num1)log(num))~O(num2lognum2), SC=O(1)
        int wavy_ct=0;
        for(int i=num1;i<=num2;++i){
            string s=to_string(i);
            if(s.size()>2){
                for(int j=1;j<s.size()-1;++j){
                    if((s[j]>s[j-1] && s[j]>s[j+1]) || (s[j]<s[j-1] && s[j]<s[j+1])) ++wavy_ct;
                }
            }
        }
        return wavy_ct;
    }
};
