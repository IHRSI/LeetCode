//Counting Sort
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {//TC=O(n+m), SC=O(1)
        int sum=accumulate(apple.begin(),apple.end(),0);
        int boxct=0;
        vector<int> ct(51);
        for(int a:capacity) ++ct[a];
        for(int i=50;i>=1;--i){
            if(ct[i]!=0){
                while(ct[i]>0){
                    sum-=i;
                    ++boxct;
                    if(sum<=0) return boxct;
                    ct[i]--;
                }
            }
        }
        return 0;
    }
};

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
