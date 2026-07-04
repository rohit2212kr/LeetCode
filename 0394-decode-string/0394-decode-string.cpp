class Solution {
public:
    string decodeString(string s) {
        stack<int> numst;
        stack<string> strst;

        string curr = "";
        int num = 0;
        for(char c : s){
            if(isdigit(c)){
                num = num*10 + (c - '0');
            }
            else if(c == '['){
                numst.push(num);
                strst.push(curr);
                num = 0;
                curr = "";
            }
            else if(c == ']'){
                int n = numst.top();
                numst.pop();
                string prev = strst.top();
                strst.pop();
                string repeat = "";
                for(int i = 0; i<n; i++){
                    repeat += curr;
                }

                curr = prev+ repeat ;
            }
            else{
                curr += c;
            }
        }
        return curr;
    }
};