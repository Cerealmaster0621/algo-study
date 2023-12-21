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

class Solution {
public: aaabb
    int ans(string s, int k){
        unordered_map<char,int> map;
        int left = 0, ans;
        for(int right = 0;right<s.size();right++){
            map[s[right]]++;
            while(map.size()>k){
                map[s[left]]--;
                if(map[s[left]]==0){
                    map.erase(s[left]);
                }
                left--;
            }
            ans = max(ans,right-left+1);
        }

        return ans;
    }
}