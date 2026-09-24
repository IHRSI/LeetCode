class Solution {//Efficient
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {//TC=O(n^2+k1*k2), SC=O(k1+k2+(2n-1)^2)~O(k1+k2+n^2)
        //Worst case, if every cell is 1: k₁ = k₂ = n² → TC = O(n⁴) worst case.
        int n = img1.size();
        vector<pair<int,int>> A, B;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) A.emplace_back(i, j);
                if (img2[i][j] == 1) B.emplace_back(i, j);
            }
        }
        vector<vector<int>> cnt(2 * n-1, vector<int>(2 * n-1, 0));
        int best = 0;
        for (auto& a : A) {
            for (auto& b : B) {
                int dx = b.first - a.first + n-1;
                int dy = b.second - a.second + n-1;
                best = max(best, ++cnt[dx][dy]);
            }
        }
        return best;
    }
};

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {//TC=O(n^2+k^2), SC=O(k^2)
        //Since k ≤ n², worst case is still O(n⁴), but in practice it's much better when the images are sparse. Let k = number of 1s in each image.
        int n = img1.size();
        vector<pair<int,int>> a, b;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(img1[i][j] == 1) a.push_back({i,j});
                if(img2[i][j] == 1) b.push_back({i,j});
            }
        }
        map<pair<int,int>, int> mp;//Not efficient as it user map even with better TC than below approach
        int ans = 0;
        for(auto [x1,y1] : a) {
            for(auto [x2,y2] : b) {
                int dx = x2 - x1;
                int dy = y2 - y1;
                ans = max(ans, ++mp[{dx,dy}]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int ctoverlap(vector<vector<int>>& a, vector<vector<int>>& b, int rowoffset,int coloffset){
        int ct=0,n=a.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int bi=i+rowoffset, bj=j+coloffset;
                if(bi<0 || bi>=n || bj<0 || bj>=n) continue;
                if(a[i][j]==1 && b[bi][bj]==1) ++ct;
            }
        }
        return ct;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {//TC=O(n^4), SC=O(1)
        int ans=0;
        int n=img1.size();
        for(int i=-n+1;i<n;++i){//i=row offset
            for(int j=-n+1;j<n;++j){//j=col offset
                int ct=ctoverlap(img1,img2,i,j);
                ans=max(ans,ct);
            }
        }
        return ans;
    }
};
