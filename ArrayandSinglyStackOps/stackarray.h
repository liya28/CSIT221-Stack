#include "stack.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

class StackArray 
{
	private:
		int top;
		int *arr;
		int size;
		int capacity;
		
		void dynamic_resizeArr()
		{
			int new_capacity = capacity + ceil(capacity * 0.5);
			if (new_capacity < 5)
			{
				new_capacity = 5;
			}
			arr = (int*)realloc(arr, new_capacity * sizeof(int));
			capacity = new_capacity;
			return;
		}
		
		void dynamic_deduceArr()
		{
			int new_capacity = capacity - ceil(capacity * 0.5);
			if (new_capacity < 5)
			{
				new_capacity = 5;
			}
			arr = (int*)realloc(arr, new_capacity * sizeof(int));
			capacity = new_capacity;
			return;
		}
		
	public:
		StackArray()
		{
			capacity = 2;
			arr = (int*)calloc(capacity, sizeof(int));
			top = -1;
			size = 0;
		}
		
		~StackArray()
		{
			free(arr);
		}
		
		void pushArr(int num)
		{
			if (size == capacity)
			{
				dynamic_resizeArr();
			}	
			arr[++top] = num;
			size++;
			cout << "Element " << arr[top] << " is added successfully.\n";
		}
		
		int popArr()
		{
			if (isEmptyArr())
			{
				cout << "Stack underflow.\n";
				return -1;
			}
			
			int del = arr[top--];
			size--;
			
			cout << del << " is removed. ";
			if (!isEmptyArr())
			{
				cout << "New top of the stack: " << arr[top] << endl;
			}
			else
			{
				cout << del << "Stack is now empty.\n";
			}
			
			if (size <= capacity / 4)
			{
				dynamic_deduceArr();
			}
			
			return del;
		}
		
		int topArr()
		{
			if (isEmptyArr())
			{
				cout << "Stack is empty.\n";
				return -1;
			}
			return arr[top];
		}
		
		bool isEmptyArr() 
		{
			return size == 0;
		}
		
		void printArr()
		{
			if (isEmptyArr())
			{
				cout << "Stack is empty.\n";
				return;
			}
			cout << "STACK ELEMENTS (SIZE: " << size << ")" << endl;
			for (int i = top; i >= 0; i--)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};
