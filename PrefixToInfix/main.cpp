#include <iostream>
#include <string>
#include "stackarray.h"

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '*' || c == '/' || c == '-');
}

string prefixToInfix(string prefix)
{
    StackArray *stack = new StackArray;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (isOperator(c))
        {
            string op1 = stack->pop();
            string op2 = stack->pop();

			if (op1.empty() || op2.empty())
			{
				cout << "Insufficient operands.\n";
				delete stack;
				return "";
			}
			
            string infix = "(" + op1 + " " + c + " " + op2 + ")";
            stack->push(infix);
        }
        else
        {
            stack->push(string(1, c));
        }
    }

    string result = stack->pop();
    delete stack; // Clean up memory
    
    if (result.empty())
    {
    	return "";
	}
	
    return result;
}

int main()
{
    string given;

    cout << "Enter a prefix expression: ";
    cin >> given;

    cout << prefixToInfix(given);

    return 0;
}

