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

//Using Priority Queue
//Using a min-heap to decide the next lake that must be dried — the one that rains soonest next.
/*Approach
Preprocess to know for each lake the list of upcoming rain days.
While traversing:
If rains[i] > 0, mark lake as full, remove its current day from its list, and push its next rain day (if any) to heap.
If rains[i] == 0, pop from heap → dry that lake.
If heap empty → dry any lake.

Complexity
Time: O(n log n)
Space: O(n)
*/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, queue<int>> future;  // lake -> next rain days
        unordered_set<int> full;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for (int i = 0; i < n; ++i)
            future[rains[i]].push(i);

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                future[lake].pop();
                ans[i] = -1;
                if (full.count(lake)) return {};
                full.insert(lake);
                if (!future[lake].empty())
                    pq.push({future[lake].front(), lake});
            } else {
                if (!pq.empty()) {
                    auto [nextRain, lake] = pq.top();
                    pq.pop();
                    ans[i] = lake;
                    full.erase(lake);
                }
            }
        }
        return ans;
    }
};
