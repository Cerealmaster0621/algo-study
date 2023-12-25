/*
Leetcode 383 easy
basic hashmap count
Example 1
Input: ransomNote = "a", magazine = "b"
Output: false
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        for(char& c : magazine){
            map[c]++;
        }
        for(char& c : ransomNote){
            if(map.find(c)==map.end() || map[c] <= 0){
                return false;
            }
            map[c]--;
        }
        return true;
    }
};