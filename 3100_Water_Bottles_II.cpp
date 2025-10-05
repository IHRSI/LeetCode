//Both solution are upgraded version of Water Bottles 1
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {//TC=O(n) , SC=O(1)
        int consumedBottles = 0;
        while (numBottles >= numExchange) {
            consumedBottles += numExchange;
            numBottles -= numExchange;
            numBottles++;
            ++numExchange;
        }
        return consumedBottles + numBottles;
    }
};

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {//TC=O(sqrt(n)) , SC=O(1) - To understand refer editorial
        int ans=numBottles;
        while (numBottles >= numExchange) {//Now numBottles are emptyBottles
            ++ans;
            numBottles-=numExchange-1;
            ++numExchange;
        }
        return ans;
    }
};

//There is one O(1) solution as well but tricky to understand it uses quadratic equation generated from TC calc of above soln
