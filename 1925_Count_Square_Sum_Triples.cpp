class Solution {
public:
    int countTriples(int n) {//TC=O(n^2), SC=O(1)
        int ans=0;
        for(int a=1;a<n;++a){
            for(int b=a+1;b<=n;++b){
                int c=sqrt(a*a+b*b);//O(1) implemented by hardware in fixed no. of instructuons
                if(c<=n && c*c==a*a+b*b){
                    ans+=2;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countTriples(int n) {//TC=O(n^3), SC=O(1)
        int ans=0;
        for(int a=1;a<n;++a){
            for(int b=a+1;b<=n;++b){
                for(int c=b;c<=n;++c){
                    if(a*a + b*b== c*c){
                        ans+=2;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
