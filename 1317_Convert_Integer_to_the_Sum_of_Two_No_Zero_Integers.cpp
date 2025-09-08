//Better runtime and memory effcient than below editorial solution
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {//TC=O(nlogn) , SC=O(1)
        for(int i=n-1;i>=1;--i){
            bool check0=false;
            int j=i;
            while(j>0){
                if(j%10==0){
                    check0=true;
                    break;
                }
                j/=10;
            }
            if(!check0){
                int k=n-i;
                while(k>0){
                    if(k%10==0){
                        check0=true;
                        break;
                    }
                    k/=10;
                }
                if(!check0) return {i,n-i};
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {//TC=O(nlogn) , SC=O(1)
        for(int i=1;i<n;++i){
            int a=i;
            int b=n-i;
            if((to_string(a)+to_string(b)).find('0')==string::npos) return {a,b};
        }
        return {};
    }
};
