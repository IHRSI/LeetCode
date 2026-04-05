class Solution {
public:
    bool judgeCircle(string moves) {//TC=O(n), SC=O(1)
        int posx=0,posy=0;
        for(char c: moves){
            if(c=='U') ++posy;
            else if(c=='R') ++posx;
            else if(c=='D') --posy;
            else --posx;
        }
        return (posx==0 && posy==0)?1:0;
    }
};
