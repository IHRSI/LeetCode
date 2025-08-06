//Initial thought
class Solution {//TC=O(n^2), SC=O(1)
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int left=n;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(baskets[j]==0) continue;
                if(fruits[i]<=baskets[j]){
                    --left;
                    baskets[j]=0;
                    break;
                }
            }
        }
        return left;
    }
};

//Used ordered set
class Solution {//TC=O(n^2+nlogn) , SC=O(n)
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        set<int> unusedIndices;
        for (int i = 0; i < n; ++i)
            unusedIndices.insert(i); // all baskets initially unused

        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            bool placed = false;
            for (int j : unusedIndices) {
                if (baskets[j] >= fruits[i]) {
                    unusedIndices.erase(j); // use the basket
                    placed = true;
                    break;
                }
            }
            if (!placed) ++unplaced; // fruit couldn't be placed
        }

        return unplaced;
    }
};
