class Solution { // TC=O(n) , SC=O(1)
public:
    int minimumLength(string s) {
        int n=s.length();
        if(n==1 || n==2) return n;
        unordered_map<char,int> um;
        for(char ele: s){
            um[ele]+=1;
        }
        for(auto ele: um){
            if((ele.second)%2==0){
                n=n-(ele.second) +2;
            }
            else n=n-(ele.second) +1;
        }
        return n;
    }
};
