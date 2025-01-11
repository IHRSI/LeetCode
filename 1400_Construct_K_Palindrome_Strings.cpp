class Solution { // TC-O(n) where n=s.length() , SC-O(26)=O(1)
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;
        else if(s.length()==k) return true;
        else{
            vector<int> v(26,0);
            for(char &c: s) v[c - 'a']+=1;
            int count=0;
            for(int &i: v){
                if(i%2!=0) count+=1;
            }
            if(count>k) return false;
        }
        return true;
    }
};
