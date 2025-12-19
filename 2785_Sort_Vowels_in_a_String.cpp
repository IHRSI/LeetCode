class Solution {
public:
    bool isvov(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string sortVowels(string s) {//TC=O(n), SC=O(1)
        int n=s.size();
        unordered_map<char,int> ct;//O(10)
        for(char c: s){
            if(isvov(c)) ct[c]++;
        }
        string sortedvov="AEIOUaeiou";
        int j=0;
        for(int i=0;i<n;++i){
            if(isvov(s[i])){
                while(ct[sortedvov[j]]==0) ++j;
                s[i]=sortedvov[j];
                ct[sortedvov[j]]--;
            }
        }
        return s;
    }
};

class Solution {
public:
    bool isvov(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string sortVowels(string s) {//TC=O(nlogn), SC=O(n)
        int n=s.size();
        string vovstr;//SC=O(n) in worst case
        for(char c: s){
            if(isvov(c)) vovstr+=c;
        }
        sort(vovstr.begin(),vovstr.end());
        int j=0;
        for(int i=0;i<n;++i){
            if(isvov(s[i])){
                s[i]=vovstr[j];
                ++j;
            }
        }
        return s;
    }
};
