#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_valid(string &str)
{
    stack<char> stack;
    
    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stack.push(c);
        }
        else
        {
            if (stack.empty())
            {
                return false;
            }
            else
            {
                char top = stack.top();
                stack.pop();
                
                if ((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }
    }
    
    return stack.empty();
}

int main()
{
    string str;
    cout << "Enter a string with parentheses: ";
    getline(cin, str);
    
    if (is_valid(str))
    {
        cout << "The parentheses are balanced!";
    }
    else
    {
        cout << "The parentheses are not balanced!";
    }
    
    return 0;
}
