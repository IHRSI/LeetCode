class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {//TC=O(n), SC=O(1)
        if(rows==1) return encodedText;
        int n=encodedText.size();
        int col=n/rows;
        string ans="";
        for(int c=0;c<col;++c){
            for(int j=c;j<n;j+=(col+1)){
                ans+=encodedText[j];
            }
        }
        while(!ans.empty() && ans.back()==' ') ans.pop_back();
        return ans;
    }
};

//Using Martix
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {//TC=O(2n)~O(n), SC=O(n)
        int r=rows;
        int n=encodedText.size();
        int c=n/r;
        vector<vector<char>> v(r,vector<char>(c));
        int k=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                v[i][j]=encodedText[k];
                ++k;
            }
        }
        string ans="";
        for(int col=0;col<c;++col){
            int i=0,j=col;
            while(i<r && j<c){
                ans+=v[i][j];
                ++i;
                ++j;
            }
        }
        while(!ans.empty() && ans.back()==' ') ans.pop_back();
        return ans;
    }
};
