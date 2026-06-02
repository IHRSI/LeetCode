class Solution {//TC=O(2*(n+m))~O(n+m), SC=O(1)
public:
    int solve(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2){
        int finish1=INT_MAX;
        int n=s1.size();
        for(int i=0;i<n;++i){
            finish1=min(finish1,s1[i]+d1[i]);
        }
        int finish2=INT_MAX;
        int m=s2.size();
        for(int j=0;j<m;++j){
            finish2=min(finish2,max(finish1,s2[j])+d2[j]);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landwater=solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int waterland=solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(landwater,waterland);
    }
};

class Solution {//TC=O(n*m), SC=O(1)
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;++i){
            int landtime=landStartTime[i]+landDuration[i];
            for(int j=0;j<m;++j){
                int landwater=max(landtime,waterStartTime[j]);
                ans=min(ans,landwater+waterDuration[j]);

                int watertime=waterStartTime[j]+waterDuration[j];
                int waterland=max(watertime,landStartTime[i]);
                ans=min(ans,waterland+landDuration[i]);
            }
        }
        return ans;
    }
};
