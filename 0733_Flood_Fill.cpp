class Solution {
public:
    void dfs(vector<vector<int>>& mat, int i, int j, int color,int orig){//TC=O(n*m), SC=O(n*m), n*m is the no of pixel, SC and TC comes from the depth of the recursion call in the worst case
        int r=mat.size();
        int c=mat[0].size();
        if(i<0 || j<0 || i>r-1 || j>c-1) return;
        if(mat[i][j]!=orig) return;
        mat[i][j]=color;
        dfs(mat,i-1,j,color,orig);
        dfs(mat,i+1,j,color,orig);
        dfs(mat,i,j-1,color,orig);
        dfs(mat,i,j+1,color,orig);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig=image[sr][sc];
        if(color!=orig) dfs(image,sr,sc,color,orig);
        return image;
    }
};
