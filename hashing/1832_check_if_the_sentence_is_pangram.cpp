/*
leetcode 1832 easy
hash set approach is ok, but iterating string with 
array counter is also available and even faster.
Example 1:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26)return false;
        unordered_set<char> set;
        for(char c : sentence){
            set.insert(c);
            if(set.size()==26) return true;
        }
        return false;
    }
};
