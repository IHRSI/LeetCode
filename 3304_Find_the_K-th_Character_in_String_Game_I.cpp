//Great soln - good use of bit manipaulation thinking
//doing k-1 to make it 0 indexed
//The key observation is that:
//Each operation effectively adds the count of 1s in the binary representation of (k - 1) to the starting character 'a'
//The number of operations needed corresponds to the number of bits in (k - 1)'s binary representation
class Solution {//TC=O(1) , SC=O(1)
public:
    char kthCharacter(int k) {//****The no of jumps the index does is always in pow of 2 so at all jumps any bit get sets thats the catch
        int shift=__builtin_popcount(k-1);//O(1)
        return 'a'+shift;
    }
};

//Editorial - backtracked to count no. of shifts similar to above logic
class Solution {
public:
    char kthCharacter(int k) {//TC=O(logk) , SC=O(1)
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if ((1 << t) == k) {
                t--;
            }
            k = k - (1 << t);
            ans++;
        }
        return 'a' + ans;
    }
};

//My initial thought - Simulation
class Solution {//TC=O(2K) - worst case =O(K) , SC=O(2K)=O(k);
public:
    char kthCharacter(int k) {
        char ans;
         int ct=1;
         string str="a";
         while(ct<k){
            string temp="";
            for(auto s: str){
                char ch= s=='z'? 'a': s+1;
                temp.push_back(ch);
            }
            ct<<=1;
            str+=temp;
         }
         ans=str[k-1];
        return ans;
    }
};

//Since the constraint is 1≤k≤500, we don't need to worry about performing modulus 26 operations explicitly.
//First 500 letters 
//This obvisouly i cant generate but pasted this soln to show the SC diffrence it does in defining globally.
const string a="abbcbccdbccdcddebccdcddecddedeefbccdcddecddedeefcddedeefdeefeffgbccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfgghbccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfgghcddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfgghghhibccdcddecddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfgghcddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfgghghhicddedeefdeefeffgdeefeffgeffgfgghdeefeffgeffgfggheffgfgghfgghghhideefeffgeffgfggheffgfgghfgghghhieffgfgghfgghghhifgghghhighhihiij";
class Solution {//TC=O(1) , BUT SC is O(n=500)but beats 100% as its defined as const globally
public:
        char kthCharacter(int k) {
        return a[k-1];
    }
};
