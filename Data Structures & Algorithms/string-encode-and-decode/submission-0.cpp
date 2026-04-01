class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].length();
            res += to_string(len) + "#" + strs[i];
        }
        cout << res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        int i = 0;
        string tmp = "";
        while(i < s.length()){
            string numStr = "";
            int j = i;
            for(j = i; j < s.length(); j++){
                if(s[j] == '#'){
                    break;
                }
                numStr += s[j];
            }
            int num = stoi(numStr);
            int startIndex = j + 1;
            int endIndex = startIndex + num;
            for(int m = startIndex; m < endIndex; m++){
                tmp += s[m];
            }
            vec.push_back(tmp);
            tmp = "";
            i += numStr.length() + 1 + num;
        }
        return vec;
    }
};
