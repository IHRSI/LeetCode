class Solution {
public:
    int minPartitions(string n) {//TC=O(n), SC=O(1)
        return *max_element(n.begin(),n.end())-'0';
    }
};

//Brute Force
class Solution {
public:
    int minPartitions(string n) {//TC=O(n*max_ele), SC=O(1)
        int ct=0;
        while(true){
            bool changed=0;
            for(char &ch: n){
                if(ch!='0'){
                    --ch;
                    changed=true;
                }
            }
            if(!changed) break;
            ++ct;
        }
        return ct;
    }
};
