class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {//TC=O(n+mlogm), SC=O(logm)
        int tot_app=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end());
        int min_box_req=0;
        int app_ct=0;
        int n=capacity.size();
        for(int i=n-1;i>=0;--i){
            app_ct+=capacity[i];
            ++min_box_req;
            if(app_ct>=tot_app) return min_box_req;
        }
        return 0;
    }
};
//To minimize the number of boxes, always use boxes with larger capacity first (greedy).
