//We must dry the lake that will rain next earliest, otherwise it’ll flood.
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {//TC=O(nlogn), SC=O(n)
        int n=rains.size();
        vector<int> ans(n,1);
        unordered_map<int,int> fullake;
        set<int> norainday;
        for(int i=0;i<n;++i){
            int lake=rains[i];
            if(lake==0) norainday.insert(i);
            else{
                ans[i]=-1;
                if(fullake.find(lake)!=fullake.end()){
                    int lastrain=fullake[lake];
                    auto it = norainday.upper_bound(lastrain);//Greedy logic-BS
                    if(it==norainday.end()) return {};
                    ans[*it]=lake;
                    norainday.erase(it);
                }
                fullake[lake]=i;
            }
        }
        return ans;
    }
};
