class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].length();
            res += to_string(len) + "#" + strs[i];
        }
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
            tmp = s.substr(startIndex, num);
            vec.push_back(tmp);
            tmp = "";
            i += numStr.length() + 1 + num;
        }
        return vec;
    }
};
