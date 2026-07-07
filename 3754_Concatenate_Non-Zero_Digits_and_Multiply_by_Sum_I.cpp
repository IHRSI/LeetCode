//Without Conversion to String: Traversing from Right to Left
class Solution {
public:
    long long sumAndMultiply(int n) {//TC=O(logn), SC=O(1)
        long long ans=0;
        int sum=0,pow10=1;
        while(n){
            int d=n%10;
            if(d!=0){
                sum+=d;
                ans+=d*1ll*pow10;
                pow10*=10;
            }
            n/=10;
        }
        return ans*sum;
    }
};

//By Conversion to String: Traversing from Left to Right
class Solution {
public:
    long long sumAndMultiply(int n) {//TC=O(2logn)~O(logn) , SC=O(logn)
        string str=to_string(n);
        long long ans=0;
        int sum=0;
        for(char &c: str){
            if(c!='0'){
                sum+=c-'0';
                ans*=10;
                ans+=c-'0';
            }
        }
        return ans*sum;
    }
};
