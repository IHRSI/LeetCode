//Very great Approach - Using bits to store frequency as val range in not >2^15-1 as we divide the 32 bits in 2 halves.
//To use the  bits 0-15 for value and 16-31 for ctoring count.
//GOAT method
class Solution {//TC=O(n) , SC=O(1) in place
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        for(int &num : arr) {
            int val = (num & (1<<16)-1);//(1<<16)-1==65536
            if(val <= n) {
                arr[val-1] += (1<<16);
            }
        }
        for(int val = n; val >= 1; val--) {
            if((arr[val-1] >> 16) == val) return val;
        }
        return -1;
    }
};

//Using hash array
class Solution {
public:
    int findLucky(vector<int>& arr) {//TC=O(500) (n<=500) , SC=O(500) ~ O(1)
        int freq[501]={0};
        int n=arr.size();
        for(int i=0;i<n;++i) ++freq[arr[i]];
        for(int i=500;i>0;--i) if(i==freq[i]) return i;
        return -1;
    }
};
//Improved a little
class Solution {
public:
    int findLucky(vector<int>& arr) {//TC=O(n) (Improved from 500 to n as n<=500) , SC=O(500) ~ O(1)
        int freq[501]={0};
        int n=arr.size();
        for(int i=0;i<n;++i) if(arr[i]<=n) ++freq[arr[i]];
        for(int i=n;i>0;--i) if(i==freq[i]) return i;
        return -1;
    }
};
