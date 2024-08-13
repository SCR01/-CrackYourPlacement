class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for(char ch : s) {
            if(ch != ']') {
                st.push(ch);
                continue;
            }
            
            string innerString = "";
            while(!st.empty() && st.top() != '[') {
                innerString = st.top() + innerString;
                st.pop();
            }
            st.pop(); // Pop '['
            
            string multiplierStr = "";
            while(!st.empty() && isdigit(st.top())) {
                multiplierStr = st.top() + multiplierStr;
                st.pop();
            }
            
            int multiplier = stoi(multiplierStr);
            string repeatedString = "";
            for(int i = 0; i < multiplier; ++i) {
                repeatedString += innerString;
            }
            
            for(char c : repeatedString) {
                st.push(c);
            }
        }
        
        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};