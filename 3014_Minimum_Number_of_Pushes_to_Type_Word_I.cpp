class Solution {
public:
    int minimumPushes(string word) {//TC=O(1), SC=O(1)
        int n=word.size();
        if(n<=8) return n;
        else if(n<=16) return 8+(n-8)*2;
        else if(n<=24) return 8+8*2+(n-16)*3;
        else return 8+8*2+8*3+(n-24)*4;
        return 0;
    }
};

class Solution {
public:
    int minimumPushes(string word) {//TC=O(n), SC=O(1)
        int n=word.size();
        int ans=0;
        for(int i=0;i<n;++i){
            ans+=i/8+1;
        }
        return ans;
    }
};
