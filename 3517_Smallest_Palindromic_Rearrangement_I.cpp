//Self Coded - Most Efficient
//Eventually concept used is counting sort
class Solution {
public:
    string smallestPalindrome(string s) {//TC=O(n), SC=O(1)
        int n=s.size();
        int arr[26]={0};
        for(int i=0;i<n/2;++i){
            ++arr[s[i]-'a'];
        }
        int k=0;
        for(int i=0;i<26;++i){
            if(arr[i]){
                int ct=arr[i];
                while(ct>0){
                    s[k]='a'+i;
                    --ct;
                    ++k;
                }
            }
        }
        if(n&1) ++k;
        for(int i=25;i>=0;--i){
            if(arr[i]){
                int ct=arr[i];
                while(ct>0){
                    s[k]='a'+i;
                    --ct;
                    ++k;
                }
            }
        }
        return s;
    }
};

//Concised code - Used the mirror property of palindrome
class Solution {
public:
    string smallestPalindrome(string s) {//TC=O(n), SC=O(1)
        int n=s.size();
        int arr[26]={0};
        for(int i=0;i<n/2;++i){
            ++arr[s[i]-'a'];
        }
        int l=0,r=n-1;
        for(int i=0;i<26;++i){
            int ct=arr[i];
            while(ct>0){
                char c='a'+i;
                s[l++]=c;
                s[r--]=c;
                --ct;
            }
        }
        return s;
    }
};

//Sorting
class Solution {//TC=O(n/2 + (n/2)log(n/2)), SC=O(logn)
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        sort(s.begin(),s.begin()+n/2);
        for(int i=0;i<n/2;++i){
            s[n-1-i]=s[i];
        }
        return s;
    }
};
