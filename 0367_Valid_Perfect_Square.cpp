//Using binary search - efficient
class Solution { // TC=O(log(num)) better TC, SC=O(1)
public:
    bool isPerfectSquare(int num) {
        int sqrt=1;
        int lo=1, hi=num;
        long int mid;
        while(hi>=lo){
            mid=lo + (hi - lo)/2;
            if(mid*mid==num){
                sqrt=mid;
                return 1;
            }
            else if(mid*mid>num) hi=mid-1;
            else lo=mid+1;
        }
        return 0;
    }
};

// Math logic - sum of 1st n odd numbers gives n^2
class Solution {
public:
    bool isPerfectSquare(int num) {// TC=O(sqrt(num)) , SC=O(1)
        long sum = 0;
        int i = 1;
        while (sum < num) {
            sum += i;
            if (sum == num) return 1;
            i += 2;
        }
        return 0;
    }
};
