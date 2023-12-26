/*
leetcode 20 easy
stack + hashmap for character combination
STRING CAN BE USED AS STACK IN C++
edge cases - s is only opened or closed
push when opened character, compare with 
top of the stack when closed character.
Example 1
Input: s = "()[]{}"
Output: true
*/

//STRING AS STACK
class Solution {
public:
    bool isValid(string s) {
        string stack = "";
        unordered_map<char,char> map = {{'(',')'},{'{','}'},{'[',']'}};
        for(char c : s){
            if(stack.empty()&&!map[c]){return false;}
            if (!stack.empty() && map[stack.back()] == c){
                stack.pop_back();
            }else{
                stack.push_back(c);
            }
        }
        if(!stack.empty()) return false;
        return true;
    }
};

//stack cases
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> map = {{'(',')'},{'{','}'},{'[',']'}};
        for(char& c : s){
            //edge case when c is closed and st is empty
            if(st.empty() && !map[c]) return false;
            if (c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                char tmp = st.top();
                if(c != map[tmp]){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
        //edge case when c is open and other c is never closed
        if(!st.empty()){
            return false;
        }
        return true;
    }
};