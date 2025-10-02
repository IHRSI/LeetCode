//By me - efficient
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {//TC=O(n), SC=O(1)
        int ans=numBottles;
        while(numBottles>=numExchange){
            int quo=numBottles/numExchange;
            ans+=quo;
            numBottles=numBottles%numExchange+quo;
        }
        return ans;
    }
};

//Simulation
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {//TC=O(n), SC=O(1) - Refer editorial
        int consumedBottles = 0;

        while (numBottles >= numExchange) {
            // Consume numExchange full bottles.
            consumedBottles += numExchange;
            numBottles -= numExchange;

            // Exchange them for one full bottle.
            numBottles++;
        }

        // Consume the remaining numBottles (<numExchange).
        return consumedBottles + numBottles;
    }
};
