class Solution {
public:
    bool isAnagram(string s, string t) {
        // 先檢查兩個字串長度是否相同, 不相同直接回傳false
        if(s.size() != t.size()){
            return false;
        }
        // 用hashmap<string, int> or 1d int array都可以
        // 紀錄頻率, 然後檢查兩個字的頻率是否相同
        int c[26] = {};
        for(int i = 0; i < s.size(); i++){
            c[s[i] - 'a']++;
            c[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(c[i] != 0){
                return false;
            }
        }
        return true;
    }
};
