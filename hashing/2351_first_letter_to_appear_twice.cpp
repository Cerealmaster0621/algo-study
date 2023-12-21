/*
leetcode 2351 easy
hashmap basics
iterate through string, check hashmap everytime if
hashmap[s[i]] exits, if not, make one.
*/

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,bool> hash_map;
        for(int i =0 ; i<s.length();i++){
            if(hash_map.find(s[i])!=hash_map.end()){
                return s[i];
            }
            hash_map[s[i]]=true;
        }
        return ' ';
    }
};

//using set
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> set;
        for(int i =0 ; i<s.length();i++){
            if(set.find(s[i]!= set.end())){
                return s[i];
            }
            set.insert(s[i]);
        }
        return ' ';
    }
};