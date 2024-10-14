#include <iostream>
#include <string>
#include "stackarray.h"

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '*' || c == '/' || c == '-');
}

string postfixToPrefix(string postfix)
{
    StackArray *stack = new StackArray;

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (isOperator(c))
        {
            string op2 = stack->pop(); 
            string op1 = stack->pop(); 

            if (op1.empty() || op2.empty())
            {
                cout << "Insufficient operands.\n";
                delete stack;
                return "";
            }

            string prefix = c + op1 + op2; 
            stack->push(prefix); 
    	}
        else
        {
            stack->push(string(1, c));
        }
    }

    string result = "";
	while (!stack->isEmpty())
    {
    	result += stack->pop();
	}
    return result;
}

int main()
{
    string given;

    cout << "Enter a postfix expression: ";
    cin >> given;

    string result = postfixToPrefix(given);
    cout << "Prefix expression: " << result << endl;

    return 0;
}

