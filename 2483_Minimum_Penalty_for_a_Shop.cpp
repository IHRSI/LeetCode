class Solution {//Two Pass
public:
    int bestClosingTime(string customers) {//TC=O(n), SC=O(1)
        int n=customers.size();
        int yct=0,nct=0;
        for(int i=0;i<n;++i){
            if(customers[i]=='Y') ++yct;
        }
        int minpen=yct,j=0;//closed at 0th hour
        for(int i=0;i<n;++i){
            if(customers[i]=='N'){
                ++nct;
            }
            else --yct;
            if(minpen>nct+yct){
                j=i+1;//closed st i+1th hour
                minpen=nct+yct;
            }
        }
        return j;
    }
};
//If we needed the min penelty then the above gives correct value the below one relatively calcs the min to just get the correct min penelty day.
//In the previous solution, we used the first traversal to calculate the count of 'Y', ensuring that each penalty obtained is accurate.
//However, we don't need the actual penalty values. It is important to note that the problem only requires the earliest hour with the lowest penalty.
//Thus, the only thing that matters is the penalty of the hours relative to each other, and our initial reference point is not significant.

//Just removed the 1st for loop of the above code
class Solution {//One Pass
public:
    int bestClosingTime(string customers) {//TC=O(n), SC=O(1)
        int n=customers.size();
        int yct=0,nct=0;
        int minpen=yct,j=0;
        for(int i=0;i<n;++i){
            if(customers[i]=='N'){
                ++nct;
            }
            else --yct;
            if(minpen>nct+yct){
                j=i+1;
                minpen=nct+yct;
            }
        }
        return j;
    }
};
