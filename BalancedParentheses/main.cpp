#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class stack
{
    private:
        int top;
        int capacity;
        char *arr;
        
    public:
        stack()
        {
            capacity = 100;
            arr = (char*)malloc(100 * sizeof(char));
            top = -1;
        }
        
        bool isEmpty()
        {
            return top == -1;
        }
        
        bool isFull()
        {
            return top == capacity - 1;
        }
        
        void push(char c)
        {
            if (isFull()) return;
            arr[++top] = c;
        }
        
        char pop()
        {
            if (isEmpty()) return '\0';
            return arr[top--];
        }
        
        char peek()
        {
            if (isEmpty()) return '\0';
            return arr[top];
        }
};

bool isBalanced(string str)
{
    stack s;
    
    for (char c : str)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else
        {
            if (s.isEmpty()) return false;
            char t = s.peek();
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{'))
            {
                return false;
            }
            s.pop();
        }
    }
    
    return s.isEmpty();
}

int main()
{
    string str;
    cout << "Enter a string containing only parentheses: ";
    getline(cin, str);
    
    if (isBalanced(str)) 
    {
        cout << "Balanced parentheses found!";
    }
    else 
    {
        cout << "No balanced parentheses found!";
    }
    
    return 0;
}
