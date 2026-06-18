class Solution {
public:
    double angleClock(int hour, int minutes) {//TC=O(1), SC=O(1)
        double hourangle=hour*30;
        double minangle=6*minutes;
        hourangle+=30*(minutes/60.0);
        double ans=abs(hourangle-minangle);
        return (ans>180)?360.0-ans:ans;
    }
};
