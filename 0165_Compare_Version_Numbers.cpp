class Solution {
public:
    int compareVersion(string version1, string version2) {//TC=O(n) , SC=O(1 , n=max(n1,n2)
        int n1=version1.size();
        int n2=version2.size();
        for(int i=0,j=0;i<n1 || j<n2;++i,++j){
            int x1=0,x2=0;
            while(i<n1 && version1[i]!='.'){
                x1=x1*10+(version1[i++]-'0');
            }
            while(j<n2 && version2[j]!='.'){
                x2=x2*10+(version2[j++]-'0');
            }
            if(x1>x2) return 1;
            else if(x1<x2) return -1;
        }
      /*Using ehile loop
      int i=0,j=0;
        while(i<n1 || j<n2){
            //Code
            ++i;
            ++j;
        }
      */
        return 0;
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1), s2(version2);
        string token1, token2;
        
        while (getline(s1, token1, '.') || getline(s2, token2, '.')) {
            int num1 = token1.empty() ? 0 : stoi(token1);
            int num2 = token2.empty() ? 0 : stoi(token2);
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            token1.clear(); token2.clear();
        }
        return 0;
    }
};
