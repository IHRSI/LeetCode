//Count Sort
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {//TC=O(2n)~O(n), SC=O(n)
        int n=arr.size();
        vector<int> count(n+1);
        for(int e: arr){
            if(e>=n) ++count[n];
            else ++count[e];
            // or ++count[min(e,n)];
        }
        int ans=1;
        for(int i=2;i<=n;++i){
            ans=min(ans+count[i],i);
        }
        return ans;
    }
};

//Sorting - intuitive
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {//TC=O(nlogn+n)~O(nlogn), SC=O(logn)
        sort(arr.begin(),arr.end());
        int n=arr.size();
        arr[0]=1;
        for(int i=1;i<n;++i){
            if(arr[i]>arr[i-1]+1) arr[i]=arr[i-1]+1;
        }
        return arr[n-1];
        /*
        sort(arr.begin(),arr.end());
        int n=arr.size(),ans=1;
        for(int i=1;i<n;++i){
            if(arr[i]>=ans+1) ++ans;
        }
        return ans;
        */
    }
};
