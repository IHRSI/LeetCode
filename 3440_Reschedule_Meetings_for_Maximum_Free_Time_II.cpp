//Understand by drawing an example to do correct indexing
class Solution {//TC=O(4n)~O(n) , SC=O(3n)~O(n)
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gaps(n+1);
        gaps[0]=startTime[0];//Gaps length calc
        for(int i=1;i<n;++i){
            gaps[i]=startTime[i]-endTime[i-1];
        }
        gaps[n]=eventTime-endTime[n-1];
        vector<int> right(n,0);////Contains the max gap value from right
        vector<int> left(n,0);//Contains the max gap value from left
        for(int i=1;i<n;++i){
            left[i]=max(gaps[i-1],left[i-1]);
        }
        for(int i=n-2;i>=0;--i){
            right[i]=max(gaps[i+2],right[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int meeti=endTime[i]-startTime[i]; 
            if(meeti<=left[i] || meeti<=right[i]){//Case1 - meetings can be fitted in other gaps
                ans=max(ans,gaps[i]+meeti+gaps[i+1]);
            }
            else{//Case2 - meeting cant be fitted in other gaps
                ans=max(ans,gaps[i]+gaps[i+1]);
            }
        }
        return ans;
    }
};
