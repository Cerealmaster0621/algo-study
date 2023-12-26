/*
leetcode 1544 easy
stack + string.
isupper(c), toupper(c), tolower(c)
stack to string in right order ->
str = stack.top() + str
stack.pop()
*/

class Solution {
public:
    string makeGood(string s) {
        stack<char>stack;
        string ans;
        for(char c : s){
            if(stack.empty()) {
                stack.push(c);
                continue;
            };
            if(isupper(c)){
                if(stack.top() == tolower(c)){
                    stack.pop();
                }else{
                    stack.push(c);
                }
            }else{
                if(stack.top() == toupper(c)){
                    stack.pop();
                }else{
                    stack.push(c);
                }
            }
        }
        while(!stack.empty()){
            ans=stack.top()+ans;
            stack.pop();
        }
        return ans;
    }
};