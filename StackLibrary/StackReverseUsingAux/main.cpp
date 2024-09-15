#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void reverse(vector<int> &stack_arr)
{
    stack<int> aux;
    
    for (int i = 0; i < stack_arr.size(); i++)
    {
        aux.push(stack_arr[i]);
    }
    
    for (int i = 0; i < stack_arr.size(); i++)
    {
        stack_arr[i] = aux.top();
        aux.pop();
    }
    return;
}

int main()
{
    int size;
    cout << "Enter size of stack array: ";
    cin >> size;
    
    vector<int> stack_arr(size);
    
    cout << "Enter elements of stack array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> stack_arr[i];
    }
    
    reverse(stack_arr);
    
    for (int i = 0; i < size; i++)
    {
        cout << stack_arr[i] << " ";
    }
    
    return 0;
}
