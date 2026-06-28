class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int a = 0;
        int b = 0;

        for(string c: operations){
            if(c == "C"){
                st.pop();
            }
            else if(c == "D"){
                a = st.top();
                st.push(2*a);
                a = 0;
            }
            else if(c == "+"){
                b =st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a);
                st.push(b);
                st.push(a+b);
                a=0;
                b=0;
            }
            else{
                st.push(stoi(c));
            }
        }
        int res = 0;
        while(st.size() != 0){
            res += st.top();
            st.pop();
        }
        return res;
    }
};