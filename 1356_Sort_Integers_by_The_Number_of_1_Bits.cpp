class Solution {
public:
    //Brian Kerninghan's Algorithm
    int hamming(int num){//Runs the number of times set bit is present in the num
        int wt=0;//No. of 1 bits
        while(num>0){
            num&=(num-1);
            ++wt;
        }
        return wt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a, int b){
            int x=hamming(a);
            int y=hamming(b);
            if(x==y) return a<b;
            return x<y;
        });
        return arr;
    }
};

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
            /*
            if (__builtin_popcount(a) == __builtin_popcount(b)) {
            return a < b;
            }
            return __builtin_popcount(a) < __builtin_popcount(b);
            */
        });
        return arr;
    }
};
