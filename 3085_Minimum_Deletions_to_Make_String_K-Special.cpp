//Best soln SC=TC=100%beats
/*Greedy - Since there are only 26 character types, we can enumerate one of them as the 
"character with the lowest frequency after the deletion operation" and set it as c.
Then, all characters with frequencies less than cnt[c] will be entirely deleted,
and all characters with frequencies greater than cnt[c]+k will be reduced to exactly cnt[c]+k instances.*/
//Reason-Suppose we select several characters as the final answer, and let x be the character with the smallest frequency in the answer.
//It can be shown that out of the selected characters, the optimal solution will never delete an occurrence of character x to obtain the answer.
class Solution {//TC=(n+26^2) SC=O(26)=O(1)
public:
    int minimumDeletions(string &s, int k) {
        vector<int> freq(26, 0);
        for (char &c : s) {//hashing
            ++freq[c - 'a'];//string logic for storing
        }
        int ans = s.size();
        for(int &a : freq){    
            int deleted = 0;
            for(int &b : freq){//counting
                if(b < a) deleted += b;
                else if (b > a+k) deleted += (b - (a+k));
            }
            ans = min(ans, deleted);
        }
        return ans;
    }
};


//Wrong solutiom which  i tried 635/732 test cases passed
class Solution {
public:
    int minimumDeletions(string word, int k) {//Tried using sorting but is getting tougher to code , sliding window has to be included to solve further
        int ans=0;
        vector<int> v(26,0);
        for(char &c: word) ++v[c-'a'];
        sort(v.begin(),v.end());
        int max1=25;
        for(int i=0;i<25;++i){//TC=(26*26log26) SC=O(26)=O(1)
            int min1=0;
            if(v[max1]-v[i]>k){
                min1=min(v[i],v[max1]-v[i]-k);
                if(min1==v[max1]-v[i]-k){
                    v[max1]=v[i]+k;
                    sort(v.begin()+ i,v.end());
                }
            }
            ans+=min1;
        }
        return ans;
    }
};
