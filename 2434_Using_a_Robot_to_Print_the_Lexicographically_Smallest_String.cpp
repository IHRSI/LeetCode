class Solution {// TC=O(n+26) , SC=O(n+n)=O(n)
public:
    string robotWithString(string s) {
        unordered_map<char,int> um;
        string ans="";
        stack<char> st;
        for(char c : s){
            um[c]++;
        }
        char minchar='a';
        for(char c : s){
            st.push(c);
            um[c]--;
            while(minchar<='z' && um[minchar]==0) minchar++;//good logic
            while(!st.empty() && st.top()<=minchar){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};
