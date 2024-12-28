class Solution { //TC=SC=O(n)
public:
    bool isValid(string str) {
        stack<char> s;
        for(char &ele: str){
            if(ele == '(' || ele == '{' || ele == '[') {
                s.push(ele);
            } 
            else {
                if(s.empty()) return 0;
                if(ele == ')' && s.top() != '(') return 0;
                if(ele == '}' && s.top() != '{') return 0;
                if(ele == ']' && s.top() != '[') return 0;
                s.pop();
            }
        }
        return s.empty();
    }
};
