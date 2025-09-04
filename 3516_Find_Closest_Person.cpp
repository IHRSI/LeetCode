class Solution {
public:
    int findClosest(int x, int y, int z) {//TC=O(1), SC=O(1)
        if(abs(z-x)==abs(z-y)) return 0;
        else if(abs(z-x)>=abs(z-y)) return 2;
        else return 1;
    }
};
