class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {//TC=O(n), SC=O(1)
        int ans=0;
        for(string &s: operations){
            if(s[1]=='+') ++ans;
            else --ans;
        }
        return ans;
    }
};

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {//TC=O(n), SC=O(1)
        int ans=0;
        for(string s: operations){
            if(s[0]=='X'){
                if(s[1]=='+') ++ans;
                else --ans;
            }
            else{
                if(s[0]=='+') ++ans;
                else --ans;
            }
        }
        return ans;
    }
};
