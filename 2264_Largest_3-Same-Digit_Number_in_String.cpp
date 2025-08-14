class Solution {//TC=O(n-2) , SC=O(1)
public:
    string largestGoodInteger(string num) {
        string temp="";
        string ans="";
        int n=num.size();
        for(int i=0;i<n-2;++i){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                temp={num[i],num[i+1],num[i+2]};
                if(temp>ans || ans.empty()) ans=temp;
            }
        }
        return ans;
    }
};
