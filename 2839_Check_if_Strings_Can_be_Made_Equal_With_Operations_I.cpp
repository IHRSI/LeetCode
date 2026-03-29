//Brute Force
class Solution {
public:
    bool canBeEqual(string s1, string s2) {//TC=O(1), SC=O(1)
        if( ( (s1[0]==s2[0] && s1[2]==s2[2]) ||
              (s1[0]==s2[2] && s1[2]==s2[0])  ) &&
            ( (s1[1]==s2[1] && s1[3]==s2[3]) ||
              (s1[1]==s2[3] && s1[3]==s2[1])  )
           ) return true;
        return false;
    }
};

//Logic
class Solution {
public:
    bool canBeEqual(string s1, string s2) {//TC=O(26), SC=O(26*2)
        int even[26]={0},odd[26]={0};
        for(int i=0;i<4;++i){
            if(i==0 || i==2){
                ++even[s1[i]-'a'];
                --even[s2[i]-'a'];
            }
            else{
                ++odd[s1[i]-'a'];
                --odd[s2[i]-'a'];
            }
        }
        for(int i=0;i<26;++i){
            if(even[i]!=0 || odd[i]!=0) return false;
        }
        return true;
    }
};
