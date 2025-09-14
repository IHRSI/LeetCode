class Solution {
public:
    int maxFreqSum(string s) {//TC=O(n+26) , SC=O(26)
        int arr[26]={0};
        int maxv=0,maxc=0;
        for(char c: s){
            ++arr[c-'a'];
        }
        for(int i=0;i<26;++i){
            if(i==0 || i==4 || i ==8 || i==14 || i==20){
                if(arr[i]>maxv) maxv=arr[i];
            }
            else{
                if(arr[i]>maxc) maxc=arr[i];
            }
        }
        return maxc+maxv;
    }
};
//Using char in for loop instead of int datatype
          for(char i='a';i<='z';++i){
            if(i=='a' || i=='e' || i =='i' || i=='o' || i=='u'){
                if(arr[i-'a']>maxv) maxv=arr[i-'a'];
            }
            else{
                if(arr[i-'a']>maxc) maxc=arr[i-'a'];
            }
          }
