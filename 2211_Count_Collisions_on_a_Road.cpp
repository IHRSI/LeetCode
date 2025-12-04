//THis Q can also be done using stack but will take space(SC)

class Solution {//Simulation - handling back collisions eg- 'RRLL'
public:
    int countCollisions(string directions) {//TC=O(n), SC=O(1)
        int res = 0;
        int flag = -1;
        for (auto c : directions) {
            if (c == 'L') {
                if (flag >= 0) {
                    res += flag + 1;
                    flag = 0;
                }
            } else if (c == 'S') {
                if (flag > 0) {
                    res += flag;
                }
                flag = 0;
            } else {
                if (flag >= 0) {
                    flag++;
                } else {
                    flag = 1;
                }
            }
        }
        return res;
    }
};

class Solution {//Counting - After analyising the test cases
public:
    int countCollisions(string dir) {//TC=O(n), SC=O(1)
        int colls=0;
        int n=dir.size();
        int l=0,r=n-1;
        while(l<n && dir[l]=='L') ++l;
        while(r>=l && dir[r]=='R') --r;
        for(int i=l;i<=r;++i){
            if(dir[i]!='S') ++colls;
        }
        return colls;
    }
};
