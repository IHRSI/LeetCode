//Two Pointer
class Solution {//TC=O(M) , SC=O(1)
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[i]==t[j]) ++i;
            ++j;
        }
        if(i==s.length()) return true;
        return false;
    }
};
/*So here's one idea for the follow up:
Since there are more than a billion string, time complexity is now not in any second but it just need to be as low as possible.
In that case, we need to optimize the runtime to check 1 string to a prepared specific string. In most solution, time complexity is O(N) with N is the maximum size of string t and s. And since all the time size of s must smaller than or equal to string t, we should be able to get this to lower than size of string t.
The idea here is to use prefix sum and binary search:
First, we need to prepare a 2D array size 26xN call T[x-'a'][i] = number of character x appear from start to i in string t.
For example I have string t="abdeabcd" a part of my array should look something like this:
x\i :0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
a | 1 | 1 | 1 | 1 | 2 | 2 | 2 | 2 |
b | 0 | 1 | 1 | 1 | 1 | 2 | 2 | 2 |
c | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
d | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 2 |
e | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 |

Next, with every character in string S, let say j is the position that we last found character S[i-1], to find S[i], we need to get the first position in T[ S[i] ] that have value greater than T[ S[i] - 'a' ][j], if we don't found any return false.
For example: With string t above and string S="add", let say we found character S[1] = 'd' and we need to find S[2] which is also d, in that case, we can find it in log2(N) by binary search the value T[d][2]+1, in this case, we can find that position at j=7.

Code should look sth like this
let say: S is maximum size of string s, N is size of string t
With that, overall complexity of the follow up is:
O( KSlog2(N) + N26 ) much better if we do the regular algorithm with time complexity : O(NS*K)*/
