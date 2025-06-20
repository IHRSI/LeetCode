//The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
//My code - not efficient 460ms
class Solution {//TC=O(n) , SC=O(4)=O(1)
public:
    int maxDistance(string s, int k) {
        int ans=0;
        unordered_map<char,int> um;
        for(char c : s){
            if(c=='N') ++um['N'];
            else if(c=='S') ++um['S'];
            else if(c=='E') ++um['E'];
            else ++um['W'];
            int net=abs(um['N']-um['S'])+ abs(um['E']-um['W']);
            int min1=min(um['N'],um['S']);
            int min2=min(um['E'],um['W']);
            if(min1+min2>=k) net+=k*2;
            else net+=(min1+min2)*2;
            ans=max(ans,net);
        }
        return ans;
    }
};

//This is efficient - as here i used variables instead of UM. and no other things vary. switch i just used as single char comparison was needed not complex cond.
class Solution {//TC=O(n) , SC=O(1) same as above
public:
    int maxDistance(string s, int k) {
        int ans=0;
        int n=0,sou=0,e=0,w=0;
        for(char c : s){
            switch(c){
            case 'N':
                ++n;
                break;
            case 'S':
                ++sou;
                break;
            case 'E':
                ++e;
                break;
            case 'W':
                ++w;
                break;
            }
            int net=abs(n-sou)+ abs(e-w);
            int min1=min(n,sou);
            int min2=min(e,w);
            if(min1+min2>=k) net+=k*2;
            else net+=(min1+min2)*2;
            ans=max(ans,net);
        }
        return ans;
    }
};

//Editorial soln
class Solution {//TC=O(n) , SC=O(1) same as above
public:
    int maxDistance(string s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1)); 
        }
        return ans;
    }
};
