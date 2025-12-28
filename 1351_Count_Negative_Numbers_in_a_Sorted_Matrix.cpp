//Staircase Method
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {//TC=O(n+m), SC=O(1)
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        int i=n-1,j=0;
        while(i>=0 && j <m){
            if(grid[i][j]<0){
                ans+=m-j;
                --i;
            }
            else ++j;
        }
        return ans;
    }
};

//Binary Search
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {//TC=O(nlogm), SC=O(1)
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;++i){
            int low=0,high=m-1,mid;
            while(low<=high){
                mid=low+(high-low)/2;
                if(grid[i][mid]>=0) low=mid+1;
                else high=mid-1;
            }
            ans+=m-low;
        }
        return ans;
    }
};

//BS using UB with comparator
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {//TC=O(nlogm), SC=O(1)
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(auto &vec: grid){
            auto it=upper_bound(vec.begin(),vec.end(),0,greater<int>());
            ans+=vec.end()-it;
        }
        return ans;
    }
};

//Brute Force
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {//TC=O(n^2), SC=O(1)
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]<0) ++ans;
            }
        }
        return ans;
    }
};
