class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(char c:S){
            if(isdigit(c)){
                st.push(c-'0');
            }
            else{
                int y=st.top();
                st.pop();
                int x=st.top();
                st.pop();
                switch(c){
                    case '+':
                    st.push(x+y);
                    break;
                    case '-':
                    st.push(x-y);
                    break;
                    case '*':
                    st.push(x*y);
                    break;
                    case '/':
                    st.push(x/y);
                    break;
                }
            }
        }
        return st.top();
    }
};