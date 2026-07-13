class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;

        if(n == 0) return 0;

        while(i<n && s[i] == ' '){
            i++;
        }
        if(i==n) return 0;
        
        int sign = 1;
        if(s[i] == '-'){
            sign *= -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        long ans =0;
        while(i<n && isdigit(s[i])){
            int num = s[i] -'0';
            ans= ans*10 + num;
        if(sign* ans <=INT_MIN){
            return INT_MIN;
        }
        else if(sign* ans >= INT_MAX){
            return INT_MAX;
        }
            i++;

        }
        // else{
            return sign*ans;
        // }
    }
};
