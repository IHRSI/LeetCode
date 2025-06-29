//subsequen Q - sorted first to get k large elements then sorted them according to index to get correct subsequence ordering
class Solution {//This is also good
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {//TC=O(nlogn) , SC=O(n)
        vector<pair<int,int>> val_idx;//O(n) - used vec pair to stopre index with value
        int n=nums.size();
        for(int i=0;i<n;++i){
            val_idx.push_back({nums[i],i});
        }
        sort(val_idx.begin(),val_idx.end(),[](auto a,auto b){return a.first>b.first;});//O(nlogn) to sort desc by value
        sort(val_idx.begin(),val_idx.begin()+k,[](auto a,auto b){return a.second<b.second;});//O(klogk) to sort asc by index upto k
        vector<int> ans;
        for(int i=0;i<k;++i){//O(k)
            ans.push_back(val_idx[i].first);
        }
        return ans;
    }
};

//Improving TC usinf MinHeap to O(nlogk) and SC to O(k)
class Solution { //Best efficient
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {//TC=O(nlogk) , SC=O(k)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//O(k)
        int n = nums.size();
        for(int i=0;i<n;i++){//O(nlogk)
            pq.push({nums[i],i});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){//O(k)
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++){//O(k)
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};
