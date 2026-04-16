class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {//TC=O(n*L), SC=O(1)
        int n=words.size();
        int ans=n;
        for(int i=0;i<n;++i){
            if(words[i]==target){
                int dist=abs(i-startIndex);
                ans=min(ans,min(dist,n-dist));
            }
        }
        return ans!=n?ans:-1;
    }
};
