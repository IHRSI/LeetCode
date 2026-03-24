//TC=O((m−k)×(n−k)×(k^2+k^2logk+k^2))~O((m−k)×(n−k)×k^2logk) SC=O(k^2)
class Solution {//Highly Efficient
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1));
        vector<int> sub;
        for(int i=0;i<n-k+1;++i){
            for(int j=0;j<m-k+1;++j){
                sub.clear();
                for(int p=i;p<=i+k-1;++p){
                    for(int q=j;q<=j+k-1;++q){
                        sub.push_back(grid[p][q]);
                    }
                }
                sort(sub.begin(),sub.end());
                int minabsdiff=INT_MAX;
                for(int h=1;h<sub.size();++h){
                    if(sub[h]!=sub[h-1]) minabsdiff=min(minabsdiff,abs(sub[h]-sub[h-1]));;
                }
                if(minabsdiff!=INT_MAX) ans[i][j]=minabsdiff;
            }
        }
        return ans;
    }
};

class Solution {//TC=O((m−k)×(n−k)×k^2×logk) SC=O(k^2)
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {// Using set - distinct mentioned
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<n-k+1;++i){
            for(int j=0;j<m-k+1;++j){
                set<int> sub;
                for(int p=i;p<=i+k-1;++p){
                    for(int q=j;q<=j+k-1;++q){
                        sub.insert(grid[p][q]);
                    }
                }
                int minabsdiff=INT_MAX;
                auto prev=sub.begin();
                for(auto itr=next(sub.begin());itr!=sub.end();++itr){
                    minabsdiff=min(minabsdiff,abs(*itr-*prev));
                    prev=itr;
                }
                if(minabsdiff!=INT_MAX) ans[i][j]=minabsdiff;
            }
        }
        return ans;
    }
};
