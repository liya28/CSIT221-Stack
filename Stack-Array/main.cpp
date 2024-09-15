#include <iostream>

using namespace std;

class Stack
{
    private:
        int *stack_arr;
        int top;
        int capacity;
        
        void resize(int new_capacity)
        {
            int *new_arr = new int[new_capacity];
            
            for (int i = capacity - 1; i >= 0; i--)
            {
                new_arr[i] = stack_arr[i];
            }
            
            delete[] stack_arr;
            stack_arr = new_arr;
            capacity = new_capacity;
            
            return;
        }
        
    public:
        Stack(int initial_capacity = 2)
        {
            stack_arr = new int[initial_capacity];
            top = -1;
            capacity = initial_capacity;
        }
        
        ~Stack()
        {
            delete[] stack_arr;    
        }
        
        void push(int data)
        {
            if (isFull())
            {
                resize(capacity *= 2);
                cout << "Stack resized" << endl;
            }
            
            top++;
            stack_arr[top] = data;
            cout << "Push successful" << endl;
            return;
        }
        
        int pop()
        {
            if (isEmpty())
            {
                cout << "Stack underflow." << endl;
                return -1;
            }
            
            int value = stack_arr[top];
            top--;
            cout << "Pop successful" << endl;
            
            return value;
        }
        
        bool isFull()
        {
            return top == capacity - 1;
        }
        
        bool isEmpty()
        {
            return top == -1;
        }
        
        int peek()
        {
            if (isEmpty())
            {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return stack_arr[top];
        }
        
        void print()
        {
            cout << "Stack array: ";
            
            for (int i = top; i >= 0; i--)
                cout << stack_arr[i] << " ";
            cout << endl;
            return;
        }
};

int main()
{
    Stack stack;
    
    int data;
    int choice;
    
    while (1)
    {
        cout << "Welcome to Stack Array" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Print" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << "Enter element: ";
                cin >> data;
                stack.push(data);
                cout << endl;
                break;
                
            case 2:
                data = stack.pop();
                cout << "Popped element: " << data << endl << endl;
                break;
            
            case 3:
                data = stack.peek();
                cout << "Top element of the stack array: " << data << endl << endl;
                break;        
        
            case 4:
                cout << "Printing..." << endl; 
                stack.print();
                cout << endl;
                break;
                
            case 5:
                cout << "Thank you for participating. Exiting the program..." << endl;
                return 0;
            
            default:
                cout << "Invalid choice. Try again." << endl << endl;
        }
    }
    
    return 0;
}
