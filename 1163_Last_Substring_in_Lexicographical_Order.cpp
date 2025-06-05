//Refer Q 3403 same Q with with a bit of enhancement
class Solution //Tc=O(n) , SC=O(1)
public:
    string lastSubstring(string s) {
        int i=0,j=1,n=s.length();
        while(j<n){
            int k=0;
            while(j+k<n && s[i+k]==s[j+k]) k++;
            if(j+k<n && s[i+k]<s[j+k]){
                int t=i;
                i=j;
                j=max(j+1,t+k+1);
                /*
                case2 : i+k > j
                if you are doing j=j+1, this might lead to O(n^2) 
                in case of many large repeated patterns
                sol: to optimise this we need to skip the part which we know for sure is not the answer (skip inferior substings)
                reason: when you know that the char at i+k is not part your answer (s[i+k]<s[j+k]), why do you want to waste your time traversing from j+1 to i+k
                */
            }
            else j+=k+1;
        }
        return s.substr(i,n-i); // or s.substr(i); i to end of string s
    }
};
