class Solution {//TC-O(n^2) SC-O(n)
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++){
            unordered_set<int> us1,us2;
            for(int j=0; j<n; j++){
                us1.insert(matrix[i][j]);
                us2.insert(matrix[j][i]);
            }
            if(us1.size()!=n) return 0;
            if(us2.size()!=n) return 0;
        }
        return 1;
    }
};
//Better Solution
class Solution {//SC-o(n) but the datatype is boolean therefore takes less space than the above code , TC- O(n^2)
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            vector<bool> s(n,false);
            vector<bool> s2(n,false);
            for(int j=0;j<n;j++){
                if(s[matrix[i][j]-1]==true)return false;
                else s[matrix[i][j]-1]=true;
                if(s2[matrix[j][i]-1]==true)return false;
                else s2[matrix[j][i]-1]=true;
            }
        }
        return true;
    }
};
