class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {//TC=O(n), SC=O(1)
        int n=digits.size();
        if(digits[n-1]!=9) digits[n-1]+=1;
        else{
            int i=n-1;
            while(i>=0 && digits[i]==9){
                digits[i]=0;
                --i;
            }
            if(i>=0) digits[i]+=1;
            else{
                digits.push_back(1);
                reverse(digits.begin(),digits.end());
            }
        }
        return digits;
    }
};
