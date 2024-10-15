#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void nextGreater(vector<int> vec)
{
    stack<int> s;
    vector<int> result(vec.size(), -1);
    
    for (int i = 0; i < vec.size(); i++)
    {
        while (!s.empty() && vec[i] > vec[s.top()])
        {
            result[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    cout << "Next Greater Element Index: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    
    return;
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    
    vector<int> vec(size);
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) 
        cin >> vec[i];
        
    nextGreater(vec);
    
    return 0;
}
