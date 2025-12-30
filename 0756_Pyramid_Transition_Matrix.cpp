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

//Bit Masking and manipulation use - Better runtime and space utilisation
class Solution {//TC ans SC remains same but peformance improves
public:
    // memo[row_key] = whether this row can form a pyramid
    unordered_map<int, bool> memo;

    // transition[a][b] = bitmask of possible top blocks
    int transition[6][6] = {};

    // Backtracking to build next row from bitmasks
    bool buildNextRow(int idx,
                      vector<int>& nextRow,
                      vector<int>& nextMasks) {
        if (idx == nextRow.size())
            return dfs(nextRow);

        int mask = nextMasks[idx];

        // try all possible letters using bits
        while (mask) {
            int bit = mask & -mask;           // lowest set bit
            int letter = __builtin_ctz(bit);  // index of bit

            nextRow[idx] = letter;
            if (buildNextRow(idx + 1, nextRow, nextMasks))
                return true;

            mask -= bit; // remove this option
        }
        return false;
    }

    // DFS on current row
    bool dfs(vector<int>& row) {
        int n = row.size();
        if (n == 1) return true;

        // encode row into an integer key (base-6)
        int key = 0;
        for (int x : row)
            key = key * 6 + x;

        if (memo.count(key))
            return memo[key];

        vector<int> nextMasks(n - 1, 0);

        // compute possible masks for next row
        for (int i = 0; i < n - 1; i++) {
            nextMasks[i] = transition[row[i]][row[i + 1]];
            if (nextMasks[i] == 0)
                return memo[key] = false;
        }

        vector<int> nextRow(n - 1);

        bool res = buildNextRow(0, nextRow, nextMasks);
        memo[key] = res;
        return res;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // build transition table
        for (auto &s : allowed) {
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            int c = s[2] - 'A';
            transition[a][b] |= (1 << c);
        }

        // convert bottom string to numeric row
        vector<int> row;
        for (char c : bottom)
            row.push_back(c - 'A');

        return dfs(row);
    }
};
