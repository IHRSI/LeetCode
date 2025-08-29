class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {//TC=O(n), SC=O(1)
        int n=dimensions.size();
        int max_dig_sq=0;
        int ans=0;
        int a,b,temp_sq;
        for(int i=0;i<n;++i){
            a=dimensions[i][0];
            b=dimensions[i][1];
            temp_sq=a*a+b*b;
            if(temp_sq>max_dig_sq){
                max_dig_sq=temp_sq;
                ans=a*b;
            }
            else if(temp_sq==max_dig_sq){
                ans=max(ans,a*b);
            }
        }
        return ans;
    }
};
/*
You compute the diagonal, convert it to an int, and compare.
But sqrt() returns a double.
When you cast it to int, you lose precision, and two rectangles with slightly different diagonals could end up considered equal incorrectly.
eg - [[10,3],[5,9],[8,3]] therefore we compared squared diagonals directly.
*/
