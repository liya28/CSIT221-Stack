#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void stock_span(vector<int> vec)
{
    stack<int> s;
    vector<int> result(vec.size());
    
    for(int i = 0; i < vec.size(); i++)
    {
        while (!s.empty() && vec[s.top()] <= vec[i])
        {
            s.pop();
        }
        
        if (s.empty())
        {
            result[i] = i + 1;
        }
        else
        {
            result[i] = i - s.top();
        }
        
        s.push(i);
    }
    
    for (int i = 0; i < result.size(); i++) 
        cout << result[i] << " ";
        
    return;
}

int main()
{
    int size;
    cout << "Enter the number of stocks: ";
    cin >> size;
    
    vector<int> vec(size);
    
    cout << "Enter the stock prices:\n";
    for(int i = 0; i < size; i++)
        cin >> vec[i];
    
    stock_span(vec);
    
    return 0;
}
