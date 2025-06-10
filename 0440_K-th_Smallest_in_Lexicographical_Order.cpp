//The total number of calls to countstep is also O(log n) in practice, because you skip large sections at a time.
//The outer loop runs at most k times, but in practice, it’s much less because you skip entire subtrees using countstep.
class Solution {//TC=O((logn)^2) , SC=O(1)
public:
    int findKthNumber(int n, int k) {
        int ans=1;
        k--;
        while(k>0){
            int step=countstep(n,ans,ans+1);
            if(k>=step){//atmost called logn times only
                k-=step;
                ans++;
            }
            else{
                ans*=10;
                k--;
            }
        }
        return ans;
    }
    int countstep(int n,long prefix1,long prefix2){// To prevent overflow the comparison in done in float
        int steps=0;
        while(prefix1 <= n){//O(logn)
            steps +=min((long)(n + 1), prefix2) - prefix1;//[prefix1, prefix2) - as we need no. of nodes in subtree of prefix1
            prefix1*=10;
            prefix2*=10;
        }
        return steps;
    }
};
/*If prefix1 = 10, prefix2 = 20, and n = 17
We want to count numbers: 10, 11, ..., 17 (only up to n)
prefix2 = 20 goes beyond n, so to not over-count, we cap it using:
min(n + 1, prefix2)
min(18, 20) = 18, so we do:
18 - 10 = 8 numbers → 10 to 17 (correct!)*/
