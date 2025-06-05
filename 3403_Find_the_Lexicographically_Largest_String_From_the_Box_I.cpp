// Tow Pointer Concept
class Solution {// TC=O(n) dos'nt look like but it is, SC=O(1)
public:
    string lastsubstr(string s){
        int i=0,j=1,n=s.length();
        while(j<n){
            int k=0;
            while(j+k<n && s[i+k]==s[j+k]) k++;
            if(j+k<n && s[i+k]<s[j+k]){
                int t=i;
                i=j;
                j=max(j+1,t+k+1);
                /* So what’s being skipped? if (t+k+1>j+1) :
                You're skipping the indices between j + 1 and t + k + 1, because those substrings:
                Start within the overlap
                Have already been compared
                Cannot possibly be better, since they are rotations or shifts of what's already worse*/
            }
            else j+=k+1;
        }
        return s.substr(i,n-1);
    }
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        string last=lastsubstr(word);
        int n=word.length();
        int m=last.length();
        return last.substr(0,min(m,n-(numFriends-1)));
    }
};


// Enumeratin concept
class Solution { TC=O(n^2) , SC=O(n)
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        string ans="";
        int n=word.length();
        int maxlen=n-(numFriends-1);
        for(int i=0;i<n;i++){
            ans=max(ans,word.substr(i,min(maxlen,n-i)));//O(n)+O(n) :They’re not nested, they’re just sequential steps in each loop.
        }
        return ans;
    }
};
