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
        
        ~stack()
        {
            free(arr);
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

bool isDuplicate(string str)
{
    stack s;
    
    for (char c : str)
    {
        // Check for immediate duplicates
        // If current character is a ), ], } and the top of the stack 
        // is its matching (, [, {, return true.
        if (c == ')' && !s.isEmpty() && s.peek() == '(') return true;
        else if (c == ']' && !s.isEmpty() && s.peek() == '[') return true;
        else if (c == '}' && !s.isEmpty() && s.peek() == '{') return true;
        // If the character is an (, [, {, push it onto the stack
        else if (c == '(' || c == '[' || c == '{') s.push(c);
        // If it's a closing, we need to pop the matching opening parenthesis from the stack.
        else if (c == ')' || c == ']' || c == '}') 
        {
            // Pop characters from the stack until we find matching opening parenthesis.
            while (!s.isEmpty() && s.peek() != '(' && s.peek() != '[' && s.peek() != '{')
            {
                s.pop(); // Remove non-matching chars.
            }
            // Pop the matching opening parenthesis if the stack isn't empty.
            if (!s.isEmpty())
            {
                s.pop();
            }
        }
    }
    // If no duplicate parentheses found, we return false.
    return false;
}

int main()
{
    string str;
    cout << "Enter a string containing only parentheses: ";
    getline(cin, str);
    
    if (isDuplicate(str)) 
    {
        cout << "Duplicate parentheses found!";
    }
    else 
    {
        cout << "No duplicate parentheses found.";
    }
    
    return 0;
}
