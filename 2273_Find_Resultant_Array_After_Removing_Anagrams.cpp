class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {//TC=O(n*m), SC=O(26) - not considering the size of ans array
        vector<int> hsh1(26);
        vector<string> ans;
        for(int i=0;i<words[0].size();++i){
            ++hsh1[words[0][i]-'a'];
        }
        ans.push_back(words[0]);
        int n=words.size();
        for(int i=1;i<n;++i){
            vector<int> hsh2(26);
            for(int j=0;j<words[i].size();++j){
                ++hsh2[words[i][j]-'a'];
            }
            bool check=true;
            for(int k=0;k<26;++k){
                if(hsh1[k]!=hsh2[k]){
                    check=false;
                    break;
                }
            }
            if(!check){
                ans.push_back(words[i]);
                hsh1=hsh2;
            }
        }
        return ans;
    }
};
