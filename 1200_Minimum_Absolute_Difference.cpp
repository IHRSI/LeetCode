class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {//TC=O(nlogn+2n)~O(nlogn), SC=O(logn)
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;//This is not counted in SC as it's returned as the answer
        int mindiff=INT_MAX;
        int n=arr.size();
        for(int i=0;i<n-1;++i){
            mindiff=min(mindiff,arr[i+1]-arr[i]);
        }
        for(int i=0;i<n-1;++i){
            if(arr[i+1]-arr[i]==mindiff) ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};
