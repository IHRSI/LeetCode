class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {//TC=O(3n+nlogn)~O(nlogn), SC=O(2n+logn)~O(n)
        if(arr.empty()) return {};
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(),sortedArr.end());
        int n=arr.size();
        unordered_map<int,int> um;
        int rank=1;
        um[sortedArr[0]]=1;
        for(int i=1;i<n;++i){
            if(sortedArr[i]>sortedArr[i-1]) ++rank;
            um[sortedArr[i]]=rank;
        }
        for(int  i=0;i<n;++i){
            arr[i]=um[arr[i]];//arr now contains the ranks
        }
        return arr;
    }
};

//This approach uses set and hence as 2x time taken and more space.(Though it seems it is efficient than above in complexity)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {//TC=O(nlogn+2n)~O(nlogn), SC=O(2n)
        if(arr.empty()) return {};
        set<int> nums(arr.begin(),arr.end());
        unordered_map<int,int> numToRank;
        int rank=1;
        for(auto num: nums){
            numToRank[num]=rank;
            ++rank;
        }
        int n=arr.size();
        for(int  i=0;i<n;++i){
            arr[i]=numToRank[arr[i]];
        }
        return arr;
    }
};

//This approach seems small and better in tc ans sc but has more time and space taken fron the 2nd approach also.
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {//TC=O(nlogn+n)~O(nlogn), SC=O(n)
        map<int,vector<int>> numToIdx;
        int n=arr.size();
        for(int  i=0;i<n;++i){
            numToIdx[arr[i]].push_back(i);
        }
        int rank=1;
        for(auto &[num,idx]: numToIdx){
            for(auto i:idx) arr[i]=rank;
            ++rank;
        }
        return arr;
    }
};
