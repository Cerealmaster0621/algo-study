/*
leetcode 71 medium
string + stack
set tmp and while loop inbetween / to /
continue -> jump to the next i and start
loop again, ++i -> add i + 1 and continue
loop.
string add technique using stack -
string = stack.top() + string
this will make string in a right order.
*/

class Solution {
public: 
    string simplifyPath(string path) {
        stack<string> stack;
        string str = "";
        for(int i = 0; i<path.size(); i++){
            string tmp;
            if(path[i]=='/'){
                continue;
            }
            while(path[i]!='/'&&i<path.size()){
                tmp.push_back(path[i]);
                ++i;
            }
            if(tmp == "."){
                continue;
            }else if(tmp == ".."){
                if(!stack.empty()){
                    stack.pop();
                }
            }else{
                stack.push(tmp);
            }
        }
        string ans = "";
        while(!stack.empty()){
            ans='/' + stack.top() + ans;
            stack.pop();
        }

        return ans == ""? "/":ans;       
    }
};