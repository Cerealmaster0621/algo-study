/*
leetcode 1189 easy
string counter
Example 1
Input: text = "nlaebolko"
Output: 1
*/

//less memory, but little slower
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> count;
        int mn = 10000;
        for(const char& i : text){
            count[i]++;
        }
        string s1 = "ban";
        string s2 = "lo";
        for(const char& c: s1){
            if(count.find(c)==count.end()){
                return 0;
            }else{
                mn = min(mn,count[c]);
            }
        }
        for(const char& c: s2){
            if(count[c] > 1){
                mn = min(mn,count[c]/2);
            }else{
                return 0;
            }
        }
        return mn;
    }
};

//more memories, but faster
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> map;
        for(char& c : text){
            if(c == 'b'|| c=='a' || c=='l' || c=='o' || c=='n'){
                map[c]++;
            }
        }
        vector<int> cnt (5);
        int mn = 10000;
        cnt[0] = map['b'];
        cnt[1] = map['a'];
        cnt[2] = map['l']/2;
        cnt[3] = map['o']/2;
        cnt[4] = map['n'];
        for(int i =0; i<cnt.size();i++){
            mn = min(mn,cnt[i]);
        }
        return mn;
    }
};