//Sorting using comparator
//number line dry run for deducing that the last remain interval only matters for checking with the present interval
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {//TC=O(nlogn+n)~O(nlogn), SC=O(logn)
        auto comp=[](vector<int> &v1, vector<int> &v2){
            if(v1[0]==v2[0]){
                return v1[1]>v2[1];
            }
            return v1[0]<v2[0];

        };
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int last_interval_end=intervals[0][1];
        int remain_ct=1;
        for(int i=1;i<n;++i){
            if(last_interval_end<intervals[i][1]){
                ++remain_ct;
                last_interval_end=intervals[i][1];
            }
        }
        return remain_ct;
    }
};

//Brute Force
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {//TC=O(n^2), SC=O(1)
        int n=intervals.size();
        int remain=n;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i!=j){
                    int a=intervals[i][0],b=intervals[i][1];
                    int c=intervals[j][0],d=intervals[j][1];
                    if(c<=a && b<=d){
                        --remain;
                        break;
                    }
                }
            }
        }
        return remain;
    }
};
