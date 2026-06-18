//Efficient - Uses logic of Q23 - This implementation looks similar to that of Q23 min heap soln
class Solution {
public:
    typedef tuple<int,int,int> t;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {//TC=O(min(n,k)*log(min(n,k))) + O(k*log(min(n,k))~O(klog(min(n,k))), SC=O(min(n,k))
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> ans;
        priority_queue<t,vector<t>,greater<t>> pq;
        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        while(k-- && !pq.empty()){
            auto [sum,i,j]=pq.top();
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<m){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
            }
        }
        return ans;
    }
};

//This is thinkable
//TLE - Max Heap
class Solution {//Brute force and Optimised Brute Force
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {//TC=O(n*m*logk), SC=O(k)
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int a: nums1){
            for(int b: nums2){
                pq.emplace(a+b,make_pair(a,b));
                if(pq.size()>k) pq.pop();
                //No TLE - enhancement
                /*This exploits the sorted vectors info, and is an enhancement, This code runs but has the same worse case TC.
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

//This is very non intuitive
//Min heap + set
class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {//TC=O(klogk), SC=O(k)
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> ans;
        set<pair<int,int>> visited;
        priority_queue<p,vector<p>,greater<p>> pqmh;
        pqmh.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});
        while(k-- && !pqmh.empty()){
            auto top=pqmh.top();
            pqmh.pop();
            int i=top.second.first;
            int j=top.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<n && visited.find({i+1,j})==visited.end()){
                visited.insert({i+1,j});
                pqmh.push({nums1[i+1]+nums2[j],{i+1,j}});
            }
            if(j+1<m && visited.find({i,j+1})==visited.end()){
                visited.insert({i,j+1});
                pqmh.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};
