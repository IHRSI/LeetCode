class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {//TC=O(qdn), SC=O(1)
        vector<string> ans;
        int n=queries[0].size();
        for(auto q: queries){
            for(auto d: dictionary){
                int diff=0;
                for(int i=0;i<n;++i){
                    if(q[i]!=d[i]){ 
                        ++diff;
                        if(diff>2) break;
                    }
                }
                if(diff<=2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};
