class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s)
        {
            if(ch == ')')
            {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if(ch == '}')
            {
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else if(ch == ']')
            {
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            else
                st.push(ch);
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s)
        {
            if(ch ==')' || ch ==']' || ch == '}')
            {
                if(!st.empty() && ((ch - st.top()) == 1 || (ch - st.top()) == 2))
                    st.pop();
                else
                    return false;
            }
            else
                st.push(ch);
                
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};