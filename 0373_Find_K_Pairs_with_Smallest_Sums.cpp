//TLE - Max Heap
class Solution {//Brute force and Optimised Brute Force
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {//TC=O(n*m*logk), SC=O(k)
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int a: nums1){
            for(int b: nums2){
                pq.emplace(a+b,make_pair(a,b));
                if(pq.size()>k) pq.pop();
                /*This exploits the sorted vectors info, and is an enhancement, This code runs but is not efficient, has the same worse case TC
                if(pq.size()<k) pq.emplace(a+b,make_pair(a,b));
                else if(a+b<pq.top().first){
                    pq.pop();
                    pq.emplace(a+b,make_pair(a,b));
                }
                else break;
                */
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [sum,p]=pq.top();
            pq.pop();
            ans.push_back({p.first,p.second});
        }
        return ans;
    }
};
