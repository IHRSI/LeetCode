class Solution {
public:
    int countCommas(int n) {//TC=O(1), SC=O(1)
        return (n>=1000)?n-999:0;
    }
};
