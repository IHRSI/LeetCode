//Use push_back()
#include <bits/stdc++.h>
class Solution {
public:
    string interpret(string command) {
        string s="";
        for(int i=0;i<command.length();i++){
            if(command[i]=='G') s+="G";//s.push_back('G');
            else if(command[i+1]==')'){
                s+="o";// s.push_back('o');
                i+=1;
            }
            else{
                s+="al";
                i+=3;
            }
        }
        return s;
    }
};
