//Used hashing concept- Efficint time complexity
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return 0;
        int a[26]={0};
        int b[26]={0};
        for(int i; i<s.length(); i++){
            a[(s[i] - 'a')]++;
            b[(t[i] - 'a')]++;
        }
        for(int i; i<26; i++){
            if(a[i]!=b[i]) return 0;
        }
        return 1;
    }
};
/* Dont use this has greater time complexity
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
*/
