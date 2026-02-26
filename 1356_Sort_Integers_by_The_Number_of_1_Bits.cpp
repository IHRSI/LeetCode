//TC=O(nlogn), SC=O(logn)
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int a, int b){
            int x=__builtin_popcount(a);
            int y=__builtin_popcount(b);
            if(x>y) return false;
            else if(x==y) return a<b;
            return true;
        });
        return arr;
    }
};
