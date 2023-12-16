/*
** Example 1 :
** Input : s = ["h","e","l","l","o"]
** Output : ["o","l","l","e","h"]
** Example 2:
** Input: s = ["H","a","n","n","a","h"]
** Output: ["h","a","n","n","a","H"]
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        char tmp; 
        while(left<right){
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left ++;
            right --;
        }
    }
};