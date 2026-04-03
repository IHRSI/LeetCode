//Optimised DP
class Solution {
public:
    int minimumDeletions(string s) {//TC=O(n), SC=O(1)
        int n = s.length();
        int min_deletions = 0;
        int b_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                b_count++;
            } else {
                min_deletions = min(min_deletions + 1, b_count);
            }
        }
        return min_deletions;
    }
};

//Stack - Single Pass
class Solution {//TC=O(n), SC=O(n) worst case
public:
    int minimumDeletions(string s) {
        int n=s.size();
        stack<char> lifo;
        int mindel=0;
        for(int i=0;i<n;++i){
            if(!lifo.empty() && lifo.top()=='b' && s[i]=='a'){
                lifo.pop();
                ++mindel;
            }
            else lifo.push(s[i]);
        }
        return mindel;
    }
};

//2 pass
class Solution {
public:
    int minimumDeletions(string s) {//TC=O(2n~n), SC=O(1)
        int n = s.length();
        int a_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a_count++;
        }
        int b_count = 0;
        int min_deletions = a_count;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a_count--;
            min_deletions = min(min_deletions, a_count + b_count);
            if (s[i] == 'b') b_count++;
        }
        return min_deletions;
    }
};

//Prefix Sum
class Solution {
public:
    int minimumDeletions(string s) {//TC=O(2n)~O(n), SC=O(n)
        int n=s.size();
        vector<int> ct_a(n,0);
        ct_a[n-1]=s[n-1]=='a'?1:0;
        for(int i=n-2;i>=0;--i){
            ct_a[i]=ct_a[i+1];
            if(s[i]=='a') ++ct_a[i];
        }
        int ct_b=0;
        int min_del=INT_MAX;
        for(int i=0;i<n;++i){
            min_del=min(min_del,ct_a[i]+ct_b);
            if(s[i]=='b') ++ct_b;
        }
        //For i=n
        min_del = min(min_del, ct_b);//As ct_a=0 at i=n
        return min_del;
    }
};
