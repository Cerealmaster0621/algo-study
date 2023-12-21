/*
leetcode 1941 easy
using hashmap count + hashset frequencies
for checking if every elements have the same
frequencies of appeared.
Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
*/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> count;
        for (const char& c : s){
            count[c]++;
        }
        unordered_set<int> frequencies;
        for(const auto&[key, val] : count){
            frequencies.insert(val);
        }
        return frequencies.size() == 1; // if any other size exists, size of frequencies will be more than 2.
    }
};