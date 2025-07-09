//Prefix Sum approach is confusing here therefore used purely sliding window. Means i tried to sue SW on PS array and it was not working.
//greedy here id that always shifthing K meething we get the max free time not less than K.
class Solution {//TC=O(n) , SC=O(n)
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gaps(n+1,0);
        gaps[0]=startTime[0];
        for(int i=1;i<n;++i){
            gaps[i]=startTime[i]-endTime[i-1];
        }
        gaps[n]=eventTime-endTime[n-1];
        int ans=0;
        int i=0,j=0;
        int slid_sum=0;
        while(j<n+1){
            slid_sum+=gaps[j];
            if(j-i+1>k+1){
                slid_sum-=gaps[i];
                ++i;
            }
            ans=max(ans,slid_sum);
            ++j;
        }
        return ans;
    }
};
