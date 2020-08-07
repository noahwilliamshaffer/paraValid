#include <stack>

class Solution {
public:
    //boolean function takes in string of parethisis and brackets 
    bool isValid(string s) {
        //initilize a stack of chars
        stack<char> paren;
        //for each character in the string 
        for (char& c : s) {
            switch (c) {
                    //add the left brackets and paras to the stack
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                    
                    //for the right brackets and paras if there is a left equivilent available delete it from the stack
                    //otherwise if it is empty or there is not a left equivilent return false
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                    
                    //if none of the obove move to next character in the string
                default: ; // pass
            }
        }
        //if the stack is empty then the paras and brackets are valid
        return paren.empty() ;
    }
};
