#include <iostream>
#include <stack>

using namespace std;

void insert_at_bottom(stack<int> &s, int element)
{
    if (s.empty() || element > s.top())
    {
        s.push(element);
    }
    else
    {
        int top = s.top();
        s.pop();
        
        insert_at_bottom(s, element);
        s.push(top);
    }
}

void sort_stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    else
    {
        int top = s.top();
        s.pop();
        
        sort_stack(s);
        
        insert_at_bottom(s, top);
    }
}

int main()
{
    stack<int> s;
    int size;
    int data;
    
    cout << "Enter the number of elements in the stack: ";
    cin >> size;
    
    cout << "Enter the elements of the stack:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        s.push(data);
    }
    
    stack<int> temp = s;
    cout << "Stack before sorting: ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    
    sort_stack(s);
    cout << endl;
    
    cout << "Stack after sorting: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}
