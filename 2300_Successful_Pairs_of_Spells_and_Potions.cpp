class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {//TC=O(nlogm+mlogm) , SC=O(1)
        int n=spells.size();
        int m=potions.size();
        vector<int> ans(n);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;++i){
            int val=spells[i];
            int l=0,r=m-1;
            while(l<=r){
                int mid=l+((r-l)>>1);
                if(val*1.0*potions[mid]>=success) r=mid-1;
                else l=mid+1;
            }
            ans[i]=m-l;
        }
        return ans;
    }
};
