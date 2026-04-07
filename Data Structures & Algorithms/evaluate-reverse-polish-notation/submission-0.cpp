class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++){
            if( tokens[i] == "+" ||
                tokens[i] == "-" ||
                tokens[i] == "*" ||
                tokens[i] == "/"){
                    int f2 = s.top();
                    s.pop();
                    int f1 = s.top();
                    s.pop();
                    int val = 0;
                    if (tokens[i] == "+"){
                        val = f1 + f2;
                    } else if(tokens[i] == "-"){
                        val = f1 - f2;
                    } else if(tokens[i] == "*"){
                        val = f1 * f2;
                    } else if(tokens[i] == "/"){
                        val = f1 / f2;
                    }
                    s.push(val);
                }else{
                    s.push(stoi(tokens[i]));
                }
        }
        return s.top();
    }
};
