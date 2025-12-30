//Even though rows shrink, the same intermediate row can be formed via multiple paths — memoization prevents recomputing them.
//The repetition is not across different heights, but across different recursion branches.
//Using memo helps to reduce space used in recursion depth so we get better space optimised from 16mb to 20mb

//Although total recursive calls are O(n(n+1)/2)~O(n^2), only O(n) calls exist simultaneously on the stack, so recursion depth is O(n).
//Horizontal recursion (idx) finishes before moving up
//Vertical recursion starts only after horizontal completes
////Recusrsive Stack SC=O(n)

/*
TC depends on:
How many different rows are possible=6^6 + 6^5 + 6^4 + 6^3 + 6^2 + 6^1 ~ 6^L
How much work we do per row=O(6*L)
TC=(number of unique rows) × (work per row)=O((6^L)*(6*L)) as L<=6 TC~O(6^L)
*/
class Solution {
public:
    unordered_map<string,bool> memo;//Possible memo states=6^6 + 6^5 + 6^4 + 6^3 + 6^2 + 6^1 ~ 6^L, 6 alphabets, L is len of row
    bool bt(string curr,string above,unordered_map<string,vector<char>> &um,int idx){//TC=O(6^L), SC net=O(6^L) - exponential
        if(curr.size()==1) return true;
        if(memo.find(curr)!=memo.end()) return memo[curr];
        if(idx==curr.size()-1) return memo[above]=bt(above,"",um,0);
        string pair;
        pair.push_back(curr[idx]);
        pair.push_back(curr[idx+1]);
        if(um.find(pair)==um.end()) return false;
        else{
            for(char c: um[pair]){
                above.push_back(c);
                if(bt(curr,above,um,idx+1)==true) return true;
                above.pop_back();
            }
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> um;//Transition map SC <O(6*6*6)
        for(auto s:allowed){

            um[s.substr(0,2)].push_back(s[2]);
        }
        return bt(bottom,"",um,0);
    }
};
