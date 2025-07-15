class Solution {
public:
    bool isValid(string word) {//TC=O(n) , SC=O(1)
        int n=word.size();
        if(n<3) return 0;
        bool vowel=0,consonant=0;
        for(char c: word){
            if(c=='@' || c=='#' || c=='$') return 0;
            if(c=='a' || c=='e' || c=='i' || c=='o'|| c=='u' || c=='A' || c=='E' || c=='I' || c=='O'|| c=='U') vowel=1;
            else if(c>=65 && c<=90 || c>=97 && c<=122) consonant=1;// or use this - else if(c>57) consonant=1
        }
        if(vowel && consonant) return 1;
        return 0;
    }
};

//Samw as above just converted c to lower case using bit manipulation trick
class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return 0;
        bool vowel=0,consonant=0;
        for(char c: word){
            if(c=='@' || c=='#' || c=='$') return 0;
            c=c|' ';//Upper case to Lower case
            if(c=='a' || c=='e' || c=='i' || c=='o'|| c=='u') vowel=1;
            else if(c>=97 && c<=122) consonant=1;
        }
        if(vowel && consonant) return 1;
        return 0;
    }
};

//Used functions
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) {
            return false;
        }

        bool hasVowel     = false;
        bool hasConsonant = false;

        for(char ch : word) {
            if(isalpha(ch)) {
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if(!isdigit(ch)) {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
};
