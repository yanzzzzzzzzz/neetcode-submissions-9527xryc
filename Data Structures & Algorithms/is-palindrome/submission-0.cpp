class Solution {
public:
    bool isPalindrome(string s) {
        string ss="";
        int len = s.length();
        for(int i = 0; i < len; i++){
            char n = tolower(s[i]);
            if(isalnum(n)){
                ss += n;
            }
        }
        cout << ss <<endl;
        for(int i = 0; i < ss.length() / 2; i++){
            if(ss[i] != ss[ss.length() - i - 1]){
                cout << ss[i] <<"," << ss[ss.length() - i + 1];
                return false;
            }
        }
        return true;
    }
};
