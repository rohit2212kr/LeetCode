class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        
        stringstream ss(path);
        string token;
        while(getline(ss, token, '/')){
            if(token == ".."){
                if(!st.empty()){
                   st.pop_back();
                }
            }
            else if(token == "" || token == "."){
                continue;
            }
            else{
                st.push_back(token);
            }
        }

        string res = "";
        for(int i = 0; i<st.size(); i++){
            res += '/' + st[i];
        }
        if(res.size() == 0){
            return "/";
        }
        else{
            return res;
        }

    }
};