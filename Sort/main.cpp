#include <iostream>
#include <stack>

using namespace std;

void sort_stack(stack<int> &s)
{
    stack<int> temp;
    
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        
        while (!temp.empty() && temp.top() > top)
        {
            s.push(temp.top());
            temp.pop();
        }
        
        temp.push(top);
    }
    
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<int> s;
    int size;
    int data;
    
    cout << "Enter number of elements to push into stack: ";
    cin >> size;
    
    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        s.push(data);
    }
    
    sort_stack(s);
    
    cout << "Sorted Stack in ascending order:\n";
    while (!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }
    
    return 0;
}
