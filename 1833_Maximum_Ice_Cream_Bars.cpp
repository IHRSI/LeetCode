//Counting Sort
//Using freq array and then resetting it for each testcase is faster and takes about no space as it is created only once(acts as ~O(1) as it is used by all the testcases)
//rather than using a vector which is created dynamically every testcase which eventually takes space and time in creating vector object

//Using array
int freq[100001];
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {//TC=O(2n+100001)~O(n), SC=O(100001)~O(1) as it is common for all the test cases
        int maxcost=0,mincost=INT_MAX;
        for(int cost:costs){
            ++freq[cost];
            maxcost=max(maxcost,cost);
            mincost=min(mincost,cost);
        }
        int ct=0;
        for(int i=mincost;i<=maxcost;++i){
            if(freq[i]==0) continue;
            int canbuy=min(freq[i],coins/i);
            if(canbuy<freq[i]){
                ct+=canbuy;
                break;
            }
            else{
                coins-=canbuy*i;
                ct+=canbuy;
            }
        }
        for(int c:costs) freq[c]=0;//reset
        return ct;
    }
};

//Using vector
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {{//TC=O(n+100001)~O(n), SC=O(100001)
        vector<int> freq(100001);
        int maxcost=0,mincost=INT_MAX;
        for(int cost:costs){
            ++freq[cost];
            maxcost=max(maxcost,cost);
            mincost=min(mincost,cost);
        }
        int ct=0;
        for(int i=mincost;i<=maxcost;++i){
            if(freq[i]==0) continue;
            int canbuy=min(freq[i],coins/i);
            if(canbuy<freq[i]) return ct+canbuy;
            else{
                coins-=canbuy*i;
                ct+=canbuy;
            }
        }
        return ct;
    }
};

//Sorting
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {//TC=O(nlogn+n), SC=O(logn)
        sort(costs.begin(),costs.end());
        int ct=0;
        for(int cost: costs){
            if(cost<=coins){
                coins-=cost;;
                ++ct;
            }
            else return ct;
        }
        return ct;
    }
};
