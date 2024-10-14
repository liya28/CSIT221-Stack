#include <iostream>
#include <string>
#include <cstdlib> // For std::atoi
#include <sstream> // For std::stringstream
#include "stackarray.h"

using namespace std;

int stringToInt(const string &str)
{
    int num;
    stringstream ss(str);
    ss >> num;
    return num;
}

string intToString(int num) 
{
    stringstream ss;
    ss << num;
    return ss.str();
}

bool isOperator(char c) 
{
    return (c == '+' || c == '*' || c == '/' || c == '-');
}

int evaluatePostfix(string postfix) 
{
    StackArray *stack = new StackArray; 

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) 
		{
            stack->push(string(1, c)); 
        } 
        else if (isOperator(c)) 
		{
            if (stack->isEmpty()) 
			{
                cout << "Insufficient operands.\n";
                delete stack; 
                return -1;
            }
            
            string op2_str = stack->pop(); 
            if (stack->isEmpty()) 
			{
                cout << "Insufficient operands.\n";
                delete stack;
                return -1; 
            }
            string op1_str = stack->pop();

            int op1 = stringToInt(op1_str); 
            int op2 = stringToInt(op2_str); 
            int result = 0;

            switch (c) 
			{
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        cout << "Division by zero error.\n";
                        delete stack; 
                        return -1; 
                    }
                    result = op1 / op2;
                    break;
                default:
                    cout << "Invalid operator.\n";
                    delete stack; 
                    return -1; 
            }

            stack->push(intToString(result)); 
        }
    }

    if (stack->isEmpty()) 
	{
        cout << "Invalid postfix expression.\n";
        delete stack; 
        return -1; 
    }

    string finalResult = stack->pop();
    delete stack; 

    if (finalResult.empty()) 
	{
        return -1;
    }

    return stringToInt(finalResult); 
}

int main() 
{
    string given;

    cout << "Enter a postfix expression: ";
    cin >> given;

    int result = evaluatePostfix(given);
    if (result != -1) 
	{ 
        cout << "Evaluation result: " << result << endl;
    }

    return 0;
}

