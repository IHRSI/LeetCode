class Solution { //TC=O(n*m) improved, SC=0(1)
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
          /*if (words[i].find(x) != string::npos) {
                res.push_back(i);
            } alternative */
            int j=0;
            int k=words[i].length();
            while(j<k){
                if(words[i][j]==x){
                    ans.push_back(i);
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};
