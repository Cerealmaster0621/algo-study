/*
leetcode 844 easy
string as stack
make function bc same process twice
Example1
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
# means backspace
*/

class Solution {
public:
    string build_string(string s){
        string ans = "";
        for(char c : s){
            if(c == '#'){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }else{
                ans.push_back(c);
            }
        }
        return ans;
    }

    bool backspaceCompare(string s, string t) {
        return build_string(s)==build_string(t);
    }
};