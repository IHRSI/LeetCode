//My initial thought - Simulation
class Solution {//TC=O(2K) - worst case =O(K) , SC=O(2K)=O(k);
public:
    char kthCharacter(int k) {
        char ans;
         int ct=1;
         string str="a";
         while(ct<k){
            string temp="";
            for(auto s: str){
                temp.push_back(s+1);
            }
            ct<<=1;
            str+=temp;
         }
         ans=str[k-1];
        return ans;
    }
};
