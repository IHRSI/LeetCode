class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {//TC=O(nm), SC=O(1)
        int n1=arr1.size(),n2=arr2.size(),ans=0;
        for(int i=0;i<n1;++i){
            bool check=1;
            for(int j=0;j<n2;++j){
                if(abs(arr1[i]-arr2[j])<=d){
                    check=0;
                    break;
                }
            }
            if(check) ++ans;
        }
        return ans;
    }
};

//Optimised approach uses lower bound and TC is (n+m)logm.
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {//TC=O((n+m)logm), SC=O(logm)
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (auto& x : arr1) {
            int p =lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            bool ok = true;
            if (p < arr2.size()) {
                ok &= (arr2[p] - x > d);
            }
            if (p - 1 >= 0) {
                ok &= (x - arr2[p - 1] > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};
