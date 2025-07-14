//Same as 2410
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {//TC=O(n1logn1 + n2logn2+n2) , SC=O(logn1+logn2) Worst case - during sorting dur to recursion stack
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n1=g.size();
        int ans=0;
        int n2=s.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(g[i]<=s[j]){
                ++ans;
                ++i;
                ++j;
            }
            else ++j;
          /*Simplified
            if(players[i]<=trainers[j]){
                ++ans;
                ++i;
            }
            ++j; */
        }
        return ans;
    }
};
