//1 pass greedy
class Solution {
public:
    int maxDistance(vector<int>& colors) {//TC=O(n), SC=O(1)
        int n=colors.size();
        int ans=-1;
        for(int i=0;i<n;++i){
            if(colors[n-1]!=colors[i]) ans=max(ans,n-1-i);
            if(colors[0]!=colors[i]) ans=max(ans,i);
        }
        return ans;
    }
};

//2 pass - Greedy
class Solution {
public:
    int maxDistance(vector<int>& colors) {//TC=O(2n), SC=O(1)
        int n=colors.size();
        int ans=-1;
        for(int i=n-1;i>0;--i){
            if(colors[0]!=colors[i]){
                ans=max(ans,i);
                break;
            }
        }
        for(int i=0;i<n-1;++i){
            if(colors[n-1]!=colors[i]){
                ans=max(ans,n-1-i);
                break;
            }
        }
        return ans;
    }
};

//Brute Force
class Solution {
public:
    int maxDistance(vector<int>& colors) {//TC=O(n^2), SC=O(1)
        int n=colors.size();
        int ans=-1;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(colors[i]!=colors[j]) ans=max(ans,j-i);
            }
        }
        //Improved Brute Force
        /*
        for(int j=n-1;j>i;--j){
            if(colors[i]!=colors[j]){
                ans=max(ans,j-i);
                break;
            }
        }
        */
        return ans;
    }
};
