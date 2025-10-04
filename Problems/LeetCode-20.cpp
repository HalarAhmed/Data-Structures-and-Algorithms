// Idea of the problem is (last opening bracket should have the first closing bracket in the stack)
class Solution 
{
public:
    bool isValid(string str) 
    {
        stack<char>s;
        for(int i=0;i<str.size();i++)
        {
            if((str[i]=='(') || (str[i]=='{') || (str[i]=='['))   // for opening brackets
            {
                s.push(str[i]);
            }
            else    
            {
                if(s.size()==0) // if the stack is empty and there is a closing bracket
                {
                    return false;
                }
                if((s.top()=='(' && str[i]==')') || (s.top()=='[' && str[i]==']') || (s.top()=='{' && str[i]=='}'))
                {
                    s.pop();    // if the top contains the opening bracket of the corresponding closing bracket.
                }
                else
                {
                    return false;   // if the top does not contain the opening bracket of the corresponding closing bracket.
                }
            }
        }
        if(s.size()==0) // after travering through the string if the stack is empty 
        {
            return true;
        }
        else
        {
            return false; // after travering through the string if the stack is not empty 
        }
    }
};
