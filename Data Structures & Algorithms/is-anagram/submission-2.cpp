class Solution {
public:
    bool isAnagram(string s, string t) {
        //判斷一樣的文字組成, 找文字出現的頻率
        //文字頻率:hashmap, 或是已知字母只有26個小寫字, 可以用int[26]
        //簡單過濾:先比對長度
        if(s.size() != t.size()){
            return false;
        }
        int f1[26] = {0};
        int f2[26] = {0};
        for(int i = 0; i < s.size(); i++){
            f1[s[i] - 'a']++;
            f2[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(f1[i] != f2[i]){
                return false;
            }
        }
        return true;
    }
};
