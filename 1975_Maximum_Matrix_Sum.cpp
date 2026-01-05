class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {//TC=O(n*m), SC=O(1)
        long long maxsum=0;
        int ngtvct=0;
        int absminele=INT_MAX;
        for(auto &arr: matrix){
            for(int &ele: arr){
                if(ele<0) ++ngtvct;
                maxsum+=abs(ele);
                absminele=min(absminele,abs(ele));
            }
        }
        if(ngtvct&1) maxsum-=2*absminele;
        return maxsum;
    }
};
