class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {//TC=O(n1logn1 + n2logn2+n2) , SC=O(logn1+logn2) Worst case - during sorting dur to recursion stack
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int n1=players.size();
        int ans=0;
        int n2=trainers.size();
        int i=0,j=0;
        while(i<n1 && j<n2){//O(n2)
            if(players[i]<=trainers[j]){
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
