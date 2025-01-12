//My soln using stack- TC=SC=O(n)
class Solution {
public:
    bool canBeValid(string p, string locked) {
        int n=p.length();
        if(n%2!=0) return false;
        stack<int> s1;
        stack<int> s2;
        for(int i=0; i<n;i++){
            if(locked[i]=='0') s2.push(i);
            else if(p[i]=='(') s1.push(i);
            else{
                if(!s1.empty()) s1.pop();
                else if(!s2.empty()) s2.pop();
                else return false;
            }
        }
        while(!s1.empty() && !s2.empty() && s1.top()<s2.top()){
            s1.pop();
            s2.pop();
        }
        if(s2.size()%2!=0) return false;
        return s1.empty();
    }
};

//Without stack better effeciency , SC-O(1), TC-O(n)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) {
            return false; // Odd length cannot form valid parentheses
        }

        // Left-to-right pass: Ensure there are enough open brackets
        int openCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') {
                openCount++;
            } else { // s[i] == ')' and locked[i] == '1'
                openCount--;
            }
            if (openCount < 0) {
                return false; // Too many ')' encountered
            }
        }

        // Right-to-left pass: Ensure there are enough close brackets
        int closeCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') {
                closeCount++;
            } else { // s[i] == '(' and locked[i] == '1'
                closeCount--;
            }
            if (closeCount < 0) {
                return false; // Too many '(' encountered
            }
        }

        return true;
    }
};
