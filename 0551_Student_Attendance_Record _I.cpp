class Solution {
public:
    bool checkRecord(string s) {
        int c1=0,c2=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='A'){
                c1+=1;
                if(c1>=2){
                    return 0;
                    break;
                }
            }
            else if(s[i]=='L'){
                c2+=1;
                if(c2>=3){
                    return 0;
                    break;
                }
                else if(s[i+1]!='L'){
                    c2=0;
                }
            }
          /*else if(s[i]=='L' && s[i+1]=='L' && s[i+2]=='L'){
                return 0;
                break;
            }*/
        }
        return 1;
    }
};
