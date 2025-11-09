class Solution {//Simulation
public:
    int countOperations(int num1, int num2) {//TC(Worst Case)=O(max(num1, num2) / min(num1, num2)), SC=O(1)
        int ans=0;
        while(num1>0 && num2>0){
            if(num1>=num2) num1-=num2;
            else num2-=num1;
            ++ans;
        }
        return ans;
    }
};

class Solution {//GCD Euclidian algo
public:
    int countOperations(int num1, int num2) {//TC=O(log(max(num1,num2))), SC=O(1)
        int ans=0;
        while(num1 && num2){ // or simply write while(num2){
            ans+=num1/num2;
            num1%=num2;
            swap(num1,num2);
        }
        return ans;
    }
};
