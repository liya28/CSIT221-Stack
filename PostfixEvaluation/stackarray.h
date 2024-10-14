// stackarray.h

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class StackArray
{
    private:
        int top;
        int size;
        int capacity;
        string *arr;

        // Resizes the array to increase capacity
        void dynamic_resize()
        {
            capacity += ceil(capacity * 0.5);
            if (capacity < 5) capacity = 5;
            
            string* newArr = new string[capacity]; // Allocate new array
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i]; // Copy existing data to the new array
            }
            delete[] arr; // Free old array
            arr = newArr;
        }

        // Reduces the array's capacity if needed
        void dynamic_deduce()
        {
            capacity = capacity - ceil(capacity / 4);
            if (capacity < 5) capacity = 5;
            
            string* newArr = new string[capacity];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }

    public:
        StackArray()
        {
            capacity = 2;
            size = 0;
            top = -1;
            arr = new string[capacity];
        }

        ~StackArray()
        {
            delete[] arr; // Properly free the array
        }

        // Pushes an element onto the stack
        void push(const string& str)
        {
            if (size == capacity) dynamic_resize();
            arr[++top] = str;
            size++;
        }

        // Pops an element from the stack
        string pop()
        {
            if (isEmpty()) return "";
            string c = arr[top--];
            size--;
            
            if (size < capacity / 4)
            {
            	dynamic_deduce();
			}
            return c;
        }

        // Peeks the top element
        string peek()
        {
            if (isEmpty()) return "";
            return arr[top];
        }

        // Checks if the stack is empty
        bool isEmpty()
        {
            return top == -1;
        }

        // Prints the stack contents
        void print()
        {
            if (isEmpty()) return;
            cout << "Size: " << size << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

