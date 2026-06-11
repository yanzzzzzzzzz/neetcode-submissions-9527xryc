class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int c[26] = {0};
        int left = 0;
        for(int i = 0; i < s1.size(); i++){
            c[s1[i] - 'a']++;
        }
        for(int right = 0; right < s2.size(); right++){
            c[s2[right] - 'a']--;

            if((right - left + 1) > s1.size()){
                c[s2[left] - 'a']++;
                left++;
            }
            if((right - left + 1) == s1.size()){
                bool checkIsAns = true;
                for(int i = 0; i < 26; i++){
                    if(c[i]){
                        checkIsAns = false;
                    }
                }
                if(checkIsAns){
                    return true;
                }
            }
        }
        return false;
    }
};
