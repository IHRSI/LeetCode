class Solution { // TC=O(n) - (Think recursion tree- as no number is visited again ), SC=O(1) 
//Notice while inside for- These backtracks only happen after big runs, and they just remove digits (num /= 10) — at most log₁₀(n) per backtrack.
//Though num /= 10 happens many times, it's: Not per iteration :Spread across total work
//The space used by the list is not considered in the complexity analysis.
//Iterative implementation using DSF logic
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int num=1;
        for(int i=0;i<n;i++){
            ans.push_back(num);
            if(num*10<=n) num*=10;//going into depth
            else {
                while(num%10==9 || num==n) num/=10;//backtrack logic
                num+=1;//append logic
            }
        }
        return ans;
    }
};

//DFS left

//Trie left
