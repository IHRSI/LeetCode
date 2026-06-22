class Solution {
public:
    int maxNumberOfBalloons(string text) {//TC=O(n), SC=O(26)~O(1)
        int arr[26]={0};
        for(char c: text){
            ++arr[c-'a'];
        }
      /*
        return min({
            freq['b'-'a'],
            freq['a'-'a'],
            freq['l'-'a']/2,
            freq['o'-'a']/2,
            freq['n'-'a']
        });
        */
        int ct=INT_MAX;
        for(int e:"balloon"){
            if(e=='\0') break;
            if(e=='l' || e=='o'){
                ct=min(ct,arr[e-'a']/2);
            }
            else ct=min(ct,arr[e-'a']);
        }
        return ct;
    }
};
