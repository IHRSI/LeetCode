//LC 316 has the same soln
//Solved this Q from dry run and logic the code came out to be implementation of monotonic stack style
//Maintain a lexicographically increasing stack; if a smaller character arrives and the stack's top appears again later, pop it so the smaller character can come earlier.
class Solution {
public:
    string smallestSubsequence(string s) {//TC=O(2n)~O(n), SC=O(56)~O(1)
        int n=s.size();
        string ans="";//The string acts as stack
        int lastidx[26];
        bool taken[26]={0};
        for(int i=0;i<n;++i){
            lastidx[s[i]-'a']=i;
        }
        for(int i=0;i<n;++i){
            char ch=s[i];
            if(taken[ch-'a']) continue;
            while(!ans.empty() && ans.back()>ch && lastidx[ans.back()-'a']>i){
                taken[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(ch);
            taken[ch-'a']=1;
        }
        return ans;
    }
};

//Using stack - but the upper soln is better , both are similar soln
class Solution {
public:
    string smallestSubsequence(string s) {//TC=O(24n)~O(n), SC=O(56+n)~O(n)
        int n = s.length();
        stack<char> st;
        bool taken[26]={0};
        int lastIndex[26];
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            lastIndex[ch-'a'] = i;
        }
        for(int i = 0; i < n; i++) {   
            int idx = s[i] - 'a';
            if(taken[idx] == true) continue;
            while(!st.empty()  && s[i] < st.top() && lastIndex[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            taken[idx] = true;
        }
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(begin(result), end(result));
        return result;
    }
};
