//Easy - read Q understood it saw eg got the logic/intution.
class Solution {//TC=(n) , SC=O(1)
public:
    int possibleStringCount(string word) {
        int ans=1;
        for(int i=1;i<word.size();++i){
            while(word[i]==word[i-1]){
                ++ans;
                ++i;
            }
        }
        return ans;
    }
};

//Same approach - no difference
class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1,n=word.size();
        for(int i=1;i<n;++i) if(word[i]==word[i-1]) ++ans;
        return ans;
    }
};
