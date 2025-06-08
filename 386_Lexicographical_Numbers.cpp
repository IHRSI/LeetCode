class Solution { // TC=O(n) - notice while inside for it doesn't run more than O(log n) over the whole loop because each backtrack shortens the number. , SC=O(1) 
//The space complexity analysis does not account for the result list itself, as the problem requires returning a list with n elements.
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
