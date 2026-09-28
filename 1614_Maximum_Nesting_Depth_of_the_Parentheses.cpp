class Solution {
public:
    int maxDepth(string s) {//TC=O(n), SC=O(1)
        int ct=0;//This does the work of stack
        int ans=0;
        for(char c: s){
            if(c=='(') ++ct;
            else if(c==')'){
                ans=max(ans,ct);
                if(ct>0) --ct;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxDepth(string s) {//TC=O(n), SC=O(n)
        stack<char> st;
        int ans=0;
        for(char c: s){
            if(c=='(') st.push(c);
            else if(c==')'){
                ans=max(ans,(int)st.size());
                if(!st.empty()) st.pop();
            }
        }
        return ans;
    }
};
