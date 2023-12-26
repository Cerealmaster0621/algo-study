/*
leetcode 1047 easy
stack with string
STRING IN C++ IS ALSO MUTABLE SO USE STRING ONLY
INSTEAD WITH STACK
always check if stack is empty when populate 
stack.top.
reverse answer string bc LIFO
Example 1
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
*/
//STRING AS STACK
class Solution {
public:
    string removeDuplicates(string s) {
       string ans = "";
       for(char c : s){
           if(!ans.empty() && ans.back() == c){
               ans.pop_back();
           }else{
               ans.push_back(c);
           }
       }
       return ans;
    }
};
//with stack
class Solution {
public:
    string removeDuplicates(string s) {
       stack<char> stack;
       string ans = "";
       for(char& c : s){
           if(!stack.empty()&&stack.top() == c){
               stack.pop();
           }else{
               stack.push(c);
           }
       } 
       while(!stack.empty()){
           ans+=stack.top();
           stack.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};